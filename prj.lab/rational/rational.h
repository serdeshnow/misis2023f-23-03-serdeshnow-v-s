#ifndef RATIONAL_LIB_HPP
#define RATIONAL_LIB_HPP
#include <cstdint>
#include <iostream>
#include <stdexcept>


class Rational {
public:
  Rational() = default; /// если ничего не получили (значение по умолчанию)
  Rational(int64_t num, int64_t den) : num_(num), den_(den) { fix(); } /// если на вход получили 2 числа
  explicit Rational(int64_t num) : Rational{ num, 1 } {} /// если на вход получили только 1 число /// explicit + cпособ обойти константность полей (direct initialization)
  ~Rational() = default; /// деструктор
  Rational(const Rational& rhs) = default; /// получили на вход только  Rational A(1, 2) -> Rational B(A)
  Rational& operator=(const Rational& rhs) { num_ = rhs.num_; den_ = rhs.den_; return *this; } /// оператор присваивания


  [[nodiscard]] int64_t num() const { return num_; }
  [[nodiscard]] int64_t den() const { return den_; }


  /// Операторы сравнения (логическе):
  bool operator==(const Rational& rhs) const { return num_ * rhs.den_ == rhs.num_ * den_; } /// оператор ==
  bool operator==(const int64_t rhs) const { return num_ * 1 == rhs * den_; }

  bool operator!=(const Rational& rhs) const { return num_ * rhs.den_ != rhs.num_ * den_; } /// оператор !=
  bool operator!=(const int64_t rhs) const { return !operator==(rhs); } /// тоже оператор !=, но выраженный через оператор ==

  bool operator>(const Rational& rhs) const { return rhs.den_ * num_ > rhs.num_ * den_; } /// оператор >
  bool operator>(const int64_t rhs) const { return 1 * num_ > rhs * den_; }

  bool operator>=(const Rational& rhs) const { return operator==(rhs) || operator>(rhs); } /// оператор >=
  bool operator>=(const int64_t rhs) const { return operator==(rhs) || operator>(rhs); }

  bool operator<=(const Rational& rhs) const { return !operator>(rhs); } /// оператор <= (выражен через оператор > )
  bool operator<=(const int64_t rhs) const { return !operator>(rhs); }

  bool operator<(const Rational& rhs) const { return operator<=(rhs) && !operator==(rhs); } /// оператор < (выражен через <= и не оператор ==)
  bool operator<(const int64_t rhs) const { return operator<=(rhs) && !operator==(rhs); }

  /// Операторы арифметические:
  Rational& operator+=(const Rational& rhs); /// объявление оператора +=
  Rational& operator+=(const int64_t rhs) { return operator+=(Rational(rhs)); } /// объявление и определение

  Rational& operator-=(const Rational& rhs); /// оператор -=
  Rational& operator-=(const int64_t rhs) { return operator-=(Rational(rhs)); }

  Rational& operator*=(const Rational& rhs); /// оператор *=
  Rational& operator*=(const int64_t rhs) { return operator*=(Rational(rhs)); }

  Rational& operator/=(const Rational& rhs); /// оператор /=
  Rational& operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); }

  std::istream& input(std::istream& read); /// чтение для ПК, сами мы записываем  значение
  std::ostream& output(std::ostream& write) const; /// вывод значений с ПК, мы читаем то, что он вывел

private:
  int64_t num_ = 0; /// числитель 
  int64_t den_ = 1; /// знаменатель
  char separator = '/'; /// сепаратор 

  int64_t gcd(int64_t a, int64_t b) { /// НОД, китайская теорема об остатках
    if (a * b == 0) {
      return a + b; /// сам НОД
    }
    else if (a > b) {
      return gcd(a % b, b);
    }
    else {
      return gcd(b % a, a);
    }
  }

  void fix() {
    bool is_positive = (num_ * den_ >= 0 ? true : false); /// знак дроби
    num_ = std::abs(num_);
    den_ = std::abs(den_);
    int64_t nod = gcd(num_, den_);
    num_ /= nod;
    den_ /= nod;
    num_ = (is_positive ? num_ : -num_);
  }


};

std::istream& operator>>(std::istream& stream, Rational& rhs) { return rhs.input(stream); }
std::ostream& operator<<(std::ostream& stream, Rational& rhs) { return rhs.output(stream); }

#endif