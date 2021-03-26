#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

#define ll long long
#define ull unsigned long long
#define ld long double
#define print(n) cout << n << endl
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n) // here you need to specify char[SIZE] first, reads to next space
#define ssL(n) scanf("%s",n) // here you need to specify char[SIZE] first, reads to NL
#define sss(n) getline(cin, n) // doesnt work after scanf and after cin needs getchar()
#define sc(n) scanf("%c",&n)
#define FOR(i, n) for(int i = 0; i<n; i++)
#define FORS(i, n) for(i; i<n; i++)
#define FORI(i, a, b) for(int i = a; i<b; i++)
#ifndef ONLINE_JUDGE
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;

using namespace std; 
void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
    cin >> t;
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
    int n;
    cin >> n;
    vector<pair<ll, ll>> times(n, pair<ll, ll>());
    for(ll i=0; i<n;i++){
        ll a, b;
        cin >> a >> b;
        times[i] = {a, b};
    }
    long long current = 0;
    ll lastDepReal = 0;
    ll lastDepPlan = 0;
    ll delayTotal = 0;
    for(ll i=0; i<n;i++){
        current = lastDepReal;
        current += get<0>(times[i]) - lastDepPlan;
        ll delay;
        cin >> delay;
        current += delay;
        long long wait = ceil(((float)get<1>(times[i]) - (float)get<0>(times[i])) / (float) 2);
        lastDepReal = max(get<1>(times[i]), current + wait);
        lastDepPlan = get<1>(times[i]);


    }
    cout << current;
}

