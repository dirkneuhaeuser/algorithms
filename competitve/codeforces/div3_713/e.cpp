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
    cin >> t;
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
void solve() 
{
    int n, l, r, s;
    cin >>n >> l >> r >>s;
    l--;
    r--;
    int cnt = r- l+1;
    set<int> alr;
    vector<int> skipped;
    int sum = 0; 
    for(int i = n;i>0;--i){
        if(sum + cnt*(cnt-1)/2 + i > s){
            skipped.push_back(i);
            continue;
        }else{
            alr.insert(i);
            cnt--;
            sum += i;
        }
    }
    if(cnt != 0 || sum != s){
        cout << -1;
        return;
    }
    int i = 0;
    //dbg(alr);
    //dbg(skipped);
    for(;i<l;++i){
        //dbg(i);
        cout << skipped[i] << " ";
    }
    //i--;
    for(int x: alr){
        cout << x << " ";
    }
    for(int j=0; j<(n-r-1); ++j){
        //dbg(i+j);
        cout << skipped[i+j] << " ";
    }
    
    
}

