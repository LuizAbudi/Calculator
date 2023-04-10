#include "calculator.hpp"

class DisplayLuiz : public Display
{
public:
  void add(Digit digit);
  void clear();
};

class CpuLuiz : public Cpu
{
public:
  void receive(Digit);
  void receive(Operator);
  void receive(Control);
};

class KeyboardLuiz : public Keyboard
{
  void receive(Digit);
  void receive(Operator);
  void receive(Control);
  Key *getKey(Digit);
  Key *getKey(Operator);
  Key *getKey(Control);
  void add(Key *);
};
class KeyDigitLuiz : public KeyDigit
{
public:
  KeyDigitLuiz(char const *symbol, Digit);
  void press();
  char const *getSymbol();
  void setKeyboard(Keyboard *);
  Digit getDigit();
};

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