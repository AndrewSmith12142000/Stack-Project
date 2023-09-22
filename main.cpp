/*
 * your header here
 * 
 */

#include "main.h"

int main(int argc, char **argv) {
    
    const int stackSize = 10; 
	const int MULTIPLIER = 2; 
	
    void rand_string(std::string* str);
    std::srand(time(nullptr));

    int stackSizes = stackSize;
   
    // Check if a command line argument
    if (argc > 1) {
        try {
            stackSizes = std::stoi(argv[1]);

            if (stackSizes < 2) {
                std::cerr << "Stack size must be 2 or greater. Using default size of 10." << std::endl;
                stackSizes = stackSize; 
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument. Please enter an integer for the stack size." << std::endl;
            return 1; 
        } catch (const std::out_of_range& e) {
            std::cerr << "Argument out of range. Please enter a smaller integer for the stack size." << std::endl;
            return 1; 
        }
    }
    Stack stack(stackSizes);

    // Test for Empty
    std::cout << "Beginning tests..." << std::endl << std::endl << "Testing empty operations." << std::endl;
    std::cout << "=====================================================" << std::endl;

    // Testing isEmpty() on an empty stack
    if (stack.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is NOT empty" << std::endl;
    }

    Data peekedData;
    if (stack.peek(peekedData)) {
        std::cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << std::endl;
    } else {
        std::cout << "Peek underflow error: Stack is empty" << std::endl;
    }

    try {
        Data poppedData;
        stack.pop(poppedData);
        std::cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Pop underflow error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    // Testing for filling and full

    std::cout << "Testing full operations." << std::endl;
    std::cout << "=====================================================" << std::endl;

    // Testing filling the stack and overflow
    std::cout << "Filling stack..." << std::endl;
    for (int i = 0; i < stackSize * MULTIPLIER; i++) {
    int id = i + 1;
    std::string info;
    rand_string(&info); 
    if (stack.push(id, info)) { 
        std::cout << "Pushed: ID=" << id << ", Info=" << info << std::endl;
    } else {
        std::cout << "Overflow error: ID=" << id << " not pushed" << std::endl;
    }
}
    std::cout << std::endl;

    // Testing isEmpty() on a full stack
    if (stack.isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << "Stack is NOT empty" << std::endl;
    }
    std::cout << std::endl;

    // Testing for peek and pop on a full stack
    if (stack.peek(peekedData)) {
        std::cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << std::endl;
    } else {
        std::cout << "Peek underflow error: Stack is empty" << std::endl;
    }

    try {
        Data poppedData;
        stack.pop(poppedData);
        std::cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Pop underflow error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Dump stack output
    std::cout << "Dumping stack..." << std::endl;
    std::cout << "=====================================================" << std::endl;
    stack.dumpStack();

}
