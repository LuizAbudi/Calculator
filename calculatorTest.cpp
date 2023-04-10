#include "calculatorLuiz.hpp"
#include <iostream>

void calculatorTest() {
  DisplayLuiz d1, d2;
try{

  d1.add(ZERO);//
  d1.add(ONE);//
  d1.add(TWO);//
  d1.add(THREE);//  
  d1.add(FOUR);//
  d1.add(FIVE);//
  d1.add(SIX);//
  d1.add(SEVEN);//
  d1.add(EIGHT);//
  d1.add(NINE);//
  d1.clear();//

  }catch(CalculatorError e){
  std::cout << "Algum erro aconteceu: " << e.getMessage();  
}
  
  Calculator* c1 = new calculatorLuiz();

  Keyboard* kb1 = c1->getKeyboard();
  kb1->getKey(ONE)->press();
  kb1->getKey(TWO)->press();
  kb1->getKey(THREE)->press();
  kb1->getKey(SUM)->press();
  kb1->getKey(FOUR)->press();
  kb1->getKey(FIVE)->press();
  kb1->getKey(SIX)->press();
  kb1->getKey(SEVEN)->press();
  kb1->getKey(EIGHT)->press();
  kb1->getKey(NINE)->press();
  kb1->getKey(EQUAL)->press();

  // Calculator c1, c2;
  // c1.display = &d1;
  // c2.display = &d2;

  // c1.display = c2.display;
}
