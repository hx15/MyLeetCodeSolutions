class Solution {
public:
    bool compareTwoMaps(int a[], int b[]){
        int count = 0;
        for(int i = 0; i < 26; i++){
                if(a[i] && a[i] != b[i]) return false;
            }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int mapS1[26] = {0};
        int mapS2[26] = {0};
        
        // we now have the frequencies stored in mapS1;
        for(auto& c: s1) mapS1[c - 'a'] +=1;
        
        unsigned int N = s2.size();
        unsigned int M = s1.size(); 
        int r = M-1;
        int l = 0;
        
        for(int i = l; i <=r ; i++) mapS2[s2[i] - 'a'] += 1;
        
        
        if(compareTwoMaps(mapS1, mapS2)) return true;
    
        
        while(r < N-1){
            mapS2[s2[++r] - 'a'] += 1;
            mapS2[s2[l++] - 'a'] -= 1;
            if(compareTwoMaps(mapS1, mapS2)) return true;
        }
        
        return false;
    }
};
