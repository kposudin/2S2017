#include <iostream>
#include "functions.hpp"
#include "globals.hpp"
using namespace std;


int main() {
    cout << "Input n / k" << endl;
    cin >> n >> k;
    cout << "All combinations" << endl;
    rec(-1, 0);
    return 0;
}
