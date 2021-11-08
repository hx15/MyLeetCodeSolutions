class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        vector<int> freqs;
        for (int x : arr) ++cnt[x];
        for(const auto [_, freq] : cnt) freqs.push_back(freq);
        sort(freqs.begin(), freqs.end(), [](int& l, int& r){
            return l < r;
        });
        
        int rem = arr.size(), half = rem/2, i = freqs.size()-1, count = 0;
        while(rem > half)
            rem -= freqs[i--], count++;
        
        
        return count;
    }
};
