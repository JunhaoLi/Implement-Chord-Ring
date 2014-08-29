#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>


int socket_client(const char *port, const char *server_name)
{
  int sockfd,portno,n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];

  portno = atoi(port);
  /* Create a socket point */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
    {
      perror("ERROR opening socket");
      return EXIT_FAILURE;
    }
  server = gethostbyname(server_name);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, 
	(char *)&serv_addr.sin_addr.s_addr,
	server->h_length);
  serv_addr.sin_port = htons(portno);

  /* Now connect to the server */
  
  fprintf(stdout,"before connect function\n");
  if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0) 
    {
      perror("ERROR connecting\n");
      return EXIT_FAILURE;
    }
  /* Now ask for a message from the user, this message
   * will be read by server
   */
  printf("Please enter the message: ");
  bzero(buffer,256);
  fgets(buffer,255,stdin);
  /* Send message to the server */
  n = write(sockfd,buffer,strlen(buffer));
  if (n < 0) 
    {
      perror("ERROR writing to socket");
      return EXIT_FAILURE;
    }
  /* Now read server response */
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0) 
    {
      perror("ERROR reading from socket");
      return EXIT_FAILURE;
    }
  printf("%s\n",buffer);
}

int main (int argc, const char** argv){
  if (argc != 3){
    return EXIT_FAILURE;
  }
  //argc[1] is portno
  //argv[2] is hostname

  int result = socket_client(argv[1],argv[2]);
  return EXIT_SUCCESS;
}
