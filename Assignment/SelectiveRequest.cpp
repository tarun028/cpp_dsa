#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
const int WINDOW_SIZE = 4;
const int MAX_SEQUENCE_NUM = 8;

class Packet {
public:
    int sequenceNumber;
    std::string data;

    Packet(int sequenceNumber, const std::string& data) : sequenceNumber(sequenceNumber), data(data) {}
};

class Sender {
private:
    std::vector<Packet> packets;
    int nextSequenceNumber;
    int base;

public:
    Sender() : nextSequenceNumber(0), base(0) {}

    void sendPacket() {
        if (nextSequenceNumber < packets.size()) {
            std::cout << "Sending packet: " << packets[nextSequenceNumber].data << std::endl;
            // Simulating transmission delay
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            nextSequenceNumber++;
        }
    }

    void receiveAck(int ackNumber) {
        base = ackNumber + 1;
        std::cout << "Received ACK for packet: " << ackNumber << std::endl;
    }

    void run() {
        while (base < packets.size()) {
            int i = base;
            while (i < base + WINDOW_SIZE && i < packets.size()) {
                sendPacket();
                i++;
            }

            // Simulating random ACK loss
            int random = rand() % 10;
            if (random < 8) { // 80% chance of receiving ACK
                int ackNumber = rand() % WINDOW_SIZE + base;
                receiveAck(ackNumber);
            } else {
                std::cout << "ACK lost." << std::endl;
            }
        }
    }

    void addPacket(const std::string& data) {
        if (nextSequenceNumber < MAX_SEQUENCE_NUM) {
            Packet packet(nextSequenceNumber, data);
            packets.push_back(packet);
            nextSequenceNumber++;
        }
    }
};

int main() {
    srand(time(nullptr));

    Sender sender;

    std::string data;
    std::cout << "Enter data (type 'end' to finish): ";
    std::cin >> data;
    while (data != "end") {
        sender.addPacket(data);
        std::cout << "Enter data (type 'end' to finish): ";
        std::cin >> data;
    }

    sender.run();

    return 1;
}
