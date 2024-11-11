 #include <iostream>
 using namespace std;
 int findLRU(int time[], int capacity) {
 int minimum = time[0], pos = 0;
 for (int i = 1; i < capacity; ++i) {
 if (time[i] < minimum) {
 minimum = time[i];
 pos = i;
 }
 }
 return pos;
 }
 void lruPageReplacement(int pages[], int n, int capacity) {
 int frames[capacity];
 int time[capacity];
 int page_faults = 0;
 // Initialize frames and time arrays
 for (int i = 0; i < capacity; ++i) {
 frames[i] =-1;
 time[i] = 0;
 }
 for (int i = 0; i < n; ++i) {
 //-1 indicates an empty frame
 // Initial time
bool page_found = false;
 // Check if the page is already in one of the frames
 for (int j = 0; j < capacity; ++j) {
 if (frames[j] == pages[i]) {
 page_found = true;
 time[j] = i + 1; // Update the time for the page
 break;
 }
 }
 // If the page is not found in frames
 if (!page_found) {
 int pos = findLRU(time, capacity); // Find LRU position
 frames[pos] = pages[i];
 time[pos] = i + 1;
 // Replace LRU page
 // Update time
 page_faults++;
 }
 // Print current frames
 cout << "Frames after page " << pages[i] << ": ";
 for (int j = 0; j < capacity; ++j) {
 if (frames[j] ==-1) {
 cout << "- ";
 } else {
 cout << frames[j] << " ";
 }
}
 cout << endl;
 }
 cout << "Total Page Faults: " << page_faults << endl;
 }
 int main() {
 int pages[] = {1, 2, 3, 4, 5, 3, 4, 1, 6, 7};
 int n = sizeof(pages) / sizeof(pages[0]);
 int capacity = 3;
 cout << "LRU Page Replacement Algorithm Simulation" << endl;
 lruPageReplacement(pages, n, capacity);
 return 0;
 }
 /*OUTPUT
 LRUPage Replacement Algorithm Simulation
 Frames after page 1: 1--
 Frames after page 2: 1 2
Frames after page 3: 1 2 3
 Frames after page 4: 4 2 3
 Frames after page 5: 4 5 3
 Frames after page 3: 4 5 3
 Frames after page 4: 4 5 3
Frames after page 1: 4 1 3
 Frames after page 6: 4 1 6
 Frames after page 7: 7 1 6
 Total Page Faults: 8*/