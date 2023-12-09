#include <iostream>
#include "../prj.lab/rational/rational.h"


int main() {
  Rational a(22, 6);
  Rational b(14, 6);
  Rational c = a + b;
  std::cout << c;
  return 0;
}
