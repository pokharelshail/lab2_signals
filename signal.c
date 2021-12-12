/* signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int busy_wait = 1;

void handler(int signum) {
  printf("Hello World!\n");
  busy_wait = 0;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler);
  while (1) {
    alarm(1);
    while(busy_wait);
    printf("Turing was right!\n");
    busy_wait = 1;
  }
  return 0;
}