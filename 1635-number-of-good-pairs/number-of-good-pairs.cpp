class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }

        int sum = 0;

        for(auto it : mp){
            int m = it.second.size();
            if(m < 2){
                continue;
            }
            int k = (m * (m-1))/2;
            sum += k;
        }
        return sum;
    }
};