/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */


#include "stack.h"
#include <iostream>

Stack::Stack(int size) : size(size), top(-1) {
    if (size < 2) {
        size = 10; 
    }
    stack = new Data*[size];
}

Stack::~Stack() {
    for (int i = 0; i <= top; ++i) {
        delete stack[i];
    }
    delete[] stack;
}


bool isEmpty() const {
    return top == -1;
}