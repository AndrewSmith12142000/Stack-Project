/*
 * Your comment header here
 * modify this file as needed to complete the assignment
 */

#ifndef STACK_H
#define STACK_H

#include "data.h"
#include "functions.h"

class Stack {

public:

    Stack(int size = 10);
    ~Stack();

    bool push(int id, const std::string& info);
    bool pop(Data& data);
    bool peek(Data& data);
    bool isEmpty() const;
    int getSize() const;
    void dumpStack() const;

private:
    int top;
    int size;
    Data** stack;
};

#endif //STACK_H
