//
//  main.cpp
//  list
//
//  Created by Suda idi m on 09.12.16.
//  Copyright © 2016 suh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int v=0;

struct node{
    int value;
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
    
    
    void push (int newvalue){
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
    
    void push_end (int newvalue){
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
    
    int pop(){
        int temp=head->value;
        node*temp1=head;
        head=head->next;
        delete temp1;
        return temp;
    }
    
    int& operator [](int index){
        node*temp1=head;
        int i;
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return v;
            }
        }
        return temp1->value;
    }
    
    int operator [](int index) const {
        node*temp1=head;
        int i;
        i=0;
        while (i!=index){
            temp1=temp1->next;
            i++;
            if (temp1->next==NULL and i<index){
                cerr<<"err:bounds violation" << endl;
                return v;
            }
        }
        return temp1->value;
    }
    
    
    void push_val (int val, int newvalue){
        node*temp1=head;
        node*temp2;
        node*temp=new node;
        temp->value=newvalue;
        while (temp1->value!=val){
            if (temp1->next==NULL){cout << "can't find node w/ value " << val << endl;return;}
            temp1=temp1->next;
        }
        
        if (temp1->prev!=NULL){
            temp2=temp1->prev;
            temp1->prev=temp;
            temp2->next=temp;
            temp->next=temp1;
            temp->prev=temp2;
        }
        else {
            temp1->prev=temp;
            temp->prev=NULL;
            temp->next=temp1;
        }
    }
    
    int pop_val(int val){
        int tval;
        node*temp1=head;
        node*temp;
        node*temp2;
        while (temp1->value!=val){
            temp1=temp1->next;
        }
        tval=temp1->value;
        if (temp1->next==NULL){
            temp=temp1->prev;
            temp->next=NULL;
            tail=temp;
            delete temp1;
            return tval;
        }
        if (temp1->prev==NULL){
            head=head->next;
            delete temp1;
            return tval;
        }
        else {
            temp=temp1->prev;
            temp2=temp1->next;
            temp->next=temp2;
            temp2->prev=temp;
            delete temp1;
            return tval;
        }
    }
    
    void show(){
        node*temp1=head;
        while(temp1->next!=NULL) {
            cout << temp1->value << endl;
            temp1=temp1->next;
        }
        cout << temp1->value << endl;
        delete temp1;
    }
    
    
    
};
void fcn(ostream &err) {
    err << "Error";
}


int main() {
    
    
   // fcn(std::cerr);
//    std::ofstream err("log.txt",std::ofstream::app);
    std::ofstream err("log.txt");
    fcn(err);
    
    int a[5];
    int i,x,b;
    list gucci;
    for(i=0; i<5; i++){
        cin >> a[i];
        gucci.push(a[i]);
    }
    b=gucci[3];
    /*
     x=gucci.pop();
     cout << x << " - popped value" << endl;
     x=gucci.pop_val(a[2]);
     cout << x << " - popped value " << endl;
     gucci.push_val(8, 228);
     gucci.push(100);
     gucci.push(150);
     gucci.push_val(100, 125);
     gucci.push_end(1232);*/
    cout << "list: " << endl;
    gucci.show();
    
    cout << "element n4 is " << b << endl;
    b=gucci[5];
    err.close();
    return 0;
}
