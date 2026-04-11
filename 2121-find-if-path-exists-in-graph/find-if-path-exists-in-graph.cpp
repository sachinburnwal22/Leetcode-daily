class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> visited(n, 0);

        queue<int> que;
        que.push(source);
        visited[source] = 1;

        while(!que.empty()){
            int node = que.front();
            que.pop();
            if(node == destination) return true;

            for(auto &it : mp[node]){
                if(!visited[it]){
                    que.push(it);
                    visited[it] = 1;
                }
            }
        }
        return false;
    }
};