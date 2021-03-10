// Least secnificant bit
// As index i is responsible for [(i - LSOne(i)+1)..i]
// Update: update as well the next bigger number responsible for you (i' = i+LSOne(i))
// Query: get as well next smaller number, which is responsible for [..i-LSOne(i) + 1)
#define LSOne(S) ((S) & -(S))


// Point-Update Range-Query (Standard Fenwick)
// like Prefix sum, but dynamic
// queries and update in O(logn), build in O(n) or O(nlogn)
class PURQ {
private:
    vector<long long> ft;
public:
    PURQ(int n) { // without leading 0
        ft.assign(n+1, 0); // idx 0 is bound, no value asigned to it
    }
    // builds in O(n), as oposed to O(n*logn)
    void build(vector<long long> vals){ // vals idx are keys of Fenwick-tree -> first in vector needs to be 0:
        int n = vals.size();
        ft.assign(n, 0);
        for(int i=0;i<n; i++){
            ft[i] += vals[i];
            if(i+LSOne(i)<n){
                ft[i+LSOne(i)] += vals[i];
            }
        }
    }
    long long range_query_from_left(int j){ // interval [1,...,j]
        assert(j>=0 && j < ft.size());
        long long ret = 0;
        while(j!=0){
            ret += ft[j];
            j-=LSOne(j);
        }
        return ret;
    }
    long long range_query(int i, int j){ // interval [i,...,j]
        assert(j>=i && j < ft.size());
        assert(i>=0 && i < ft.size());
        return range_query_from_left(j) - range_query_from_left(i-1);
    }
    void point_update(int i, int val){
        assert(i>0 && i < ft.size());
        while(i < ft.size()){
            ft[i]+=val;
            i += LSOne(i);
        }
    }
};
// Range-Update Point-Query
class RUPQ {
private:
    PURQ purq;
public:
    RUPQ(int m): purq(PURQ(m)){};
    void range_update(int ui, int uj, int v){
        purq.point_update(ui,v);
        purq.point_update(uj+1,-v);
    }
    long long point_query(int i) {return purq.range_query_from_left(i);}
};

// Range-Update Range-Query
class RURQ{
private:
    PURQ purq;
    RUPQ rupq;
public:
    RURQ(int m) : rupq(RUPQ(m)), purq(PURQ(m)) {}
    void range_update(int ui, int uj, int v){
        rupq.range_update(ui, uj, v);
        purq.point_update(ui,v*(ui-1)); // for cancelataion
        purq.point_update(uj+1,-v*uj); // for cancelataion

    }
    long long range_query_from_left(int j){
        return rupq.point_query(j)*j - purq.range_query_from_left(j);  // initial calculation - cancelation factor
    }
    long long range_query(int i, int j){
        return range_query_from_left(j) - range_query_from_left(i-1);
    }
};

//vector<long long> test{0,1,23,325,34,5};
//PURQ purq = PURQ(6);
//purq.build(test);

//RUPQ rupq = RUPQ(6);
//rupq.range_update(2, 3, 5);
//cout << rupq.point_query(4) << endl;

//RURQ rurq = RURQ(10);
//rurq.range_update(1, 6, 5); // remember from 1 to 6 means from 0 to 5 in your arr
//rurq.range_update(4, 8, 5);
//cout << rurq.range_query(7, 10) << endl;
