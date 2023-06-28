#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>

class DFA {
private:
    int numStates;
    std::unordered_map<char, std::vector<int>> transitions;
    std::set<int> acceptingStates;
    int startState;
    
public:
    DFA(int states) : numStates(states) {}
    
    void addTransition(int fromState, char symbol, int toState) {
        transitions[symbol].push_back(toState);
    }
    
    void setAcceptingState(int state) {
        acceptingStates.insert(state);
    }
    
    void setStartState(int state) {
        startState = state;
    }
    
    bool isAcceptingState(int state) {
        return acceptingStates.count(state) > 0;
    }
    
    int getStartState() {
        return startState;
    }
    
    int transition(int state, char symbol) {
        if (transitions.find(symbol) != transitions.end()) {
            std::vector<int> states = transitions[symbol];
            for (int s : states) {
                if (s == state) {
                    return s;
                }
            }
        }
        return -1;
    }
};

int main() {
    // DFA construction
    DFA dfa(4);
    
    // Set start state
    dfa.setStartState(0);
    
    // Set accepting states
    dfa.setAcceptingState(3);
    
    // Add transitions
    dfa.addTransition(0, 'a', 1);
    dfa.addTransition(1, 'b', 2);
    dfa.addTransition(2, 'c', 3);
    
    // Test the DFA with some input strings
    std::vector<std::string> inputStrings = {"abc", "ab", "abcd"};
    
    for (const std::string& input : inputStrings) {
        int currentState = dfa.getStartState();
        
        for (char symbol : input) {
            currentState = dfa.transition(currentState, symbol);
            if (currentState == -1) {
                break;
            }
        }
        
        if (dfa.isAcceptingState(currentState)) {
            std::cout << input << " is accepted" << std::endl;
        } else {
            std::cout << input << " is not accepted" << std::endl;
        }
    }
    
    return 0;
}
