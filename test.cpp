#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int fact = n;
    for(int i = 1; i<n; i++){
        fact = fact * (n-i);
    }
    cout << fact<<endl;

    string x = "@", y="#";
    string conc = x+y;
    cout<<"concatinatio: "<<conc<<endl; 
    return 0;
}