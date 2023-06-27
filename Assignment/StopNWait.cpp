#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

// Simulated delay for message transmission
const int TRANS_DELAY_MS = 500;

// Simulated probability of packet loss
const int PACKET_LOSS_PROBABILITY = 20; // 20% probability of packet loss

// Function to simulate message transmission delay
void simulateDelay() {
    std::this_thread::sleep_for(std::chrono::milliseconds(TRANS_DELAY_MS));
}

// Function to simulate packet loss
bool simulatePacketLoss() {
    int randomValue = rand() % 100 + 1; // Generate a random value between 1 and 100
    return randomValue <= PACKET_LOSS_PROBABILITY;
}

// Function to send message from client to server using Stop and Wait protocol
void sendMessage(int message) {
    // Simulate delay for message transmission
    simulateDelay();

    // Simulate packet loss
    if (simulatePacketLoss()) {
        std::cout << "Packet loss occurred for message: " << message << std::endl;
        return;
    }

    // Message successfully received by the server
    std::cout << "Message received by the server: " << message << std::endl;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numMessages;
    std::cout << "Enter the number of messages to send: ";
    std::cin >> numMessages;

    // Send messages one by one
    for (int i = 0; i < numMessages; ++i) {
        int message;
        std::cout << "Enter message " << (i + 1) << ": ";
        std::cin >> message;

        // Send message using Stop and Wait protocol
        sendMessage(message);
    }

    return 0;
}
