#include <stdio.h>


int mutex = 1;     // A variable used to simulate a mutex lock
int full = 0;      // Tracks the number of filled slots in the buffer
int empty = 10;    // Tracks the number of empty slots (buffer size is 10)
int x = 0;         // Represents the item being produced/consumed

// Producer function
void producer() {
    --mutex;       // Lock (simulates locking by decrementing mutex)

    ++full;        // Increment the count of filled slots
    --empty;       // Decrement the count of empty slots
    x++;           // Increment the item count (produce a new item)
    printf("\nProducer produces item %d", x);

    ++mutex;       // Unlock (simulates unlocking by incrementing mutex)
}

// Consumer function
void consumer() {
    --mutex;       // Lock

    --full;        // Decrement the count of filled slots
    ++empty;       // Increment the count of empty slots
    printf("\nConsumer consumes item %d", x);
    x--;           // Decrement the item count (consume an item)

    ++mutex;       // Unlock
}

int main() {
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {  // Check if buffer has space and is unlocked
                    producer();
                } else {
                    printf("Buffer is full!");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {  // Check if buffer has items and is unlocked
                    consumer();
                } else {
                    printf("Buffer is empty!");
                }
                break;

            case 3:
                exit(0);  // Exit the program
                break;

            default:
                printf("Invalid choice! Please enter 1, 2, or 3.");
                break;
        }
    }
}
