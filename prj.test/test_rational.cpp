#include <iostream>
#include "../prj.lab/rational/rational.cpp"


int main() {
  Rational a(24, 6);
  int b = 4;
  Rational c = a + b;
  std::cout << c;
  return 0;
}
