#define MOD 100000007;
class Solution {
public:
    int knightDialer(int n) {
        if(n == 0)
            return 0;
        
        int numRows = 4;
        int numCols = 3;
        
        vector<vector<bool>> numPad (numRows, vector<bool> (numCols, true));
        numPad[3][0] = false;
        numPad[3][2] = false;
        
        vector<vector<int>> cords = {{2,1},{2,-1},
                                     {-1,-2},{-1,2},
                                     {1,-2},{1,2},
                                     {-2,1},{-2,-1}};
        vector<vector<vector<int>>> dp (numRows, vector<vector<int>>(numCols, vector<int>(5001, -1)));
        
        long long res = 0;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                res = res%1000000007 + numOfPossibilities(numPad, cords, dp, i, j, n)%1000000007;
            }
        }
        
        return res;
    }
    
    int numOfPossibilities(vector<vector<bool>>& numPad, vector<vector<int>>& cords, vector<vector<vector<int>>>& dp, int i, int j, int n){
        if(i < 0 || i >= numPad.size() || j < 0 || j >= numPad[0].size() || numPad[i][j] == false)
            return 0;
        if(n == 1)
            return 1;
        
        int res = 0;
        
        if(dp[i][j][n] != -1)
            return dp[i][j][n];
        
        for(int k = 0; k < cords.size(); k++){
            int r = i + cords[k][0];
            int c = j + cords[k][1];
            res = res%1000000007 + (numOfPossibilities(numPad, cords, dp, r, c, n-1)%1000000007);
        }
        
        dp[i][j][n] = res;
        
        return dp[i][j][n];
    }
    
    
};
