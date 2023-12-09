#include <iostream>
#include <string>
#include <cstdint>

class Rational {
public:
  Rational() = default; // если ничего не получили (значение по умолчанию)
  explicit Rational(int num) : num_(num) {} // если на вход получили только 1 число // explicit
  Rational(int num, int din) : num_(num), din_(din) { fix(); } // если на вход получили 2 числа
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
  Rational& operator+=(const Rational& rhs); // объявление оператора +=
  Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); } // объявление и определение

  Rational& operator-=(const Rational& rhs); // оператор -=
  Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }

  Rational& operator*=(const Rational& rhs); // оператор *=
  Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); } 

  Rational& operator/=(const Rational& rhs); // оператор /=
  Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }

  std::istream& input(std::istream& read); // чтение для ПК, сами мы записываем  значение
  std::ostream& output(std::ostream& write) const; // вывод значений с ПК, мы читаем то, что он вывел


private:
  int num_ = 0; // числитель 
  int din_ = 1; // знаменатель
  char separator = '/'; // сепаратор 

  int gcd(int a, int b) { // НОД, китайская теорема об остатках
    if (a * b == 0) {
      return a + b; // сам НОД
    }
    else if (a > b) {
      return gcd(a % b, b);
    }
    else {
      return gcd(b % a, a);
    }
  }

  void fix() {
    bool is_positive = (num_ * din_ >= 0 ? true : false); // знак дроби
    num_ = std::abs(num_);
    din_ = std::abs(din_);
    int nod = gcd(num_, din_);
    num_ /= nod;
    din_ /= nod;
    num_ = (is_positive ? num_ : -num_);
  }
  

};

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
  result += rhs;
  return result;
}
Rational operator-(const Rational& lhs, const int rhs) {
  Rational result(lhs);
  result += rhs;
  return result;
}
Rational operator-(const int lhs, const Rational& rhs) {
  Rational result(lhs);
  result += rhs;
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
  int64_t num(0);
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
    throw std::runtime_error("Division by zero!");
  }
  else {
    return read;
  }
}

std::ostream& Rational::output(std::ostream& write) const {
  write << num_ << separator << din_;
  return write;
}

std::istream& operator>>(std::istream& stream, Rational &rhs) { return rhs.input(stream); }
std::ostream& operator<<(std::ostream& stream, Rational &rhs) { return rhs.output(stream); }


int main() {
  Rational a(22, 6);
  Rational b(14, 6);
  Rational c = a + b;
  std::cout << c;
}
