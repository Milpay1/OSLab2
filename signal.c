/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_invoked = 0; // Global variable to track if handler was invoked

void handler(int signum)
{ // signal handler
  printf("Hello World!\n");
  handler_invoked = 1; // Set flag to indicate handler was invoked
}

int main(int argc, char *argv[])
{
  signal(SIGALRM, handler); // Register handler to handle SIGALRM
  alarm(5); // Schedule a SIGALRM for 5 seconds
  
  // Wait until the handler has been invoked
  while (!handler_invoked); 
  
  // This line is executed after handler_invoked is set by the handler
  printf("Turing was right!\n");

  return 0;
}
