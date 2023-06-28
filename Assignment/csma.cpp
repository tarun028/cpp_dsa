#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>


// Function to simulate random backoff time
void simulateBackoffTime()
{
    int backoffTime = rand() % 10;
    std::cout << "Backoff Time: " << backoffTime << " units" << std::endl;
    for (int i = 0; i < backoffTime; ++i) {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(std::time(nullptr));  // Seed the random number generator

    int numStations;
    std::cout << "Enter the number of stations: ";
    std::cin >> numStations;

    int collisionCount = 0;
    for (int i = 0; i < numStations; ++i) {
        std::cout << "Station " << i+1 << " is attempting to transmit..." << std::endl;
        simulateBackoffTime();
        if (collisionCount < 10) {
            std::cout << "Transmission successful for Station " << i+1 << std::endl;
        } else {
            std::cout << "Exceeded maximum collision attempts for Station " << i+1 << std::endl;
        }
        ++collisionCount;
        std::cout << std::endl;
    }

    return 0;
}
