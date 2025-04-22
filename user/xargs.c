
 #include "kernel/types.h"
 #include "kernel/stat.h"
 #include "user/user.h"
 #include "kernel/param.h"

 int readline(char* buf) {
   char* p = buf;
   while (read(0, p, 1) != 0) {
     if (*p == '\n') {
       *p = 0;
       return 1;
     }
     p++;
   }
   return 0;
 }

 int main(int argc, char *argv[]) {
   if (argc < 2) {
     printf("not enough args");
     exit(1);
   }
   int pid;
   char buf[128];
   char* subArgv[MAXARG];
   for (int i = 1; i < argc; i++) {
     subArgv[i-1] = argv[i];
   }
   while (readline(buf) == 1) {
     subArgv[argc-1] = buf;
     pid = fork();
     if (pid == 0) {
       exec(subArgv[0], subArgv);
       exit(0);
     } else {
       wait(0);
     }
   }

   exit(0);
 }
