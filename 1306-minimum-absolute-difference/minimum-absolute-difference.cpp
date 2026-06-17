class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int minDiff = INT_MAX;
        for(int i=0; i<n-1; i++){
            int a = arr[i];
            int b = arr[i+1];

            minDiff = min(minDiff, b-a);
        }

        for(int i=0; i<n-1; i++){
            int a = arr[i];
            int b = arr[i+1];

            if(minDiff == b-a){
                ans.push_back({a, b});
            }
        }

        return ans;
    }
};