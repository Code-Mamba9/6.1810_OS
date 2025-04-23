
 #include "kernel/types.h"
 #include "kernel/stat.h"
 #include "user/user.h"
 #include "kernel/param.h"
void printPrime(int *leftPipe) __attribute__((noreturn));
void printPrime(int* leftPipe) {
   close(leftPipe[1]);
   int received, thisPrime;
   int rightPipe[2];

   if (read(leftPipe[0], &received, 4) == 0) {
     close(leftPipe[0]);
     exit(0);
   }
   thisPrime = received;
   printf("prime %d\n", thisPrime);

   pipe(rightPipe);
   if (fork() == 0) {
     close(rightPipe[1]);
     close(leftPipe[0]);
     printPrime(rightPipe);
   } else {
     close(rightPipe[0]);
     while (read(leftPipe[0], &received, 4)!= 0) {
       if (received % thisPrime) {
         write(rightPipe[1], &received, 4);
       }
     }
     close(leftPipe[0]);
     close(rightPipe[1]);
     wait(0);
     exit(0);
   }
}

int main(int argc, char *argv[]) {
   if (argc >= 2) {
     printf("primes only needs no arg");
     exit(1);
   }
   int p[2];
   pipe(p);
   if (fork() == 0) { // child
     printPrime(p);
   } else {
     close(p[0]);
     for (int i = 2; i < 280; i++) {
       write(p[1], &i, 4);
     }
     close(p[1]);
     wait(0);
   }
   exit(0);
}
