#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <io.h>
#include <process.h>
#else
#include <unistd.h>
#endif

int main(){
  printf("Hello world!\n");
  return 0;
}
