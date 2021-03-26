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
    ll n, k;
    cin >> n >> k;

    while(k>3){
        n--;
        k--;
        cout << 1 << " ";
    }

    // first obs:
    // 1 doesn't makt LCM greater
    // pattern:
    // odd = 1 + (n-1)/2 + (n-1)/2
    // even:
    //  - power of 2:
    //      n/4, n/4, n/2
    //  - not power of 2: find least 2 multiple k in this number 
    //      2^k, (n-2^k)/2, (n-2^k)/2
    if(n&1){
        cout << 1 << " " << (n-1)/2 << " " << (n-1)/2;
    }else if((n&(n-1))==0){ // power of 2
        cout << n/4 << " " << n/4 << " " << n/2;
    }else{
        int lsb = (n&-n); // 6 = 00000000 00000000 00000000 00000110, -6= 11111111 11111111 111111111 111111010  (neg and +1)
        int left = (n - lsb) >> 1;
        cout << lsb << " " << left <<  " " << left;
    }

}

