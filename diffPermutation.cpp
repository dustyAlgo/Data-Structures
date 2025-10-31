#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    void getpermutation(vector<int>& nums, int idx, set<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.insert(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getpermutation(nums, idx + 1, ans);
            swap(nums[i], nums[idx]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        getpermutation(nums, 0, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2}; // Test input with duplicate
    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "All unique permutations:\n";
    for (const auto& perm : result) {
        cout << "[";
        for (size_t i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i < perm.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
