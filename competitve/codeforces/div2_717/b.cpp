#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
using namespace std; 

// 2**6 =  64
// 2**8 =  256
// 2**10 = 1,024
// 2**15 = 32,768
// 2**20 = 1,048,576
// 2**25 = 33,554,432
// 2**30 = 1,073,741,824
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
    vector<int> nums, pfs;
    for(int i=0; i<n; ++i){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    pfs.push_back(0);
    for(int i=0; i<n; ++i){
        pfs.push_back(pfs.back() ^ nums[i]);
    }
    //dbg(pfs);
    // even
    for(int i=0; i<n-1; ++i){
        // take i to left
        int right =  pfs[n]^pfs[i+1];
        int left = pfs[i+1];
        if(left == right){
            cout << "YES";
            //cout << "YES1" << i << " " << left << " " << right;
            return;
        }
    }
    // odd
    for(int i =0; i<n-1; ++i){
        for(int j=i; j<n; ++j){
            if(i==0 && j == n-1) continue;
            // skip
            int skip = pfs[j+1] ^ pfs[i+1-1];
            int left = (pfs[i+1-1]);
            int right = (pfs[n] ^ pfs[j+1]);
            if((left == skip || left == 0) && (skip == right|| right == 0)){
                int leftcheck = 0;
                for(int k1 = 0 ; k1< i; k1++){
                    leftcheck ^= nums[k1];
                    if(leftcheck == skip){
                        cout << "YES";
                        return;
                    }
                }
                int rightcheck = 0;
                for(int k1 = j+1 ; k1< n; k1++){
                    rightcheck ^= nums[k1];
                    //cout << j << " " << right << " " << skip << " " << rightcheck << " " << k1 <<  " "  << nums[k1] << endl;
                    if(rightcheck == skip){
                        cout << "YES";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO";
    

}

