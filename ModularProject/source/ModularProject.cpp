//============================================================================
// Name        : ModularProject.cpp
// Author      : Sidorov Alexey
// Version     : 1.0
// E-mail      : alexsid117@gmail.com
//============================================================================

#include <iostream>
#include <utility>

using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::istream;
using std::swap;
using std::ostream;

/*
 * Class of integer numbers with field P arithmetics.
 */
template <int P>
class Modular {
public:
  Modular(void);
  explicit Modular(int number);
  Modular(const Modular<P> &rhs);

  void Cut(void);

  Modular<P> &operator =(Modular<P> rhs);

  const Modular<P> operator -(void) const;

  Modular<P> &operator +=(const Modular<P> &rhs);
  Modular<P> &operator +=(int rhs);

  const Modular<P> operator +(const Modular<P> &rhs) const;
  const Modular<P> operator +(int rhs) const;

  template <int V>
  friend const Modular<V> operator +(int lhs, const Modular<V> &rhs);

  Modular<P> &operator -=(const Modular<P> &rhs);
  Modular<P> &operator -=(int rhs);

  const Modular<P> operator -(const Modular<P> &rhs) const;
  const Modular<P> operator -(int rhs) const;

  template <int V>
  friend const Modular<V> operator -(int lhs, const Modular<V> &rhs);

  Modular<P> &operator *=(const Modular<P> &rhs);
  Modular<P> &operator *=(int rhs);

  const Modular<P> operator *(const Modular<P> &rhs) const;
  const Modular<P> operator *(int rhs) const;

  template <int V>
  friend const Modular<V> operator *(int lhs, const Modular<V> &rhs);

  Modular<P> &operator /=(const Modular<P> &rhs);
  Modular<P> &operator /=(int rhs);

  const Modular<P> operator /(const Modular<P> &rhs) const;
  const Modular<P> operator /(int rhs) const;

  template <int V>
  friend const Modular<V> operator /(int lhs, const Modular<V> &rhs);

  Modular<P> &operator %=(const Modular<P> &rhs);
  Modular<P> &operator %=(int rhs);

  const Modular<P> operator %(const Modular<P> &rhs) const;
  const Modular<P> operator %(int rhs) const;

  template <int V>
  friend const Modular<V> operator %(int lhs, const Modular<V> &rhs);

  template <int V>
  friend istream &operator >>(istream &in, Modular<V> &rhs);

  template <int V>
  friend ostream &operator <<(ostream &out, const Modular<V> &rhs);

  bool operator ==(const Modular<P> &rhs) const;
  bool operator ==(int rhs) const;

  template <int V>
  friend bool operator ==(int lhs, const Modular<V> &rhs);

  bool operator !=(const Modular<P> &rhs) const;
  bool operator !=(int rhs) const;

  template <int V>
  friend bool operator !=(int lhs, const Modular<V> &rhs);

  bool operator >(const Modular<P> &rhs) const;
  bool operator >(int rhs) const;

  template <int V>
  friend bool operator >(int lhs, const Modular<V> &rhs);

  bool operator <(const Modular<P> &rhs) const;
  bool operator <(int rhs) const;

  template <int V>
  friend bool operator <(int lhs, const Modular<V> &rhs);

  bool operator >=(const Modular<P> &rhs) const;
  bool operator >=(int rhs) const;

  template <int V>
  friend bool operator >=(int lhs, const Modular<V> &rhs);

  bool operator <=(const Modular<P> &rhs) const;
  bool operator <=(int rhs) const;

  template <int V>
  friend bool operator <=(int lhs, const Modular<V> &rhs);

  class ExceptionDivisionByZero: exception {
  };

private:
  long long number_;
};

//============================================

template <int P>
void Modular<P>::Cut(void) {
  if (number_ >= P) {
    number_ %= P;
  } else if (number_ < 0) {
    number_ = P - ((-number_) % P);
  }
}

//============================================

template <int P>
Modular<P>::Modular(void)
    : number_(0) {
}

template <int P>
Modular<P>::Modular(int number)
    : number_(number) {
  Cut();
}

template <int P>
Modular<P>::Modular(const Modular<P> &rhs)
    : number_(rhs.number_) {
}

template <int P>
Modular<P> &Modular<P>::operator =(Modular<P> rhs) {
  swap(number_, rhs.number_);
  return *this;
}

template <int P>
const Modular<P> Modular<P>::operator -(void) const {
  return *this * (-1);
}

template <int P>
const Modular<P> Modular<P>::operator +(const Modular<P> &rhs) const {
  return Modular<P>(*this) += rhs;
}

template <int P>
const Modular<P> Modular<P>::operator +(int rhs) const {
  return Modular<P>(*this) += Modular<P>(rhs);
}

template <int V>
const Modular<V> operator +(int lhs, const Modular<V> &rhs) {
  return rhs + lhs;
}

template <int P>
Modular<P> &Modular<P>::operator +=(const Modular<P> &rhs) {
  number_ += rhs.number_;
  Cut();
  return *this;
}

template <int P>
Modular<P> &Modular<P>::operator +=(int rhs) {
  return *this += Modular<P>(rhs);
}

template <int P>
const Modular<P> Modular<P>::operator -(const Modular<P> &rhs) const {
  return *this + (-rhs);
}

template <int P>
const Modular<P> Modular<P>::operator -(int rhs) const {
  return *this + (Modular<P>(-rhs));
}

template <int V>
const Modular<V> operator -(int lhs, const Modular<V> &rhs) {
  return -(rhs - lhs);
}

template <int P>
Modular<P> &Modular<P>::operator -=(const Modular<P> &rhs) {
  return *this += (-rhs);
}

template <int P>
Modular<P> &Modular<P>::operator -=(int rhs) {
  return *this += Modular<P>(-rhs);
}

template <int P>
const Modular<P> Modular<P>::operator *(const Modular<P> &rhs) const {
  return Modular<P>(*this) *= rhs;
}

template <int P>
const Modular<P> Modular<P>::operator *(int rhs) const {
  return Modular<P>(*this) *= Modular<P>(rhs);
}

template <int V>
const Modular<V> operator *(int lhs, const Modular<V> &rhs) {
  return rhs * lhs;
}

template <int P>
Modular<P> &Modular<P>::operator *=(const Modular<P> &rhs) {
  number_ *= rhs.number_;
  Cut();
  return *this;
}

template <int P>
Modular<P> &Modular<P>::operator *=(int rhs) {
  return *this *= Modular<P>(rhs);
}

template <int P>
const Modular<P> Modular<P>::operator /(const Modular<P> &rhs) const {
  return Modular<P>(*this) /= rhs;
}

template <int P>
const Modular<P> Modular<P>::operator /(int rhs) const {
  return Modular<P>(*this) /= Modular<P>(rhs);
}

template <int V>
const Modular<V> operator /(int lhs, const Modular<V> &rhs) {
  return Modular<V>(lhs) /= rhs;
}

template <int P>
Modular<P> &Modular<P>::operator /=(const Modular<P> &rhs) {
  if (!rhs.number_) {
    throw ExceptionDivisionByZero();
  }

  number_ /= rhs.number_;
  return *this;
}

template <int P>
Modular<P> &Modular<P>::operator /=(int rhs) {
  return *this /= Modular<P>(rhs);
}

template <int P>
const Modular<P> Modular<P>::operator %(const Modular<P> &rhs) const {
  return Modular<P>(*this) %= rhs;
}

template <int P>
const Modular<P> Modular<P>::operator %(int rhs) const {
  return Modular<P>(*this) %= Modular<P>(rhs);
}

template <int V>
const Modular<V> operator %(int lhs, const Modular<V> &rhs) {
  return Modular<V>(lhs) %= rhs;
}

template <int P>
Modular<P> &Modular<P>::operator %=(const Modular<P> &rhs) {
  if (!rhs.number_) {
    throw ExceptionDivisionByZero();
  }

  number_ %= rhs.number_;
  return *this;
}

template <int P>
Modular<P> &Modular<P>::operator %=(int rhs) {
  return *this %= Modular<P>(rhs);
}

template <int V>
istream &operator >>(istream &in, Modular<V> &rhs) {
  in >> rhs.number_;
  rhs.Cut();
  return in;
}

template <int V>
ostream &operator <<(ostream &out, const Modular<V> &rhs) {
  out << rhs.number_;
  return out;
}

template <int P>
bool Modular<P>::operator ==(const Modular<P> &rhs) const {
  return number_ == rhs.number_;
}

template <int P>
bool Modular<P>::operator ==(int rhs) const {
  return number_ == Modular<P>(rhs);
}

template <int P>
bool Modular<P>::operator !=(const Modular<P> &rhs) const {
  return !(*this == rhs);
}

template <int P>
bool Modular<P>::operator !=(int rhs) const {
  return !(*this == rhs);
}

template <int P>
bool Modular<P>::operator <(const Modular<P> &rhs) const {
  return number_ < rhs.number_;
}

template <int P>
bool Modular<P>::operator <(int rhs) const {
  return number_ < Modular<P>(rhs);
}

template <int P>
bool Modular<P>::operator >(const Modular<P> &rhs) const {
  return !(*this <= rhs);
}

template <int P>
bool Modular<P>::operator >(int rhs) const {
  return !(*this <= rhs);
}

template <int P>
bool Modular<P>::operator <=(const Modular<P> &rhs) const {
  return *this < rhs || *this == rhs;
}

template <int P>
bool Modular<P>::operator <=(int rhs) const {
  return *this <= Modular<P>(rhs);
}

template <int P>
bool Modular<P>::operator >=(const Modular<P> &rhs) const {
  return !(*this < rhs);
}

template <int P>
bool Modular<P>::operator >=(int rhs) const {
  return !(*this < rhs);
}

template <int V>
bool operator ==(int lhs, const Modular<V> &rhs) {
  return rhs == lhs;
}

template <int V>
bool operator !=(int lhs, const Modular<V> &rhs) {
  return rhs != lhs;
}

template <int V>
bool operator >(int lhs, const Modular<V> &rhs) {
  return rhs < lhs;
}

template <int V>
bool operator <(int lhs, const Modular<V> &rhs) {
  return rhs > lhs;
}

template <int V>
bool operator >=(int lhs, const Modular<V> &rhs) {
  return rhs <= lhs;
}

template <int V>
bool operator <=(int lhs, const Modular<V> &rhs) {
  return rhs >= lhs;
}

//============================================

int main() {
  Modular<5> a(45);

  cout << "45 mod 5 == " << a << endl;

  Modular<7> b(-8);

  cout << "-8 mod 7 == " << b << endl;

  Modular<7> c(5);

  cout << endl;
  cout << "(6 + 5) mod 7 == " << (b + c) << endl;
  cout << "(6 - 5) mod 7 == " << (b - c) << endl;
  cout << "(6 * 5) mod 7 == " << (b * c) << endl;
  cout << "(6 / 5) mod 7 == " << (b / c) << endl;
  cout << "(6 % 5) mod 7 == " << (b % c) << endl;
  cout << endl;

  cout << endl;
  cout << "(6 == 5) mod 7 == " << boolalpha << (b == c) << endl;
  cout << "(6 != 5) mod 7 == " << boolalpha << (b != c) << endl;
  cout << "(6 > 5) mod 7 == " << boolalpha << (b > c) << endl;
  cout << "(6 < 5) mod 7 == " << boolalpha << (b < c) << endl;
  cout << "(6 >= 5) mod 7 == " << boolalpha << (b >= c) << endl;
  cout << "(6 <= 5) mod 7 == " << boolalpha << (b <= c) << endl;
  cout << endl;
  return 0;
}

