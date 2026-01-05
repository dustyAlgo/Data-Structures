// maximum operation code using Unordered map/ dictonary;
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for(int x:nums){
            int find = k-x;
            if(freq[find] > 0){
                count++;
                freq[find]--;
            }
            else{
            freq[x]++;
            }
        }
        return count;
    }