class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }

        for(int i=mini; i<=maxi; i++){
            if(find(nums.begin(), nums.end(), i) == nums.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};