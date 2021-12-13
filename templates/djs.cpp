class DJS{ // O(E Log E)
public:
    vector<int> rank, par;
    int forrests;
    DJS(int n){
        par = vector<int>(n, 0);
        for(int i=0; i<n; ++i)par[i] = i;
        forrests = n;
        rank.assign(n, 1);
    }
    int getPar(int x){
        if(par[x] == x) return x;
        return par[x] = getPar(par[x]);
    }
    bool isSame(int x, int y){
        return getPar(x) == getPar(y);
    }
    bool unionfy(int x, int y){
        if(isSame(x, y)) return false;
        forrests--;
        int px = getPar(x), py = getPar(y);
        if(rank[px] < rank[py]){
            swap(px, py);
        }
        par[py] = px;
        rank[px] += rank[py];
        return true;
    }
};
// // in main;
// vector<tiii> edges; // add all edges
// sort(edges.begin(), edges.end());
// DJS djs(n);
// long long ret = 0;
// for(int j=0; j<edges.size(); ++j){
//   auto [cost, a, b] = edges[i];
//   if(djs.unionfy(a, b)){
//     ret += cost;
//   }
// }