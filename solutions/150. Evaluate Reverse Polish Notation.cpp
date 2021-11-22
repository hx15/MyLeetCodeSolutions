class Solution {
public:
    int evalRPN(vector<string>& t) {
        vector<string> stk;
        size_t N = t.size();
        for(int i = 0 ; i < N; i++){
            if(1 < t[i].size() || isdigit(t[i].front())) {
                stk.push_back(t[i]);
            }
            else{
                int x = stoi(stk.back());
                stk.pop_back();
                int y = stoi(stk.back());
                stk.pop_back();
                if(t[i].front() == '*') stk.push_back(to_string(x*y));
                else if(t[i].front() == '+') stk.push_back(to_string(x+y));
                else if(t[i].front() == '/') stk.push_back(to_string(y/x));
                else stk.push_back(to_string(y-x));
            }
        }
        
        
        return stoi(stk.front());
    }
};
