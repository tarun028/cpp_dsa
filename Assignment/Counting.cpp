#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class CountingSemaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;

public:
    CountingSemaphore(int initialCount) : count(initialCount) {}

    void Acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        while (count <= 0)
            cv.wait(lock);
        count--;
    }

    void Release() {
        std::unique_lock<std::mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

CountingSemaphore semaphore(5); // Initialize semaphore with an initial count of 5

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
