#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int pid;
  int p1[2];
  int p2[2];
  pipe(p1);
  pipe(p2);
  char* byte = "xxxxx";

  pid = fork();
  if (pid < 0) {
    exit(1);
  } else if (pid == 0) {
    // child
    close(p1[1]);
    close(p2[0]);
    if (read(p1[0], &byte, 1) != 1) {
      printf("child read failed");
      exit(1);
    }
    printf("%d: received ping\n", getpid());
    write(p2[1], &byte, 2);
    close(p1[0]);
    close(p2[1]);
    exit(0);
  } else {
    close(p1[0]);
    close(p2[1]);
    write(p1[1], &byte, 1); // write to child
    
    // wait(0);
    if (read(p2[0], &byte, 1) != 1) {
      printf("Parent read failed");
      exit(1);
    }
    printf("%d: received pong\n", getpid());
    close(p1[1]);
    close(p2[0]);
  }
  exit(0);
}
