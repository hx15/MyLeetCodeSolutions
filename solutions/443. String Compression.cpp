class Solution {
public:
    int compress(vector<char>& chars) {
        
        /// shit solution
        vector<char> c;
        vector<int> n;
        vector<char> res;
        for(int i = 0; i < chars.size(); i++){
            if(!c.empty() && c.back() == chars[i]){
                n.back()++;
                continue;
             }
            c.push_back(chars[i]);
            n.push_back(1);
            }
        for(int i = 0; i < c.size(); i++){
            res.push_back(c[i]);
            if(n[i] == 1) continue;
            else{
                string digits = to_string(n[i]);
                for(auto d: digits) res.push_back(d);
            }
        }
        chars = res;
        
        return chars.size();
    }
};
