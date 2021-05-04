#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
using namespace std; 

// 2**6 =  64                           // 5!  = 120                        
// 2**8 =  256                          // 10! = 3,628,800
// 2**10 = 1,024                        // 12! = 479,001,600
// 2**15 = 32,768                       // 14! = 87,178,291,200
// 2**20 = 1,048,576                    // 16! = 20,922,789,888,000
// 2**25 = 33,554,432                   // 18! = 6,402,373,705,728,000
// 2**30 = 1,073,741,824                // 20! = 2,432,902,008,176,640,000
// 2**32 = 4,294,967,296


// int up to  2*10^9 (2^31-1)
// ll up to   9*10^18 (2^63 -1)
// ull up to 18*10^18 (2^64-1)/

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long, long> pll;
typedef pair<int, int> pii;

#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;



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
    //int count = 1;
    while(t--) 
    { 
        //cout<<"Case #" << count++ << ": ";
        solve(); 
        //cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

ll dfs2(int idx, vector<bool> &alr, vector<set<int>> &g, vector<int> &cols, vector<int> &connected){
    // find pos colors
    vector<bool> p = {true, true, true};
    for(int a: g[idx]){
        if(alr[a]){
            p[cols[a]] = false;
        }
    }
    ll ret =0;
    alr[idx]=true;
    for(int i=0; i<3; ++i){
        if(p[i]){
            cols[idx]=i;
            ll factor = 1;
            set<int> connectedCheck;
            for(int a: g[idx]){
                if(!alr[a] && connectedCheck.find(connected[a]) == connectedCheck.end()){
                    // make sure not to go to a if already (circle /connected component)
                    connectedCheck.insert(connected[a]);

                    factor *= dfs2(a, alr, g, cols, connected);
                }
            }
            ret += factor;
        }
    }
    alr[idx]=false;
    return ret;
}

void dfs(int idx, vector<bool> &visited, vector<set<int>> &g, vector<int> &connected, int nr){ //find root
    visited[idx]=true;
    connected[idx] =nr;
    for(int a: g[idx]){
        if(!visited[a]){
            dfs(a, visited, g, connected, nr);
        }
    }
}


void solve() 
{
    // todo: not working
    int n, m; cin >> n >> m;
    vector<set<int>> g(n, set<int>());
    for(int i=0; i<m; ++i){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    vector<int> roots;
    vector<bool>visited(n, false);
    auto it = find(visited.begin(), visited.end(), false);

    int nr = 0;
    vector<int>connected(n, -1);
    while(it != visited.end()){
        int nr = it - visited.begin();
        roots.push_back(nr);
        dfs(nr, visited, g, connected, nr);
        it = find(visited.begin(), visited.end(), false);
    }
    ll ret = 1;
    for(int r: roots){
        vector<bool> alr(n, false);
        vector<int> cols(n, 0);
        ll ans = dfs2(r, alr, g, cols, connected );
        ret *= ans;
        
    }
    cout <<ret; 

}

