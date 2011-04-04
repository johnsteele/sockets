/**
 * @file	sockets_server_client/client.c
 * @author	John Steele <EMAIL:programjsteele {at} gmail {dot} com>
 * @version	1.0.0
 * @date
 * 	Created:	Sun 03 Apr 2011 04:55:08 PM PDT \n
 * 	Last Update:	Sun 03 Apr 2011 04:55:08 PM PDT
 */

#include    <stdio.h>           /* fprintf */
#include    <stdlib.h>          /* exit    */
#include    <string.h>          /* bzero   */
#include    <netinet/in.h>      /* htonl, htons, inet_ntoa */
#include    <netdb.h>           /* gethostbyname           */

#define     SERVER_PORT     40448 
#define     MAX_LINE        256 

int main (int argc, char **argv)
{ 
    char    *host;                      /* cmd-line host             */
    struct  hostent *host_ptr;          /* pointer to host           */
    struct  sockaddr_in sendSockAddr;   /* address of sending socket */
    char    buffer [MAX_LINE];          /* send/receive data         */
    int     clientSd;                   /* client socket descriptor  */
    int     buffer_length;              /* send/receive data size    */


    /* Check command line provided host */
    if (argc == 2) { host = argv [1]; }
    else { fprintf (stderr, "***Sockets Error. Usage: sockets host\n"); exit (1); }
 

    /* Translate host name into peer's IP address. */
    host_ptr = gethostbyname (host); 
    if (!host_ptr) {
      fprintf (stderr, "***Sockets Error. Unknown host: %s\n", host);
      exit (1);
    } 


    /* Zero initialize socket address. */
    bzero ((char *) &sendSockAddr, sizeof (sendSockAddr));
   
    /* Address Family Internet */ 
    sendSockAddr.sin_family = AF_INET; 
    bcopy (host_ptr->h_addr, (char *) &sendSockAddr.sin_addr, host_ptr->h_length);
    sendSockAddr.sin_port = htons (SERVER_PORT);


    /*Create the socket for active Open */
    if ((clientSd = socket (PF_INET, SOCK_STREAM, 0)) < 0)  { 
        perror ("***Sockets Error: Creating socket.\n");
        exit (1);
    }

  
    /* Connect to the socket */ 
    if (connect (clientSd, (struct sockaddr *) &sendSockAddr, sizeof (sendSockAddr))) {
        perror ("***Sockets Error: Connecting to socket.\n");
        close (clientSd);
        exit (1); 
    }


    /* Main loop: get and send lines of text. */
   while (fgets (buffer, sizeof (buffer), stdin)) {

      /* Null terminate end of buffer. */
      buffer [MAX_LINE - 1] = '\0';
      buffer_length = strlen (buffer) + 1;

      /* Send the buffer */
      send (clientSd, buffer, buffer_length, 0); 
   } 
    
    return 0;
} /* end main () */

