#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    
    // Example 1
    string s1 = "babad";
    cout << "Input: " << s1 << "\nOutput: " << sol.longestPalindrome(s1) << endl; 
    // Possible output: "bab" or "aba"

    // Example 2
    string s2 = "cbbd";
    cout << "Input: " << s2 << "\nOutput: " << sol.longestPalindrome(s2) << endl; 
    // Output: "bb"

    return 0;
}
