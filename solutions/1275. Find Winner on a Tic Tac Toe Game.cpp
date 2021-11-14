class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int r_size = moves.size();
        int c_size = moves[0].size();
        int n = 3;
        vector<pair<int, int>> rows (n, {0,0});
        vector<pair<int, int>> cols (n, {0,0});
        vector<pair<int, int>> diags (2, {0,0});
        
        for(int i = 0; i < moves.size(); i++){
            if(!(i%2)){
                rows[moves[i][0]].first++;
                cols[moves[i][1]].first++;
                diags[0].first += isMainDiagonal(n, moves[i][0], moves[i][1]) ? 1 : 0;
                diags[1].first += isAntiDiagonal(n, moves[i][0], moves[i][1]) ? 1 : 0;
                if(rows[moves[i][0]].first == n || cols[moves[i][1]].first == n || diags[0].first == n || diags[1].first == n )
                    return "A";
            }
            else {
                rows[moves[i][0]].second++;
                cols[moves[i][1]].second++;
                diags[0].second += isMainDiagonal(n, moves[i][0], moves[i][1]) ? 1 : 0;
                diags[1].second += isAntiDiagonal(n, moves[i][0], moves[i][1]) ? 1 : 0;
                if(rows[moves[i][0]].second == n || cols[moves[i][1]].second == n || diags[0].second == n || diags[1].second == n )
                    return "B";
            }
        }
        
 
        return n * n == moves.size() ? "Draw" : "Pending" ;
        
    }
    
    
    bool isMainDiagonal(int n, int i, int j){
        if(i == j)
            return true;
        return false;
    }
    
    bool isAntiDiagonal(int n, int i, int j){
        if(i + j == n-1)
            return true;
        return false;
    }
};
