#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int optPageReplacement(vector<int> pageRequests, int numFrames) {
    unordered_set<int> frameSet;
    vector<int> frames(numFrames, -1); // -1 represents an empty frame

    int pageFaults = 0;

    for (int i = 0; i < pageRequests.size(); i++) {
        int currentPage = pageRequests[i];

        // Check if the page is already in a frame
        if (frameSet.find(currentPage) != frameSet.end()) {
            continue; // Page hit, no page fault
        }

        pageFaults++;

        // Check if there is an empty frame available
        if (frameSet.size() < numFrames) {
            frameSet.insert(currentPage);
            frames[frameSet.size() - 1] = currentPage;
        } else {
            // Find the page that will be accessed furthest in the future
            int farthestPage = -1;
            int farthestIndex = -1;
            for (int j = 0; j < numFrames; j++) {
                int nextPageIndex = i + 1;
                while (nextPageIndex < pageRequests.size()) {
                    if (frames[j] == pageRequests[nextPageIndex]) {
                        if (nextPageIndex > farthestIndex) {
                            farthestPage = j;
                            farthestIndex = nextPageIndex;
                        }
                        break;
                    }
                    nextPageIndex++;
                }
                if (nextPageIndex == pageRequests.size()) {
                    farthestPage = j;
                    break;
                }
            }

            // Replace the farthest page with the current page
            frameSet.erase(frames[farthestPage]);
            frameSet.insert(currentPage);
            frames[farthestPage] = currentPage;
        }
    }

    return pageFaults;
}

int main() {
    vector<int> pageRequests = {1, 2, 3, 4, 1, 5, 6, 2, 7, 8, 7, 8, 9, 7, 8, 9, 5, 4, 5, 4, 2};

    int numFrames;
    cout << "Enter the number of page frames: ";
    cin >> numFrames;

    int pageFaults = optPageReplacement(pageRequests, numFrames);

    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
