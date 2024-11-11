#include <iostream>
using namespace std;

// Function to find the optimal page to replace
int findOptimal(int pages[], int n, int frames[], int capacity, int currentIndex) {
    int farthest = currentIndex;
    int pos = -1;
    
    // Iterate over all frames to find the best page to replace
    for (int i = 0; i < capacity; ++i) {
        // If the frame is empty, return it immediately
        if (frames[i] == -1) {
            return i;
        }

        // Find the next occurrence of the frame's page in the future reference list
        int j;
        for (j = currentIndex; j < n; ++j) {
            if (frames[i] == pages[j]) {
                // Found the page in future references
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        
        // If the page is not found in future references, return this frame
        if (j == n) {
            return i;
        }
    }
    return pos;
}

// Function to implement the Optimal Page Replacement algorithm
void optimalPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity]; // Array to hold pages in frames
    int page_faults = 0;

    // Initialize the frames array to -1 (empty frames)
    for (int i = 0; i < capacity; ++i) {
        frames[i] = -1;
    }

    // Iterate through each page in the reference string
    for (int i = 0; i < n; ++i) {
        bool page_found = false;
        
        // Check if the page is already in one of the frames
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == pages[i]) {
                page_found = true; // Page found, no page fault
                break;
            }
        }

        // If the page is not found in the frames, we have a page fault
        if (!page_found) {
            int pos = findOptimal(pages, n, frames, capacity, i); // Find the optimal position to replace
            frames[pos] = pages[i];
            page_faults++;
        }

        // Print the current state of frames after each page reference
        cout << "Frames after page " << pages[i] << ": ";
        for (int j = 0; j < capacity; ++j) {
            if (frames[j] == -1) {
                cout << "- "; // Indicating an empty frame
            } else {
                cout << frames[j] << " ";
            }
        }
        cout << endl;
    }

    // Print the total number of page faults
    cout << "Total Page Faults: " << page_faults << endl;
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Reference string
    int n = sizeof(pages) / sizeof(pages[0]); // Number of pages
    int capacity = 3; // Number of frames in main memory

    cout << "Optimal Page Replacement Algorithm Simulation" << endl;
    optimalPageReplacement(pages, n, capacity);

    return 0;
}
