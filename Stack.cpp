/* 8/31/98 Mary Elaine Califf
 * a C++ linked list implementation of stacks
 */

// Modified:
//   8/20/2003 by Mary Elaine Califf
//      Changed to ANSI C++
// revised 12/25/20
// Name: Chris Keveloh
//Implementation of a stack of integers

#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
topNode = nullptr;
}

bool Stack::push(char newValue) 
{
  Node* newNode = new Node(newValue);
  newNode->next = topNode;
  topNode = newNode;
  return true;
}

char Stack::pop()
{
  
  // taking advantage of pre-increment so we don't have to save the value off to return it
  if(topNode != nullptr)
  {
  char value = topNode->data;
  Node* temp = topNode;
  topNode = topNode->next;
  delete temp;
  return value;
  }

  else
  return '0';

}

bool Stack::isEmpty() const{
  return topNode == nullptr;
}

Stack::~Stack() // destructor
{
  clear();
}

Stack::Stack(const Stack& other) //copy constructor
{
 if(other.isEmpty())
 {
  topNode = nullptr;
  return;
 }
  copy(other);
}


Stack& Stack::operator=(const Stack& other) //assignment operator uses helper methods to clear and copy data
{
  
  if(this != &other)
  {
    clear();
    copy(other);
  }

  return *this;

}

char Stack::top() // returns top node 
{
  return topNode->data;
  
}

void Stack::clear() //clear helper method
{
  while(!isEmpty())
  {
    pop();
  }
}

void Stack::copy(const Stack& other) //copy helper method
{
  if(other.isEmpty())
  {
    return;
  }

  Node* otherNode = other.topNode;
  topNode = new Node(otherNode->data);
  Node* currNode = topNode;

  while(otherNode->next)
  {
    otherNode = otherNode->next;
    currNode->next = new Node(otherNode->data);
    currNode = currNode->next;
  }

}