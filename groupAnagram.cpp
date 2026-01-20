#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function to get the character frequency map of a string
vector<int> getFrequency(const string& s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    return freq;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> result;
    vector<bool> visited(n, false); // Keeps track of strings already grouped

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue; // Skip if this string is already in a group

        vector<string> group;
        group.push_back(strs[i]);
        visited[i] = true;

        // Step 1: Store char count of the current (i-th) string
        vector<int> freqI = getFrequency(strs[i]);

        // Step 2: Iterate over other strings after the current one
        for (int j = i + 1; j < n; j++) {
            if (!visited[j]) {
                // Get frequency of the j-th string
                vector<int> freqJ = getFrequency(strs[j]);

                // Compare frequency maps
                if (freqI == freqJ) {
                    group.push_back(strs[j]);
                    visited[j] = true; // Mark as grouped
                }
            }
        }
        result.push_back(group);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> grouped = groupAnagrams(strs);

    // Print result
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const string& s : group) cout << s << " ";
        cout << "]" << endl;
    }

    return 0;
}
