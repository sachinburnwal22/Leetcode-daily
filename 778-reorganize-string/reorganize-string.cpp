class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        
        string ans = "";

        pair<int, char> prev = {0, '#'};
        while(!pq.empty()){
            pair<int, char> curr = pq.top();
            pq.pop();

            if(curr.second == prev.second){
                if(pq.empty()){
                    return "";
                }
                curr = pq.top();
                pq.pop();
                pq.push(prev);
            }

            ans += curr.second;
            curr.first--;
            prev = curr;
            if(curr.first > 0){
                pq.push(curr);
            }
        }

        return ans;
    }
};