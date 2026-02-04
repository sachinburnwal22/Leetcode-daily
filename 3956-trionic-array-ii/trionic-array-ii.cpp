class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {

        int n = nums.size();
        long long res = LLONG_MIN;

        for (int i = 1; i < n - 2; i++) {

            int a = i;
            int b = i;

            long long net = nums[a];

            // strictly decreasing (middle part)
            while (b + 1 < n && nums[b + 1] < nums[b]) {
                net += nums[b + 1];
                b++;
            }

            if (b == a) continue;

            int c = b;

            long long left = 0, right = 0;
            long long lx = LLONG_MIN;
            long long rx = LLONG_MIN;

            // strictly increasing (left part)
            while (a - 1 >= 0 && nums[a - 1] < nums[a]) {
                left += nums[a - 1];
                lx = max(lx, left);
                a--;
            }

            if (a == i) continue;

            // strictly increasing (right part)
            while (b + 1 < n && nums[b + 1] > nums[b]) {
                right += nums[b + 1];
                rx = max(rx, right);
                b++;
            }

            if (b == c) continue;

            res = max(res, lx + net + rx);

            // skip already processed indices
            i = b - 1;
        }

        return res;
    }
};
