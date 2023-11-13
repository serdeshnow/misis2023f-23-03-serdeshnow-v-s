//Complex.h------------------------------------------------------------------------------------
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

//test.cpp-------------------------------------------------------------------------------------
#include <sstream>

void test_constructors(int tub) {
  std::cout << std::string(tub, ' ') << "* constructor checking:" << std::endl;
  tub += 4;
  Complex a;
  std::cout << std::string(tub, ' ') << "Complex()              -> " << a << std::endl;
  Complex b(1, 1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1)          -> " << b << std::endl;
  Complex c(1);
  std::cout << std::string(tub, ' ') << "Complex(1)             -> " << c << std::endl;
  Complex d(b);
  std::cout << std::string(tub, ' ') << "Complex(other Complex) -> " << d << std::endl;

  std::cout << std::endl;
}
void test_input(int tub) {
  std::cout << std::string(tub, ' ') << "* input check:" << std::endl;
  tub += 4;

  {
    std::istringstream input_stream_a("(1.1,1)");
    Complex a;
    input_stream_a >> a;
    std::cout << std::string(tub, ' ') << "Complex a(0, 0); \"(1.1,1)\"  >> a  -> a" << a << std::endl;
  }
  {
    std::istringstream input_stream_a("(1.1, 1)");
    Complex a;
    input_stream_a >> a;
    std::cout << std::string(tub, ' ') << "Complex a(0, 0); \"(1.1, 1)\" >> a  -> a" << a << std::endl;
  }
  {
    std::istringstream input_stream_a("(1.1 1)");
    Complex a;
    input_stream_a >> a;
    std::cout << std::string(tub, ' ') << "Complex a(0, 0); \"(1.1 1)\"  >> a  -> a" << a << std::endl;
  }
  {
    std::istringstream input_stream_a("(1.1 1)");
    Complex a;
    input_stream_a >> a;
    std::cout << std::string(tub, ' ') << "Complex a(0, 0); \"(1.1 1)\"  >> a  -> a" << a << std::endl;
  }
  {
    std::istringstream input_stream_a("[1.1, 1]");
    Complex a;
    input_stream_a >> a;
    std::cout << std::string(tub, ' ') << "Complex a(0, 0); \"[1.1 1]\"  >> a  -> a" << a << std::endl;
  }

  std::cout << std::endl;
}
void test_appropriation(int tub) {
  std::cout << std::string(tub, ' ') << "* appropriation check:" << std::endl;
  tub += 4;

  Complex a(1, 1);
  Complex b(2, 2);
  a = b;
  std::cout << std::string(tub, ' ') << "Complex(1, 1) = Complex(2, 2) -> " << a << std::endl;

  std::cout << std::endl;
}
void test_sum(int tub) {
  std::cout << std::string(tub, ' ') << "* addition check:" << std::endl;
  tub += 4;
  Complex a(1, 1);
  Complex b(2, 2);
  a += b;
  std::cout << std::string(tub, ' ') << "Complex(1, 1) += Complex(2, 2) -> " << a << std::endl;

  Complex c(1, 1);
  Complex d(2, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) + Complex(2, 2)  -> " << c + d << std::endl;

  Complex e(1, 1);
  double f(2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) + double(2)      -> " << e + f << std::endl;

  std::cout << std::endl;
}
void test_diff(int tub) {
  std::cout << std::string(tub, ' ') << "* subtraction check:" << std::endl;
  tub += 4;

  Complex a(1, 1);
  Complex b(2, 2);
  a -= b;
  std::cout << std::string(tub, ' ') << "Complex(1, 1) -= Complex(2, 2) -> " << a << std::endl;

  Complex c(1, 1);
  Complex d(2, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) - Complex(2, 2)  -> " << c - d << std::endl;

  Complex e(1, 1);
  double f(2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) - double(2)      -> " << e - f << std::endl;

  std::cout << std::endl;
}
void test_mult(int tub) {
  std::cout << std::string(tub, ' ') << "* multiplication check:" << std::endl;
  tub += 4;
  Complex a(1, 1);
  Complex b(2, 2);
  a *= b;
  std::cout << std::string(tub, ' ') << "Complex(1, 1) *= Complex(2, 2) -> " << a << std::endl;

  Complex c(1, 1);
  Complex d(2, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) * Complex(2, 2)  -> " << c * d << std::endl;

  Complex e(1, 1);
  double f(2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) * double(2)      -> " << e * f << std::endl;

  std::cout << std::endl;
}
void test_div_by_0(int tub) {
  std::cout << std::string(tub, ' ') << "* checking division by 0:" << std::endl;
  tub += 4;

  Complex a(1, 1);
  Complex b(0, 0);
  try {
    a /= b;
    std::cout << std::string(tub, ' ') << "Complex(1, 1) /= Complex(0, 0) -> " << a << std::endl;
  }
  catch (std::string error)
  {
    std::cout << std::string(tub, ' ') << "Complex(1, 1) /= Complex(0, 0) -> " << "Error: " << error << std::endl;
  }

  Complex c(1, 1);
  Complex d(0, 0);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) / Complex(0, 0)  -> ";
  try {
    std::cout << c / d << std::endl;
  }
  catch (std::string error)
  {
    std::cout << "Error: " << error << std::endl;
  }

  Complex e(1, 1);
  double f(0);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) / double(0)      -> ";
  try {
    std::cout << e / f << std::endl;
  }
  catch (std::string error)
  {
    std::cout << "Error: " << error << std::endl;
  }

  std::cout << std::endl;
}
void test_div(int tub) {
  std::cout << std::string(tub, ' ') << "* division check:" << std::endl;
  tub += 4;

  Complex a(1, 1);
  Complex b(2, 2);
  a /= b;
  std::cout << std::string(tub, ' ') << "Complex(1, 1) /= Complex(2, 2) -> " << a << std::endl;

  Complex c(1, 1);
  Complex d(2, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) / Complex(2, 2)  -> " << c / d << std::endl;

  Complex e(1, 1);
  double f(2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) / double(2)      -> " << e / f << std::endl << std::endl;

  test_div_by_0(tub);
}
void test_ariphmetic(int tub) {
  std::cout << std::string(tub, ' ') << "* arithmetic check:" << std::endl;
  tub += 4;
  test_sum(tub);
  test_diff(tub);
  test_mult(tub);
  test_div(tub);
}
void test_comparison_for_equality(int tub) {
  std::cout << std::string(tub, ' ') << "* comparison for equality check:" << std::endl;
  tub += 4;

  Complex c(1, 1);
  Complex d(1, 1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) == Complex(1, 1)  -> " << (c == d ? "True" : "False") << std::endl;

  Complex c1(1, 1);
  Complex d1(1, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) == Complex(1, 2)  -> " << (c1 == d1 ? "True" : "False") << std::endl;
  Complex c2(1, 1);
  Complex d2(2, 1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) == Complex(2, 1)  -> " << (c2 == d2 ? "True" : "False") << std::endl;
  Complex c3(1, 1);
  Complex d3(2, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) == Complex(2, 2)  -> " << (c3 == d3 ? "True" : "False") << std::endl;

  Complex e(1, 0);
  double f(1);
  std::cout << std::string(tub, ' ') << "Complex(1, 0) == double(1)      -> " << (e == f ? "True" : "False") << std::endl;

  Complex e1(1, 1);
  double f1(1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) == double(1)      -> " << (e1 == f1 ? "True" : "False") << std::endl;
  
  Complex e2(2, 1);
  double f2(1);
  std::cout << std::string(tub, ' ') << "Complex(2, 1) == double(1)      -> " << (e2 == f2 ? "True" : "False") << std::endl;
  
  Complex e3(1, 0);
  double f3(2);
  std::cout << std::string(tub, ' ') << "Complex(1, 0) == double(2)      -> " << (e3 == f3 ? "True" : "False") << std::endl;

  std::cout << std::endl;
}
void test_comparison_for_no_equality(int tub) {
  std::cout << std::string(tub, ' ') << "* comparison for no equality check:" << std::endl;
  tub += 4;

  Complex c(1, 1);
  Complex d(1, 1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) != Complex(1, 1)  -> " << (c != d ? "True" : "False") << std::endl;
  Complex c1(1, 1);
  Complex d1(1, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) != Complex(1, 2)  -> " << (c1 != d1 ? "True" : "False") << std::endl;
  Complex c2(1, 1);
  Complex d2(2, 1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) != Complex(2, 1)  -> " << (c2 != d2 ? "True" : "False") << std::endl;
  Complex c3(1, 1);
  Complex d3(2, 2);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) != Complex(2, 2)  -> " << (c3 != d3 ? "True" : "False") << std::endl;

  Complex e(1, 0);
  double f(1);
  std::cout << std::string(tub, ' ') << "Complex(1, 0) != double(1)      -> " << (e != f ? "True" : "False") << std::endl;

  Complex e1(1, 1);
  double f1(1);
  std::cout << std::string(tub, ' ') << "Complex(1, 1) != double(1)      -> " << (e1 != f1 ? "True" : "False") << std::endl;

  Complex e2(2, 1);
  double f2(1);
  std::cout << std::string(tub, ' ') << "Complex(2, 1) != double(1)      -> " << (e2 != f2 ? "True" : "False") << std::endl;

  Complex e3(1, 0);
  double f3(2);
  std::cout << std::string(tub, ' ') << "Complex(1, 0) != double(2)      -> " << (e3 != f3 ? "True" : "False") << std::endl;

  std::cout << std::endl;
}
void test_comparison(int tub) {
  std::cout << std::string(tub, ' ') << "* comparison check:" << std::endl;
  tub += 4;

  test_comparison_for_equality(tub);
  test_comparison_for_no_equality(tub);
}
void test_conjugate(int tub) {
  std::cout << std::string(tub, ' ') << "* conjugate check:" << std::endl;
  tub += 4;

  Complex a(1, 1);
  a.conjugate();
  std::cout << std::string(tub, ' ') << "Complex(1, 1).conjugate()  -> " << a << std::endl;

  std::cout << std::endl;
}

int main() {
  test_constructors(0);
  test_input(0);
  test_appropriation(0);
  test_ariphmetic(0);
  test_comparison(0);
  test_conjugate(0);
}

//Complex.cpp----------------------------------------------------------------------------------
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
