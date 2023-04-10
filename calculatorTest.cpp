#include "calculatorLuiz.hpp"
#include <iostream>

void calculatorTest()
{
  Calculator *calculator = new CalculatorLuiz();
  Display *display = new DisplayLuiz();
  Cpu *cpu = new CpuLuiz();
  Keyboard *keyboard = new KeyboardLuiz();

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

  calculator->setDisplay(display);
  calculator->setCpu(cpu);
  calculator->setKeyboard(keyboard);

  try
  {
    calculator->getKeyboard()->getKey(ONE)->press();
    calculator->getKeyboard()->getKey(TWO)->press();
    calculator->getKeyboard()->getKey(THREE)->press();
    calculator->getKeyboard()->getKey(SUM)->press();
    calculator->getKeyboard()->getKey(FOUR)->press();
    calculator->getKeyboard()->getKey(FIVE)->press();
    calculator->getKeyboard()->getKey(SIX)->press();
    calculator->getKeyboard()->getKey(EQUAL)->press();
  }
  catch (CalculatorError &e)
  {
    std::cout << "Algum erro aconteceu: " << e.getMessage();
  }
}
