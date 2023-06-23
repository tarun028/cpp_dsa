#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int BUFFER_SIZE = 10;
int buffer[BUFFER_SIZE];
int itemCount = 0;
int producerIndex = 0;
int consumerIndex = 0;
std::mutex mtx;
std::condition_variable producerCV, consumerCV;

void producer()
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

void consumer()
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
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
