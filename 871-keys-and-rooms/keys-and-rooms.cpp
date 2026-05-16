class Solution {
public:
    void dfs(int startPt, vector<int>& visited, vector<vector<int>>& rooms){
        visited[startPt] = 1;

        for(int next : rooms[startPt]){
            if(visited[next] == 0){
                dfs(next, visited, rooms);
            }    
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, 0);

        dfs(0, visited, rooms);

        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                return false;
            }
        }

        return true;
    }
};