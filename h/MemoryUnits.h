#ifdef __cplusplus
extern "C"{
#endif

#ifndef MemoryUnits_h
#define MemoryUnits_h

#define MEM_SIZE 1 << 16

typedef unsigned char byte;

// In case this assert fails, change word to a 2 byte integer type
static_assert(sizeof(unsigned short) == 2);
typedef unsigned short word;

typedef bool bit;

#endif

#ifdef __cplusplus
}
#endif