enum {UNVISITED=-1};
vector<int> dfs_low, dfs_num, parent;
vector<pii> bridges;
vector<bool> is_articulation;
int dfs_idx, root, root_children;

void dfs(int cur, vector<vector<int>> &AL){ // O(V+E)
    dfs_num[cur] = dfs_low[cur] = dfs_idx++;
    for(int next: AL[cur]){
        if(dfs_num[next] == UNVISITED){
            parent[next] = cur;
            if(root == cur) root_children++; // only need for articulation points
            dfs(next, AL);
            if(dfs_low[next] > dfs_num[cur]){ 
                // bc of bridges here strictly greater
                bridges.push_back({next, cur});
            }
            if(dfs_low[next] >= dfs_num[cur]){ 
                // for points greater/equal
                is_articulation[cur] = true;
            }
            
            dfs_low[cur] = min(dfs_low[cur], dfs_low[next]);
        }else{
            if(parent[cur] != next){
                dfs_low[cur] = min(dfs_low[cur], dfs_num[next]); // compare with dfs_num of next, otherwise it would set it too low
            }
        }
    }
}
//// in main
//int n = 100;
//dfs_low.assign(n, UNVISITED);
//dfs_num.assign(n, UNVISITED);
//parent.assign(n, UNVISITED);
//is_articulation.assign(n, false);
//dfs_idx = 0;
//root = 0; // or set to which is root
//root_children = 0;
//if(root_children>1){
//    is_artiuclation[root] = true;
//}
