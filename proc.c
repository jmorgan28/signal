#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void loop(){
  while(1){
  printf("%d\n", getpid());
  sleep(1);
  }
}


int main(){
  loop();

  return 0;
}
