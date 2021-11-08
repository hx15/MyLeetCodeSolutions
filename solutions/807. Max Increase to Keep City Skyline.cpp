class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // we only need two directions.
        vector<int> upv; //up view
        vector<int> sidev; // side view
        // find maximum for the upv
        for(int i = 0; i < grid[0].size(); i++){
            int maxHeight = 0;
            for(int j = 0; j < grid.size(); j++){
                maxHeight = max(maxHeight, grid[j][i]);
            }
            upv.push_back(maxHeight);
        }
        for(int i = 0; i < grid.size(); i++){
            int maxHeight = 0;
            for(int j = 0; j < grid[0].size(); j++){
                maxHeight = max(maxHeight, grid[i][j]);
            }
            sidev.push_back(maxHeight);
        }
        
        int increase = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                increase += min(upv[j],sidev[i]) - grid[i][j];
            }
        }
        
        
        return increase;
    }
};
