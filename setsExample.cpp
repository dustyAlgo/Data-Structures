#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;
 int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        // If target is in the right sorted half
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        }
        // Otherwise in the left half
        else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
int main(){
    unordered_set<int> s = {1, 2, 3,3,3};
    int total,left=0;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    for(int num : s){
        total +=num;
    }
    for(int i =0; i<nums.size(); i++){
        int right = total - left - nums[i];
    }
    return -1;
};