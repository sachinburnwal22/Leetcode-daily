class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_set<char> st;
            for(int j=i; j<n; j++){
                if(vowels.find(word[j]) == vowels.end()){
                    break;
                }
                st.insert(word[j]);
                if(st.size() == 5){
                    ans++;
                }
            }
        }
        return ans;
    }
};