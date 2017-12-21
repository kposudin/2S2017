//
//  main.cpp
//  tick_queue test
//
//  Created by tin on 06.04.17.
//  Copyright © 2017 suh. All rights reserved.
//

//
//  main.cpp
//  list
//
//  Created by Suda idi m on 16.12.16.
//  Copyright © 2016 suh. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int time;
    char name[5];
    node*next;
    node*prev;
    
};
struct list {
    node*head;
    // node*tail;
    
    list(){
        head=NULL;
        //  tail=NULL;
    };
    
    
    void tick(){
        
        node *temp1=new node;
        
        int i;
        temp1->time=head->time;
        
        for (i=0;i<5;i++){
            temp1->name[i]=head->name[i];
        }
        
        temp1->next=head->next;
        temp1->prev=head->prev;
        
        head->time-=1;
        if (head->next!=NULL){
            while(temp1->next!=NULL) {
                temp1=temp1->next;
                temp1->time-=1;
                
            }
        }
        tick_clean();
        
    }
    
    void tick_clean(){
        if (head!=NULL){
            if (head->time==0){
                delhead();
            }
            else return;
        }
        else return;
        
    }
    
    
    
    void delhead(){
        
        int i;
        for (i=0; i<5; i++){
            cout << head->name[i];
        }
        cout << endl;
        node*temp1=head;
        head=head->next;
        delete temp1;
        if (head!=NULL){
            head->prev=NULL;
        }
        
        
        tick_clean();
    }
    
    
    
    void push_val (int newtime,char newname[5]){
        
        int i;
        node*temp=new node; // creating memory for new node
        
        for (i=0;i<5;i++){
            temp->name[i]=newname[i];
        }
        temp->time=newtime;
        
        if (head==NULL){       //If queue is empty -> creating head/tail
            temp->prev=NULL;
            temp->next=NULL;
            head=temp;
            //   tail=temp;
            return;
        }
        else insert(newtime,newname);
    }
   
    
    void insert (int newtime,char newname[5]){
        if (newtime<=0){
            cout << "error, time should be positive" << endl;
            return;
        }
        node*temp1=head;
        node*temp2;
        node*temp=new node;
        temp->time=newtime;
        int i;
        for (i=0; i<5; i++){
            temp->name[i]=newname[i];
        }
        while (temp1->time<=newtime){
            if (temp1->next==NULL){temp1->next=temp; temp->prev=temp1; temp->next=NULL;return;}
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
            head=temp;
        }
    }
    
    
    void show_head(){
        int i;
        node*temp1=head;
        cout << temp1->time << " ";
        for (i=0;i<5;i++){
            cout << temp1->name[i];
        }
        return;
    }
    
    void show(){
        int i;
        node*temp1=head;
        if (head==NULL) cout << "queue is empty";
        else{
        while(temp1->next!=NULL) {
            cout << temp1->time << " ";
            for (i=0; i<5; i++){
                cout << temp1->name[i];
            }
            cout << endl;
            temp1=temp1->next;
        }
        cout << temp1->time << " ";
        for (i=0; i<5; i++){
            cout << temp1->name[i];
        }
        }
        cout << endl;
        //delete temp1;
    
    }
    
    
};



int push_val_test(){
    cout << "push method test" << endl;
    cout << "at the input, the function takes the value of the variable (integer) and its name (char[5]), and then sorts in ascending order of the value. "<< endl;
    cout << "testing method with different values. 3 of them will be bigger than the integer boundaries. 3 - smaller" << endl;
    char c[5];
    list gucci;
    c[0]='p';
    c[1]='r';
    c[2]='o';
    c[3]='c';
    c[4]='1';
    cout << "pushing value 100"<<endl;
    gucci.push_val(100,c);
    c[4]='2';
    cout << "pushing value 100000"<<endl;
    gucci.push_val(100000,c);
    c[4]='3';
    cout << "pushing value 4294967295"<<endl;
    gucci.push_val(4294967295,c);
    c[4]='4';
    cout << "pushing value 4294967296"<<endl;
    gucci.push_val(4294967296,c);
    c[4]='5';
    cout << "pushing value -100"<<endl;
    gucci.push_val(-100,c);
    c[4]='6';
    cout << "pushing value -100000"<<endl;
    gucci.push_val(-100000,c);
    c[4]='7';
    cout << "pushing value -2147483648"<<endl;
    gucci.push_val(-2147483648,c);
    c[4]='8';
    cout << "pushing value -2147483649"<<endl;
    gucci.push_val(-2147483649,c);
    c[4]='9';
    cout << "pushing value 0" << endl;
    gucci.push_val(0,c);
    cout << "expected result:" << endl <<"100 proc1" << endl <<"100000 proc2" << endl <<"2147483647 proc8"<< endl << endl;
    cout << "real result:"<< endl << endl;
    
    gucci.show();

    
    
    
    return 0;
}

void show_method_test(){
    cout <<endl<<endl<< "show method test" << endl;
    cout << "expected result:  " << endl << "queue is empty" << endl << "100 blud" << endl << "99 blud" << endl;
    cout << "real result:"<<endl;
    list gucci;
    cout << endl;
    gucci.show();
    char c[4];
    c[0]='b';
    c[1]='l';
    c[2]='u';
    c[3]='d';
    gucci.push_val(100,c);
    gucci.show();
    gucci.tick();
    gucci.show();
    
    
    
    
}

void tick_test(){
cout <<endl<<endl<< "tick method test" << endl;
    cout << "testin huge amount of ticks" << endl;
    char c[5];
    list gucci;
    c[0]='p';
    c[1]='r';
    c[2]='o';
    c[3]='c';
    c[4]='1';
    cout << "pushing value 100"<<endl;
    gucci.push_val(100,c);
    c[4]='2';
    cout << "pushing value 100000"<<endl;
    gucci.push_val(10000000,c);
    cout << "expected result:  " << endl << "proc1" << endl << "proc2" << endl;
    cout << "real result:"<<endl;
     while (gucci.head!=NULL){
         gucci.tick();
    }
    cout << "No more processes" << endl;
}


int main() {
    tick_test();
    cout << endl;
    push_val_test();
    cout << endl;
    show_method_test();
    /*int a;
    char c[5];
    char com[4];
    
    int i;
    list gucci;*/
    
    //1ST NODE
   /* cout << "Insert 1st process. Input time in sec and the name of process (5 letters only) " << endl;
    
    cin >> a;
    for (i=0; i<5; i++){
        cin >> c[i];
    }
    gucci.push_val(a,c);
    
    // cout << "nsrt for insert; tick for 1sek; show to show all the elements + time remained; " << endl;
    
    
    while (gucci.head!=NULL){
        
        cout << "nsrt for insert; tick for 1sek; show to show all the elements + time remained; " << endl;
        //COMMAND MENU
        
        
        for (i=0;i<4;i++){
            cin >> com[i];
        }
        
        
        
        //INPUT
        if (com[0]=='n' and com[1]=='s' and com[2]=='r' and com[3]=='t'){
            cout << "Input time in sec and the name of process (5 letters only)" << endl;
            cin >> a;
            for (i=0; i<5; i++){
                cin >> c[i];
            }
            gucci.push_val(a,c);
        }
        
        
        //TICK
        else if (com[0]=='t' and com[1]=='i' and com[2]=='c' and com[3]=='k'){
            gucci.tick();
        }
        
        
        //SHOW
        else if (com[0]=='s' and com[1]=='h' and com[2]=='o' and com[3]=='w'){
            gucci.show();
        }
        else cout << "Unknown command" << endl;
        
    }                   //The end of the gucci head while.
    
    
    cout << "No more processes." << endl;
    
    
    
    */
    
    return 0;
    
}

