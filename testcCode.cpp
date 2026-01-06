#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> pair;
        if(arr1.size()<arr2.size()){
           return isPossible(k, arr2, arr1); 
        }
        for(int i =0; i<arr1.size(); i++){
            int find = k - arr1[i];
            bool flag = false;
            for(int j = 0; j<arr2.size(); j++){
                    if(arr2[j]>=find){
                        arr2[j] = INT_MIN;
                        flag = true;
                        break;
                    }
                }
                if (flag) return false;
            
            }
            return true;
        }
}; 
int main(){
   Solution sol;
   int k = 10;
    vector<int> arr1 = {12, 3, 4, 7, 10};
    vector<int> arr2 = {12, 3, 4, 7, 10};
    bool result = sol.isPossible(k, arr2, arr1); 
    return 0;
 }