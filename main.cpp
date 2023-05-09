#include "calculatorLuiz.hpp"
#include "cpuLuiz.hpp"
#include "displayLuiz.hpp"
#include "keyDigit.hpp"
#include "keyboard.hpp"
//#include "calculatorTest.hpp"
#include <iostream>
#include <stdio.h>





void myTest(Calculator *calculator) {
  /*TESTE 1
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(TWO)->press();
  calculator->getKeyboard()->getKey(THREE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(FOUR)->press();
  calculator->getKeyboard()->getKey(FIVE)->press();
  calculator->getKeyboard()->getKey(SIX)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  calculator->getKeyboard()->getKey(OFF)->press();
  */

  /*TESTE 2*/
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
  


  /*TESTE 4*/
  // calculator->getKeyboard()->getKey(ONE)->press();
  // calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  // calculator->getKeyboard()->getKey(ONE)->press();
  // calculator->getKeyboard()->getKey(SUM)->press();
  // calculator->getKeyboard()->getKey(ONE)->press();
  // calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  // calculator->getKeyboard()->getKey(ONE)->press();
  // calculator->getKeyboard()->getKey(EQUAL)->press();
  
}


int main() {

    /* Build da calculadora */
  Calculator *calculator = new CalculatorLuiz();
  Display *display = new DisplayLuiz();
  Cpu *cpu = new CpuLuiz();
  Keyboard *keyboard = new KeyboardLuiz();

  /* ... Criar todas as teclas */
  KeyDigit *keyZero = new KeyDigitLuiz("0", ZERO);
  KeyDigit *keyOne = new KeyDigitLuiz("1", ONE);
  KeyDigit *keyTwo = new KeyDigitLuiz("2", TWO);
  KeyDigit *keyThree = new KeyDigitLuiz("3", THREE);
  KeyDigit *keyFour = new KeyDigitLuiz("4", FOUR);
  KeyDigit *keyFive = new KeyDigitLuiz("5", FIVE);
  KeyDigit *keySix = new KeyDigitLuiz("6", SIX);
  KeyDigit *keySeven = new KeyDigitLuiz("7", SEVEN);
  KeyDigit *keyEight = new KeyDigitLuiz("8", EIGHT);
  KeyDigit *keyNine = new KeyDigitLuiz("9", NINE);

  KeyOperator *keySum = new KeyOperatorLuiz("+", SUM);
  KeyOperator *keySubtraction = new KeyOperatorLuiz("-", SUBTRACTION);
  KeyOperator *keyMultiplication = new KeyOperatorLuiz("*", MULTIPLICATION);
  KeyOperator *keyDivision = new KeyOperatorLuiz("/", DIVISION);
  KeyOperator *keySquareRoot = new KeyOperatorLuiz("SQRT", SQUARE_ROOT);
  KeyOperator *keyPercentage = new KeyOperatorLuiz("%", PERCENTAGE);

  KeyControl *keyEqual = new KeyControlLuiz("=", EQUAL);
  KeyControl *keyDecimalSeparator = new KeyControlLuiz(".", DECIMAL_SEPARATOR);
  KeyControl *keyClearError = new KeyControlLuiz("ON_CE", ON_CLEAR_ERROR);
  KeyControl *keyOff = new KeyControlLuiz("OFF", OFF);
  KeyControl *keyMemoryReadClear = new KeyControlLuiz("MRC", MEMORY_READ_CLEAR);
  KeyControl *keyMemorySum = new KeyControlLuiz("M+", MEMORY_SUM);
  KeyControl *keyMemorySubtraction =
      new KeyControlLuiz("M-", MEMORY_SUBTRACTION);

  /* ... Inserir todas as teclas no teclado  */
  keyboard->add(keyZero);
  keyboard->add(keyOne);
  keyboard->add(keyTwo);
  keyboard->add(keyThree);
  keyboard->add(keyFour);
  keyboard->add(keyFive);
  keyboard->add(keySix);
  keyboard->add(keySeven);
  keyboard->add(keyEight);
  keyboard->add(keyNine);

  keyboard->add(keySum);
  keyboard->add(keySubtraction);
  keyboard->add(keyMultiplication);
  keyboard->add(keyDivision);
  keyboard->add(keySquareRoot);
  keyboard->add(keyPercentage);

  keyboard->add(keyEqual);
  keyboard->add(keyClearError);
  keyboard->add(keyDecimalSeparator);
  keyboard->add(keyOff);
  keyboard->add(keyMemoryReadClear);
  keyboard->add(keyMemorySum);
  keyboard->add(keyMemorySubtraction);

  keyboard->setCpu(cpu);

  cpu->setDisplay(display);

  /* Conectando as partes da calculadora */
  calculator->setDisplay(display);
  calculator->setCpu(cpu);
  calculator->setKeyboard(keyboard);

  myTest(calculator);
}