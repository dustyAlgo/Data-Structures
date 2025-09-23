#include <iostream>
using namespace std;
int main(){
   int num;
   cin >> num;
   int i=0;
   int j = 0; 
   while(i<=num){
    int spaces = num - i;
    while(spaces){
        if(spaces == 0){
            cout << "@";
        }
        cout << "_ ";
        spaces--;
        cout << spaces;
    }
    cout <<"\n";
    i++;
   }
    return 0;
}