#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Example.h"

#define EXSIZE 64


void esend(int sock){
    char buffer[EXSIZE];

    bzero(buffer, EXSIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("\n\033[0;35m\tFrom server:\033[0m %s.", buffer);

    bzero(buffer, EXSIZE);
    strcpy(buffer, "Hello, from client");
    send(sock, buffer, strlen(buffer), 0);

    bzero(buffer, EXSIZE);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("\n\033[0;35m\tFrom server:\033[0m %s.", buffer);

}


void ercv(int sock){
    char buffer[EXSIZE];
    bzero(buffer, EXSIZE);
    strcpy(buffer, "Hello, from server");
    send(sock, buffer, strlen(buffer), 0);
         
    bzero(buffer, EXSIZE);
    printf("\nWaiting...");
    recv(sock, buffer, sizeof(buffer), 0);
    printf("\n\033[0;35m\tFrom client:\033[0m %s.", buffer); 
        
    bzero(buffer, EXSIZE);
    strcpy(buffer, "Goodbye, from server");
    send(sock, buffer, strlen(buffer), 0);

}

