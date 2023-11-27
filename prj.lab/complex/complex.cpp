#include "complex.h"

Complex::Complex() {
}
Complex::Complex(const double real) : Complex() {
  real_ = real;
}
Complex::Complex(const double real, const double imaginary) : Complex() {
  real_ = real;
  imaginary_ = imaginary;
}
Complex::Complex(const Complex& rhs) : Complex(rhs.real_, rhs.imaginary_) {
}

Complex& Complex::operator= (const Complex& rhs) {
  real_ = rhs.real_;
  imaginary_ = rhs.imaginary_;
  return *this;
}
Complex& Complex::operator= (const double& rhs) {
  real_ = rhs;
  imaginary_ = 0;
  return *this;
}
Complex& Complex::operator+= (const Complex& rhs) {
  real_ += rhs.real_;
  imaginary_ += rhs.imaginary_;
  return *this;
}
Complex& Complex::operator+= (const double& rhs) {
  real_ += rhs;
  return *this;
}
Complex& Complex::operator-= (const Complex& rhs) {
  real_ -= rhs.real_;
  imaginary_ -= rhs.imaginary_;
  return *this;
}
Complex& Complex::operator-= (const double& rhs) {
  real_ -= rhs;
  return *this;
}
Complex& Complex::operator*= (const Complex& rhs) {
  real_ = real_ * rhs.real_ - imaginary_ * rhs.imaginary_;
  imaginary_ = imaginary_ * rhs.real_ + real_ * rhs.imaginary_;
  return *this;
}
Complex& Complex::operator*= (const double& rhs) {
  real_ *= rhs;
  imaginary_ *= rhs;
  return *this;
}
Complex& Complex::operator/= (const Complex& rhs) {
  if (rhs.real_ == 0 && rhs.imaginary_ == 0)
    throw std::string("Complex devision by zero");
  else
  {
    real_ = (real_ * rhs.real_ + imaginary_ * rhs.imaginary_) /
      (rhs.real_ * rhs.real_ + rhs.imaginary_ * rhs.imaginary_);
    imaginary_ = (imaginary_ * rhs.real_ - real_ * rhs.imaginary_) /
      (rhs.real_ * rhs.real_ + rhs.imaginary_ * rhs.imaginary_);
  }
  return *this;
}
Complex& Complex::operator/= (const double& rhs) {
  if (rhs == 0)
    throw std::string("Complex devision by zero");
  else
  {
    real_ /= rhs;
    imaginary_ /= rhs;
  }
  return *this;
}

Complex Complex::operator+ (const Complex& rhs) const {
  Complex answer(*this);
  answer += rhs;
  return answer;
}
Complex Complex::operator+ (const double& rhs) const {
  Complex answer(*this);
  answer += rhs;
  return answer;
}
Complex Complex::operator- (const Complex& rhs) const {
  Complex answer(*this);
  answer -= rhs;
  return answer;
}
Complex Complex::operator- (const double& rhs) const {
  Complex answer(*this);
  answer -= rhs;
  return answer;
}
Complex Complex::operator* (const Complex& rhs) const {
  Complex answer(*this);
  answer *= rhs;
  return answer;
}
Complex Complex::operator* (const double& rhs) const {
  Complex answer(*this);
  answer *= rhs;
  return answer;
}
Complex Complex::operator/ (const Complex& rhs) const {
  Complex answer(*this);
  answer /= rhs;
  return answer;
}
Complex Complex::operator/ (const double& rhs) const {
  Complex answer(*this);
  answer /= rhs;
  return answer;
}

bool Complex::operator== (const Complex& rhs) const {
  return real_ == rhs.real_ && imaginary_ == rhs.imaginary_;
}
bool Complex::operator== (const double& rhs) const {
  return real_ == rhs && imaginary_ == 0;
}
bool Complex::operator!= (const Complex& rhs) const {
  return !(*this == rhs);
}
bool Complex::operator!= (const double& rhs) const {
  return !(*this == rhs);
}

void Complex::conjugate() {
  imaginary_ *= -1;
}

std::istream& operator>> (std::istream& stream, Complex& val) {
  char leftBrace{ 0 };
  double real{ 0 };
  char separator{ 0 };
  double imaginary{ 0 };
  char rightBrace{ 0 };
  stream >> leftBrace >> real >> separator >> imaginary >> rightBrace;

  if (stream.good()) {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == separator)
      && (Complex::rightBrace == rightBrace)) {
      val.real_ = real;
      val.imaginary_ = imaginary;
    }
    else {
      stream.setstate(std::ios_base::failbit);
    }
  }

  return stream;
}
std::ostream& operator<< (std::ostream& stream, const Complex val) {
  stream << Complex::leftBrace << val.real_ << Complex::separator << val.imaginary_ << Complex::rightBrace;
  return stream;
}