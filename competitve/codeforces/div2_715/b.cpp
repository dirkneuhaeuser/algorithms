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
    //int count = 1;
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
    int n; cin >> n;
    string a; cin >> a;
    int ct=0, cm=0;
    FOR(i, n){
        if(a[i]=='T'){
            ct++;
        }else{
            cm++;
        }
    }
    if(ct != 2*n/3 || cm != n/3){
        cout << "NO";
        return;
    }
    int amountt = 0, amountm=0;
    for(int i=0; i<n; ++i){
        if(a[i]=='T'){
            amountt++;
        }
        if(a[i]=='M'){
            amountm++;
        }
        if(amountm > amountt){
            cout << "NO";
            return;
        }
        
    }
    amountt = 0; amountm=0;
    for(int i=n-1; i>=0; --i){
        if(a[i]=='T'){
            amountt++;
        }
        if(a[i]=='M'){
            amountm++;
        }
        if(amountm > amountt){
            cout << "NO";
            return;
        }
        
    }

    cout << "YES";

}

