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
}
