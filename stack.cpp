/*
 Name: Andrew Smith
 Coding 04
 Purpose: This file shows the stacks
 File: stack.cpp
 *
 */

#include "stack.h"

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

bool Stack::push(int id, const std::string& info) {
    bool success = false; 
    if (id >= 0 && top < size - 1) {
        stack[++top] = new Data{ id, info };
        success = true; 
    }
    return success; 
}

bool Stack::pop(Data& data) {
    bool success = false; 
    if (!isEmpty()) {
        data = *stack[top];
        delete stack[top--];
        success = true;
    } 
	else {
        data.id = -1;
        data.information = "";
    }
    return success; 
}

bool Stack::peek(Data& data) {
    bool success = false; 
    if (!isEmpty()) {
        data = *stack[top];
        success = true; 
    } else {
        data.id = -1;
        data.information = "";
    }
    return success; 
}

bool Stack::isEmpty() const {
    return top == -1;
}

int Stack::getSize() const {
    return size + 1;
}

