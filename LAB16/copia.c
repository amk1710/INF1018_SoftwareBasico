#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TAM 128

int tamBufferAberto;

int myopen (const char *pathname, int flags, int size);
ssize_t myread(int fd, void *buf);

ssize_t mywrite(int fd, const void *buf, size_t count);
int myclose(int fd);

/*

int myopen (const char *pathname, int flags, int buffersize) {
  tamBufferAberto = buffersize;
  return open(pathname, flags);
}



ssize_t myread(int fd, void *buf) {
  return read(fd, buf, tamBufferAberto);
}



ssize_t mywrite(int fd, const void *buf, size_t count) {
  return write(fd, buf, count);
}



int myclose(int fd) {
  return close(fd);
}

*/
 
                                                                            
int main (int argc, char** argv) {                                            

  int arq;                                                                    
  char buf[TAM];                                                          
  ssize_t lidos;                                                              

  if (argc != 2) {                                                            
    fprintf(stderr,"forma correta: %s <nomearquivo>\n", argv[0]);       
    return 1;                                                                 
  }                                                                           

  arq = myopen (argv[1], O_RDONLY, TAM);                                           
  if (arq<0) { perror("abertura de arquivo"); return 1;}                      

  while ((lidos = myread (arq, buf)) > 0)                                
    if ((mywrite (STDOUT_FILENO, buf, lidos) != lidos))                       
      { perror("escrita:"); return 1;}                                        

  myclose (arq);                                                              
  return 0;                                                                   
}
