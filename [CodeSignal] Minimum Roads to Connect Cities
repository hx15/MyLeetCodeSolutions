class UnionFind{
public:
    map<int, int> parents;
    UnionFind(int n){
        for(int i = 1; i <= n; i++)
            parents[i] = i;
    }
    
void unionize(int x, int y){
    int x_p = find(x);
    int y_p = find(y);
    if(x_p == y_p) return;
    parents[x_p] = y_p;
}

int find(int x ){
    if(parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

int getNumberOfParents(){
    int res = 0;
    for(auto it = parents.begin(); it != parents.end(); ++it)
        if(it->first == it->second) res++;
    return res;
}
    
};

int solution(int n, vector<vector<int>> roads) {
    UnionFind uf(n);
    int res = 0;
    for(int i = 0; i < roads.size(); i++){
        uf.unionize(roads[i][0], roads[i][1]);
    }
    return uf.getNumberOfParents()-1;
}
