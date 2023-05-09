#pragma once

#include "cpuLuiz.hpp"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <sstream>

CpuLuiz::CpuLuiz() {
  this->register1 = new Stack();
  this->register2 = new Stack();
  this->indexDecimalSeparator1 = 0;
  this->indexDecimalSeparator2 = 0;
  this->firstOperand = true;
  this->lastOperator = SUM;

  this->memory = 0;

  this->anyOperatorPressed = false;
  this->lastOperator = SUM; // iniciamos com SUM

  this->memorySetted = false;
  this->lastTypeOfKeyPressed = UNDEF;
}

void CpuLuiz::receive(Digit digit) { this->processDigit(digit); }

void CpuLuiz::processDigit(Digit digit) {
  this->pushDigitToRegister(this->getActiveRegister(), digit);
  this->sendDigitToDisplay(digit);
  this->saveTypeOfKeyPressed(TK_Digit);
}

Register CpuLuiz::getActiveRegister() {
  if (this->firstOperand)
    return REGISTER_ONE;
  return REGISTER_TWO;
}

void CpuLuiz::saveTypeOfKeyPressed(TypeOfKey typeOfKey) {
  this->lastTypeOfKeyPressed = typeOfKey;
}
bool CpuLuiz::lastKeyPressedWasDigit() {
  return this->lastTypeOfKeyPressed == TK_Digit;
}
bool CpuLuiz::lastKeyPressedWasOperator() {
  return this->lastTypeOfKeyPressed == TK_Operator;
}
bool CpuLuiz::lastKeyPressedWasControl() {
  return this->lastTypeOfKeyPressed == TK_Control;
}

void CpuLuiz::pushDigitToRegister(Register reg, Digit digit) {
  switch (reg) {
  case REGISTER_ONE:
    this->register1->push(digit);
    break;
  case REGISTER_TWO:
    this->register2->push(digit);
    break;
  }
}

void CpuLuiz::sendDigitToDisplay(Digit digit) {
  if (this->display) {
    this->display->add(digit);
  }
}

void CpuLuiz::receive(Operator op) { this->processOperator(op); }

void CpuLuiz::switchOperand() { 
  this->firstOperand = !this->firstOperand; 
  this->display->clear();
}

void CpuLuiz::execOp(bool operateOnMemory) {
  float auxiliar = operateOnMemory ? this->memory : toFloat(REGISTER_ONE);
  switch (this->lastOperator) {
  case SUM:
    this->memory = auxiliar + this->lastOperandOperated;
    break;
  case SUBTRACTION:
    this->memory = auxiliar - this->lastOperandOperated;
    break;
  case MULTIPLICATION:
    this->memory = auxiliar * this->lastOperandOperated;
    break;
  case DIVISION:
    this->memory = auxiliar / this->lastOperandOperated;
    break;
  }
  // DEBUG
  //printf("\n memory1 -> %.2f\n", this->memory);

  this->display->clear();
  toDigit(this->memory, REGISTER_ONE);
  
  this->memorySetted = true;
}

void CpuLuiz::executeOpOnRegisters() {
  this->lastOperandOperated = toFloat(REGISTER_TWO);
  
  switch (this->lastOperator) {
  case SUM:
    this->memory = toFloat(REGISTER_ONE) + this->lastOperandOperated;
    break;
  case SUBTRACTION:
    this->memory = toFloat(REGISTER_ONE) - this->lastOperandOperated;
    break;
  case MULTIPLICATION:
    this->memory = toFloat(REGISTER_ONE) * this->lastOperandOperated;
    break;
  case DIVISION:
    this->memory = toFloat(REGISTER_ONE) / this->lastOperandOperated;
    break;
  }
  // DEBUG
  //printf(" memory1 -> %.2f\n", this->memory);
  //printf("  =  %.2f\n", this->memory);

  //dar um clear no display 
  this->display->clear();
  //transformar o float em um Digit
  toDigit(this->memory, REGISTER_ONE);
  
  this->memorySetted = true;
}

void CpuLuiz::executeOpOnMemoryAndRegister() {
  this->lastOperandOperated = toFloat(this->getActiveRegister());
  switch (this->lastOperator) {
  case SUM:
    this->memory = this->memory + this->lastOperandOperated;
    break;
  case SUBTRACTION:
    this->memory = this->memory - this->lastOperandOperated;
    break;
  case MULTIPLICATION:
    this->memory = this->memory * this->lastOperandOperated;
    break;
  case DIVISION:
    this->memory = this->memory / this->lastOperandOperated;
    break;
  }

  //dar um clear no display 
  this->display->clear();
  //transformar o float em um Digit
  toDigit(this->memory, REGISTER_ONE);
  // DEBUG
  //printf(" memory2 -> %.2f\n", this->memory);
  //printf("  =  %.2f\n", this->memory);
}

void CpuLuiz::executeLastOperationOnMemory() {
  switch (this->lastOperator) {
  case SUM:
    this->memory = this->memory + this->lastOperandOperated;
    break;
  case SUBTRACTION:
    this->memory = this->memory - this->lastOperandOperated;
    break;
  case MULTIPLICATION:
    this->memory = this->memory * this->lastOperandOperated;
    break;
  case DIVISION:
    this->memory = this->memory / this->lastOperandOperated;
    break;
  }

  //dar um clear no display 
  this->display->clear();
  //transformar o float em um Digit
  toDigit(this->memory, REGISTER_ONE);

  // DEBUG
  //printf(" memory3 -> %.2f\n", this->memory);
  //printf("  =  %.2f\n", this->memory);
}

void CpuLuiz::executeOperation() {
  if (!this->memorySetted) {
    this->executeOpOnRegisters();
  } else {
    this->executeOpOnMemoryAndRegister();
  }
}

void CpuLuiz::processOperator(Operator op) {
  if (this->anyOperatorPressed && this->memorySetted &&
      this->equalKeyHasBeenPressed) {
    this->lastOperator = op;
    this->executeOperation();
  }
  if (this->anyOperatorPressed && this->memorySetted &&
      !this->equalKeyHasBeenPressed) {
    //printf(" called\n");
    this->executeOperation();
  }
  // if (this->anyOperatorPressed) {
  //   this->executeOperation();
  // }
  // vem de um igual
  if (!this->anyOperatorPressed && this->memorySetted) {
    this->lastOperator = op;
    this->executeOpOnMemoryAndRegister();
  }
  if (this->anyOperatorPressed && !this->memorySetted) {
    this->executeOpOnRegisters();
  }

  // DEBUG
  // printf("memory -> %.2f\n", this->memory);

  this->lastOperator = op;
  this->anyOperatorPressed = true;
  this->saveTypeOfKeyPressed(TK_Operator);
  this->switchOperand();
}

void CpuLuiz::receive(Control control) { this->processControl(control); 
}

void CpuLuiz::setIndexDecimalSeparator(Register reg) {
  if (this->isDecimalSeparatorUnset(reg)) {
    switch (reg) {
    case REGISTER_ONE:
      this->indexDecimalSeparator1 = this->register1->size();
      break;
    case REGISTER_TWO:
      this->indexDecimalSeparator2 = this->register2->size();
      break;
    }
  }
}

void CpuLuiz::unsetIndexDecimalSeparator(Register reg) {
  switch (reg) {
  case REGISTER_ONE:
    this->indexDecimalSeparator1 = 0;
    break;
  case REGISTER_TWO:
    this->indexDecimalSeparator2 = 0;
    break;
  }
}

void CpuLuiz::processEqualControlKey() {
  // casos
  // 0: só pressionou equal (mostra o que já tinha?)
  // 1: pressionou digit e sem operador
  // 2: pressionou digit com operador
  if (this->anyOperatorPressed && this->lastKeyPressedWasDigit()) {
    this->executeOperation();
  }
  if (!this->anyOperatorPressed && this->lastKeyPressedWasEqualKey) {
    this->executeLastOperationOnMemory();
  }
  // 3: pressionou operador sem digit
  // 4: pressionou operador com digit
  this->anyOperatorPressed = false;
}

void CpuLuiz::processControl(Control control) {
  switch (control) {
  case DECIMAL_SEPARATOR:
    this->setIndexDecimalSeparator(this->getActiveRegister());
    this->display->addDecimalSeparator();
    break;
  case EQUAL:
    this->processEqualControlKey();
    this->equalKeyHasBeenPressed = true;
    this->lastKeyPressedWasEqualKey = true;
    break;
  case ON_CLEAR_ERROR:
    this->display ? this->display->clear(): void();
    break;
  case OFF:
    std::cout << "Desligando...";
    exit(0);
    break;
  case MEMORY_READ_CLEAR:
    this->register1->clear();
    this->register2->clear();
    break;
  case MEMORY_SUM:
    // salva o numero na memoria
    break;
  case MEMORY_SUBTRACTION:
    // apaga o numero salvo na memoria
    break;
  }

  this->saveTypeOfKeyPressed(TK_Control);
}

//função que recebe o valor e qual registrador deve ser colocado
//tranformando o valor para digit
void CpuLuiz::toDigit(float value, Register reg){
  this->firstOperand = reg == REGISTER_ONE;
  
  std::stringstream str1;
  str1  << std::noshowpoint << value;
  
  //DEBUG
  //std::cout << "result " << str1.str();
  
   for(char& c : str1.str()) {
     switch(c){
       case '0': processDigit(ZERO); break; 
       case '1': processDigit(ONE); break; 
       case '2': processDigit(TWO); break;
       case '3': processDigit(THREE); break;
       case '4': processDigit(FOUR); break;
       case '5': processDigit(FIVE); break;
       case '6': processDigit(SIX); break;
       case '7': processDigit(SEVEN); break;
       case '8': processDigit(EIGHT); break;
       case '9': processDigit(NINE); break; 
       case '.': processControl(DECIMAL_SEPARATOR); break;
       case '-': this->display->setSignal(NEGATIVE); break;
       default: break;
     } 
   }
}


float CpuLuiz::toFloat(Register reg) {
  float fractionalPart = 0;
  float integerPart = 0;
  int exponent = 0;
  int decimalPlaces = -1;

  if (reg == REGISTER_ONE) {
    if (this->indexDecimalSeparator1 != 0) {
      for (int i = this->register1->size(); i > this->indexDecimalSeparator1;
           i--) {
        int digit = this->register1->pop();
        fractionalPart += digit * (pow(10, exponent));
        exponent++;
        decimalPlaces++;
      }
    }
    exponent = 0;
    while (this->register1->size() > 0) {
      int digit = this->register1->pop();
      integerPart += digit * (pow(10, exponent));
      exponent++;
    }
  } else if (reg == REGISTER_TWO) {
    if (this->indexDecimalSeparator2 != 0) {
      for (int i = this->register2->size(); i > this->indexDecimalSeparator2;
           i--) {
        int digit = this->register2->pop();
        fractionalPart += digit * (pow(10, exponent));
        exponent++;
        decimalPlaces++;
      }
    }

    exponent = 0;
    while (this->register2->size() > 0) {
      int digit = this->register2->pop();
      integerPart += digit * (pow(10, exponent));
      exponent++;
    }
  }

  this->unsetIndexDecimalSeparator(reg);
  return integerPart + fractionalPart / (10 * pow(10, decimalPlaces));
}

void CpuLuiz::setDisplay(Display *display) { this->display = display; }

bool CpuLuiz::isDecimalSeparatorUnset(Register reg) {
  switch (reg) {
  case REGISTER_ONE:
    return this->indexDecimalSeparator1 == 0;
  case REGISTER_TWO:
    return this->indexDecimalSeparator2 == 0;
  }
}