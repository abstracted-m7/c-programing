#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // For close()

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    char buffer[BUF_SIZE];
    const char *message = "Hello from server!"; // Message to send to the client

    // Create the socket
    serverSocket = socket(PF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created successfully\n");

    // Prepare the sockaddr_in structure
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY; 

    // Bind the socket to the port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Binding failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
    printf("Binding successful\n");

    // Listen for incoming messages
    printf("Listening for incoming messages...\n");
    addr_size = sizeof(clientAddr);

    while (1) {
        // Receive a message from a client
        int recv_len = recvfrom(serverSocket, buffer, BUF_SIZE, 0,
                                (struct sockaddr*)&clientAddr, &addr_size);
        if (recv_len < 0) {
            perror("Receive failed");
            continue; // Continue listening for other messages
        }

        // Null-terminate the received data
        buffer[recv_len] = '\0';
        printf("Received message from %s:%d: %s\n", 
               inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port), buffer);

        // Send a response back to the client
        if (sendto(serverSocket, message, strlen(message), 0,
                   (struct sockaddr*)&clientAddr, addr_size) < 0) {
            perror("Send failed");
        } else {
            printf("Message sent to client: %s\n", message);
        }
    }

    // Close the socket (this will never be reached in this infinite loop)
    close(serverSocket);
    printf("Server socket closed\n");

    return 0; // Return 0 to indicate successful completion
}

