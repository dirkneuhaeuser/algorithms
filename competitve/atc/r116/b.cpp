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

const int MOD = 998244353;
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
    int N;
    cin >> N;
    ll val = 3ll << 62;
    ll added = 0;
    ll ret = 0;
    vector<ll> nums;
    FOR(i, N){
        ll num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    ll factor = 0;
    ll prevFactor = 0;
    ll addup = 0;
    ll offset = 0;
    FOR(i, N){
        nums[i] = nums[i]%MOD;

        if(i >=2){
            prevFactor += nums[i-2];
            factor += prevFactor;
            prevFactor *=2; 
        }
        factor+=nums[i];
        ret += factor*nums[i];
        //ret += nums[i]*nums[i];


        //cout << factor << endl;
        

        //factor += nums[i];
        //ret += nums[i] * factor;
        //factor += addup;
        //addup += nums[i];

        prevFactor = prevFactor%MOD;
        factor = factor%MOD;
        addup = addup%MOD;
        ret = ret%MOD;

    }
    cout << ret;

}

