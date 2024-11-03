/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int handler_invoked = 0; // Global variable to track if handler was invoked
int alarm_count = 0;     // Counter to track the number of alarms
time_t start_time;       // Start time of the program

void handler(int signum)
{ // Signal handler for SIGALRM
  printf("Hello World!\n");
  handler_invoked = 1; // Set flag to indicate handler was invoked
  alarm_count++;       // Increment the alarm count
}

void sigint_handler(int signum)
{ // Signal handler for SIGINT
  time_t end_time = time(NULL); // Get the end time
  double elapsed_time = difftime(end_time, start_time);
  
  printf("\nProgram executed for %.0f seconds.\n", elapsed_time);
  printf("Total number of alarms: %d\n", alarm_count);
  
  exit(0); // Exit the program
}

int main(int argc, char *argv[])
{
  start_time = time(NULL); // Record the start time

  signal(SIGALRM, handler);       // Register handler for SIGALRM
  signal(SIGINT, sigint_handler); // Register handler for SIGINT

  while (1) {
    alarm(5); // Schedule a SIGALRM every 5 seconds
    while (!handler_invoked); // Wait until handler is invoked
    printf("Turing was right!\n");
    handler_invoked = 0; // Reset flag for the next cycle
  }

  return 0;
}
