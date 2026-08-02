class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;

        int takeI = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int takeJ = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return max(takeI, takeJ);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);

        int p1 = solve(0, n-1, nums);
        int p2 = sum - p1;
        return p1 >= p2;
    }
};