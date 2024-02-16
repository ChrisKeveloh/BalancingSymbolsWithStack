/* 8/31/98 Mary Elaine Califf
 * a C++ array implementation of stacks
 *
 * Revised 12/25/2020
 */
 // Name: Chris Keveloh
 //Header file for a stack of integers

#ifndef STACK_H
#define STACK_H

class Stack
{

private:

void copy(const Stack& other);
void clear();
  struct  Node
{
  char data;
  Node* next;
  Node(char value) : data(value), next(nullptr){}

};

Node* topNode;



public:

  Stack(); // constructor
  ~Stack();
  Stack(const Stack& other);
  Stack& operator = (const Stack& other);
  bool isEmpty() const;
  char top();

  // add a new value to the stack
  // fails and return false if the stack is full
  bool push(char newValue);

  // pops top item off of the stack
  // Precondition: stack must not be empty
  char pop();

  // return item at the top of the stack without removing it
  // Precondition: stack must not be empty
  


};

#endif
