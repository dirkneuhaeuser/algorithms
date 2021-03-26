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
    int n; cin >>n;
    vector<ll> a,b;
    FOR(i,n){
        ll num; cin >> num;
        a.push_back(num);
    }
    FOR(i,n){
        ll num; cin >> num;
        b.push_back(num);
    }
    vector<pair<ll,ll>> c;

    FOR(i,n){
        c.emplace_back(a[i],b[i]);
    }
    sort(c.begin(), c.end());
    ll lastLevel = 0;
    ll lastSecond = 1;
    ll lastFirst = 1;
    ll ret = 0;
    FOR(i, n){
        ll curLevel = c[i].first - c[i].second;
        //cout << curLevel << " " << lastLevel << endl;
        if(lastLevel == curLevel){
            if(!(lastLevel&1)){
                ret+= c[i].second - lastSecond;
            }
        }else{
            if((lastLevel&1)==0){
                lastLevel++;
            }
            ret += (curLevel +1- lastLevel) >>1;
        }
        lastLevel = curLevel;
        lastSecond = c[i].second;

        
    }
    cout << ret;

    


}

