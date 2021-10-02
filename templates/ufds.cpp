// Union-Find Disjoint Set
class UFDS{
private:
    vector<int> par, rank, setSizes;
    int numSets;
public:
    UFDS(int n){
        par.assign(n, 0);for(int i=0; i<n; ++i) par[i] = i;
        rank.assign(n, 0);
        setSizes.assign(n, 1);
        numSets = n;
    }
    int findSet(int i){ // O(1)
        if(par[i] == i) return i;
        return par[i] = findSet(par[i]); // path compression
    }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
    int numDisjointSets(){ return numSets; }
    int sizeOfSet(int i){ return setSizes[i]; };
    bool unionSets(int i, int j){
        if(isSameSet(i, j)) return true;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) swap(x, y);
        par[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        numSets--;
        setSizes[y]+=setSizes[x];
        return false;
    }
};
// Use-cases:
// 1. Find Connected Components in undirected Graph
//
//
// // 2. Spanning Tree (Kruscal)
// sort(el.begin(), el.end());
// UFDS ufds(n);
// ld ret = 0;
// for(auto [w, a, b]: el){
//     if(ufds.unionSets(a, b)) continue;
//     ret += w;
// }
// cout << ret;
