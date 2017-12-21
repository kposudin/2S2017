
/*class Triad{
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
        cout << *a <<" "<< *b << " " << *c << endl;
    }
    Triad (const Triad &A){
    cout << "Конструктор копирования" << endl;
        a=new int;
        b=new int;
        c=new int;
        *a=*A.a;
        *b=*A.b;
        *c=*A.c;
        
    }
    ~Triad()
    {
        cout << "bruh" << endl;;
        delete a;
        delete b;
        delete c;
        
    }
};*/
void V(Triad A, Triad B){}

int main(int argc, const char * argv[]) {
    int f,g,h;
    cin >> f >> g >> h;
    Triad obj1(f,g,h);
    obj1.show();
    Triad obj2 = obj1;
    cout << endl;
    obj2.show();
    V(obj1,obj2);
    
    return 0;
}
