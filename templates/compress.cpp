// compresses the vector into [0, 1, 2, .. n]
// values which were bigger than others still are bigger and vice versa
int comp(vector<int> &A){
    std::map<int,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}
