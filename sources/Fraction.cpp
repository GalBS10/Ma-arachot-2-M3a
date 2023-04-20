#include "Fraction.hpp"

// in order to get rid of the errors i must implement these functions
// I also implemented some easy functions too.

Fraction::Fraction(int numer, int denomin)
{ // constructor
    try
    {
        if (denomin == 0)
        {
            throw std::overflow_error("Divide by zero exception");//found this throw in stackoverflow.
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

Fraction Fraction::operator+(double number) const
{ // plus
    Fraction answer(numerator + number * denominator, denominator);
    answer.minimilize();
    return answer;
}

Fraction Fraction::operator-(double number) const
{ // minus
    Fraction answer(numerator - number * denominator, denominator);
    answer.minimilize();
    return answer;
}

Fraction Fraction::operator/(double number) const
{ // devision
    Fraction answer(numerator, denominator * number);
    answer.minimilize();
    return answer;
}

Fraction operator*(double number, const Fraction &fraction)
{ // multiply
    Fraction answer(number * fraction.get_numerator(), fraction.get_denominator());
    answer.minimilize();
    return answer;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
{ // to string
    os << fraction.get_numerator() << "/" << fraction.get_denominator();
    return os;
}

// boolean
bool Fraction::operator>(Fraction fraction) const
{ // bigger
    return (double)numerator / denominator > (double)fraction.numerator / fraction.denominator;
}
bool operator>=(const Fraction &fraction1, const Fraction &fraction2)
{ // bigger or equal to
    return (double)fraction1.get_numerator() / fraction1.get_denominator() >= (double)fraction2.get_numerator() / fraction2.get_denominator();
}

bool operator>(const Fraction &fraction1, double number)
{ // bigger
    return (double)fraction1.get_numerator() / fraction1.get_denominator() > number;
}

bool operator<=(const Fraction &fraction1, const Fraction &fraction2)
{ // smaller or equal to
    return (double)fraction1.get_numerator() / fraction1.get_denominator() <= (double)fraction2.get_numerator() / fraction2.get_denominator();
}

bool operator<(const Fraction &fraction1, const double number)
{ // smaller
    return (double)fraction1.get_numerator() / fraction1.get_denominator() < number;
}
bool Fraction::operator<(Fraction fraction) const
{ // smaller
    return (double)numerator / denominator < (double)fraction.numerator / fraction.denominator;
}
bool Fraction::operator==(Fraction fraction) const
{ // equal
    return numerator == fraction.numerator && denominator == fraction.denominator;
}
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

int Fraction::gcd(int numer, int denom)
{ // getting the max num that divide both of the numerator and denominator.
    if (denom != 0)
        return gcd(denom, numer % denom);
    else
        return numer;
}
