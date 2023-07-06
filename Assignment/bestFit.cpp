#include <iostream>
using namespace std;

struct MemoryBlock {
    int blockId;
    int size;
    bool isAllocated;
};

void bestFit(MemoryBlock blocks[], int numOfBlocks, int requestedSize) {
    int bestFitIndex = -1;
    int minDifference = INT_MAX;

    for (int i = 0; i < numOfBlocks; i++) {
        if (!blocks[i].isAllocated && blocks[i].size >= requestedSize) {
            int difference = blocks[i].size - requestedSize;
            if (difference < minDifference) {
                minDifference = difference;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        blocks[bestFitIndex].isAllocated = true;
        cout << "Memory block " << blocks[bestFitIndex].blockId << " allocated with size " << requestedSize << endl;
    }
    else {
        cout << "Insufficient memory to allocate " << requestedSize << " units" << endl;
    }
}

int main() {
    const int numOfBlocks = 5;
    MemoryBlock blocks[numOfBlocks] = {
        {0, 100, false},
        {1, 200, false},
        {2, 50, false},
        {3, 300, false},
        {4, 150, false}
    };

    int requestedSize;
    cout << "Enter the size of memory to allocate: ";
    cin >> requestedSize;

    bestFit(blocks, numOfBlocks, requestedSize);

    return 0;
}
