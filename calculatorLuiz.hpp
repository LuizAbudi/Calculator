#pragma once
#include "calculator.hpp"
#include <iostream>

class CalculatorLuiz : public Calculator
{
    Display *display;
    Cpu *cpu;
    Keyboard *keyboard;

public:
    void setDisplay(Display *);
    Display *getDisplay();
    void setCpu(Cpu *);
    Cpu *getCpu();
    void setKeyboard(Keyboard *);
    Keyboard *getKeyboard();
};

class CalculatorErrorLuiz : public CalculatorError
{
    char const *message;

public:
    CalculatorErrorLuiz(char const *message);
    char const *getMessage();
};