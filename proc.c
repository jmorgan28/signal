#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler (int signo){
  if(signo == SIGINT){
    printf("seen");
    exit(0);
  }
}




int main(){
  while(1){
    signal(SIGINT, sighandler);
    printf("%d\n", getpid());
    sleep(1);
  }
  

  return 0;
}
