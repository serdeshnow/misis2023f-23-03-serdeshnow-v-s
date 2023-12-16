#include "rational.h"

Rational& Rational::operator+=(const Rational& rhs) { /// определение оператора +=
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  fix();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) { /// определение оператора -=
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  fix();
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) { /// определение оператора *=
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  fix();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) { /// определение оператора /=
  num_ = num_ * rhs.den_;
  den_ = den_ * rhs.num_;
  fix();
  return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) { /// оператор +
  Rational result(lhs);
  result += rhs;
  return result;
}
Rational operator+(const Rational& lhs, const int64_t rhs) {
  Rational result(lhs);
  result += rhs;
  return result;
}
Rational operator+(const int64_t lhs, const Rational& rhs) {
  Rational result(lhs);
  result += rhs;
  return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs) { /// оператор -
  Rational result(lhs);
  result -= rhs;
  return result;
}
Rational operator-(const Rational& lhs, const int64_t rhs) {
  Rational result(lhs);
  result -= rhs;
  return result;
}
Rational operator-(const int64_t lhs, const Rational& rhs) {
  Rational result(lhs);
  result -= rhs;
  return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs) { /// оператор *
  Rational result(lhs);
  result *= rhs;
  return result;
}
Rational operator*(const Rational& lhs, const int64_t rhs) {
  Rational result(lhs);
  result *= rhs;
  return result;
}
Rational operator*(const int64_t lhs, const Rational& rhs) {
  Rational result(lhs);
  result *= rhs;
  return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs) { /// оператор /
  Rational result(lhs);
  result /= rhs;
  return result;
}
Rational operator/(const Rational& lhs, const int64_t rhs) {
  Rational result(lhs);
  result /= rhs;
  return result;
}
Rational operator/(const int64_t lhs, const Rational& rhs) {
  Rational result(lhs);
  result /= rhs;
  return result;
}

std::istream& Rational::input(std::istream& read) {
  int64_t num(0); /// инициализация при объявлении
  char sep(0);
  int64_t den(0);
  read >> num >> sep >> den;
  if (read.good()) {
    if (sep == separator) {
      num_ = num;
      den_ = den;
    }
    else {
      read.setstate(std::ios_base::failbit);
    }
  }
  if (den_ == 0) {
    throw std::runtime_error("Division by zero!"); /// вызов исключения
  }
  else {
    return read;
  }
}

std::ostream& Rational::output(std::ostream& write) const {
  write << num_ << separator << den_;
  return write;
}