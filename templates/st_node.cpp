struct Node{
    ll val;
    bool invalid=false;
    Node(){}
    Node(ll _val){
        val = _val;
    }
    Node operator+(const Node &right) const{
        if(invalid) return right;
        if(right.invalid) return *this;
        Node x;
        x.val = val+right.val;
        return x;
    }
};
class ST{
private:
    // TODO:
    ll LAZY_NO_VALUE=-1;

    Node NO_VALUE; // query
    ll n;
    vector<Node> st;
    vector<ll> lazy;
    ll l(ll p){return p<<1;}
    ll r(ll p){return (p<<1) +1;}

    // only needs O(n), as it just visits all nodes only once
    void build(ll p, ll L, ll R, const vector<ll> &A){
        if (L == R){
            st[p] = Node(A[L]);
        } else{
            ll m = (L+R)/2;
            build(l(p), L, m, A);
            build(r(p), m+1, R, A);
            st[p] = st[l(p)] + st[r(p)];
        }
    }

    // needed for range-updates
    void propagate(ll p, ll L, ll R){ 
        if(lazy[p] != LAZY_NO_VALUE){
            // TODO alter as you nneed
            st[p] = Node(lazy[p]);
            if(L!=R){
                // TODO merge lazy flags (if children have already flags set)
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            }
            lazy[p] = LAZY_NO_VALUE;
        }
    }

    void update(ll p, ll L, ll R, ll i, ll j, ll val){ // O(logn)
        propagate(p, L, R);
        if(L > j || R < i) return;
        if(L>=i && R<=j){  
            st[p] = Node(val);  // alternative: define `add` function in Node 
            if(L!=R){
                // TODO: merge lazy flags (if children lazy flag already set)
                lazy[l(p)] = val;
                lazy[r(p)] = val;
            }
        } else{
            ll m = (L+R)/2;
            update(l(p), L, m, i, j, val);
            update(r(p), m+1, R, i, j, val);
            st[p] = st[l(p)] + st[r(p)];

        }
    }


    Node query(ll p, ll L, ll R, ll i, ll j){ // O(logn)
        propagate(p, L, R);
        if(L > j || R < i) return NO_VALUE;
        if(i<=L && j>=R){
            return st[p];
        }
        ll m = (L+R)/2;
        return query(l(p), L, m, i, j) + query(r(p), m+1, R, i, j);
    }
public:
    ST(ll size) : n(size) {
        NO_VALUE.invalid = true; // TODO;
        st.resize(4*size, NO_VALUE); // 4 = 2*2. First 2: to make n a factor of two [actualy 2 * upper(log_2(n))], and second 2 for the inner nodes of the tree
        lazy.assign(4*n, LAZY_NO_VALUE);
    }
    ST(const vector<ll> &initA): ST(initA.size()) {
        build(1, 0, n-1, initA);
    } 
    // All idx's i,j from 0 to n-1
    // For point update set i == j
    void update(ll i, ll j, ll val) {
        // updates [i,..j]
        update(1, 0, n-1, i, j, val);
    }
    Node query(ll i, ll j){
        // queries [i,..j]
        return query(1, 0, n-1, i, j);
    }
};
// ST with Nodes
//vector<Node> arr;
//vi nums{1, 2, 3, 4, 5, 6, 7, 8};
//// 1. insert values as nodes, and redefine operator + in struct Node
//FOR(i, nums.size()){
//    Node x;
//    x.val = nums[i];
//    arr.push_back(x);
//}
//ST st(arr);
//// range-query as defined in node:
//cout << st.query(0,1).val << endl; // 3
//cout << st.query(1,2).val << endl; // 5
//cout << st.query(0,0).val << endl; // 1
//
//// point update of idx 0 to 10 (lazy flag won't be used here)
//Node upd;
//upd.val = 10;
//st.update(0,0,upd);
//
//cout << st.query(0,1).val << endl; // 12
//cout << st.query(1,2).val << endl; // 5
//cout << st.query(0,0).val << endl; // 10
//
//// for range updates with lazy flag you need to redefine the propagate methode:
//// range update of all idx to 100 (lazy flag won't be used here)
//upd.val = 100;
//st.update(0, 7,upd);
//
//cout << endl;
//cout << st.query(0,7).val << endl; // 1
//cout << st.query(0,1).val << endl; // 3
//cout << st.query(1,2).val << endl; // 5
//cout << st.query(0,0).val << endl; // 1
