class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};
    int orgColor;
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int row, int col){
        if(image[sr][sc] != orgColor){
            return;
        }else{
            image[sr][sc] = color;
            for(int i=0; i<4; i++){
                int nsr = sr + dr[i];
                int nsc = sc + dc[i];
                if(nsr >= 0 && nsr < row && nsc >= 0 && nsc < col){
                    dfs(image, nsr, nsc, color, row, col);
                }
            }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();
        orgColor = image[sr][sc];
        if(orgColor == color) return image;
        dfs(image, sr, sc, color, row, col);

        return image;
    }
};