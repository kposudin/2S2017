#include <iostream>


using namespace std;


template <typename t1, typename t2, typename t3>
class Triad{
 t1 *a;
 t2 *b;
 t3 *c;
 public:
 Triad(t1 gro, t2 org, t3 greg){
 a = new t1;
 *a=gro;
 b = new t2;
 *b=org;
 c = new t3;
 *c=greg;
 };
 
 
 void show(){
 cout << *a <<" "<< *b << " " << *c << endl;
 }
 Triad (const Triad &A){
 cout << "Конструктор копирования" << endl;
 a=new t1;
 b=new t2;
 c=new t3;
 *a=*A.a;
 *b=*A.b;
 *c=*A.c;
 
 }
 ~Triad()
 {
 cout << "Деструктор" << endl;;
 delete a;
 delete b;
 delete c;
 
 }
 };


int main(int argc, const char * argv[]) {
    int f;
    char g;
    bool h;
    cin >> f;
    cin >> g;
    cin >> h;
    Triad <int, char, bool>obj1(f,g,h);
    obj1.show();
    Triad <int, char, bool> obj2 = obj1;
    cout << endl;
    obj2.show();
    
    return 0;
}
