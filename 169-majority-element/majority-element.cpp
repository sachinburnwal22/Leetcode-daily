class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int req = n/2;
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto m : mp){
            if(m.second > req){
                ans = m.first;
            }
        }
        return ans;
    }
};