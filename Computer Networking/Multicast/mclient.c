#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // For close()

#define PORT 8080
#define SERVER_IP "127.0.0.1" // Change this to your server's IP address if needed
#define BUF_SIZE 1024

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[BUF_SIZE];
    const char *message = "Hello from client!";

    // Create the socket
    clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Send messages continuously
    while (1) {
        // Send a message to the server
        if (sendto(clientSocket, message, strlen(message), 0,
                   (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
            perror("Send failed");
        } else {
            printf("Message sent to server: %s\n", message);
        }

        // Wait for a response from the server
        socklen_t addr_size = sizeof(serverAddr);
        int recv_len = recvfrom(clientSocket, buffer, BUF_SIZE, 0,
                                (struct sockaddr*)&serverAddr, &addr_size);
        if (recv_len < 0) {
            perror("Receive failed");
        } else {
            buffer[recv_len] = '\0'; // Null-terminate the received data
            printf("Received from server: %s\n", buffer);
        }

        // Sleep for a bit to avoid flooding the server
        usleep(1000000); // Sleep for 1 second
    }

    // Close the socket (this will never be reached in this infinite loop)
    close(clientSocket);
    printf("Client socket closed\n");

    return 0; // Return 0 to indicate successful completion
}

