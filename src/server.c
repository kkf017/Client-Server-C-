#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Example/Example.h"
#include "Files/Files.h"
#include "Bytes/Bytes.h"
#include "Msg/Msg.h"

#define PORT 8080
#define TIMEWAIT 15




void server(){

    int sockServer, sockClient;
    struct sockaddr_in addrServer, addrClient;
    socklen_t addrSize;
 

    sockServer = socket(AF_INET, SOCK_STREAM, 0);
    if (sockServer < 0){
        perror("\n\033[0;91m[-]ERROR: Socket not created.\033[0m");
        exit(EXIT_FAILURE);
    }


    memset(&addrServer, '\0', sizeof(addrServer));
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(PORT);
    addrServer.sin_addr.s_addr = htonl(INADDR_ANY); // addr.sin_addr.s_addr = inet_addr(ip);


    if (bind(sockServer, (struct sockaddr*)&addrServer, sizeof(addrServer)) < 0){
        perror("\n\033[0;91m[-]ERROR: Bind error.\033[0m");
        exit(EXIT_FAILURE);
    }

    if(listen(sockServer, TIMEWAIT) < 0){
        perror("\n\033[0;91m[-]ERROR: Listen on server.\033[0m");
       	exit(EXIT_FAILURE);
    }
    printf("\n\033[0;30mListening on port %d...\033[0m", PORT);


    //while(1){
        addrSize = sizeof(addrClient);
        sockClient = accept(sockServer, (struct sockaddr*)&addrClient, &addrSize);
        if(sockClient < 0){
            perror("\n\033[0;91m[-]ERROR: Bind error.\033[0m");
            exit(EXIT_FAILURE);
        }
        printf("\n\033[0;92m[+]DONE: Client connected.\033[0m");


        /*** CHANGE THIS PART ***/

        //ercv(sockClient);
        //frcv(sockClient);
        //brcv(sockClient); // Warning !! does not work.
        mrcv(sockClient);

        /**********************/
        
        close(sockClient);
    //}

    close(sockServer);
    printf("\n\033[0;92m[+]DONE: Disconnected from the client.\n\033[0m");

}

int main(int argc, char *argv[]){
	server();
	return 1;
}
