//
//  complex.cpp
//  complex vector + header
//
//  Created by tin on 09.03.17.
//  Copyright © 2017 suh. All rights reserved.
//

#include "complex.hpp"
#include <iostream>
#include <cmath>
using namespace std;

//complex::complex(int one, int two){
complex::complex(double one, double two){
        a=one;
        b=two;
    }
complex::complex(){  //
    a=0;
    b=0;
}
complex::complex (const complex &c)   // конструктор копирования
{
    a = c.a;
    b = c.b;
}
complex::~complex ()
{
}

    complex& complex::operator = (const complex& one){
        a=one.a;
        b=one.b;
        return *this;
    }
    
    const complex operator + (const complex& one, const complex& two){
        complex temp(one.a+two.a,one.b+two.b);
        return temp;
    }
    
    const complex operator - (const complex& one, const complex& two){
        complex temp(one.a-two.a,one.b-two.b);
        return temp;
    }
    
    const complex operator * (const complex& one, const complex& two){
        complex temp(one.a*two.a-one.b*two.b,one.a*two.b+one.b*two.a);
        return temp;
    }
    
    void show(complex one){
        cout << one.a << "+" << one.b <<"i" << endl;
    }
double abs (complex one)
{
    return sqrt(one.a*one.a + one.b*one.b);
}
double im (complex one)
{
    return one.b;
}
double re (complex one)
{
    return one.a;
}


