#include "keyDigit.hpp"
#include <cstddef>

KeyDigitLuiz::KeyDigitLuiz(Symbol symbol, Digit digit) {
  this->symbol = symbol;
  this->digit = digit;
}
void KeyDigitLuiz::press() {
  if (this->keyboard != NULL)
    this->keyboard->receive(this->digit);
}
Symbol KeyDigitLuiz::getSymbol() { return this->symbol; }
void KeyDigitLuiz::setKeyboard(Keyboard *keyboard) {
  this->keyboard = keyboard;
}
Digit KeyDigitLuiz::getDigit() { return this->digit; }

KeyControlLuiz::KeyControlLuiz(Symbol symbol, Control control) {
  this->symbol = symbol;
  this->control = control;
}
void KeyControlLuiz::press() {
  if (this->keyboard != NULL)
    this->keyboard->receive(this->control);
}
Symbol KeyControlLuiz::getSymbol() { return this->symbol; }
void KeyControlLuiz::setKeyboard(Keyboard *keyboard) {
  this->keyboard = keyboard;
}
Control KeyControlLuiz::getControl() { return this->control; }

KeyOperatorLuiz::KeyOperatorLuiz(Symbol symbol, Operator operator_) {
  this->symbol = symbol;
  this->operator_ = operator_;
}
void KeyOperatorLuiz::press() {
  if (this->keyboard != NULL)
    this->keyboard->receive(this->operator_);
}
Symbol KeyOperatorLuiz::getSymbol() { return this->symbol; }
void KeyOperatorLuiz::setKeyboard(Keyboard *keyboard) {
  this->keyboard = keyboard;
}
Operator KeyOperatorLuiz::getOperator() { return this->operator_; }