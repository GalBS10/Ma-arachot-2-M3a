#include "Fraction.hpp"



//in order to get rid of the errors i must implement these functions
//I also implemented some easy functions too.

Fraction::Fraction(int numer, int denomin) : numerator{numer}, denominator{denomin} {} //constructor

//getters
int Fraction::get_numerator() const {
    return numerator;
}

int Fraction::get_denominator() const {
    return denominator;
}

//operators only with Fractions
Fraction Fraction::operator+(Fraction fraction) const {// plus
    int new_num = numerator * fraction.denominator + denominator * fraction.numerator;
    int new_den = denominator * fraction.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(Fraction fraction) const {// minus
    int new_num = numerator * fraction.denominator - denominator * fraction.numerator;
    int new_den = denominator * fraction.denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator/(Fraction fraction) const {// devision
    int new_num = numerator * fraction.denominator;
    int new_den = denominator * fraction.numerator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(Fraction fraction) const {// multiply
    int new_num = numerator * fraction.numerator;
    int new_den = denominator * fraction.denominator;
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

Fraction Fraction::operator+( double number) const {//plus
    return Fraction(numerator + number * denominator, denominator);
}

Fraction Fraction::operator-( double number) const {//minus
    return Fraction(numerator - number * denominator, denominator);
}

Fraction Fraction::operator/( double number) const {// devision
    return Fraction(numerator, denominator * number);
}

Fraction operator*( double number, const Fraction &fraction) {// multiply
    return Fraction(number * fraction.get_numerator(), fraction.get_denominator());
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {//to string
    os << fraction.get_numerator() << "/" << fraction.get_denominator();
    return os;
}

//boolean
bool Fraction::operator>(Fraction fraction) const {//bigger
    return (double)numerator/denominator > (double)fraction.numerator/fraction.denominator;
}
bool operator>=(const Fraction &fraction1,const Fraction &fraction2) {//bigger or equal to
    return (double)fraction1.get_numerator()/fraction1.get_denominator() >= (double)fraction2.get_numerator()/fraction2.get_denominator();
}

bool operator>(const Fraction &fraction1, double number) {//bigger
    return (double)fraction1.get_numerator()/fraction1.get_denominator() > number;
}

bool operator<=(const Fraction &fraction1,const Fraction &fraction2) {//smaller or equal to
    return (double)fraction1.get_numerator()/fraction1.get_denominator() <= (double)fraction2.get_numerator()/fraction2.get_denominator();
}

bool operator<(const Fraction &fraction1,const double number) {//smaller
    return (double)fraction1.get_numerator()/fraction1.get_denominator() < number;
}
bool Fraction::operator<(Fraction fraction) const {//smaller
    return (double)numerator/denominator < (double)fraction.numerator/fraction.denominator;
}
bool Fraction::operator==(Fraction fraction) const {//equal
    return numerator == fraction.numerator && denominator == fraction.denominator;
}


