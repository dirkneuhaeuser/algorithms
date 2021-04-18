#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

// int up to 2*10^9 (2^31-1)
typedef long long ll; // up to 9*10^18 (2^63 -1)
typedef unsigned long long ull;  // up to 18*10^18 (2^64-1)
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;

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

vector<ll> a, b;
ll c;
map<pli, ll> memo;
ll dp(ll money,int idx){
    pii key(money, idx);
    auto it = memo.find(key);
    if(it != memo.end()){
        return it->second; 
    }
    if(money >= c)return 0;
    if(idx==(a.size()-1)){
        bool offset = (c-money)%a[idx];
        return memo[key] = (c-money)/a[idx] + offset;
    }
    if(money >= b[idx]){
        // rise or forever here
        ll forever = (c-money)/a[idx] + ((c-money)%a[idx] != 0);
        return memo[key] = min(forever, 1+dp(money-b[idx],idx+1) );
    }else{
        // next step: rise or computer
        ll nextEventDays = min((c-money)/a[idx] + ((c-money)%a[idx] != 0), (b[idx]-money)/a[idx] + ((b[idx]-money)%a[idx] != 0));
        return memo[key] = nextEventDays + dp(money + nextEventDays*a[idx],idx);
    }
}
void solve() 
{
    memo = map<pli,ll>();
    a = vector<ll>();
    b = vector<ll>();
    int n;
    cin >> n >> c;
    FOR(i, n){
        ll num; cin >> num;
        a.push_back(num);
    }
    FOR(i, n-1){
        ll num; cin >> num;
        b.push_back(num);
    }
    cout << dp(0, 0);
    //dbg(memo);

}


