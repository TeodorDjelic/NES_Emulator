#include <stdio.h>
#include "test.h"

void f(int v){
    for(int i = v; i < v + 10; i++)
       printf("Hi %d\n", i);
       
}