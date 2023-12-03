#include <iostream>
#include <string>
#include <cstdint>

class Rational {
public:
  Rational() = default; // если ничего не получили (значение по умолчанию)
  Rational(int num) : num_(num) {} // если на вход получили только 1 число
  Rational(int num, int din) : num_(num), din_(din) {} // если на вход получили 2 числа
  ~Rational() = default; // деструктор
  Rational(const Rational& rhs) = default; // получили на вход только  Rational A(1, 2) -> Rational B(A)
  Rational& operator=(const Rational& rhs) { num_ = rhs.num_; din_ = rhs.din_; return *this; } // оператор присваивания
  
  // Операторы сравнения (логическе):
  bool operator==(const Rational& rhs) const { return num_ * rhs.din_ == rhs.num_ * din_; } // оператор ==
  bool operator==(const int rhs) const { return num_ * 1 == rhs * din_; }

  bool operator!=(const Rational& rhs) const { return num_ * rhs.din_ != rhs.num_ * din_; } // оператор !=
  bool operator!=(const int rhs) const { return !operator==(rhs); } // тоже оператор !=, но выраженный через оператор ==
  
  bool operator>(const Rational& rhs) const { return rhs.din_ * num_ > rhs.num_ * din_;} // оператор >
  bool operator>(const int rhs) const { return 1 * num_ > rhs * din_; }

  bool operator>=(const Rational& rhs) const { return operator==(rhs) || operator>(rhs); } // оператор >=
  bool operator>=(const int rhs) const { return operator==(rhs) || operator>(rhs); }

  bool operator<=(const Rational& rhs) const { return !operator>(rhs); } // оператор <= (выражен через оператор > )
  bool operator<=(const int rhs) const { return !operator>(rhs); }

  bool operator<(const Rational& rhs) const { return operator<=(rhs) && !operator==(rhs); } // оператор < (выражен через <= и не оператор ==)
  bool operator<(const int rhs) const { return operator<=(rhs) && !operator==(rhs); }

  // Операторы арифметические:
  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }

  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }

  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }

  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }



private:
  int num_ = 0; // числитель 
  int din_ = 1; // знаменатель

};

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = num_ * rhs.din_ + din_ * rhs.num_;
  din_ = din_ * rhs.din_;
  return *this;
}

