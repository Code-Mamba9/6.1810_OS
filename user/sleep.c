#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char* argv[]) {
  char* errMsg = "Sleep requires only 1 argument\n";
  char* sleepMsg = "(nothing happens for a little while)\n";
  if (argc != 2) {
    printf(errMsg);
    exit(1);
  }
  int sleepTime = atoi(argv[1]);
  printf(sleepMsg);
  sleep(sleepTime);
  exit(0);
}
