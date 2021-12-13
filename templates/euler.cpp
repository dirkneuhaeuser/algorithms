vector<int> hierholzer(int s, vector<vector<int>> &AL){
    // Finds the euler path within a graph in O(E).
    // The algorithm passes through the graph rather arbitrarily. 
    // Idea: If you start u and at some point come back to u, you either have each edge passed (save the progress in vi idx) or you can still have another detour starting from u.
    // With the stack you have this kind of post-order (similar to topological sort) -> REVERSE the result
    vector<int> ret, stack, idx(AL.size(), 0);
    stack.push_back(s);
    while(stack.size()){
        int cur = stack.back();
        if(idx[cur] < AL[cur].size()){
            stack.push_back(AL[cur][idx[cur]]);
            idx[cur]++;
        }else{
            int justFinishedCycle = stack.back(); stack.pop_back();
            ret.push_back(justFinishedCycle);
        }
    }
    return ret; // needs to be reversed.
}
