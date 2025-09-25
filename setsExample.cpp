#include <unordered_set>
#include <iostream>
using namespace std;

int main(){
    unordered_set<int> s = {1, 2, 3,3,3};

    for(int num : s){
        cout << num << endl;
    }
}