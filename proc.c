#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <string.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


static void sighandler (int signo){
  if(signo == SIGINT){
    umask(0);
    int fd = open( "message.txt", O_CREAT | O_APPEND | O_WRONLY, 0644 );
    write( fd, "exited due to SIGINT\n",21 );
    close(fd); //finish writing to file
    ///printf("exited due to SIGINT\n");
    exit(0);
  }
  if (signo == SIGUSR1) {
    printf("ppid: %d\n",getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1,sighandler);
  while(1){
    printf("pid: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
