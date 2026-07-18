class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto max_it = max_element(arr.begin(), arr.end());
        if (max_it != arr.end()) {
            auto index = distance(arr.begin(), max_it);
            return index;
        }else{
            return -1;
        }
    }
};