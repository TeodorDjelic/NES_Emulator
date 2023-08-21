# == DIRECTORY CONFIGS ==

PROGRAM=main.exe
SRCDIR=src
INCDIRS=h
OBJDIR=bin
DEPDIR=bin

# == COMPILER CONFIGS ==

CXX=g++
CC=gcc
OPT=-O0

# == DO NOT TOUCH ANYTHING UNDER ==

vpath %.c $(SRCDIR)
vpath %.cpp $(SRCDIR)
vpath %.o $(OBJDIR)
vpath %.h $(INCDIRS)
vpath %.d $(DEPDIR)

DEPFLAGS=-MP -MD
BASEFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CFLAGS=$(BASEFLAGS)
CPPFLAGS= -std=c++11 $(BASEFLAGS)

### TODO:
# CFILES and CPPFILES need to recursively find .c and .cpp respectively in subdirectories


CFILES=$(wildcard $(SRCDIR)/*.c)
CPPFILES=$(wildcard $(SRCDIR)/*.cpp)

TEMP=$(patsubst %.c,%.o,$(CFILES))
TEMP+=$(patsubst %.cpp,%.o,$(CPPFILES))
OBJECTS=$(foreach D,$(notdir $(TEMP)),$(OBJDIR)/$(D))

TEMP2=$(patsubst %.c,%.d,$(CFILES))
TEMP2+=$(patsubst %.cpp,%.d,$(CPPFILES))
DEPFILES=$(foreach D,$(notdir $(TEMP2)),./$(DEPDIR)/$(D))

all: $(PROGRAM)

run: all
	$(info )
	$(info === PROGRAM IS STARTING ===)
	$(info )
	@./$(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $@ $(foreach D,$^,$(OBJDIR)/$(notdir $(D)))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $(OBJDIR)/$(notdir $@) $<
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c -o $(OBJDIR)/$(notdir $@) $<

-include $(DEPFILES)

.PHONY: all run init clean

init:
	-md $(SRCDIR) $(INCDIRS) $(OBJDIR) $(DEPDIR)

clean:
	-del $(PROGRAM) $(foreach D,$(subst /,\,$(foreach T,$(OBJECTS),$(OBJDIR)/$(notdir $(T)))),".\$(D)") $(foreach D,$(subst /,\,$(foreach T,$(DEPFILES),$(DEPDIR)/$(notdir $(T)))),".\$(D)")