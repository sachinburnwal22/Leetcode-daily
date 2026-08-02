class Solution {
public:
    int n;
    int t[2][101][101];

    int solveForAlice(vector<int>& piles, int i, int p, int M){
        if(i >= n){
            return 0;
        }

        if(t[p][i][M] != -1){
            return t[p][i][M];
        }

        int result = (p == 1) ? -1 : INT_MAX;
        int stones = 0;

        for(int x=1; x<=min(2*M, n-i); x++){
            stones += piles[i+x-1];

            if(p == 1){
                result = max(result, stones + solveForAlice(piles, i+x, 0, max(M, x)));
            }else{
                result = min(result, solveForAlice(piles, i+x, 1,max(M, x)));
            }
        }

        return t[p][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return solveForAlice(piles, 0, 1, 1);
    }
};