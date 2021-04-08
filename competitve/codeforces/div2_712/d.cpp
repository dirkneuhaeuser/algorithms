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
    cin >>n;
    int dim = n*2 -1;
    int rowBlue = 0;
    int stepBlue = 0;
    int rowRed = 1;
    int stepRed = 0;

    unordered_map<int, pair<int, int>> dm;
    int k = 0;
    FOR(i, dim){
        if(i < n)
            dm[i] = {i, 0};
        else{
            k++;
            dm[i] = {n-1, k};
        }
    }

    //dbg(dm);


    int counter = pow(n, 2);
    while(counter){
        counter--;
        int num;
        cin >> num;
        if(rowBlue < dim && num != 1){
            pair<int, int> coord = dm[rowBlue];
            cout << 1 << " " << coord.first+1 << " " << coord.second +1<< endl;
            cout.flush();
            coord.first -= 1;
            coord.second += 1;
            if(coord.first <0 ||  coord.second >= n){
                rowBlue += 2;
            }else{
                dm[rowBlue] = coord;

            }
            //dbg(rowBlue);
            //dbg(coord);
        }else if(rowRed < dim && num != 2){
            ///cout << "stupid" << endl;
            pair<int, int> coord = dm[rowRed];
            cout << 2 << " " << coord.first +1 << " " << coord.second+1 << endl;
            cout.flush();
            coord.first -= 1;
            coord.second += 1;
            //dbg(coord);
            if(coord.first < 0 ||  coord.second >= n){
                rowRed += 2;
                //dbg(rowRed);
            }else{
                dm[rowRed] = coord;
            }
            //dbg(rowRed);
            //dbg(coord);
        } else{
            if(rowBlue < dim){
                pair<int, int> coord = dm[rowBlue];
                cout << 3 << " " << coord.first+1 << " " << coord.second+1 << endl;
                cout.flush();
                coord.first -= 1;
                coord.second += 1;
                if(coord.first < 0||  coord.second >=n){
                    rowBlue += 2;
                }else{
                    dm[rowBlue] = coord;
                }

            } else{
                pair<int, int> coord = dm[rowRed];
                cout << 3 << " " << coord.first+1 << " " << coord.second+1 << endl;
                cout.flush();
                coord.first -= 1;
                coord.second += 1;
                if(coord.first < 0 ||  coord.second >= n){
                    rowRed += 2;
                }else{
                    dm[rowRed] = coord;
                }

            }
        }

    }
    return;

}

