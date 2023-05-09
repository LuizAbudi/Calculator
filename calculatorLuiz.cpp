#include "calculatorLuiz.hpp"
#include <iostream>
#include <stdio.h>

CalculatorErrorLuiz::CalculatorErrorLuiz(char const *message) {
  this->message = message;
}
char const *CalculatorErrorLuiz::getMessage() { return this->message; }

void CalculatorLuiz::setDisplay(Display *display) { this->display = display; }
Display *CalculatorLuiz::getDisplay() { return this->display; }
void CalculatorLuiz::setCpu(Cpu *cpu) { this->cpu = cpu; }
Cpu *CalculatorLuiz::getCpu() { return this->cpu; }
void CalculatorLuiz::setKeyboard(Keyboard *keyboard) {
  this->keyboard = keyboard;
}
Keyboard *CalculatorLuiz::getKeyboard() { return this->keyboard; }