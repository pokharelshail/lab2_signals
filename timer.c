/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

time_t start, end;
int busy_wait = 1;

void sigalrm_handler(int signum) {
  printf("SIGALRM Triggered!\n");
  busy_wait = 0;
}

void sigint_handler(int signum) {
  time(&end);
  int time_elapsed =  end - start;
  printf("\nTime Elapsed: %d seconds\n", time_elapsed);
  exit(1);
}


int main(int argc, char * argv[]) {
  signal(SIGINT, sigint_handler);
  signal(SIGALRM, sigalrm_handler);
  time(&start);
  while (1) {
    alarm(1);
    while(busy_wait);
    busy_wait = 1;
  }
  return 0;
}