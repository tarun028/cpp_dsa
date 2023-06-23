#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class BinarySemaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    bool isAvailable;

public:
    BinarySemaphore() : isAvailable(true) {}

    void Acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        while (!isAvailable)
            cv.wait(lock);
        isAvailable = false;
    }

    void Release() {
        std::unique_lock<std::mutex> lock(mtx);
        isAvailable = true;
        cv.notify_one();
    }
};

BinarySemaphore semaphore; // Initialize binary semaphore

void WorkerThread(int id) {
    semaphore.Acquire(); // Acquire the semaphore before performing work
    std::cout << "Thread " << id << " is performing work." << std::endl;
    // Perform some work here
    semaphore.Release(); // Release the semaphore after completing work
}

int main() {
    const int numThreads = 10;
    std::thread threads[numThreads];

    // Create multiple threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(WorkerThread, i);
    }

    // Start the threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}
