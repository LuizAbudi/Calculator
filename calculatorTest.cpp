#pragma once
#include "calculatorTest.hpp"
#include <functional>
#include <iostream>
#include <vector>

/** Implementação das classes de teste
---------------------------------------------*/
TestCalculatorBase::TestCalculatorBase(Calculator *calculator) {
  this->calculator = calculator;
}
void TestCalculatorBase::setup() {
  std::cout << "Iniciando teste..." << this->getName() << std::endl;
  calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
}
void TestCalculatorBase::tearDown() {
  calculator->getKeyboard()->getKey(OFF)->press();
  std::cout << "Teste finalizado..." << std::endl;
}

/**
  123 + 456 = = = = 1947
*/
TestCalculator1::TestCalculator1(Calculator *calculator)
    : TestCalculatorBase(calculator) {}
void TestCalculator1::setup() {
  this->TestCalculatorBase::setup();
  calculator->getKeyboard()->getKey("0")->press();
}

void TestCalculator1::run() {
  Symbol test[] = {"1", "2", "3", "+", "4", "5", "6", "=", "=", "=", "="};
  for (Symbol s : test)
    calculator->getKeyboard()->getKey(s)->press();
}
char const *TestCalculator1::getName() {
  return " Testando 123 + 456 = = = = 1947";
}

/**
  .1 * .1 = 0.01
*/
TestCalculator2::TestCalculator2(Calculator *calculator)
    : TestCalculatorBase(calculator) {}

void TestCalculator2::run() {
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

char const *TestCalculator2::getName() {
  return " Testando 123 + 456 = = = = 1947";
}

TestCalculatorSmart::TestCalculatorSmart(Calculator *calculator, Symbol *tests,
                                         int testsCount)
    : TestCalculatorBase(calculator) {
  // this->tests = tests;
}
void TestCalculatorSmart::run() {
  Symbol test[] = {"1", "2", "3", "+", "4", "5", "6", "=", "=", "=", "="};
  for (Symbol s : test)
    calculator->getKeyboard()->getKey(s)->press();
}
char const *TestCalculatorSmart::getName() {
  return " Testando 123 + 456 = = = = 1947";
}

/** Implementação das funções de teste
---------------------------------------------*/
/**
  123 + 456 = = = = 1947
*/
void test1(Calculator *calculator) {
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
}

/**
  .1 * .1 = 0.01
*/
void test2(Calculator *calculator) {
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}
/**
  .1 * .1 = 0.01
*/
void test3(Calculator *calculator) {
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}
/**
  .1 * .1 = 0.01
*/
void test4(Calculator *calculator) {
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(SUM)->press();
  calculator->getKeyboard()->getKey(DECIMAL_SEPARATOR)->press();
  calculator->getKeyboard()->getKey(ONE)->press();
  calculator->getKeyboard()->getKey(EQUAL)->press();
}

/* Inclua suas implementações aqui */
#include "calculatorLuiz.hpp"
#include "displayLuiz.hpp"
#include "cpuLuiz.hpp"
#include "keyDigit.hpp"
#include "keyboard.hpp"

Calculator *buildCalculator() {
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

  return calculator;
}

void mainTest() {

  try {
    std::cout << "Construindo a calculadora..." << std::endl;
    Calculator *calculator = buildCalculator();
    /** Execução dos testes Orientados a Objetos
    ---------------------------------------------*/

    std::vector<Test *> calculatorTests;
    calculatorTests.push_back(new TestCalculator1(calculator));
    calculatorTests.push_back(new TestCalculator2(calculator));

    for (Test *test : calculatorTests) {
      try {
        test->setup();
        test->run();
        test->tearDown();
      } catch (CalculatorError &e) {
        std::cout << "Algum erro aconteceu: " << e.getMessage();
      }
    }

    /** Execução dos testes estruturados
    ---------------------------------------------*/
    std::cout << "Iniciando teste1..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test1(calculator);
    std::cout << "Iniciando teste2..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test2(calculator);
    std::cout << "Iniciando teste3..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test3(calculator);
    std::cout << "Iniciando teste4..." << std::endl;
    calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
    test4(calculator);

    /** Execução dos testes estruturados mais organizados
    ---------------------------------------------*/
    std::function<void(Calculator *)> calculatorTests_[] = {&test1, &test2,
                                                            &test3, &test4};
    try {
      int i = 0;
      for (std::function<void(Calculator *)> test : calculatorTests_) {
        std::cout << "Iniciando teste..." << i++ << std::endl;
        calculator->getKeyboard()->getKey(ON_CLEAR_ERROR)->press();
        test(calculator);
      }
    } catch (CalculatorError &e) {
      std::cout << "Algum erro aconteceu: " << e.getMessage();
    }

    delete calculator;
  } catch (CalculatorError *error) {
    std::cout << "Tests failed: " << error->getMessage();
  }
}