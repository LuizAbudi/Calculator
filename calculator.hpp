enum Digit
{
  ZERO,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE
};
enum Operator
{
  SUM,
  SUBTRACTION,
  DIVISION,
  MULTIPLICATION
}; //
enum Control
{
  EQUAL,
  DECIMAL_SEPARATOR,
  CLEAR_ERROR,
  OFF,
  MEMORY_READ_CLEAR,
  MEMORY_SUM,
  MEMORY_SUBTRACTION
}; //

class Display
{
public:
  virtual void add(Digit digit) = 0;
  virtual void clear() = 0;
};

class Cpu
{
public:
  virtual void receive(Digit) = 0;
  virtual void receive(Operator) = 0;
  virtual void receive(Control) = 0;
};

class Key;
class Keyboard
{ //
public:
  virtual void receive(Digit) = 0;
  virtual void receive(Operator) = 0;
  virtual void receive(Control) = 0;
  virtual Key *getKey(Digit) = 0;
  virtual Key *getKey(Operator) = 0;
  virtual Key *getKey(Control) = 0;
  virtual void add(Key *) = 0;
};

class Key
{ //
public:
  virtual void press() = 0;
  virtual char const *getSymbol() = 0;
  virtual void setKeyboard(Keyboard *) = 0;
};

class KeyDigit : public Key
{ //
public:
  virtual Digit getDigit() = 0;
};

class KeyOperator : public Key
{ //
public:
  virtual Operator getOperator() = 0;
};

class KeyControl : public Key
{ //
public:
  virtual Control getControl() = 0;
};

/* Responsabilidade: Montar uma calculadora */
class Calculator
{
public:
  virtual void setDisplay(Display *) = 0;
  virtual Display *getDisplay() = 0;
  virtual void setCpu(Cpu *) = 0;
  virtual Cpu *getCpu() = 0;
  virtual void setKeyboard(Keyboard *) = 0;
  virtual Keyboard *getKeyboard() = 0;
};

class CalculatorError
{ //
  char const *message;

public:
  CalculatorError(char const *message) { this->message = message; };
  char const *getMessage() { return this->message; };
};
