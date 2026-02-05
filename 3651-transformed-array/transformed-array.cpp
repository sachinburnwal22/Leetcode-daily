class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> result;
        while(i < n){
            if(nums[i] > 0){
                int rem = (nums[i] + i) % n;
                result.push_back(nums[rem]);
            }else if(nums[i] < 0){
                int idx = ((i + nums[i]) % n + n) % n;
                result.push_back(nums[idx]);
            }else{
                result.push_back(nums[i]);
            }
            i++;
        }
        return result;
    }
};