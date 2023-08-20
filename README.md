# NES EMULATOR

***Made for Windows operating system***

### Author: Teodor Djelic

---

## Makefile

Basic configurable makefile. Compiles, assembles and links all c and cpp files inside the source directory. Lets the user configure target executable name, as well as source, include, intermediate and dependency directories.

*Subdirectories cannot be used inside the source directory as of this version.*

### Makefile goals:

- `make init` creates needed subdirectories (should be ran before the start of every project; in the case of this project, init goal is redundant as directories will already be ready);
- `make all` compiles, assembles and links the whole project;
- `make run` compiles, assembles and links the whole project, and then runs it;
- `make clean` deletes all intermediate files and the executable file.