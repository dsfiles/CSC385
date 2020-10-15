#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid;
  /* fork a child process */
  pid = fork(); // clone a process
  if (pid < 0) { /* error occurred (very unlikely in your VM) */
    fprintf(stderr, "Fork Failed"); //send error message to stderr (screen or a file)
  return 1;
  } else if (pid == 0) { /* child process */
    printf("child process successfully created!\n");
    printf ("child_PID = %d,parent_PID = %d\n", getpid(), getppid( ) );
  }
  else { /* parent process */
    printf("Parent process:\n");
    printf ("child_PID = %d,parent_PID = %d\n", getpid(), getppid( ) );
    wait(NULL);
  }
  return 0;
}
