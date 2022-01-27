struct Node{
    ll sum;
    int lazy, start, end, mid;
    bool has_lazy_flag;
    vector<Node> sons;
    Node(int _start, int _end, ll _sum=0, bool _has_lazy_flag=false){
        sum = _sum;
        start = _start;
        end = _end;
        mid = (start + end)/2;
        has_lazy_flag=_has_lazy_flag;
    }
    void propagate(){
        if(sons.size() == 0 && start < end){
            sons.push_back(Node(start, mid));
            sons.push_back(Node(mid+1, end));
        }
        if(has_lazy_flag){
            sum = (end - start + 1) * lazy;
            if(start < end){
                sons[0].has_lazy_flag = sons[1].has_lazy_flag = true;
                sons[0].lazy = sons[1].lazy = lazy;
            }
        }
        has_lazy_flag = false;
        lazy = 0;
    }
    ll query(int l, int r){
        propagate();
        if(start > r || end < l) return 0;
        if(l<=start && end <= r){
            return sum;
        }
        return sons[0].query(l, r) + sons[1].query(l, r);
    }
    void update(int l, int r, ll val){
        propagate();
        if(start > r || end < l)return;
        if(start >= l && end <= r){
            sum = (end - start + 1) * val;
            if(start != end){
                sons[0].lazy = val;
                sons[0].has_lazy_flag = true;
                sons[1].lazy = val;
                sons[1].has_lazy_flag = true;

            }
            return;
        }
        int m = (start + end)/2;
        sons[0].update(l, r, val);
        sons[1].update(l, r, val);
        sum = sons[0].sum + sons[1].sum;
    }

};

// Sparse SegmentTree (with lazy propagate), here with Assigment-modifying and sum-query
//Node st(0, 10);
//st.update(0, 4, 5);
//cout << st.query(0, 10) << endl; // 25
//st.update(5, 9, -5);
//cout << st.query(0, 10) << endl; // 0
//cout << st.query(0, 4) << endl; // 25
//cout << st.query(5, 10) << endl; // -25
