#include <iostream>
using namespace std;
char toLowercase(char ch){
   if(ch >='a' && ch <='z'){
      return ch;
   }
   else{
      char temp = ch - 'A' + 'a';
      return temp;
   }
}
int main() {
    string str;
    cin >> str;   // reads a word (no spaces)

    for (int i = 0; i < str.size(); i++) {
        str[i] = toLowercase(str[i]);
    }

    cout << str;
    return 0;
}