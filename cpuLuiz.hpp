#include "calculator.hpp"
#include "stack.hpp"

enum Register{REGISTER_ONE, REGISTER_TWO};
enum TypeOfKey{TK_Digit, TK_Operator, TK_Control, UNDEF};

class CpuLuiz: public Cpu {
    Display* display;
    Stack* register1;
    Stack* register2;
    int indexDecimalSeparator1;
    int indexDecimalSeparator2;
    float memory;
    float lastOperandOperated = 0;
    bool lastKeyPressedWasEqualKey = false;
    bool equalKeyHasBeenPressed = 0;

    bool firstOperand;
    bool anyOperatorPressed;

    Operator lastOperator;
    TypeOfKey lastTypeOfKeyPressed;

    // utils
    bool isDecimalSeparatorUnset(Register);
    float toFloat(Register);
    void toDigit(float value, Register reg);
    Register getActiveRegister();
    void switchOperand();
    void saveTypeOfKeyPressed(TypeOfKey);
    bool lastKeyPressedWasDigit();
    bool lastKeyPressedWasOperator();
    bool lastKeyPressedWasControl();
    void executeOperation();
    void executeLastOperationOnMemory();

    void execOp(bool);
    // cpu-display association methods
    void sendDigitToDisplay(Digit);

    // process digit && related methods/attributes
    void processDigit(Digit);
    void pushDigitToRegister(Register, Digit);

    // process operator && related methods/attributes
    void processOperator(Operator);
    void executeOpOnRegisters();
    void executeOpOnMemoryAndRegister();
    bool memorySetted;

    // process control && related methods/attributes
    void processControl(Control);
    void processEqualControlKey();
    void setIndexDecimalSeparator(Register);
    void unsetIndexDecimalSeparator(Register);

    public:
      CpuLuiz();
      void receive(Digit);
      void receive(Operator);
      void receive(Control);
      void setDisplay(Display*);

};