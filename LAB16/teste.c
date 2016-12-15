#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)
ssize_t myotherwrite(int fd, const void *buf);

int main (int argc, char** argv) {                                            
  ssize_t tam;
  int arq;                                                                    
  char buf[] = "testando escrita direta! \n";

  if (argc != 2) {                                                            
    fprintf(stderr,"forma correta: %s \n", argv[0]);       
    return 1;                                                                 
  }                                                                           

  arq = open (argv[1], O_CREAT|O_RDWR, MODE);
  if (arq<0) { perror("abertura de arquivo"); return 1;}                      

  if ((tam = myotherwrite (arq, buf)) != sizeof(buf)-1) {
    perror("escrita:"); 
    return 1;
  }                                        
  close (arq);                                                              
  return 0;   
}

