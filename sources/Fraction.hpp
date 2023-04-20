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
    Fraction operator+(double number) const;
    // friend Fraction operator+(double number, const Fraction &fraction);//

    Fraction operator-(Fraction fraction) const;
    Fraction operator-(double number) const;
    //friend Fraction operator-(double number, const Fraction &fraction);//

    Fraction operator/(Fraction fraction) const;
    Fraction operator/(double number) const;
    //friend Fraction operator/(double number, const Fraction &fraction);//

    Fraction operator*(Fraction fraction) const;
    friend Fraction operator*(double number, const Fraction &fraction);
    //friend Fraction operator*(double number, const Fraction &fraction);//

    Fraction &operator++();   // prefix++ operator
    Fraction &operator--();   // prefix -- operator
    Fraction operator++(int); // postfix ++ operator
    Fraction operator--(int); // postfix -- operator

    bool operator>(Fraction fraction) const;
    friend bool operator>(const Fraction &fraction, double number);
    // friend bool operator>( double number, const Fraction &fraction1);//

    bool operator<(Fraction fraction) const;
    friend bool operator<(const Fraction &fraction, double number);
    // friend bool operator<(double number, const Fraction &fraction1);//

    friend bool operator>=( const Fraction &fraction1, const Fraction &fraction2);
    // friend bool operator>=(const Fraction &fraction, double number);//
    // friend bool operator>=(double number, const Fraction &fraction);//


    friend bool operator<=(const Fraction &fraction1, const Fraction &fraction2);
    // friend bool operator<=(const Fraction &fraction, double number);//
    // friend bool operator<=(double number, const Fraction &fraction);//

    bool operator==(Fraction fraction) const;
    // friend bool operator==(const Fraction &fraction, double number);//
    // friend bool operator==(double number, const Fraction &fraction);//
    
    friend std::ostream &operator<<(std::ostream &_ostream, const Fraction &fraction);
    friend std::istream &operator>>(std::istream &_istream, Fraction &fraction);

    void minimilize();
    int gcd(int numer, int denom);
};
#endif
