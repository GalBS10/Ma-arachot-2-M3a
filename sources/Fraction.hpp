#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace ariel
{

}
class Fraction
{

private:
    int numerator;
    int denominator;

public:
    Fraction(int n, int d)
    {
    }
    Fraction operator+(Fraction b);
    Fraction operator-(Fraction b);
    Fraction operator/(Fraction b);
    Fraction operator*(Fraction b);
    Fraction operator++();
    Fraction operator--();
    Fraction operator>=(Fraction b);
    Fraction operator>(Fraction b);
    Fraction operator*(const double d) const
    {
        int n = numerator * d;
        return Fraction(n, denominator);
    }
    Fraction operator+(const double d) const
    {
        int n = numerator + d * denominator;
        return Fraction(n, denominator);
    }

    Fraction operator-(const double d) const
    {
        int n = numerator - d * denominator;
        return Fraction(n, denominator);
    }

    Fraction operator/(const double d) const
    {
        int n = numerator;
        int d_new = denominator * d;
        return Fraction(n, d_new);
    }
};