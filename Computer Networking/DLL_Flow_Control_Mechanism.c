// Stop & wait mechanism

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Simulate sending and receiving frames using Stop-and-Wait
void stop_and_wait() {
    int frame = 0;
    int acknowledgment;
    srand(time(NULL)); // Initialize random seed

    printf("Stop-and-Wait Flow Control Simulation\n");

    while (frame < 5) { // Simulate sending 5 frames
        printf("Sending Frame %d...\n", frame);

        // Simulate a random delay or loss
        int success = rand() % 2;

        if (success) {
            printf("Frame %d sent successfully.\n", frame);
            printf("Waiting for Acknowledgment...\n");

            sleep(1); // Simulate delay for acknowledgment
            acknowledgment = frame;
            printf("Acknowledgment received for Frame %d.\n\n", acknowledgment);

            frame++; // Move to the next frame
        } else {
            printf("Frame %d lost during transmission. Resending...\n\n", frame);
        }

        sleep(1); // Simulate time between retries
    }

    printf("All frames sent and acknowledged successfully!\n");
}

int main() {
    stop_and_wait();
    return 0;
}






// Output:
// Stop-and-Wait Flow Control Simulation
// Sending Frame 0...
// Frame 0 sent successfully.
// Waiting for Acknowledgment...
// Acknowledgment received for Frame 0.

// Sending Frame 1...
// Frame 1 lost during transmission. Resending...

// Sending Frame 1...
// Frame 1 sent successfully.
// Waiting for Acknowledgment...
// Acknowledgment received for Frame 1.

// ...
// All frames sent and acknowledged successfully!
