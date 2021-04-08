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
    vector<int> s,t;
    vector<bool>check;
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i=0;i<n;++i){
        int num = a[i] - '0';
        s.push_back(num);
    }
    for(int i=0;i<n;++i){
        int num = b[i] - '0';
        t.push_back(num);
    }
    int c1 = 0, c0 =0;
    FOR(i,n){
        if(s[i] == 0) c0++;
        if(s[i] == 1) c1++;
        if(c0 == c1){
            check.push_back(true);
        }else{
            check.push_back(false);
        }

    }
    //dbg(s);
    //dbg(t);
    //dbg(check);
    bool flip = false;
    for(int i =n-1; i>=0; --i){
        if(s[i] ^ flip == t[i]) continue;
        else{
            if(check[i]){flip =  !flip;}
            else{
                cout << "NO";
                return;
            }
        }

    }

    cout << "YES";


}

