#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

// int up to 2*10^9 (2^31-1)
#define ll long long  // up to 9*10^18 (2^63 -1)
#define ull unsigned long long // up to 18*10^18 (2^64-1)
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
    freopen("/Users/dirk/development/algorithms/competitve/input.txt", "r", stdin); 
    freopen("/Users/dirk/development/algorithms/competitve/error.txt", "w", stderr); 
    freopen("/Users/dirk/development/algorithms/competitve/output.txt", "w", stdout); 
    #endif 
    
    int t=1; 
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
    // you can formulte f_i as:
    // f_i = min(b, max(c, x+d2))
    // if t==1: d2=a, b=inf, x=-inf, ...
    //
    //
    // f = min(b2, max(c2, x+d2))
    // g = min(b1, max(c1, x+d1))
    //
    // then composition has the same form
    // f(g(x)) = min(min(b2, max(c2, b+2)), max(max(c2, c+d2), x + d + d2))
    //
    // (archived by getting rid of double max-max or min-min input to x..
    // useful:
    // max(a, max(b, x)) = max(max(a, b), x)   (moving 'a' to the inner left part)
    // min(a, min(b, x)) = min(min(a, b), x)   
    //
    // max(a, min(b, c)) = min(max(a, b), max(a, c)) (moving a into both)
    //
    int N; cin >> N;
    ll INF = 1ll << 62;
    ll NINF = 3ll << 62;
    ll b = INF, c = NINF, d = 0;
    for(int i =0; i<N; ++i){
        ll a, t;
        cin >> a >> t;
        ll b2, c2, d2;
        //cout << a << " " << t << endl;
        if(t == 1){
            b2 = INF;
            c2 = NINF;
            d2 = a;
        }else if (t ==2){
            b2 = INF;
            c2 = a;
            d2 = 0;
        } else{
            b2 = a;
            c2 = NINF;
            d2 = 0;
        }
        b = min(b2, max(c2, b+ d2));
        c = max(c2, c+d2);
        d = d+d2;
    }
    int q;
    cin >> q;
    for(int i=0;i<q;++i){
        ll x; cin >>x;
        ll ret = min(b, max(c, x+d));
        cout << ret << endl;
    }

}   


