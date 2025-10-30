#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        backTracking(path, nums, 0, ans);
        return ans; 
    }
    void backTracking(vector<int> &path, vector<int> &nums, int start, vector<vector<int>> &ans) {
        ans.push_back(path);
        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backTracking(path, nums, i + 1, ans);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // Test input

    vector<vector<int>> result = sol.subsets(nums);

    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
