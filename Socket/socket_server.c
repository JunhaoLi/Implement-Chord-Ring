#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int socket_server(int portno)
{

  //fprintf(stdout,"in function\n");
  int sockfd, newsockfd, clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int  n;

  /* First call to socket() function */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) 
    {
      perror("ERROR opening socket");
      return EXIT_FAILURE;
    }
  /* Initialize socket structure */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
 
  /* Now bind the host address using bind() call.*/
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
	   sizeof(serv_addr)) < 0)
    {
      perror("ERROR on binding");
      return EXIT_FAILURE;
    }

  /* Now start listening for the clients, here process will
   * go in sleep mode and will wait for the incoming connection
   */
  listen(sockfd,5);
  clilen = sizeof(cli_addr);

  /* Accept actual connection from the client */
//  fprintf(stdout,"before accept\n");
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, 
		     &clilen);
  if (newsockfd < 0) 
    {
      perror("ERROR on accept");
      return EXIT_FAILURE;
    }
  /* If connection is established then start communicating */
  bzero(buffer,256);
  n = read( newsockfd,buffer,255 );
  if (n < 0)
    {
      perror("ERROR reading from socket");
      return EXIT_FAILURE;
    }
  printf("Here is the message: %s\n",buffer);

  /* Write a response to the client */
  n = write(newsockfd,"I got your message",18);
  if (n < 0)
    {
      perror("ERROR writing to socket");
      exit(1);
    }
  return 0; 
}

int main (int argc, const char** argv) {

  int  portno = 8001;
  socket_server(8001);
  return EXIT_SUCCESS;
}
