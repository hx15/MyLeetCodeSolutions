class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> frest; //filtered restaurants;
        for(auto &rest : restaurants) {
            cout << rest[2] << "  " << veganFriendly << " Vegan \n "; 
            cout << rest[3] << "  " << maxPrice << "maxPrice \n ";
            cout << rest[4] << "  " << maxDistance << "maxDistance \n ";;
            
            cout << " \n";
            if(  (!veganFriendly || veganFriendly == rest[2]) && rest[3] <= maxPrice && rest[4] <= maxDistance) {
                vector<int> v (2, 0);
                v[0] = rest[0], v[1] = rest[1], frest.push_back(v);
            }
        }
            
        sort(frest.begin(), frest.end(), [](vector<int>& l, vector<int>& r){
            if (l[1] == r[1])
                return l[0] > r[0];
            return l[1] > r[1] ;
        });
        
        vector<int> ids;
        for(auto const & rest: frest)
            ids.push_back(rest[0]);
        
        
        
        return ids;
                
                
    }
};
