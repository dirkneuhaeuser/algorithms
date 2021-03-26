#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first

#define ll long long
#define ull unsigned long long
#define ld long double
#define print(n) cout << n << endl
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n) // here you need to specify char[SIZE] first, reads to next space
#define ssL(n) scanf("%s",n) // here you need to specify char[SIZE] first, reads to NL
#define sss(n) getline(cin, n) // doesnt work after scanf and after cin needs getchar()
#define sc(n) scanf("%c",&n)
#define FOR(i, n) for(int i = 0; i<n; i++)
#define FORS(i, n) for(i; i<n; i++)
#define FORI(i, a, b) for(int i = a; i<b; i++)
#ifndef ONLINE_JUDGE
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

const int MOD = 1000000007;

using namespace std; 
bool check(int x);
int reverse(int num);
void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
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
    int h, m;
    cin >> h >> m;
    string time;
    cin >> time;
    int idx = time.find(':');
    int curH = stoi(time.substr(0, idx));
    int numberDigitsM = to_string(m).size();
    int numberDigitsH = to_string(h).size();
    int curM = stoi(time.substr(idx+1));
    vector<int> digitsM;
    int waitM = 0;
    bool offset = false;
    while(!check(curM) || reverse(curM)>=h){
        //cout << curM << " " << !check(curM) << " " <<  (reverse(curM)>h) <<endl;
        curM = (curM + 1);
        if(curM >= m){
            curM =0;
            offset = true;
            break;
        }
    }

    curH += offset;
    curH = curH % h;
    int waitH = 0;
    bool go = false;
    while(!check(curH) || reverse(curH) >= m){
        // cout << curH << " " << !check(curH) << " " <<  reverse(curH) <<endl;
        curH = curH + 1;
        go = true;
        if(curH >= h){
            curH =0;
            break;
        }
    }

    if(go){
        int newM = 0;
        while(!check(newM) || reverse(newM)>=h){
            //cout << newM << " " << !check(newM) << " " <<  (reverse(newM)>h) <<endl;
            newM = (newM + 1);
            if(newM >= m){
                newM =0;
                break;
            }
        }
        //cout << curM << " "<< newM << endl;
        curM = min(curM, newM);
    }

    string retH = to_string(curH);
    string retM = to_string(curM);
    retH = string(2 - retH.size(), '0') + retH;
    retM = string(2 - retM.size(), '0') + retM;

    cout << retH << ":" << retM ;


}

set<int> reflect{0, 1, 2, 5, 8};
bool check(int x)
{
    int digit = x % 10;
    if(reflect.find(digit) == reflect.end()){
        return false;
    }
    if(x >= 10){
        return check(x / 10);
    }else{
        return true;
    }
}

map<int, int> to_switch{{1,1}, {0,0}, {2,5}, {5,2}, {8,8}};


int reverse(int num)
{
    int lz = num>=10;
    int rev_num = 0;
    while(num > 0)
    {
        rev_num = rev_num*10 + to_switch[num%10];
        num = num/10;
    }
    string retS = to_string(rev_num);
    if(!lz){
        retS += '0';
    }
    int n = stoi(retS);
    return n;
}
