#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

struct Complex {
  Complex();
  explicit Complex(const double real);
  Complex(const double real, const double imaginary);
  Complex(const Complex& rhs);

  Complex& operator= (const Complex& rhs);
  Complex& operator= (const double& rhs);
  Complex& operator+= (const Complex& rhs);
  Complex& operator+= (const double& rhs);
  Complex& operator-= (const Complex& rhs);
  Complex& operator-= (const double& rhs);
  Complex& operator*= (const Complex& rhs);
  Complex& operator*= (const double& rhs);
  Complex& operator/= (const Complex& rhs);
  Complex& operator/= (const double& rhs);

  Complex operator+ (const Complex& rhs) const;
  Complex operator+ (const double& rhs) const;
  Complex operator- (const Complex& rhs) const;
  Complex operator- (const double& rhs) const;
  Complex operator* (const Complex& rhs) const;
  Complex operator* (const double& rhs) const;
  Complex operator/ (const Complex& rhs) const;
  Complex operator/ (const double& rhs) const;

  bool operator== (const Complex& rhs) const;
  bool operator== (const double& rhs) const;
  bool operator!= (const Complex& rhs) const;
  bool operator!= (const double& rhs) const;

  void conjugate();

  double real_ = 0;
  double imaginary_ = 0;
  static const char leftBrace{ '(' };
  static const char separator{ ',' };
  static const char rightBrace{ ')' };
};
std::istream& operator>> (std::istream& stream, Complex& val);
std::ostream& operator<< (std::ostream& stream, const Complex val);

#endif