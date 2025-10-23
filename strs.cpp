#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin,s); // getline() lets you put spaces while giving input string
    cout << s.length();
}