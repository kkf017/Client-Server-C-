#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Example/Example.h"
#include "Files/Files.h"
#include "Bytes/Bytes.h"
#include "Msg/Msg.h"

#define FILE "./Files/unicorn.txt" // file to send - if needed
#define HOST "" // To complete ! server to connect
#define PORT 8080




void client(){

    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0){
        perror("\n\033[0;91m[-]ERROR: Socket not created.\033[0m");
        exit(EXIT_FAILURE);
    }

 
    memset(&addr, '\0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, (char*) HOST, &(addr.sin_addr) ); //addr.sin_addr.s_addr = inet_addr(ip);


    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        perror("\n\033[0;91m[-]ERROR: Socket not created.\033[0m");
        //exit(EXIT_FAILURE);
    }
    printf("\n\033[0;92m[+]DONE: Connected to the server.\033[0m");



    /*** CHANGE THIS PART ***/
    
    //esend(sock);
    //fsend(sock, FILE);
    //bsend(sock, FILE); // Warning !! does not work.
    msend(sock);

   /**********************/
 
    close(sock);
    printf("\n\033[0;92m[+]DONE: Disconnected from the server.\n\033[0m");
}


int main(int argc, char *argv[]){
	client();
	return 1;
}

