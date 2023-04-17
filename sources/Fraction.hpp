#ifndef FRACTION
#define FRACTION
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{

}
class Fraction
{

private:
    int numerator;
    int denominator;

public:
    Fraction(int numer, int denomin);
    int get_numerator() const;
    int get_denominator() const;
    Fraction operator+(Fraction fraction) const;
    Fraction operator-(Fraction fraction) const;
    Fraction operator/(Fraction fraction) const;
    Fraction operator*(Fraction fraction) const;
    Fraction& operator++(); //prefix++ operator
    Fraction& operator--(); //prefix -- operator
    Fraction operator++(int); // postfix ++ operator
    Fraction operator--(int); // postfix -- operator
    bool operator>(Fraction fraction) const;
    bool operator<(Fraction fraction) const;
    Fraction operator+( double number) const;
    Fraction operator-( double number) const;
    Fraction operator/( double number) const;
    friend std::ostream &operator<<(std::ostream &_ostream, const Fraction &fraction);
    friend Fraction operator*( double number, const Fraction &fraction);
    friend bool operator>=(const Fraction &fraction1,const Fraction &fraction2);
    friend bool operator>(const Fraction &fraction1, double number);
    friend bool operator<=(const Fraction &fraction1,const Fraction &fraction2);
    friend bool operator<(const Fraction &fraction1, double number);
    bool operator==(Fraction fraction) const;
    
};
#endif

