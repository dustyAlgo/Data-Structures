#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> hash = {
        {"brahma",121},
        {"vishnu", 177},
        {"mahesh",200}
    };
    for(auto i:hash){
        cout<<i.first<<":"<<i.second<<endl;
    }
        int* ptr = hash.end();
        cout<<ptr<<endl;
    return 0;
}
    

   
