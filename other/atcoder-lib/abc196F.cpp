#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
#include <atcoder/convolution>
#include <atcoder/modint>
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

using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;
void chmin(int& a, int b){ if(a > b) a = b; }




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
    while(t--) 
    { 
        solve(); 
        cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 
void solve() 
{
    string S, T;
    cin >> S >> T;
    reverse(T.begin(), T.end());
    const int N = S.size(), M = T.size();
    vector<Modint> s1(N), s2(N), t1(N), t2(N);
    for(int i = 0; i < N; i++) (S[i] == '0' ? s1 : s2)[i] = 1;
    for(int i = 0; i < M; i++) (T[i] == '0' ? t1 : t2)[i] = 1;
    s1 = atcoder::convolution(s1, t2);
    s2 = atcoder::convolution(s2, t1);
    int ans = INF;
    for(int i = M - 1; i < N; i++) chmin(ans, s1[i].val() + s2[i].val());
    cout << ans << endl;
}


