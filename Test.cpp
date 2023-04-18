#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Fraction.hpp"

TEST_CASE("Initialization")
{
    Fraction a(4, 3);
    CHECK(a.get_numerator() == 4);
    CHECK(a.get_denominator() == 3);
    Fraction b = a + 1;
    CHECK(b.get_numerator() == 7);
    CHECK(b.get_denominator() == 3);
    //minimalization
    Fraction c(21,14);
    CHECK(c.get_numerator() == 3);
    CHECK(c.get_denominator() == 2);
    //minus
    Fraction d(4,-2);
    CHECK(d.get_numerator() == 2);
    CHECK(d.get_denominator() == -1);
    //both minus
    Fraction e(-5,-10);
    CHECK(d.get_numerator() == 1);
    CHECK(d.get_denominator() == 2);
}

TEST_CASE("Operators on Fractions")
{
    Fraction a(5, 3), b(14, 21);
    Fraction c = a + b;

    // operators
    CHECK(c.get_numerator() == 7);
    CHECK(c.get_denominator() == 3);
    c = a - b;
    CHECK(c.get_numerator() == 1);
    CHECK(c.get_denominator() == 1);
    c = a * b;
    CHECK(c.get_numerator() == 10);
    CHECK(c.get_denominator() == 9);
    c = a / b;
    CHECK(c.get_numerator() == 5);
    CHECK(c.get_denominator() == 2);

    //++ or --
    Fraction d = c++;
    CHECK(d.get_numerator() == 5);
    CHECK(d.get_denominator() == 2);
    d = ++c;
    CHECK(d.get_numerator() == 9);
    CHECK(d.get_denominator() == 2); // but now c = 9/2.
    d = c--;
    CHECK(d.get_numerator() == 9);
    CHECK(d.get_denominator() == 2);
    d = --c;
    CHECK(d.get_numerator() == 5);
    CHECK(d.get_denominator() == 2); // but now c = 5/2.

    // boolean
    CHECK((c > a) == true);
    CHECK((c >= a) == true);
    CHECK((c < b) == false);
    CHECK((c <= b) == false);
    Fraction e = c;
    CHECK((c == e) == true);
}

TEST_CASE ("llegal scenarios"){



}
