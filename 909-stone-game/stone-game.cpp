class Solution {
public:
    int t[501][501];

    int solve(int i, int j, vector<int>& piles){
        if(i > j){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int takeI = piles[i] + min(solve(i+2, j, piles), solve(i+1, j-1, piles));
        int takeJ = piles[j] + min(solve(i+1, j-1, piles), solve(i, j-2, piles));

        return t[i][j] = max(takeI, takeJ);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(begin(piles), end(piles), 0);

        memset(t, -1, sizeof(t));

        int alice = solve(0, n-1, piles);

        return alice > sum/2;
    }
};