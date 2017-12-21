//
//  main.cpp
//  complex vector + header
//
//  Created by tin on 09.03.17.
//  Copyright © 2017 suh. All rights reserved.
//

#include <iostream>
#include "complex.hpp"
using namespace std;


complex p(0,0);





#include <cstdio>
#include <fstream>
using namespace std;
int v=0;

struct node{
    complex value;
    node*next;
    node*prev;
    
    
};
struct list {
    node*head;
    node*tail;
    
    list(){
        head=NULL;
        tail=NULL;
    };
    
    
    void push_start (complex newvalue){
        node*temp=new node;
        temp->value=newvalue;
        if(head==NULL){ head=temp;
            tail=temp;
        }
        else{
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    
    
    void push (complex newvalue){
        node*temp=new node;
        temp->value=newvalue;
        if(head==NULL){ head=temp;
            tail=temp;
        }
        else{
            temp->next=NULL;
            temp->prev=tail;
            tail->next=temp;
            tail=temp;
        }
        
    }
    
    complex pop(){
        complex temp=head->value;
        node*temp1=head;
        head=head->next;
        delete temp1;
        return temp;
    }
    
    complex& operator [](int index){
        node*temp1=head;
        int i;

        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return p;
            }
        }
        return temp1->value;
    }
    
    complex operator [](int index) const {
        node*temp1=head;
        int i;
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return p;
            }
        }
        return temp1->value;
    }
    
    ~list(){
    
    }
 
    
    
    
};








int main() {
    double a1,b1;
    cout << "enter c1 real / c1 im" << endl;
    cin >> a1 >> b1;
    freopen ("log.txt","a",stderr);
    list gucci;
    
    complex c1(a1,b1);
    cout << "enter c2 real / c2 im" << endl;
    cin >> a1 >> b1;
    complex c2(a1,b1);
    complex c3;
    complex c4;
    cout << "c1=";
    show(c1);
    
    cout << endl <<"c2=";
    show(c2);
    
    cout << endl << "+ operator demo" << endl << "c1+c2=";
    c3=c1+c2;
    show(c3);
    
    cout << "* operator demo" << endl << "c1*c2=";
    c4=c1*c2;
    show(c4);
    cout << endl;
    cout << "function <re> demo" << endl << "re(c1)=";
    cout << re(c1) << endl;
    
    cout << "function <im> demo" << endl << "im(c1)=";
    cout << im(c1) << endl;
    
    cout << endl << "abs demo" << endl << "abs(c1)=";
    cout << abs(c1) << endl << endl;
    cout << "c3=c1+c2=";
    show(c3);
    cout << endl << "c4=c1*c2=";
    show(c4);
    cout << endl <<  "vector demo" << endl;
    gucci.push(c1);
    gucci.push(c2);
    gucci.push(c3);
    gucci.push(c4);
    
    cout << endl;
    complex c5;
    for (int i=0; i<=3; i++){
        cout <<"v["<<i<<"]=" ;
        c5=gucci[i];
        show(c5);
    }
    
    
    
    return 0;

}
