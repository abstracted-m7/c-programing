#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to handle client communication
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    int bytes_read;

    printf("Client connected, socket: %d\n", client_socket);

    while ((bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received from client %d: %s\n", client_socket, buffer);

        // Echo the message back to the client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    if (bytes_read == 0) {
        printf("Client disconnected, socket: %d\n", client_socket);
    } else {
        perror("recv");
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, *client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        client_socket = malloc(sizeof(int));
        if (client_socket == NULL) {
            perror("Memory allocation failed");
            continue;
        }

        *client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (*client_socket == -1) {
            perror("Accept failed");
            free(client_socket);
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, handle_client, client_socket) != 0) {
            perror("Thread creation failed");
            free(client_socket);
            continue;
        }

        // Detach the thread to handle its own cleanup
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}




// Output: 
// Server is listening on port 8080
// Connection accepted from 127.0.0.1:50001
// Client connected, socket: 4
// Received from client 4: Hello, Server 1
// Received from client 4: How are you?
// Client disconnected, socket: 4
// Connection accepted from 127.0.0.1:50002
// Client connected, socket: 5
// Received from client 5: Hello, Server 2
// Client disconnected, socket: 5
// Connection accepted from 127.0.0.1:50003
// Client connected, socket: 6
// Received from client 6: Hello, Server 3
// Received from client 6: Goodbye
// Client disconnected, socket: 6
