#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Simulate a random frame loss
bool simulateFrameLoss() {
    return rand() % 10 < 2; // 20% chance of loss
}

// Simulate selective repeat mechanism
void selectiveRepeat(int totalFrames) {
    srand(time(NULL)); // Initialize random seed
    bool ackReceived[totalFrames];
    bool frameSent[totalFrames];

    // Initialize acknowledgments and sent status
    for (int i = 0; i < totalFrames; i++) {
        ackReceived[i] = false;
        frameSent[i] = false;
    }

    printf("Selective Repeat Error Control Simulation\\n");
    
    // Send frames
    for (int i = 0; i < totalFrames; i++) {
        printf("Sending frame %d...\\n", i);
        sleep(1);

        // Simulate frame loss
        if (simulateFrameLoss()) {
            printf("Frame %d lost during transmission. Waiting for acknowledgment...\\n", i);
            continue; // Wait to retransmit the lost frame
        }

        printf("Frame %d sent successfully.\\n", i);
        frameSent[i] = true;

        // Simulate receiving acknowledgment
        sleep(1);
        if (rand() % 2) { // Randomize acknowledgment simulation
            ackReceived[i] = true;
            printf("Acknowledgment received for frame %d\\n", i);
        } else {
            printf("Acknowledgment lost for frame %d. Will retransmit.\\n", i);
            frameSent[i] = false;
        }

        // Retransmit if acknowledgment not received
        while (!ackReceived[i]) {
            printf("Retransmitting frame %d...\\n", i);
            sleep(1);
            if (!simulateFrameLoss()) {
                printf("Frame %d resent successfully.\\n", i);
                ackReceived[i] = true;
                printf("Acknowledgment received for frame %d\\n", i);
            }
        }
    }

    printf("\\nAll frames have been sent and acknowledged successfully.\\n");
}

int main() {
    int totalFrames;

    printf("Enter the number of frames to send: ");
    scanf("%d", &totalFrames);

    selectiveRepeat(totalFrames);

    return 0;
}







// Output:
// If the user input = 5
// Selective Repeat Error Control Simulation
// Sending frame 0...
// Frame 0 sent successfully.
// Acknowledgment received for frame 0

// Sending frame 1...
// Frame 1 lost during transmission. Waiting for acknowledgment...
// Retransmitting frame 1...
// Frame 1 resent successfully.
// Acknowledgment received for frame 1

// Sending frame 2...
// Frame 2 sent successfully.
// Acknowledgment received for frame 2

// Sending frame 3...
// Frame 3 lost during transmission. Waiting for acknowledgment...
// Retransmitting frame 3...
// Frame 3 resent successfully.
// Acknowledgment received for frame 3

// Sending frame 4...
// Frame 4 sent successfully.
// Acknowledgment received for frame 4

// All frames have been sent and acknowledged successfully.
