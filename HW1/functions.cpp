//
//  functions.cpp
//  combinations hw1
//
//  Created by tin on 04.03.17.
//  Copyright © 2017 suh. All rights reserved.
//

#include <stdio.h>
#include "functions.hpp"
#include "globals.hpp"
#include <iostream>
using namespace std;


void rec(int lst, int cnt) {
    int i;
    if(cnt == k) {
        for(i = 0; i < n; i++) {
            if(u[i]) {
                cout << i+1 << ' ';
            }
        }
        cout << endl;
        return;
    }
    
    if(lst + 1 >= n) {
        return;
    }
    
    u[lst + 1] = true;
    rec(lst + 1, cnt + 1);
    u[lst + 1] = false;
    rec(lst + 1, cnt);
    return;
}
