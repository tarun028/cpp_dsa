#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

void fifoPageReplacement(int pageRequests[], int numRequests, int numFrames) {
    queue<int> pageQueue;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int i = 0; i < numRequests; i++) {
        int currentPage = pageRequests[i];

        // Check if the page is already in the page set
        if (pageSet.find(currentPage) != pageSet.end()) {
            continue; // Page hit, no page fault
        }

        pageFaults++;

        // Check if the page queue is full
        if (pageQueue.size() == numFrames) {
            int oldestPage = pageQueue.front();
            pageQueue.pop();
            pageSet.erase(oldestPage);
        }

        // Add the new page to the page queue and set
        pageQueue.push(currentPage);
        pageSet.insert(currentPage);
    }

    cout << "Total page faults: " << pageFaults << endl;
}

int main() {
    int pageRequests[] = {1, 2, 3, 4, 1, 5, 6, 2, 7, 8, 7, 8, 9, 7, 8, 9, 5, 4, 5, 4, 2};
    int numRequests = sizeof(pageRequests) / sizeof(pageRequests[0]);
    int numFrames;

    cout << "Enter the number of page frames: ";
    cin >> numFrames;

    fifoPageReplacement(pageRequests, numRequests, numFrames);

    return 0;
}
