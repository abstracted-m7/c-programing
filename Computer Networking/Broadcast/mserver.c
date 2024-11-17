

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345  // Port for broadcasting
#define BROADCAST_IP "255.255.255.255"  // Broadcast IP address

int main() {
    int sock;
    struct sockaddr_in broadcastAddr;
    int broadcastPermission = 1;
    char message[] = "This is a broadcast message!";

    // Create a UDP socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Allow the socket to send broadcast messages
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcastPermission, sizeof(broadcastPermission)) < 0) {
        perror("Setting broadcast permission failed");
        close(sock);
        return -1;
    }

    // Set up the broadcast address
    memset(&broadcastAddr, 0, sizeof(broadcastAddr));
    broadcastAddr.sin_family = AF_INET;
    broadcastAddr.sin_port = htons(PORT);
    broadcastAddr.sin_addr.s_addr = inet_addr(BROADCAST_IP);  // Broadcast to all devices

    // Broadcast the message
    if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&broadcastAddr, sizeof(broadcastAddr)) < 0) {
        perror("Broadcast send failed");
        close(sock);
        return -1;
    }

    printf("Broadcast message sent: %s\n", message);

    // Close the socket
    close(sock);
    return 0;
}
