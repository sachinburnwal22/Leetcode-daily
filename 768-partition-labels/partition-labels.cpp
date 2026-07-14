class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, pair<int, int>> mp;

        // Store first and last occurrence
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]].second = i;
            }
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++) {

            end = max(end, mp[s[i]].second);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};