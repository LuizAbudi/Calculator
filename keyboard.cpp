#include "keyboard.hpp"
#include "calculatorLuiz.hpp"
#include <iostream>

void KeyboardLuiz::receive(Digit digit) {
  if (this->cpu)
    this->cpu->receive(digit);
  else
    std::cerr << "Keyboard without cpu!\n";
}
void KeyboardLuiz::receive(Operator operator_) {
  if (this->cpu)
    this->cpu->receive(operator_);
  else
    std::cerr << "Keyboard without cpu!\n";
}

void KeyboardLuiz::receive(Control control) {
  if (this->cpu)
    this->cpu->receive(control);
  else
    std::cerr << "Keyboard without cpu!\n";
}
Key *KeyboardLuiz::getKey(Digit digit) {
  for (Key *key : this->keys)
    if (dynamic_cast<KeyDigit *>(key) && ((KeyDigit *)key)->getDigit() == digit)
      return key;
  throw new CalculatorErrorLuiz("Key with digit not found!");
}
Key *KeyboardLuiz::getKey(Operator operator_) {
  for (Key *key : this->keys)
    if (dynamic_cast<KeyOperator *>(key) &&
        ((KeyOperator *)key)->getOperator() == operator_)
      return key;
  throw new CalculatorErrorLuiz("Key with operator not found!");
}
Key *KeyboardLuiz::getKey(Control control) {
  for (Key *key : this->keys)
    if (dynamic_cast<KeyControl *>(key) &&
        ((KeyControl *)key)->getControl() == control)
      return key;
  throw new CalculatorErrorLuiz("Key with control not found!");
}
Key *KeyboardLuiz::getKey(Symbol symbol) {
  for (Key *key : this->keys)
    if (key->getSymbol() == symbol)
      return key;
  throw new CalculatorErrorLuiz("Key with symbol not found!");
}
void KeyboardLuiz::add(Key *key) {
  if (key != NULL) {
    this->keys.push_back(key);
    key->setKeyboard(this);
  }
}
void KeyboardLuiz::setCpu(Cpu *cpu) { this->cpu = cpu; }
