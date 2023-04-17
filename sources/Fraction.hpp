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
    Fraction(int n, int d);
    int get_numerator() const;
    int get_denominator() const;
    Fraction operator+(Fraction b) const;
    Fraction operator-(Fraction b) const;
    Fraction operator/(Fraction b) const;
    Fraction operator*(Fraction b) const;
    Fraction& operator++(); //prefix ++ operator
    Fraction& operator--(); //prefix -- operator
    Fraction operator++(int); // postfix ++ operator
    Fraction operator--(int); // postfix -- operator
    bool operator>(Fraction b) const;
    Fraction operator+(const double d) const;
    Fraction operator-(const double d) const;
    Fraction operator/(const double d) const;
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
    friend Fraction operator*(const double d, const Fraction &f);
    friend bool operator>=(const Fraction &f1,const Fraction &f2);
    friend bool operator>(const Fraction &f1,const double d);
    friend bool operator<=(const Fraction &f1,const Fraction &f2);
    friend bool operator<(const Fraction &f1,const double d);
    
};

