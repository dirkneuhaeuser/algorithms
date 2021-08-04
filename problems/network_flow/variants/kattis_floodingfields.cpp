#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long, long> pll;
typedef pair<int, int> pii;
#define FOR(i, n) for(int i=0; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif
// 2**6 =  64                           // 4!  = 24                       
// 2**8 =  256                          // 5!  = 120                      
// 2**10 = 1,024                        // 6!  = 720
// 2**15 = 32,768                       // 7!  = 5,040
// 2**20 = 1,048,576                    // 8!  = 40,320
// 2**25 = 33,554,432                   // 9!  = 362,880
// 2**30 = 1,073,741,824                // 10! = 3,628,800
// 2**32 = 4,294,967,296                // 12! = 479,001,600
                                        // 14! = 87,178,291,200
// int up to  2*10^9 (2^31-1)           // 16! = 20,922,789,888,000
// ll up to   9*10^18 (2^63 -1)         // 18! = 6,402,373,705,728,000
// ull up to 18*10^18 (2^64-1)/         // 20! = 2,432,902,008,176,640,000                                                                    
// ld up to  10*10^307
ll smod(ll a, ll m){return((a%m) +m) %m;}
ll modPow(ll b, ll p, ll m){if(p == 0){return 1;}ll a=modPow(b,p/2,m);a=smod(a*a,m);if(p&1)a=smod(a*smod(b, m),m);return a;}
ll invFerm(ll a, ll m){ return modPow(a, m-2,m);}
ll eea(ll a, ll n, ll &s, ll &t){ll xx = t = 0; ll yy = s = 1;while(n){ll q = a/n;ll u = n; n =a%n; a=u; u = xx; xx = s-q*xx; s = u;u = yy; yy = t-q*yy; t = u;}return a;}
ll invEea(ll b, ll m){ll s, t; ll d = eea(b, m, s, t); if(d!=1) return -1; return smod(s,m);}
const int MOD = 1000000007;
const int INF = 1<<30;

// Calculates maxFlow == minCut in O(V^2 * E)
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
    long long dfs(int cur, int t, long long f=1e18){ // sends a single flow from s to t through level graph O(E)
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
    void dfsMinCut(int cur, vector<int> &visited, vector<int> &firstClass){
        visited[cur] = true;
        firstClass.push_back(cur);
        for(int i=0; i<graph[cur].size(); ++i){
            if(get<2>(edges[graph[cur][i]]) < get<1>(edges[graph[cur][i]]) && !visited[get<0>(edges[graph[cur][i]])]){
                dfsMinCut(get<0>(edges[graph[cur][i]]), visited, firstClass);
            }
        }
    }
public:
    MaxFlow(int nodes): n(nodes) {
        edges.clear();
        graph.assign(n, vector<int>());
    }
    void add_edge(int cur, int v, long long w, bool directed=true){
        assert(cur<n && v < n);
        if(cur == v){return;}
        edges.emplace_back(v, w, 0);
        graph[cur].push_back(edges.size()-1);
        edges.emplace_back(cur, directed?0:w, 0); // backward edge
        graph[v].push_back(edges.size()-1);
    }
    long long dinic(int s, int t){  // O(V* (E + VE)) = O(V^2 * E)
         // calculates the maxFlow from s to t
         assert(s<n && t < n);
         long long maxFlow = 0;
         while(bfs(s, t)){ // O(E)
             last.assign(n, 0); // this remembers the index for the dfs
             while(long long flow = dfs(s, t)){ // O(E)
                 maxFlow += flow;
             }
         }
         return maxFlow;
    }

    vector<int> getLeftMinCut(int source){
        // returns all nodes, which are on the left side of the min cut. Idea: Go through residual-graph and if an edge still has capacity, this is not the bottleneck of the mincut, and hence the othernode is still part
        // of the left side (->dfs)
        vector<int> visited(n, false), firstClass;
        dfsMinCut(source, visited, firstClass);
        return firstClass;
    }

    vector<tuple<int, long long, long long>> get_used_backward_edges(int cur){
        // lists all backward edges ({taret node, cap, flow}) of node cur, which have a flow<0 (that means dinic used the backward edge, SOME FLOW HAS BEEN SENT TO THE NODE CUR)
        vector<tuple<int, long long, long long>> ret;
        for(int i=0; i<(int)graph[cur].size(); ++i){
            // fasten up in layer-graphs. Works only in LAYER Graph.
            //if(get<0>(edges[graph[cur][i]]) > cur) return ret; // first edgesa are backward edges, if node is bigger: only forward eges left. 
            if(get<2>(edges[graph[cur][i]]) < 0)ret.push_back(edges[graph[cur][i]]);

        }
        return ret;
    }

    vector<tuple<int, long long, long long>> get_used_forward_edges(int cur){
        // lists all forward edges ({taret node, cap, flow}) of node cur, which have a flow<0 (that means dinic used the forward edge, SOME FLOW HAS BEEN SENT FROM NODE CUR)
        vector<tuple<int, long long, long long>> ret;
        // find first forward edge via binary search. Works only if structed in layer graph. If not start at 0.
        //auto itr = lower_bound(graph[cur].begin(), graph[cur].end(), cur, 
        //       [=](int left, int right){return get<0>(edges[left]) < right; });
        //int lb = itr - graph[cur].begin();

        for(int i=0; i<(int)graph[cur].size(); ++i){
            if(get<2>(edges[graph[cur][i]]) > 0)ret.push_back(edges[graph[cur][i]]);
        }
        return ret;
    }

    void dbg_node(int cur){
        // prints all flows towards and all flows from the node cur
        for(int i=0; i<(int)graph[cur].size(); ++i){
            cout << "cur: " << cur << ", Target: " << get<0>(edges[graph[cur][i]]) << ", cap: " << get<1>(edges[graph[cur][i]]) << ", flow: " << get<2>(edges[graph[cur][i]]) << endl;
        }
    }

    void reset(){
        // rests flow of all edges back to 0. Afterwards you can use alter_edge() to change the capacity for a specific edge without rebuilding everything
        for(int i=0; i<(int)edges.size();++i){
            get<2>(edges[i]) = 0;
        }
    }

    void alter_edge_by_idx(int idx, int capacity){ // O(1)
        // Note that idx needs to be multiplictated by two (as each edge before idx puts 2 elements into the edges list (forward and backward)
        auto &forwardE = edges[idx];
        auto &backwardE = edges[idx+1];

        get<2>(forwardE) = 0; //get<> returns reference
        get<2>(backwardE) = 0;
        get<1>(forwardE) = capacity;
        get<1>(backwardE) = capacity;


    }

    void alter_edge(int cur, int v, long long w, bool directed=true){ // O(E)
        // changes the capacity of a specific edge (cur -> v) to w.
        for(int i=0; i<graph[cur].size(); ++i){
            if(get<0>(edges[graph[cur][i]]) == v){
                get<1>(edges[graph[cur][i]]) = w;
                break;
            }
        }
        if(!directed){
            for(int i=0; i<graph[v].size(); ++i){
                if(get<0>(edges[graph[v][i]]) == cur){
                    get<1>(edges[graph[v][i]]) = w;
                    break;
                }
            }
        }
    }
};

//MaxFlow maxFlow = MaxFlow(5); // O(V^2 * E)
//maxFlow.add_edge(0,1,10);
//maxFlow.add_edge(1,3,5);
//maxFlow.add_edge(1,2,5);
//maxFlow.add_edge(3,4,10);
//maxFlow.add_edge(2,4,10);
//long long flow = maxFlow.dinic(0, 4); // max_flow or min_cut or unweighted MCBM (bipartite matching)
//cout << flow << endl;



void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 

    #ifdef DIRK 
    freopen("/Users/dirk/development/algorithms/competitve/input.txt", "r", stdin); 
    freopen("/Users/dirk/development/algorithms/competitve/error.txt", "w", stderr); 
    freopen("/Users/dirk/development/algorithms/competitve/output.txt", "w", stdout); 
    #endif 
    
    solve();
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 
void solve() 
{
    // idea: The cows need to survive at each time stamp. Blow each gridcell up with time. Connect each cell at t with itself at t+1 and its neighbours at t+1 only if the target cell
    // is not floated. Also add vertix capacity in order to secure, that only 1 cow can be there at a given time.
    // nodes -> 100*100*24 = 240.000
    int n, k, h; cin >> n >> k >> h;
    vector<vector<int>> grid (n, vector<int>(n,0));
    vector<pii> cows;
    vector<int> rain;
    int totalFall = 0;
    int times = h + 1; // we need the 0th element and also the h+1 in our calculations
    FOR(i, n){
        FOR(j, n){
            cin >> grid[i][j];
        }
    }
    FOR(i, k){
        int x, y; cin >> x >> y;
        cows.emplace_back(x,y);
    }
    FOR(i, h){
        int fall; cin >> fall;
        totalFall += fall;
        rain.push_back(fall);
    }
    // structure: source, h*n*n cells blown by time, h*n*n vertrix capacity (one cow only), sink
    MaxFlow mf(2+ times*n*n*2);
    int offsetCell = 1;
    int offsetVertexCapacity = 1 + times*n*n;
    int sink = 1+times*n*n*2;

    
    FOR(i, n){
        FOR(j, n){
            int currentCell = i*n+j;
            int currentCellHourOffset = currentCell * times;
            // connect each cell to its neighbours:
            if(i > 0){
                FOR(t, h){
                    int neighbourCell = (i-1)*n+j;
                    int neighbourCellHourOffset = neighbourCell * times;
                    int neighbourHeight = grid[i-1][j];
                    if(neighbourHeight <= rain[t]) continue;
                    mf.add_edge(currentCellHourOffset + offsetVertexCapacity + t, neighbourCellHourOffset + offsetCell + (t+1), 1);
                }
            }
            if(i<n-1){
                FOR(t, h){
                    int neighbourCell = (i+1)*n+j;
                    int neighbourCellHourOffset = neighbourCell * times;
                    int neighbourHeight = grid[i+1][j];
                    if(neighbourHeight <= rain[t]) continue;
                    mf.add_edge(currentCellHourOffset + offsetVertexCapacity + t, neighbourCellHourOffset + offsetCell + (t+1), 1);
                }
            }
            if(j > 0){
                FOR(t, h){
                    int neighbourCell = i*n+(j-1);
                    int neighbourCellHourOffset = neighbourCell * times;
                    int neighbourHeight = grid[i][j-1];
                    if(neighbourHeight <= rain[t]) continue;
                    mf.add_edge(currentCellHourOffset + offsetVertexCapacity + t, neighbourCellHourOffset + offsetCell + (t+1), 1);
                }
            }
            if(j<n-1){
                FOR(t, h){
                    int neighbourCell = i*n+(j+1);
                    int neighbourCellHourOffset = neighbourCell * times;
                    int neighbourHeight = grid[i][j+1];
                    if(neighbourHeight <= rain[t]) continue;
                    mf.add_edge(currentCellHourOffset + offsetVertexCapacity + t, neighbourCellHourOffset + offsetCell + (t+1), 1);
                }
            }
            // stay in the same place and also connect input and output of each vertex
            FOR(t, times){
                int currentCellHourOffset = currentCell * times;
                // connect input and output of verteces (vertex capacity)
                mf.add_edge(currentCellHourOffset + offsetCell + t, currentCellHourOffset + offsetVertexCapacity + t, 1);
                int neighbourHeight = grid[i][j];
                if(t == times-1)break;
                if(neighbourHeight <= rain[t]){
                    continue;
                }
                // stay in the same cell
                mf.add_edge(currentCellHourOffset + offsetVertexCapacity + t, currentCellHourOffset + offsetCell + (t+1), 1);
            }
            
        }
    }
    // connect each grid after h hours which is not drown to the sink
    FOR(i, n){
        FOR(j, n){
            int currentCell = i*n+j;
            int currentCellHourOffset = currentCell * times;
            currentCellHourOffset += times - 1; // last time stamp
            if(grid[i][j] > rain.back()){
                mf.add_edge(currentCellHourOffset + offsetVertexCapacity, sink, 1);
            }
        }
    }
    // connect each cow with a source 
    FOR(i, cows.size()){
        int x = cows[i].first;
        int y = cows[i].second;
        //if (grid[x][y] ==0) continue; // they would drown right away? -> this has to be guessed :(
        int currentCell = x*n+y;
        int currentCellHourOffset = currentCell * times;
        mf.add_edge(0, currentCellHourOffset + offsetCell, 1);
    }
    ll flow = mf.dinic(0, sink);
    cout << flow;

}

