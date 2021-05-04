#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
using namespace std; 

// 2**6 =  64                           // 5!  = 120                        
// 2**8 =  256                          // 10! = 3,628,800
// 2**10 = 1,024                        // 12! = 479,001,600
// 2**15 = 32,768                       // 14! = 87,178,291,200
// 2**20 = 1,048,576                    // 16! = 20,922,789,888,000
// 2**25 = 33,554,432                   // 18! = 6,402,373,705,728,000
// 2**30 = 1,073,741,824                // 20! = 2,432,902,008,176,640,000
// 2**32 = 4,294,967,296


// int up to  2*10^9 (2^31-1)
// ll up to   9*10^18 (2^63 -1)
// ull up to 18*10^18 (2^64-1)/

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long, long> pll;
typedef pair<int, int> pii;

#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;



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
    //int count = 1;
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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<vector<int>> queries;
    int flips = 0;
    for(int i=0;i<q;++i){
        int t, a, b; cin >> t >> a >> b;
        vector<int> qq = {t, a, b};
        queries.push_back(qq);
        flips += (t==2);
    }
    if(flips&1){
        string front = s.substr(0, n);
        string back = s.substr(n);
        s = back + front;
    }
    int curf = 0;
    for(int i=0; i<q; ++i){
        if(queries[i][0]==2){curf++;
        }else{
            int a =--queries[i][1];
            int b =--queries[i][2];
            if(curf%2 == flips%2){
                swap(s[a], s[b]);
            }else{
                a = (a+n)%(2*n);
                b = (b+n)%(2*n);
                swap(s[a], s[b]);
            }
        }
            
    }
    cout << s;


}

