#include "rational.h"

Rational& Rational::operator+=(const Rational& rhs) { // определение оператора +=
  num_ = num_ * rhs.din_ + din_ * rhs.num_;
  din_ = din_ * rhs.din_;
  fix();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) { // определение оператора -=
  num_ = num_ * rhs.din_ - din_ * rhs.num_;
  din_ = din_ * rhs.din_;
  fix();
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) { // определение оператора *=
  num_ = num_ * rhs.num_;
  din_ = din_ * rhs.din_;
  fix();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) { // определение оператора /=
  num_ = num_ * rhs.din_;
  din_ = din_ * rhs.num_;
  fix();
  return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) { // оператор +
  Rational result(lhs);
  result += rhs;
  return result;
}
Rational operator+(const Rational& lhs, const int rhs) {
  Rational result(lhs);
  result += rhs;
  return result;
}
Rational operator+(const int lhs, const Rational& rhs) {
  Rational result(lhs);
  result += rhs;
  return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs) { // оператор -
  Rational result(lhs);
  result -= rhs;
  return result;
}
Rational operator-(const Rational& lhs, const int rhs) {
  Rational result(lhs);
  result -= rhs;
  return result;
}
Rational operator-(const int lhs, const Rational& rhs) {
  Rational result(lhs);
  result -= rhs;
  return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs) { // оператор *
  Rational result(lhs);
  result *= rhs;
  return result;
}
Rational operator*(const Rational& lhs, const int rhs) {
  Rational result(lhs);
  result *= rhs;
  return result;
}
Rational operator*(const int lhs, const Rational& rhs) {
  Rational result(lhs);
  result *= rhs;
  return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs) { // оператор /
  Rational result(lhs);
  result /= rhs;
  return result;
}
Rational operator/(const Rational& lhs, const int rhs) {
  Rational result(lhs);
  result /= rhs;
  return result;
}
Rational operator/(const int lhs, const Rational& rhs) {
  Rational result(lhs);
  result /= rhs;
  return result;
}

std::istream& Rational::input(std::istream& read) {
  int64_t num(0); // инициализация при объявлении
  char sep(0);
  int64_t din(0);
  read >> num >> sep >> din;
  if (read.good()) {
    if (sep == separator) {
      num_ = num;
      din_ = din;
    }
    else {
      read.setstate(std::ios_base::failbit);
    }
  }
  if (din_ == 0) {
    throw std::runtime_error("Division by zero!"); /// вызов исключения
  }
  else {
    return read;
  }
}

std::ostream& Rational::output(std::ostream& write) const {
  write << num_ << separator << din_;
  return write;
}