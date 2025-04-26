#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"
//
// int main(int argc, char *argv[]) {
//   char *p;
//   for (int i = 0; i < 9; i++) {
//     p = sbrk(PGSIZE);
//   }
//   write(2, p+16, 8);
//   exit(0);
// }

//
// int
// main(int argc, char *argv[])
// {
//   char *leak_page = 0;
//   // Allocate 32 pages; the i==9 allocation reuses the page
//   // where secret stored its 8 bytes at offset 32.
//   for(int i = 0; i < 32; i++){
//     char *p = sbrk(PGSIZE);
//     if(p < 0){
//       printf("sbrk failed\n");
//       exit(1);
//     }
//     if(i == 8)
//       leak_page = p;
  }
  //
  // // Now leak_page points to start of the page containing the secret.
  // // Read the 8-byte secret at offset 32 and write it to fd 2.
  // if(write(2, leak_page + 32, 8) != 8){
  //   printf("write failed\n");
  //   exit(1);
  }
  //
  // exit(0);
}



