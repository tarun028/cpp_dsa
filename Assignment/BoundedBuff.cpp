#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int BUFFER_SIZE = 10;
int buffer[BUFFER_SIZE];
int producerIndex = 0;
int consumerIndex = 0;
int itemCount = 0;
std::mutex mtx;
std::condition_variable producerCV, consumerCV;

void Producer()
{
    for (int i = 0; i < 10; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (itemCount == BUFFER_SIZE)
            producerCV.wait(lock);
        buffer[producerIndex] = i;
        producerIndex = (producerIndex + 1) % BUFFER_SIZE;
        ++itemCount;
        consumerCV.notify_one();
        lock.unlock();
    }
}

void Consumer()
{
    for (int i = 0; i < 10; ++i)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (itemCount == 0)
            consumerCV.wait(lock);
        int item = buffer[consumerIndex];
        consumerIndex = (consumerIndex + 1) % BUFFER_SIZE;
        --itemCount;
        producerCV.notify_one();
        lock.unlock();
        std::cout << "Consumed: " << item << std::endl;
    }
}

int main()
{
    const int numProducers = 2;
    const int numConsumers = 3;

    std::thread producerThreads[numProducers];
    std::thread consumerThreads[numConsumers];

    // Create producer threads
    for (int i = 0; i < numProducers; ++i)
    {
        producerThreads[i] = std::thread(Producer);
    }

    // Create consumer threads
    for (int i = 0; i < numConsumers; ++i)
    {
        consumerThreads[i] = std::thread(Consumer);
    }

    // Start producer threads
    for (int i = 0; i < numProducers; ++i)
    {
        producerThreads[i].join();
    }

    // Start consumer threads
    for (int i = 0; i < numConsumers; ++i)
    {
        consumerThreads[i].join();
    }

    return 0;
}
