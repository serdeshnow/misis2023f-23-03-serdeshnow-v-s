#include <iostream>
#include <string>
#include <cstdint>

class Rational {
public:
  Rational() = default; // ���� ������ �� �������� (�������� �� ���������)
  Rational(int num) : num_(num) {} // ���� �� ���� �������� ������ 1 �����
  Rational(int num, int din) : num_(num), din_(din) {} // ���� �� ���� �������� 2 �����
  ~Rational() = default; // ����������
  Rational(const Rational& rhs) = default; // �������� �� ���� ������  Rational A(1, 2) -> Rational B(A)
  Rational& operator=(const Rational& rhs) { num_ = rhs.num_; din_ = rhs.din_; return *this; } // �������� ������������
  
  // ��������� ��������� (���������):
  bool operator==(const Rational& rhs) const { return num_ * rhs.din_ == rhs.num_ * din_; } // �������� ==
  bool operator==(const int rhs) const { return num_ * 1 == rhs * din_; }

  bool operator!=(const Rational& rhs) const { return num_ * rhs.din_ != rhs.num_ * din_; } // �������� !=
  bool operator!=(const int rhs) const { return !operator==(rhs); } // ���� �������� !=, �� ���������� ����� �������� ==
  
  bool operator>(const Rational& rhs) const { return rhs.din_ * num_ > rhs.num_ * din_;} // �������� >
  bool operator>(const int rhs) const { return 1 * num_ > rhs * din_; }

  bool operator>=(const Rational& rhs) const { return operator==(rhs) || operator>(rhs); } // �������� >=
  bool operator>=(const int rhs) const { return operator==(rhs) || operator>(rhs); }

  bool operator<=(const Rational& rhs) const { return !operator>(rhs); } // �������� <= (������� ����� �������� > )
  bool operator<=(const int rhs) const { return !operator>(rhs); }

  bool operator<(const Rational& rhs) const { return operator<=(rhs) && !operator==(rhs); } // �������� < (������� ����� <= � �� �������� ==)
  bool operator<(const int rhs) const { return operator<=(rhs) && !operator==(rhs); }

  // ��������� ��������������:
  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }

  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }

  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }

  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }



private:
  int num_ = 0; // ��������� 
  int din_ = 1; // �����������

};

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = num_ * rhs.din_ + din_ * rhs.num_;
  din_ = din_ * rhs.din_;
  return *this;
}

