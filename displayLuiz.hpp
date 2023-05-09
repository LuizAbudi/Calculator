#pragma once
#include "calculator.hpp"

class DisplayLuiz: public Display {
    public: 
        void add(Digit);
        void add(Operator);
        void addDecimalSeparator();
        void setSignal(Signal);
        void clear();
};