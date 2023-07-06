#include <iostream>
using namespace std;

struct MemoryBlock {
    int blockId;
    int size;
    bool isAllocated;
};

void firstFit(MemoryBlock blocks[], int numOfBlocks, int requestedSize) {
    for (int i = 0; i < numOfBlocks; i++) {
        if (!blocks[i].isAllocated && blocks[i].size >= requestedSize) {
            blocks[i].isAllocated = true;
            cout << "Memory block " << blocks[i].blockId << " allocated with size " << requestedSize << endl;
            return;
        }
    }
    cout << "Insufficient memory to allocate " << requestedSize << " units" << endl;
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

    firstFit(blocks, numOfBlocks, requestedSize);

    return 0;
}
