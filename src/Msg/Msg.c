#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Msg.h"

#define MSIZE 64


void msend(int sock){
    char buffer[MSIZE];

    bzero(buffer, MSIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    //printf("\n\033[0;35m\tFrom server:\033[0m %s. \n", buffer);

    bzero(buffer, MSIZE);
    strcpy(buffer, "Hello, from client");
    send(sock, buffer, strlen(buffer), 0);
    
    printf("\n\n");
    /*------------------------------------
    	Complete with Messages.
    ------------------------------------*/
    bzero(buffer, MSIZE);
    printf("\033[0;35m\t@Client: \033[0m");
    fgets(buffer, MSIZE, stdin);
    send(sock, buffer, strlen(buffer), 0);
    
    bzero(buffer, MSIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("\033[0;35m\t@Server:\033[0m %s.", buffer);
    
    /*------------------------------------*/

    bzero(buffer, MSIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    //printf("\n\n\033[0;35m\tFrom server:\033[0m %s.MSG", buffer);

}


void mrcv(int sock){
    char buffer[MSIZE];
    bzero(buffer, MSIZE);
    strcpy(buffer, "Hello, from server");
    send(sock, buffer, strlen(buffer), 0);
         
    bzero(buffer, MSIZE);
    //printf("\nWaiting...");
    recv(sock, buffer, sizeof(buffer), 0);
    //printf("\n\033[0;35m\tFrom client:\033[0m %s. \n", buffer); 

    
    printf("\n");
    /*------------------------------------
    	Complete with Messages.
    ------------------------------------*/
    bzero(buffer, MSIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("\033[0;35m\t@Client:\033[0m %s.", buffer); 
    
    bzero(buffer, MSIZE);
    printf("\033[0;35m\t@Server: \033[0m");
    fgets(buffer, MSIZE, stdin);
    send(sock, buffer, strlen(buffer), 0);
    
    /*------------------------------------*/
      
    bzero(buffer, MSIZE);
    strcpy(buffer, " ");
    send(sock, buffer, strlen(buffer), 0);

}

