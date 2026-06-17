class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }else{
            unordered_map<char, int> mp;
            for(int i=0; i<s.size(); i++){
                if(mp.find(s[i]) == mp.end()){
                    mp[s[i]] = 1;
                }else{
                    mp[s[i]]++;
                }
            }

            for(int i=0; i<s.size(); i++){
                if(mp.find(t[i]) == mp.end()){
                    return false;
                }else{
                    mp[t[i]]--;
                }
            }

            for(auto it : mp){
                if(it.second != 0){
                    return false;
                }
            }
            return true;
        }
    }
};