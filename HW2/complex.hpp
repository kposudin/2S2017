
#ifndef complex_hpp
#define complex_hpp

#include <stdio.h>

class complex {
public:
    //complex(int one, int two);
    complex();
    complex(double a, double b);
    complex (const complex &c);
    complex& operator = (const complex& one);
    
    
    friend const complex operator + (const complex& one, const complex& two);
        
    friend const complex operator - (const complex& one, const complex& two);
    friend const complex operator * (const complex& one, const complex& two);
    friend void show(complex one);
    friend double abs (complex one);
    friend double im (complex one);
    friend double re (complex one);
    
    ~complex ();
private:
    double a;
    double b;
};

#endif /* complex_hpp */
