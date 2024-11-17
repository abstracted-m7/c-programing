
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345  // Port for listening to broadcasts

int main() {
    int sock;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    socklen_t addrLen = sizeof(serverAddr);

    // Create a UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set up the server address structure to bind to the port
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;  // Listen on all interfaces

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Binding failed");
        close(sock);
        return -1;
    }

    printf("Listening for broadcasts on port %d...\n", PORT);

    // Listen for messages (blocking call)
    while (1) {
        int recvLen = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&serverAddr, &addrLen);
        if (recvLen > 0) {
            buffer[recvLen] = '\0';  // Null-terminate the string
            printf("Received message: %s\n", buffer);
        } else {
            perror("Receive failed");
        }
    }

    // Close the socket
    close(sock);
    return 0;
}