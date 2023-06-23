#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int numPhilosophers = 5;
std::mutex chopsticks[numPhilosophers];
std::condition_variable cv;

void Think(int philosopherId)
{
    std::cout << "Philosopher " << philosopherId << " is thinking." << std::endl;
    // Simulating thinking by introducing a delay
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Eat(int philosopherId)
{
    std::cout << "Philosopher " << philosopherId << " is eating." << std::endl;
    // Simulating eating by introducing a delay
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void GetChopsticks(int philosopherId)
{
    int leftChopstick = philosopherId;
    int rightChopstick = (philosopherId + 1) % numPhilosophers;

    std::unique_lock<std::mutex> lock(chopsticks[leftChopstick]);
    cv.wait(lock, [rightChopstick]() { return !chopsticks[rightChopstick].try_lock(); });
    lock.unlock();

    chopsticks[rightChopstick].lock();
}

void PutChopsticks(int philosopherId)
{
    int leftChopstick = philosopherId;
    int rightChopstick = (philosopherId + 1) % numPhilosophers;

    chopsticks[leftChopstick].unlock();
    chopsticks[rightChopstick].unlock();

    cv.notify_all();
}

void Philosopher(int philosopherId)
{
    while (true)
    {
        Think(philosopherId);
        GetChopsticks(philosopherId);
        Eat(philosopherId);
        PutChopsticks(philosopherId);
    }
}

int main()
{
    std::thread philosophers[numPhilosophers];

    // Create philosopher threads
    for (int i = 0; i < numPhilosophers; ++i)
    {
        philosophers[i] = std::thread(Philosopher, i);
    }

    // Start philosopher threads
    for (int i = 0; i < numPhilosophers; ++i)
    {
        philosophers[i].join();
    }

    return 0;
}
