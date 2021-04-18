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
    int n;
    cin >> n;
    vector<ll> x, pf;
    n+=2;
    FOR(i, n){
        ll num; cin >>num;
        x.push_back(num);
    }
    pf.push_back(0);
    set<ll> nums (x.begin(), x.end());
    FOR(i, n){
        pf.push_back(pf.back() + x[i]);
    }

    for(int i=1; i<pf.size(); ++i){
        ll random = pf.back() - 2*x[i-1];
        ll sum = x[i-1];
        //dbg(random);
        //dbg(sum);
        if(nums.find(random) != nums.end()){
            int j = 0;
            //dbg(random);
            for(;j<n;++j){
                if(x[j] == random && j!=i-1){
                    break;
                }
            }
            //dbg(j);
            if(j==n)continue;
            int index = j;
            //dbg(index);
            //dbg(i-1);
            FOR(k, n){
                if(k != index && k != i-1 ){
                    //cout << k;
                    cout << x[k] << " ";
                }

            }
            return;
        }

    }
    cout << -1;


}

