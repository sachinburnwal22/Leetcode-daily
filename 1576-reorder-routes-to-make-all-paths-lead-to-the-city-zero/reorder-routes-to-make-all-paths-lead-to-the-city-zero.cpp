class Solution {
public:
    int cnt = 0;
    void dfs(int child, int parent, unordered_map<int, vector<pair<int,int>>>& mp){
        for(auto &it : mp[child]){
            int newChild = it.first;
            int check = it.second;
            if(newChild != parent){
                if(check == 1){
                    cnt++;
                }
                dfs(newChild, child, mp);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for(auto &it : connections){
            int a = it[0];
            int b = it[1];

            mp[a].push_back({b, 1});
            mp[b].push_back({a, 0});
        }

        dfs(0, -1, mp);
        return cnt;
    }
};