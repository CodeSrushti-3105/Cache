#include <iostream>
using namespace std;

#define MAX_PAGES 20 // Define a maximum limit for pages

// Function to simulate FIFO page replacement algorithm
void fifoPageReplacement(int frames, int pages[], int numPages) {
    int frame[MAX_PAGES]; // Array to hold the pages in frames (initialized to empty)
    int pageFaults = 0;
    int front = 0; // Pointer to the front of the queue

    // Initialize frames with -1 to indicate they are empty
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    cout << "Page Replacement using FIFO:" << endl;
    cout << "Frames: " << frames << endl;
    cout << "Pages: ";
    for (int i = 0; i < numPages; i++) {
        cout << pages[i] << " ";
    }
    cout << endl;

    // Iterate over each page in the reference string
    for (int i = 0; i < numPages; i++) {
        bool found = false;
        
        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true; // Page found, no page fault
                break;
            }
        }

        // If the page is not found in frames, we have a page fault
        if (!found) {
            // Page fault: Add new page to available frame or replace oldest one
            frame[front % frames] = pages[i]; // Circular replacement using modulo
            front++;
            pageFaults++;
        }

        // Print the current state of frames after each page reference
        cout << "Page " << pages[i] << ": ";
        for (int j = 0; j < frames; j++) {
            if (frame[j] == -1)
                cout << "- ";
            else
                cout << frame[j] << " ";
        }
        cout << endl;
    }

    // Print the total number of page faults
    cout << "Total Page Faults: " << pageFaults << endl;
}

int main() {
    int frames = 3; // Number of frames in main memory
    int pages[] = {1, 2, 3, 4, 2, 1, 5, 6}; // Pages to be loaded
    int numPages = sizeof(pages) / sizeof(pages[0]); // Calculate the number of pages

    // Call the FIFO page replacement function
    fifoPageReplacement(frames, pages, numPages);

    return 0;
}


/*Page Replacement using FIFO:
Frames: 3
Pages: 1 2 3 4 2 1 5 6 
Page 1: 1 - - 
Page 2: 1 2 - 
Page 3: 1 2 3 
Page 4: 4 2 3 
Page 2: 4 2 3 
Page 1: 4 1 3 
Page 5: 4 1 5 
Page 6: 6 1 5 
Total Page Faults: 7*/
