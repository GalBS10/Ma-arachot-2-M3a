#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Initialization"){
    Fraction a(4,3);
    CHECK(a.get_numerator()==4);
    CHECK(a.get_denominator()==3);
    Fraction b = a+1;
    CHECK(b.get_numerator()==7);
    CHECK(b.get_numerator()==3);
}

TEST_CASE("Operators on Fractions"){
    Fraction a(5,3), b(14,21);
    Fraction c = a+b;
    CHECK(c.get_numerator()==7);
    CHECK(c.get_denominator()==3);
    c = a-b;
    CHECK(c.get_numerator()==1);
    CHECK(c.get_denominator()==1);
    c = a*b;
    CHECK(c.get_numerator()==10);
    CHECK(c.get_denominator()==9);
    c = a/b;
    CHECK(c.get_numerator()==5);
    CHECK(c.get_denominator()==2);
    c++;
    CHECK(c.get_numerator()==7);
    CHECK(c.get_denominator()==2);
    ++c;
    CHECK(c.get_numerator()==7);
    CHECK(c.get_denominator()==2);//but now c = 9/2.
    c--;
    CHECK(c.get_numerator()==7);
    CHECK(c.get_denominator()==2);
    --c;
    CHECK(c.get_numerator()==7);
    CHECK(c.get_denominator()==2);//but now c = 5/2.
    CHECK(c>a == true);
    
}