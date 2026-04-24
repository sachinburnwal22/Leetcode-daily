class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    int n, m;
    void bfs(int i, int j, vector<vector<char>>& board){
        queue<pair<int, int>> q;
        board[i][j] = '+';
        q.push({i, j});
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int ni = r + dr[k];
                int nj = c + dc[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 'O'){
                    q.push({ni, nj});
                    board[ni][nj] = '+';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j] == 'O'){
                        bfs(i, j, board);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='+'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }


    }
};