class ST{
private:
    // TODO: you need to change these functions+neutrals
    ll NEUTRAL_QUERY = 1ll << 60;
    ll NEUTRAL_UPDATE = 0;
    // Segment-tree consists of two operations, update and query:
    ll conqQuery(ll a, ll b){
        // min query
        return min(a, b);
    }
    // If update function is not distributive, you might need to think a little and update lazy[..] and st[..] differntly
    ll conqUpdate(ll prev, ll op){
        // add modifing
        return prev + op;
    }


    ll n;
    vector<ll> st, lazy;
    ll l(ll p){return p<<1;}
    ll r(ll p){return (p<<1) +1;}

    // only needs O(n), as it just visits all nodes only once
    void build(ll p, ll L, ll R, const vector<ll> &init){
        if (L == R){
            st[p] = init[L];
        } else{
            ll m = (L+R)/2;
            build(l(p), L, m, init);
            build(r(p), m+1, R, init);
            st[p] = conqQuery(st[l(p)], st[r(p)]);
        }
    }

    void propagate(ll p, ll L, ll R){
        // TODO: check if works (distributive law still holds)
        st[p] = conqUpdate(st[p], lazy[p]);
        if(L!=R){
            lazy[l(p)] = conqUpdate(lazy[l(p)], lazy[p]);
            lazy[r(p)] = conqUpdate(lazy[r(p)], lazy[p]);
        }
        lazy[p] = NEUTRAL_UPDATE;
    }

    void update(ll p, ll L, ll R, ll i, ll j, ll val){ // O(logn)
        propagate(p, L, R);
        if(L > j || R < i) return;
        if(L>=i && R<=j){
            st[p] = conqUpdate(st[p], val);
            if(L != R){
                lazy[l(p)] = conqUpdate(lazy[l(p)], val);
                lazy[r(p)] = conqUpdate(lazy[r(p)], val);
            }
        } else{
            ll m = (L+R)/2;
            update(l(p), L, m, i, j, val);
            update(r(p), m+1, R, i, j, val);
            st[p] = conqQuery(st[l(p)], st[r(p)]);

        }
    }


    ll query(ll p, ll L, ll R, ll i, ll j){ // O(logn)
        propagate(p, L, R);
        if(L > j || R < i) return NEUTRAL_QUERY;
        if(i<=L && j>=R){
            return st[p];
        }
        ll m = (L+R)/2;
        return conqQuery(query(l(p), L, m, i, j), query(r(p), m+1, R, i, j));
    }
public:
    ST(ll size) : n(size) {
        st.assign(4*size, NEUTRAL_QUERY); // 4 = 2*2. First 2: to make n a factor of two [actualy 2 * upper(log_2(n))], and second 2 for the inner nodes of the tree
        lazy.assign(4*n, NEUTRAL_UPDATE);
    }
    ST(const vector<ll> &initA): ST(initA.size()) {
        build(1, 0, n-1, initA);
    } 
    // All idx's i,j from 0 to n-1
    // range update, for point update set i == j
    void update(ll i, ll j, ll val) {
        // updates [i,..j]
        update(1, 0, n-1, i, j, val);
    }
    ll query(ll i, ll j){
        // queries [i,..j]
        return query(1, 0, n-1, i, j);
    }
};


//vi nums{0, 1, 2, 3, 4, 5};
//ST st(nums);
//cout << st.query(0, 2) << endl; // 0
//st.update(0, 3, 10); // add 10 to each
//cout << st.query(0, 2) << endl; // 10
//cout << st.query(3, 3) << endl; // 13
//cout << st.query(3, 4) << endl; // 4

