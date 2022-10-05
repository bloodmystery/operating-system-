#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
   pid_t pid, student_pid, student_ppid;
   pid = getpid();
   printf("+ Process id : %d\n", pid);
   pid = fork();
   if (pid < 0) {
      perror("x fork() failure\n");
      return 1;
   }
   if (pid == 0) {
      printf("- This is student process\n");
      student_pid = getpid();
      student_ppid = getppid();
      printf("+ Process id: %d \t PPID: %d\n", student_pid, student_ppid);
   } else {  
      sleep(2);
      printf("+ teacher process \n");
      student_pid = getpid();
      student_ppid = getppid();
      printf("+ Process id: %d \t PPID: %d\n", student_pid, student_ppid);
      printf("+ Newly created process/Child pid :  %d\n", pid);
   }
   _exit(0);
    printf("Terminating process %d \n",pid);
   return 0;
}


//OUTPUT
//+ Process id : 3339
//- This is student process
//+ Process id: 3340 	 PPID: 3339
//+ teacher process 
//+ Process id: 3339 	 PPID: 3332
//+ Newly created process/Child pid :  3340
