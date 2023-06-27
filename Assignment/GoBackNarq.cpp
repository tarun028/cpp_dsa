#include <iostream>
#include <vector>
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

// Function to send message from client to server using Go-Back-N ARQ protocol
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

    int windowSize;
    std::cout << "Enter the window size: ";
    std::cin >> windowSize;

    int numMessages;
    std::cout << "Enter the number of messages to send: ";
    std::cin >> numMessages;

    std::vector<int> messages(numMessages);
    for (int i = 0; i < numMessages; ++i) {
        std::cout << "Enter message " << (i + 1) << ": ";
        std::cin >> messages[i];
    }

    // Send messages using Go-Back-N ARQ protocol
    int base = 0;
    int nextSeqNum = 0;

    while (base < numMessages) {
        int end = std::min(base + windowSize, numMessages);

        // Send messages within the window
        for (int i = base; i < end; ++i) {
            sendMessage(messages[i]);
            ++nextSeqNum;
        }

        // Receive ACKs from server
        for (int i = base; i < end; ++i) {
            // Simulate delay for ACK transmission
            simulateDelay();

            // Simulate packet loss for ACKs
            if (simulatePacketLoss()) {
                std::cout << "ACK loss occurred for message: " << messages[i] << std::endl;
                --nextSeqNum; // Retransmit the lost message
                continue;
            }

            // ACK received, move the base
            std::cout << "ACK received for message: " << messages[i] << std::endl;
            ++base;
        }
    }

    return 0;
}
