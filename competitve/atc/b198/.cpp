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
    //cin >> t;
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
    vector<int> lex2N(27,-1);
    lex2N[26]=0;
    vector<int> N2lex(10,-1);
    string a, b, c;
    cin >> a >> b >> c;
    if((c.size()-1 > a.size() &&  c.size()-1 > b.size()) || c.size() < max(a.size(), b.size()){
        cout << "UNSOLVABLE";
        return;
    }
    int n = max(c.size(), max(a.size(), b.size()));
    a = string(n-a.size(), "{") + a;
    b = string(n-b.size(), "{") + b;

    
}

bool bt(string &a, string &b, string &c, vector<int> &lex2N, vector<int> &N2lex, int idx, bool offset){
    if(idx >= c.size()) return true;
    if(a[idx] != '{'){
        if(lex2N[a[idx]-'a'] == -1){
            for(int i = 0; i< 10;++i){
                if (N2lex[i]!=-1) continue;
                lex2N[a[idx]-'a'] = i;
                N2lex[i] = a[idx]-'a';
                if (bt(a, b, c, lex2N, N2lex, idx, offset)) return true;
                lex2N[a[idx]-'a'] = -1;
                N2lex[i] = -1;
            }
            return false;
        }
    }
    if(b[idx] != '{'){
        if(lex2N[b[idx]-'a'] == -1){
            for(int i = 0; i< 10;++i){
                if (N2lex[i]!=-1) continue;
                lex2N[b[idx]-'a'] = i;
                N2lex[i] = b[idx]-'a';
                if (bt(a, b, c, lex2N, N2lex, idx, offset)) return true;
                lex2N[b[idx]-'a'] = -1;
                N2lex[i] = -1;
            }
            return false;
        }
    }
    if(lex2N[c[idx]-'a'] == -1){
        int can = (lex2N[a[idx] - 'a'] + lex2N[b[idx] - 'a'] + offset) % 10;
        int offset = (lex2N[a[idx] - 'a'] + lex2N[b[idx] - 'a'] + offset) / 10;
        if (N2lex[can]!=-1){
            return false;
        }
        N2lex[can] = c[idx];
        lex2N[c[idx]-'a'] = can;
        if (bt(a, b, c, lex2N, N2lex, idx+1, offset)) return true;
        N2lex[can] = -1;
        lex2N[c[idx]-'a'] = -1;

    }else{
        int can = (lex2N[a[idx] - 'a'] + lex2N[b[idx] - 'a'] + offset) % 10;
        int offset = (lex2N[a[idx] - 'a'] + lex2N[b[idx] - 'a'] + offset) / 10;
        if(lex2N[c[idx]-'a'] != can) return false;
        return bt(a, b, c, lex2N, N2lex, idx+1, offset)
    }

}

