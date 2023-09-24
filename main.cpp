/*
 Name: Andrew Smith
 Coding 04
 Purpose: This is suppose to show the output of the stack and shows if its successfull or not
 File: main.cpp
 *
 */

#include "main.h"


int main(int argc, char **argv) {
    void rand_string(string* str);
    srand(time(nullptr));

    int stackSizes = STACKSIZE;
   
    // Check if a command line argument
    if (argc > 1) {
        try {
            stackSizes = std::stoi(argv[1]);

            if (stackSizes < 2) {
                std::cerr << "Stack size must be 2 or greater. Using default size of 10." << endl;
                stackSizes = STACKSIZE; 
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument. Please enter an integer for the stack size." << endl;
            
        } catch (const std::out_of_range& e) {
            std::cerr << "Argument out of range. Please enter a smaller integer for the stack size." << endl;
            
        }
    } else {
        std::cerr << "No stack size argument provided. Please enter an integer for the stack size." << endl;
        return 1; // Exits the command for no number. Return needed
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
    for (int i = 0; i < STACKSIZE * MULTIPLIER; i++) {
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
    
      // Empty Test
    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // Testing for popping and peeking 
    for (int i = 0; i < MULTIPLIER * STACKSIZE; i++) {
    	if (!stack.isEmpty()) {
        	if (stack.peek(peekedData)) {
            	cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << endl;
        	} else {
            	cout << "Peek error" << endl;
        	}

        	try {
            	Data poppedData;
            	stack.pop(poppedData);
            	cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << endl;
        	} catch (const std::exception& e) {
            	cout << "Pop error: " << e.what() << endl;
        	}
    	} else {
        	cout << "Stack is empty" << endl;
    	}
	}	
    std::cout << std::endl;

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
    for (int i = 0; i < STACKSIZE / 2; i++) {
    int id = i + 1;
    string info;
    rand_string(&info); 
    if (stack.push(id, info)) { 
        cout << "Pushed: ID=" << id << ", Info=" << info << endl;
	} else {
        cout << "Overflow error: ID=" << id << " not pushed" << endl;
    	}
	}
	cout << endl;
	// Generate and push random strings
	cout << "Generating and pushing random strings:" << endl;
	cout << "============================================================" << endl; 			// Not neccessary but I did also do id. I know you said you don't have too but I did it anyways. 
																								
	
	
	for (int i = 0; i < STACKSIZE * MULTIPLIER; i++) {
    	int id = i + 1;
    	string info;
    	rand_string(&info); // Pass a pointer to a string variable
    	if (stack.push(id, info)) {
    		cout << "Pushed: ID=" << id << ", Info=" << info << endl;
    	} else {
        	cout << "Overflow error: ID=" << id << " not pushed" << endl;
    	}
	}
    
    int choice = rand() % CHOICES + 1;
    string info; // Declare 'info' variable outside the switch statement
	int id; 
    for (int i = 0; i < stackSizes * RANDOM_MULTIPLIER; i++) {
    switch (choice) {
        case 1:
        case 2:
            rand_string(&info);
            id = rand() % MAX_INT + 1;
            if (stack.push(id, info)) {
                cout << "Pushed: ID=" << id << ", Info=" << info << endl;
            } else {
                cout << "Overflow error: ID=" << id << " not pushed" << endl;
            }
            break;
        case 3:
        case 4:
            try {
                Data poppedData;
                stack.pop(poppedData);
                cout << "Popped: ID=" << poppedData.id << ", Info=" << poppedData.information << endl;
            } catch (const std::exception& e) {
                cout << "Pop underflow error: " << e.what() << endl;
            }
            break;
        case 5:
            if (stack.peek(peekedData)) {
                cout << "Peeked: ID=" << peekedData.id << ", Info=" << peekedData.information << endl;
            } else {
                cout << "Peek underflow error: Stack is empty" << endl;
            }
            break;
        case 6:
            if (stack.isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is NOT empty" << endl;
            }
            break;
    	}
    choice = rand() % CHOICES + 1;
    cout << endl;
    
   
	}
    return 0;
}
