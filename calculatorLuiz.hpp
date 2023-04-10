#include "calculator.hpp"

class DisplayLuiz: public Display{
   public:
     void add(Digit digit);//
     void clear();
};


class CpuLuiz{//

};

class KeyboardLuiz{//

};

class CalculatorLuiz{//
  public:
    Display *display;
    Cpu *cpu;
    Keyboard *keyboard;
};