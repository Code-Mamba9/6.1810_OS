#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

int main(int argc, char *argv[]) {
  char *p;
  for (int i = 0; i < 9; i++) {
    p = sbrk(PGSIZE);
  }
  write(2, p+16, 8);
  exit(0);
}
