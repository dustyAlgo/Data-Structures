#include <iostream>
#include <string>
using namespace std;

class Test {
public:
    static int x;

    static void show() {
        cout << "x = " << x << endl;
        // cout << y;  ❌ cannot access non-static members
    }
};

int Test::x = 100;

int main() {
    Test::show();    // calling without object
}

