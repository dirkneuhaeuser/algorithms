class SegmentTree{
private:
    int n;
    vector<int> A, st, lazy;
    int l(int p){return p<<1;}
    int r(int p){return (p<<1) +1;}

    // the conq method decides the problem which is being solved: here min
    int conq(int a, int b){
        if (a==-1) return b; // edge case (happens in invalid subtree in query)
        if (b==-1) return a;
        return min(a,b);
    }

    // O(n) as O(1+2+4+..+ 2**logn) = O(2n)
    void build(int p, int L, int R){
        if (L == R){
            st[p] = A[L];
        } else{
            int m = (L+R)/2;
            build(l(p), L, m);
            build(r(p), m+1, R);
            st[p] = conq(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R){ // propagate the lazy flag one level further down
        if(lazy[p] != -1){
                st[p] = lazy[p];
            if(L==R){
                A[L] = lazy[p]; // the initial update also will be updated
            }else{
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            }
            lazy[p] = -1;
        }
    }

    void update(int p, int L, int R, int i, int j, int val){ // O(logn)
        if(i>j)return; // will capture the case if you only look in the left subtree, but right gets also called
        propagate(p, L, R); // if you update a node further done, you can't have a invalid lazy flag here
        if(L>=i && R<=j){  // goal: narrow L and R down, s.t. the intervall of this node captured. == would be sufficient
            lazy[p] = val;
        } else{
            int m = (L+R)/2;
            update(l(p), L, m, i, min(j, m), val);
            update(r(p), m+1, R, max(i, m+1), j, val);
            int lsubtree = (lazy[l(p)]!=-1)?lazy[l(p)]:st[l(p)];
            int rsubtree = (lazy[r(p)]!=-1)?lazy[r(p)]:st[r(p)];
            st[p] = conq(lsubtree, rsubtree);

        }
    }

    int query(int p, int L, int R, int i, int j){ // O(logn)
        propagate(p, L, R);
        if(i>j)return -1; // invalid subtree(with no coverage)
        if(i<=L && j>=R){ // with == would be sufficent
            return st[p];
        }
        int m = (L+R)/2;
        return conq(query(l(p), L, m, i, min(m, j)), query(r(p), m+1, R, max(m+1, i), j));
    }
public:
    SegmentTree(int size) : n(size), st(4*size), lazy(4*n, -1) {}
    SegmentTree(const vector<int> &initA): SegmentTree(initA.size()) {
        A = initA;
        build(1, 0, n-1);
        dbg(st);
    }
    // range update, for point update set i == j
    void update(int i, int j, int val) {
        update(1, 0, n-1, i, j, val);
    }
    int query(int i, int j){
        return query(1, 0, n-1, i, j);
    }
};

// vector<int> test{18, 17, 13, 19, 15, 11, 20, 99};
// SegmentTree st(test);
// st.update(5,5,77); // point-update A[5] = 77
// cout << st.query(1, 3) << endl;
