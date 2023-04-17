#include "Fraction.hpp"

namespace ariel {

Fraction::Fraction(int n, int d) : numerator{n}, denominator{d} {}

int Fraction::get_numerator() const {
    return numerator;
}

int Fraction::get_denominator() const {
    return denominator;
}

Fraction Fraction::operator+(Fraction b) const {
    int new_num = numerator * b.denominator + denominator * b.numerator;
    int new_den = denominator * b.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(Fraction b) const {
    int new_num = numerator * b.denominator - denominator * b.numerator;
    int new_den = denominator * b.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator/(Fraction b) const {
    int new_num = numerator * b.denominator;
    int new_den = denominator * b.numerator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(Fraction b) const {
    int new_num = numerator * b.numerator;
    int new_den = denominator * b.denominator;
    return Fraction(new_num, new_den);
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction result = *this;
    numerator += denominator;
    return result;
}

Fraction Fraction::operator--(int) {
    Fraction result = *this;
    numerator -= denominator;
    return result;
}

bool Fraction::operator>(Fraction b) const {
    return (double)numerator/denominator > (double)b.numerator/b.denominator;
}

Fraction Fraction::operator+(const double d) const {
    return Fraction(numerator + d * denominator, denominator);
}

Fraction Fraction::operator-(const double d) const {
    return Fraction(numerator - d * denominator, denominator);
}

Fraction Fraction::operator/(const double d) const {
    return Fraction(numerator, denominator * d);
}

std::ostream &operator<<(std::ostream &os, const Fraction &f) {
    os << f.get_numerator() << "/" << f.get_denominator();
    return os;
}

Fraction operator*(const double d, const Fraction &f) {
    return Fraction(d * f.get_numerator(), f.get_denominator());
}

bool operator>=(const Fraction &f1,const Fraction &f2) {
    return (double)f1.get_numerator()/f1.get_denominator() >= (double)f2.get_numerator()/f2.get_denominator();
}

bool operator>(const Fraction &f1,const double d) {
    return (double)f1.get_numerator()/f1.get_denominator() > d;
}

bool operator<=(const Fraction &f1,const Fraction &f2) {
    return (double)f1.get_numerator()/f1.get_denominator() <= (double)f2.get_numerator()/f2.get_denominator();
}

bool operator<(const Fraction &f1,const double d) {
    return (double)f1.get_numerator()/f1.get_denominator() < d;
}

} // namespace ariel
