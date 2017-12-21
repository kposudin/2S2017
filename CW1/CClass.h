#ifndef __CCLASS_H__
#define __CCLASS_H__

class Triad{
    int *a;
    int *b;
    int *c;
public:
    Triad(int gro, int org, int greg){
        a = new int;
        *a=gro;
        b = new int;
        *b=org;
        c = new int;
        *c=greg;
    };
    
    
    void show(){
        std::cout << *a <<" "<< *b << " " << *c << std::endl;
    }
    Triad (const Triad &A){
        std::cout << "Конструктор копирования" << std::endl;
        a=new int;
        b=new int;
        c=new int;
        *a=*A.a;
        *b=*A.b;
        *c=*A.c;
        
    }
    ~Triad()
    {
        std::cout << "bruh" << std::endl;;
        delete a;
        delete b;
        delete c;
        
    }
};


#endif
