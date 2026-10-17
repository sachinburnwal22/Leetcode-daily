
class Solution {
public:
    int sumDig(int n) {
        int sum = 0;
        while (n) {
            int rem = n % 10;
            n /= 10;
            sum += rem;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSorted(nums);

        auto lambda = [this](int n1, int n2) {
            int sumDig1 = sumDig(n1);
            int sumDig2 = sumDig(n2);

            if (sumDig1 != sumDig2) {
                return sumDig1 < sumDig2;
            }
            return n1 < n2;
        };

        sort(begin(afterSorted), end(afterSorted), lambda);

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int swapCnt = 0;

        for (int i = 0; i < n; i++) {
            int expV = afterSorted[i];
            int curV = nums[i];

            if (expV == curV) continue;

            int idx = mp[expV];

            swap(nums[i], nums[idx]);

            mp[expV] = i;
            mp[curV] = idx;

            swapCnt++;
        }

        return swapCnt;
    }
};
