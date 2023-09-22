/*
 Name: Andrew Smith
 Coding 04
 Purpose: This is suppose to show the output of the stack and shows if its successfull or not
 File: main.cpp
 *
 */

#include "main.h"

int main(int argc, char **argv) {
    
    const int stackSize = 10; 
	const int MULTIPLIER = 2; 
	
    void rand_string(string* str);
    srand(time(nullptr));

    int stackSizes = stackSize;
   
    // Check if a command line argument
    if (argc > 1) {
        try {
            stackSizes = std::stoi(argv[1]);

            if (stackSizes < 2) {
                std::cerr << "Stack size must be 2 or greater. Using default size of 10." << endl;
                stackSizes = stackSize; 
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument. Please enter an integer for the stack size." << endl;
            return 1; 
        } catch (const std::out_of_range& e) {
            std::cerr << "Argument out of range. Please enter a smaller integer for the stack size." << endl;
            return 1; 
        }
    }
    Stack stack(stackSizes);

    // Test for Empty
    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // Testing isEmpty() on an empty stack
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is NOT empty" << endl;
    }

    Data peekedData;
    if (stack.peek(peekedData)) {
        cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << endl;
    } else {
        cout << "Peek underflow error: Stack is empty" << endl;
    }

    try {
        Data poppedData;
        stack.pop(poppedData);
        cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << endl;
    } catch (const std::exception& e) {
        cout << "Pop underflow error: " << e.what() << endl;
    }
    cout << endl;
    
    // Testing for filling and full

    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    // Testing filling the stack and overflow
    cout << "Filling stack..." << endl;
    for (int i = 0; i < stackSize * MULTIPLIER; i++) {
    int id = i + 1;
    string info;
    rand_string(&info); 
    if (stack.push(id, info)) { 
        cout << "Pushed: ID=" << id << ", Info=" << info << endl;
    } else {
        cout << "Overflow error: ID=" << id << " not pushed" << endl;
    }
}
    std::cout << std::endl;

    // Testing isEmpty() on a full stack
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is NOT empty" << endl;
    }
    cout << endl;

    // Testing for peek and pop on a full stack
    if (stack.peek(peekedData)) {
        cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << endl;
    } else {
        cout << "Peek underflow error: Stack is empty" << endl;
    }

    try {
        Data poppedData;
        stack.pop(poppedData);
        cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << endl;
    } catch (const std::exception& e) {
        cout << "Pop underflow error: " << e.what() << endl;
    }
    cout << endl;

    // Dump stack output
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();
    
      // Empty Test
    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // Testing for popping and peeking 
    for (int i = 0; i < MULTIPLIER * stackSize; i++) {
        if (stack.peek(peekedData)) {
            cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << endl;
        } else {
            cout << "Peek underflow error: Stack is empty" << endl;
        }

        try {
            Data poppedData;
            stack.pop(poppedData);
            cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << endl;
        } catch (const std::exception& e) {
            cout << "Pop underflow error: " << e.what() << endl;
        }
    }
    std::cout << std::endl;

    // Dumping stack output
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();

    // Testing isEmpty
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is NOT empty" << endl;
    }

    // Testing for peek and pop on a stack that is empty
    if (stack.peek(peekedData)) {
        cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << endl;
    } else {
        cout << "Peek underflow error: Stack is empty" << endl;
    }

    try {
        Data poppedData;
        stack.pop(poppedData);
        cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << endl;
    } catch (const std::exception& e) {
        cout << "Pop underflow error: " << e.what() << endl;
    }
    cout << endl;
    
     //Testing for mid stack
    cout << "Filling stack halfway and testing the middle of the stack..." << endl;
    cout << "============================================================" << endl;

    // filling the stack half way
    for (int i = 0; i < stackSize / 2; i++) {
    int id = i + 1;
    string info;
    rand_string(&info); 
    if (stack.push(id, info)) { 
        cout << "Pushed: ID=" << id << ", Info=" << info << endl;
	} else {
        cout << "Overflow error: ID=" << id << " not pushed" << endl;
    	}
	}
	
	// Generate and push random strings
	cout << "Generating and pushing random strings:" << endl;
	cout << "============================================================" << endl;

	for (int i = 0; i < stackSize * MULTIPLIER; i++) {
    	int id = i + 1;
    	string info;
    	rand_string(&info); // Pass a pointer to a string variable
    	if (stack.push(id, info)) {
    		cout << "Pushed: ID=" << id << ", Info=" << info << endl;
    	} else {
        	cout << "Overflow error: ID=" << id << " not pushed" << endl;
    	}
	}


    cout << "Testing rand_string:" << endl;
    cout << "=====================================================" << endl;

    for (int i = 0; i < 10; ++i) {
        string randomStr;
        rand_string(&randomStr);
        cout << "Random String " << i << ": " << randomStr << endl;
    }

    return 0;
}
