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
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> a, b;
    vector<char> reta, retb;
    for(int i=0;i<n;++i){
        int num = s[i] - '0';
        if(num){
            if(a.size() && b.size() && (a.size() != 1 || b.size() != 1 || (i == n-1) || int(s[i+1] - '0') != 0 )){
                a.pop();
                b.pop();
                reta.push_back(')');
                retb.push_back(')');
            } else{
                a.push(1);
                b.push(1);
                reta.push_back('(');
                retb.push_back('(');
            }
        } else{
            if(!a.size() && !b.size()){
                cout << "NO";
                return;
            }
            if(a.size() >= b.size()){
                a.pop();
                b.push(1);
                retb.push_back('(');
                reta.push_back(')');
            }else{
                b.pop();
                a.push(1);
                reta.push_back('(');
                retb.push_back(')');
            }
        }
    }
    if(!a.size() && !b.size()){
        cout << "YES" << endl;
        FOR(i, n){
            cout << reta[i];
        }
        cout << endl;
        FOR(i, n){
            cout << retb[i];
        }
    } else{
        cout << "NO";
    }


}

