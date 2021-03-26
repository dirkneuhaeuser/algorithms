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
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    int w1 = k1;
    int b1 = n-k1;
    int w2 =k2;
    int b2 = n -k2;
    
    while(w){
        if(w1 > 0 && w2 > 0 && w1&1 && w2&1){
            w1--;
            w2--;
            w--;
        } else if (w1 >= 2){
            w1-=2;
            w--;
        } else if(w2 >=2){
            w2-=2;
            w--;
        } else{
            cout << "NO";
            return;
        }
    }
    while(b){
        if(b1 > 0 && b2 > 0 && b1&1 && b2&1){
            b1--;
            b2--;
            b--;
        } else if (b1 >= 2){
            b1-=2;
            b--;
        } else if(b2 >=2){
            b2-=2;
            b--;
        } else{
            cout << "NO";
            return;
        }
    }

    cout << "YES";

}

