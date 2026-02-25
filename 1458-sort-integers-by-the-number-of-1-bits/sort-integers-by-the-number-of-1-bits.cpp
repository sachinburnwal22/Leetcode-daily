class Solution {
public:
    static bool compareOp(int a, int b) {
        int aa = __builtin_popcount(a);
        int bb = __builtin_popcount(b);

        if (aa == bb)
            return a < b;   // same number of 1s → sort by value
        return aa < bb;     // fewer 1s first
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compareOp);
        return arr;
    }
};