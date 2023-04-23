#include "Fraction.hpp"
#include <cmath>

// in order to get rid of the errors i must implement these functions
// I also implemented some easy functions too.

Fraction::Fraction(int numer, int denomin)
{ // constructor
    try
    {
        if (denomin == 0)
        {
            throw std::overflow_error("Division by zero exception");//found this throw in stackoverflow.
        }
        if(numer < 0 && denomin < 0){// if both negetive then its positive number.
            numer = 0-numer;
            denomin = 0-denomin;
        }
        int _gcd = gcd(numer, denomin);
        numerator = numer / _gcd;
        denominator = denomin / _gcd;
    }
    catch (exception &e)
    {
        cout << "coulden't initialize Fraction";
    }
}

Fraction Fraction::convert(float number){

return Fraction(int(1000*number),1000);

}

// getters
int Fraction::get_numerator() const
{
    return numerator;
}

int Fraction::get_denominator() const
{
    return denominator;
}

// operators only with Fractions
Fraction Fraction::operator+(Fraction fraction) const
{ // plus
    int new_num = numerator * fraction.get_denominator() + denominator * fraction.get_numerator();
    int new_den = denominator * fraction.get_denominator();
    Fraction answer(new_num, new_den);
    answer.minimilize();
    return answer;
}

Fraction Fraction::operator-(Fraction fraction) const
{ // minus
    int new_num = numerator * fraction.get_denominator() - denominator * fraction.get_numerator();
    int new_den = denominator * fraction.get_denominator();
    Fraction answer(new_num, new_den);
    answer.minimilize();
    return answer;
}

Fraction Fraction::operator/(Fraction fraction) const
{ // devision
    int new_num = numerator * fraction.get_denominator();
    int new_den = denominator * fraction.get_numerator();
    Fraction answer(new_num, new_den);
    answer.minimilize();
    return answer;
}

Fraction Fraction::operator*(Fraction fraction) const
{ // multiply
    int new_num = numerator * fraction.get_numerator();
    int new_den = denominator * fraction.get_denominator();
    Fraction answer(new_num, new_den);
    answer.minimilize();
    return answer;
}

Fraction &Fraction::operator++()
{ // plus 1 and then execute
    numerator += denominator;
    return *this;
}

Fraction &Fraction::operator--()
{ // minus 1 and then execute
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator++(int)
{ // execute and then plus 1
    Fraction result = *this;
    numerator += denominator;
    return result;
}

Fraction Fraction::operator--(int)
{ // execute and then minus 1
    Fraction result = *this;
    numerator -= denominator;
    return result;
}

// operators with consts and Fractions
// plus
Fraction Fraction::operator+(float number) const
{ 
    return convert(number)+*this;
}

Fraction operator+(float number, const Fraction &fraction){
    return Fraction::convert(number)+fraction;//because its a "friend" function we need to use ::
}
// minus
Fraction Fraction::operator-(float number) const
{ 
    return convert(number)-*this;
}

Fraction operator-(double number, const Fraction &fraction){
    return Fraction::convert(number)-fraction;
}
// devision
Fraction Fraction::operator/(float number) const
{ 
    return convert(number)/ *this;
}

Fraction operator/(float number, const Fraction &fraction)
{
    return Fraction::convert(number)/fraction;
}
// multiply
Fraction Fraction::operator*(float number) const
{ 
    return Fraction::convert(number)* *this;
}

Fraction operator*(float number, const Fraction &fraction)
{
    return Fraction::convert(number)*fraction;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
{ // to string
    os << fraction.get_numerator() << "/" << fraction.get_denominator();
    return os;
}

// boolean

// bigger
bool Fraction::operator>(Fraction fraction) const
{ 
    return (float)numerator / denominator > (float)fraction.get_numerator() / fraction.get_denominator();
}

bool operator>(const Fraction &fraction1, float number)
{
    return fraction1>Fraction::convert(number);
}

bool operator>( float number, const Fraction &fraction1)
{
    return Fraction::convert(number)>fraction1;
}

// smaller
bool Fraction::operator<(Fraction fraction) const
{
    return (float)numerator / denominator < (float)fraction.get_numerator() / fraction.get_denominator();
}

bool operator<(const Fraction &fraction1, const float number)
{ 
    return fraction1 < Fraction::convert(number);
}
bool operator<(float number, const Fraction &fraction1)
{
    return Fraction::convert(number) < fraction1;
}

// bigger or equal to
bool Fraction::operator>=(const Fraction &fraction) const
{ 
    return (float)numerator / denominator >= (float)fraction.get_numerator() / fraction.get_denominator();
}

bool Fraction::operator>=(float number) const
{
    return *this >= convert(number);
}

bool operator>=(float number, const Fraction &fraction)
{
    return Fraction::convert(number) >= fraction;
}

// smaller or equal to
bool Fraction::operator<=(const Fraction &fraction) const
{ 
    return (float)numerator / denominator <= (float)fraction.get_numerator() / fraction.get_denominator();
}

bool Fraction::operator<=(float number) const
{
    return *this <= convert(number);
}

bool operator<=(float number, const Fraction &fraction)
{
    return Fraction::convert(number) <= fraction;
}

// equal
bool Fraction::operator==(Fraction fraction) const
{
    return numerator == fraction.numerator && denominator == fraction.denominator;
}

bool Fraction::operator==(float number) const
{
    return *this == convert(number);
}

bool operator==(float number, const Fraction &fraction)
{
    return Fraction::convert(number) == fraction;
}


//side functions
void Fraction::minimilize()
{

    int _gcd = gcd(get_numerator(), get_denominator()); // minimalizing the Fraction.
    if (_gcd != 1)
    {
        numerator = get_numerator() / _gcd;
        denominator = get_denominator() / _gcd;
    }
    // else nothing happens
}

int Fraction::gcd(int numer, int denom)//found this code on the internet.
{ // getting the max num that divide both of the numerator and denominator.
    if (denom != 0)
        return gcd(denom, numer % denom);
    else
        return numer;
}
