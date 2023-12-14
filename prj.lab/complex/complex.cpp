#include <iostream>
#include <cstdint>
#include <sstream>

struct Complex {
  Complex() = default;
  explicit Complex(const double real) : re(real), im(0.0) {}
  Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

  // bool operators
  double eps = 2 * std::numeric_limits<double> ::epsilon();
  bool operator==(const Complex& rhs) const { return (std::abs(re - rhs.re) < eps) && (std::abs(im - rhs.im) < eps); }
  bool operator!=(const Complex& rhs) const { return !operator==(rhs); }

  // присваивающие operators
  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }

  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }

  Complex& operator*=(const Complex& rhs);
  Complex& operator*=(const double rhs) { return operator*=(Complex(rhs)); }

  Complex& operator/=(const Complex& rhs);
  Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }

  // input output
  std::ostream& write_to(std::ostream& ostrm) const;
  std::istream% read_from(std::istream& istrm);

  // a'la private
  double re{ 0.0 };
  double im{ 0.0 };


};