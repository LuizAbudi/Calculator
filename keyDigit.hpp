#pragma once
#include "calculator.hpp"

class KeyDigitLuiz: public KeyDigit{
    Symbol symbol;
    Digit digit;
    Keyboard* keyboard;
  public:
    KeyDigitLuiz(Symbol, Digit);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Digit getDigit();
};


class KeyControlLuiz: public KeyControl{
    Symbol symbol;
    Control control;
    Keyboard* keyboard;
  public:
    KeyControlLuiz(Symbol, Control);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Control getControl();
};


class KeyOperatorLuiz: public KeyOperator{
    Symbol symbol;
    Operator operator_;
    Keyboard* keyboard;
  public:
    KeyOperatorLuiz(Symbol, Operator);
    void press();
    Symbol getSymbol();
    void setKeyboard(Keyboard*);
    Operator getOperator();
};
