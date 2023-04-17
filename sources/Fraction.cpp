#include "Fraction.hpp"



//in order to get rid of the errors i must implement these functions
//I also implemented some easy functions too.

Fraction::Fraction(int n, int d) : numerator{n}, denominator{d} {} //constructor

//getters
int Fraction::get_numerator() const {
    return numerator;
}

int Fraction::get_denominator() const {
    return denominator;
}

//operators only with Fractions
Fraction Fraction::operator+(Fraction b) const {// plus
    int new_num = numerator * b.denominator + denominator * b.numerator;
    int new_den = denominator * b.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(Fraction b) const {// minus
    int new_num = numerator * b.denominator - denominator * b.numerator;
    int new_den = denominator * b.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator/(Fraction b) const {// devision
    int new_num = numerator * b.denominator;
    int new_den = denominator * b.numerator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(Fraction b) const {// multiply
    int new_num = numerator * b.numerator;
    int new_den = denominator * b.denominator;
    return Fraction(new_num, new_den);
}

Fraction& Fraction::operator++() {// plus 1 and then execute
    numerator += denominator;
    return *this;
}

Fraction& Fraction::operator--() {// minus 1 and then execute
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator++(int) {// execute and then plus 1
    Fraction result = *this;
    numerator += denominator;
    return result;
}

Fraction Fraction::operator--(int) {// execute and then minus 1
    Fraction result = *this;
    numerator -= denominator;
    return result;
}

//operators with consts and Fractions

Fraction Fraction::operator+(const double d) const {//plus
    return Fraction(numerator + d * denominator, denominator);
}

Fraction Fraction::operator-(const double d) const {//minus
    return Fraction(numerator - d * denominator, denominator);
}

Fraction Fraction::operator/(const double d) const {// devision
    return Fraction(numerator, denominator * d);
}

Fraction operator*(const double d, const Fraction &f) {// multiply
    return Fraction(d * f.get_numerator(), f.get_denominator());
}

std::ostream &operator<<(std::ostream &os, const Fraction &f) {//to string
    os << f.get_numerator() << "/" << f.get_denominator();
    return os;
}

//boolean
bool Fraction::operator>(Fraction b) const {//bigger
    return (double)numerator/denominator > (double)b.numerator/b.denominator;
}
bool operator>=(const Fraction &f1,const Fraction &f2) {//bigger or equal to
    return (double)f1.get_numerator()/f1.get_denominator() >= (double)f2.get_numerator()/f2.get_denominator();
}

bool operator>(const Fraction &f1,const double d) {//bigger
    return (double)f1.get_numerator()/f1.get_denominator() > d;
}

bool operator<=(const Fraction &f1,const Fraction &f2) {//smaller or equal to
    return (double)f1.get_numerator()/f1.get_denominator() <= (double)f2.get_numerator()/f2.get_denominator();
}

bool operator<(const Fraction &f1,const double d) {//smaller
    return (double)f1.get_numerator()/f1.get_denominator() < d;
}
bool Fraction::operator<(Fraction b) const {//smaller
    return (double)numerator/denominator < (double)b.numerator/b.denominator;
}
bool Fraction::operator==(Fraction b) const {//equal
    return numerator == b.numerator && denominator == b.denominator;
}


