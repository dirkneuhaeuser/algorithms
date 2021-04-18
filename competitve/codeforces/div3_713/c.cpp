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
    int zeros, ones;
    cin >> zeros >> ones;
    string x;
    cin >> x;
    int n = x.size();
    FOR(i, n){
        if(x[i]=='1') ones--;
        if(x[i]=='0') zeros--;
    }
    FOR(i, x.size()){
        if(x[i] == '?' && x[n-1-i] !='?'){
            if(x[n-1-i] == '1'){
                x[i] = '1';
                ones--;
            }else{
                x[i] = '0';
                zeros--;
            }
        }
    }
    FOR(i, x.size()/2){
        if(x[i] == '?'){
            if(zeros>=2){
                x[i]='0';
                x[n-1-i]='0';
                zeros -=2;
            }else if(ones>=2){
                x[i]='1';
                x[n-1-i]='1';
                ones -=2;
            }
        }
    }
    if(n&1){
        if(ones>0){
            x[n/2] = '1';
            ones--;
        }else if(zeros>0){
            zeros--;
            x[n/2] = '0';
        }
    }
    //dbg(x);
    FOR(i, n){
        if(x[i]=='?'){
            cout << "-1";
            return;
        }
    }
    string rev = x;
    reverse(rev.begin(), rev.end());
    //dbg(zeros);
    //dbg(ones);
    if(x != rev || ones != 0 || zeros != 0){
        cout << "-1";
        return;
    }
    cout << x;
    

}

