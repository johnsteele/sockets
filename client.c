/**
 * @file	sockets_server_client/client.c
 * @author	John Steele <EMAIL:programjsteele {at} gmail {dot} com>
 * @version	1.0.0
 * @date
 * 	Created:	Sun 03 Apr 2011 04:55:08 PM PDT \n
 * 	Last Update:	Sun 03 Apr 2011 04:55:08 PM PDT
 */

#include    <stdio.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <netinet/in.h>
#include    <netdb.h>

#define     SERVER_PORT     40448 
#define     MAX_LINE        256

int main (int argc, char **argv)
{
   FILE *fp;
   struct hostent *hp; 
   struct sockaddr_in sin;
   char *host;
   char buf [MAX_LINE];
   int s;
   int len;

   if (argc == 2) host = argv [1]; 
   else fprintf (stderr, "Usage: sockets_com host\n");
  
    



    return 1;
} /* end main () */
