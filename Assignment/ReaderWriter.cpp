#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable readerCV, writerCV;
int activeReaders = 0;
bool writerActive = false;
int sharedData = 0;
int numIterations = 10;  // Number of iterations before stopping

void Reader()
{
    while (numIterations > 0)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (writerActive)
            readerCV.wait(lock);
        ++activeReaders;
        lock.unlock();

        // Reading the shared data
        std::cout << "Reader: " << std::this_thread::get_id() << " reads data: " << sharedData << std::endl;

        lock.lock();
        --activeReaders;
        if (activeReaders == 0)
            writerCV.notify_one();
        lock.unlock();

        // Simulating some delay
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        --numIterations;
    }
}

void Writer()
{
    while (numIterations > 0)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (writerActive || activeReaders > 0)
            writerCV.wait(lock);
        writerActive = true;
        lock.unlock();

        // Writing to the shared data
        ++sharedData;
        std::cout << "Writer: " << std::this_thread::get_id() << " writes data: " << sharedData << std::endl;

        lock.lock();
        writerActive = false;
        readerCV.notify_all();
        writerCV.notify_one();
        lock.unlock();

        // Simulating some delay
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        --numIterations;
    }
}

int main()
{
    const int numReaders = 3;
    const int numWriters = 2;

    std::thread readerThreads[numReaders];
    std::thread writerThreads[numWriters];

    // Create reader threads
    for (int i = 0; i < numReaders; ++i)
    {
        readerThreads[i] = std::thread(Reader);
    }

    // Create writer threads
    for (int i = 0; i < numWriters; ++i)
    {
        writerThreads[i] = std::thread(Writer);
    }

    // Start reader threads
    for (int i = 0; i < numReaders; ++i)
    {
        readerThreads[i].join();
    }

    // Start writer threads
    for (int i = 0; i < numWriters; ++i)
    {
        writerThreads[i].join();
    }

    return 0;
}
