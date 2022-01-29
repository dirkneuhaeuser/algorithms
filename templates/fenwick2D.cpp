#define LSOne(S) ((S) & -(S))


class PURQ {
private:
    vector<vector<ll>> ft;
public:
    PURQ(int n) { // without leading 0
        ft.assign(n+1,vector<ll>(n+1, 0)); // idx 0 is bound, no value asigned to it
    }
    ll range_query_from_left(int i,int j){ // interval [1,...,j]
        ll ret = 0;
        for(;i>0; i-=LSOne(i)){
            int j1 = j;
            for(;j1>0; j1-=LSOne(j1)){
                //cout << i << " " << j1 << endl;
                ret += ft[i][j1];
            }
        }
        return ret;
    }
    ll range_query(int li, int lj, int ri, int rj){ // interval [i,...,j]
        return range_query_from_left(ri, rj) + range_query_from_left(li-1, lj-1) - range_query_from_left(ri, lj-1) - range_query_from_left(li-1, rj) ;
    }
    void point_update(int i, int j, int val){
        int n = ft.size();
        for(;i<n; i+=LSOne(i)){
            int j1=j;
            for(;j1<n; j1+=LSOne(j1)){
                ft[i][j1] += val;
            }
        }
    }
};

//int n; cin >> n;
//vector<vi> grid(n+1, vi(n+1, 0));
//FOR(i, n){
//    FOR(j, n){
//        cin >> grid[i+1][j+1];
//    }
//}
//PURQ fw(n+1);
//FOR(i, n){
//    FOR(j, n){
//        fw.point_update(i+1, j+1, grid[i+1][j+1]);
//    }
//}
