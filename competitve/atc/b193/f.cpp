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

using namespace std; 
void solve(); 
const int MOD = 1000000007;

// Calculates maxFlow == minCut in O(V^2 E)
class MaxFlow {
private:
    int n;
    vector<tuple<int, long long, long long>> edges; // (target node, capacity, flow used)
    vector<vector<int>> graph;
    vector<int> distance, last;
    bool bfs(int s, int t){ // construct level graph and check if more flow is possible
        distance.assign(n, -1);
        distance[s]=0;
        queue<int> q({s});
        while (!q.empty()){
            int cur = q.front(); q.pop();
            if(cur == t){break;}
            for(int idx: graph[cur]){
                auto &[v, cap, flow] = edges[idx];
                if((cap - flow) > 0 && distance[v]==-1){
                    q.push(v);
                    distance[v] = distance[cur] + 1;
                }
            }

        }
        return distance[t] != -1;

    }

    long long dfs(int cur, int t, long long f=1e18){ // send multiple flows from s to t through level graph
        if(cur==t || f==0) return f;
        for(int &i = last[cur]; i<(int)graph[cur].size(); ++i){
            auto &[v, cap, flow] = edges[graph[cur][i]];
            if(distance[cur] != distance[v] -1) continue;
            if(long long pushed = dfs(v, t, min(f, cap-flow))){
                flow += pushed;
                long long &rflow = get<2>(edges[graph[cur][i]^1]); // clever way to get back edge number^1 -> number +1 if number even else number -1
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
public:
    MaxFlow(int nodes): n(nodes) {
        edges.clear();
        graph.assign(n, vector<int>());
    }
    void add_edge(int cur, int v, long long cap, bool directed=true){ // this might be critical
        if(cur == v){return;}
        edges.emplace_back(v, cap, 0);
        graph[cur].push_back(edges.size()-1);
        edges.emplace_back(cur, directed?0:cap, 0);
        graph[v].push_back(edges.size()-1);
    }
   long long dinic(int s, int t){ // calculates the maxFlow from s to t
        long long maxFlow = 0;
        while(bfs(s, t)){
            last.assign(n, 0); // this remembers the index for the dfs
            while(long long flow = dfs(s, t)){
                maxFlow += flow;
            }
        }
        return maxFlow;

    }
};

// MaxFlow maxFlow = MaxFlow(4);
// maxFlow.add_edge(0,1,10);
// maxFlow.add_edge(1,2,5);
// maxFlow.add_edge(2,3,10);
// long long test = maxFlow.dinic(0, 3);
// cout << test << endl;


int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
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
    ll INF = 1ll << 60;
    int N; cin >> N;
    vector<vector<char>> C(N, vector<char>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c; cin >> c;
            if((c == 'B' || c== 'W') &&(i + j) &1){
                C[i][j] = c^'B'^'W';  // making neighbours to same color, s.t. we minimize different color, which is actually same color
            } else {
                C[i][j] = c;
            }
        }
    }

    MaxFlow maxFlow = MaxFlow(N*N + 2);
    for(int i=0;i<N;i++){
        int idx = i*N;
        for(int j=0;j<N;j++){
            if(C[i][j]=='B'){
                maxFlow.add_edge(N*N, idx+j, INF, false);
            }
            if(C[i][j]=='W'){
                maxFlow.add_edge(idx+j, N*N+1, INF, false);
            }
        }
    }
    for(int i=0;i<N;i++){
        int idx = i*N;
        for(int j=0;j<N;j++){
            if(j < N-1){
                maxFlow.add_edge(idx+j, idx+j+1, 1, false);
            }
            if(i < N-1){
                maxFlow.add_edge(idx + j, idx+j+N, 1, false);
            }
        }
    }
    int totalEdges = 2*N*(N-1);
    int mf = maxFlow.dinic(N*N, N*N+1);
    cout << totalEdges - mf;

}

