class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > maxi){
                maxi = mp[nums[i]];
            }
        }

        int sum = 0;
        for(auto it : mp){
            if(it.second == maxi){
                sum += it.second;
            }
        }
        return sum;
    }
};