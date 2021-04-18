#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

// int up to 2*10^9 (2^31-1)
#define ll long long  // up to 9*10^18 (2^63 -1)
#define ull unsigned long long // up to 18*10^18 (2^64-1)
#define ld long double
#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;
using namespace std; 



void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifdef DIRK 
    freopen("/Users/dirk/development/algorithms/competitve/input.txt", "r", stdin); 
    freopen("/Users/dirk/development/algorithms/competitve/error.txt", "w", stderr); 
    freopen("/Users/dirk/development/algorithms/competitve/output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
    //cin >> t;
    int count = 1;
    while(t--) 
    { 
        //cout<<"Case #" << count++ << ": ";
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 



vector<bool> good(100001, 0);
vector<vector<int>> g(100001, vector<int>());
vector<int> c(100001,-1);

void dfs(int v, set<int> &alr, vector<int> &cnt){
    alr.insert(v);
    if(cnt[c[v]] == 0){
        good[v] = 1;
    }
    cnt[c[v]]++;
    for(int a: g[v]){
        if(alr.find(a) == alr.end()){
            dfs(a, alr, cnt);
        }
    }
    cnt[c[v]]--;
}


void solve() 
{
    int n; cin >> n;
    int counter = n;
    for(int &x:c){
        counter--;
        cin >> x;
        //cout << x << endl;
        if (counter == 0) break;
    }
    FOR(i, n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        //cout << a << " " << b << endl;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    set<int> alr;
    vector<int> cnt(100001, 0);
    dfs(0, alr,  cnt);
    FOR(i, good.size()){
        if(good[i]){
            cout << i+1 << endl; 
        }
    }

}

