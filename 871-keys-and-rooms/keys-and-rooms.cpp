class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<rooms[i].size(); j++){
                mp[i].push_back(rooms[i][j]);
            }
        }

        queue<int> q;
        q.push(0);
        vector<int> visited(n, 0);
        visited[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it : mp[node]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        for(auto &it : visited){
            if(it == 0){
                return false;
            }
        }
        return true;
    }
};