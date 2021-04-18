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
        //cout<<"\n";    
    }
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 
void solve() 
{
    int n; cin >> n;
    vector<vector<char>> ret (n, vector<char>(n,'.'));
    int bot = 0, top = n, left = n, right = 0;
    FOR(i, n){
        FOR(j, n){
            char x;
            cin >> x;
            if(x=='*'){
                ret[i][j] = '*';
                bot = max(bot, i);
                top = min(top, i);
                left = min(left, j);
                right = max(right, j);

            }
        }
    }
    if(top == bot){
        if(top == 0){
            bot = 1;
        }else{
            top = 0;
        }
    }

    if(left == right){
        if(left == 0){
            right = 1;
        }else{
            left = 0;
        }
    }
    ret[top][left] = '*';
    ret[bot][left] = '*';
    ret[top][right] = '*';
    ret[bot][right] = '*';

    FOR(i, n){
        FOR(j, n){
            cout << ret[i][j];
        }
        cout << endl;
    }

    
}

