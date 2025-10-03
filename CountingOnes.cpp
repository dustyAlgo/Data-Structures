#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        long long int count = 0;
        while(n>0){
            if(n&1==1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};

int main(){
    /*int num = 13;
    Solution sol;
    int ans = sol.hammingWeight(num);
    cout << ans;*/
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int add = arr[2] + 1;
    cout<<add;
    return add; 
}