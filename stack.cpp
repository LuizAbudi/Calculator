#include <iostream>
#include <stdio.h>
#include "stack.hpp"

Node::Node(int value) {
  this->value = value;
  this->next = nullptr;
}

void Node::set(int value) { this->value = value; }
void Node::set(Node* next) { this->next = next; }
int Node::getValue() { return this->value; }
Node* Node::getNext() { return this->next; }


Stack::Stack() {
  stackPointer = nullptr;
  elCount = 0;
}

void Stack::push(int value) {
  Node* newNode = new Node(value);
  if (this->elCount > 0) {
    newNode->set(this->stackPointer);
  }
  this->stackPointer = newNode;
  this->elCount++;
}

int Stack::pop() {
  if (this->elCount > 0) {
    Node* aux = this->stackPointer->getNext();
    int stackPointerValue = this->stackPointer->getValue();
    delete(this->stackPointer);
    this->stackPointer = aux;
    this->elCount--;
    return stackPointerValue;
  }
}

void Stack::print() {
  if (this->elCount > 0) {
    Node* aux = this->stackPointer;
    while(aux != nullptr) {
      printf("%d ", aux->getValue());
      aux = aux->getNext();
    }
    printf("\n");
    return;
  }
  printf("Stack is empty.\n");
}

int Stack::size() {
  return this->elCount;
}

void Stack::clear(){ 
  while(size()>0){
    pop();
  }
}
