#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// To use ordered use ordered_multiset<type>S something like this

//int x=1;
//ost<ll> tree;
//tree.insert(x);
//ll low=tree.order_of_key(x); // this is not possible with normal multiset. There you must have use distance(s.begin(), iterator), which takes O(n);
//tree.lower_bound(x)
//ll secondSmallest = *tree.find_by_order(1); 


