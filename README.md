# Towards Algorithms and Competitive Programming

![patrick-tomasso-Oaqk7qqNh_c-unsplash](https://user-images.githubusercontent.com/44442845/128397574-cb38d50c-08ef-4fe3-9b5e-1ca613c6af65.jpg)

This repository contains my notes on common algorithms in competitive programming.
The explainations are by no means complete and also very consise. Mainly, it concentrates on the implementation side, to use as a quick look-up. If you find something is missing in a specific section or have a question, please reach out to me!
**Note this readme is work in progress.**


# Table of Contents  
1. [Maths](#maths)
    1. [Number Theory](#nt)  
    2. [Combinatorics](#ct)
        1. [Binomial Coefficient](#binCof)
        2. [Multinomial Coefficient](#mulCof) 
        3. [Permutations](#perms)
        3. [Catalan Numbers](#catalan)
        4. [Fibonacci Numbers](#fibs)
    3. [Probability Theory](#pt)
    4. [Game Theory](#gt)
    5. [Fast Matrix Power](#mp)
    6. [Cycle Detetection](#cd)
2. [Graphs](#graphs)
    1. [Master-Theorem](#master)  
    2. [Maxflow and Mincut](#maxflow)  
4. [Dynammic Programming](#dp) 
5. [String Processing](#string)
    1. [KMP](#kmp)
    2. [Suffix-Trie](#trie)
7. [Else](#else)
    1. [Convolution](#convolution)
    1. [Bit Manipulation](#bit)

<a name="maths"/>

# 1 Maths

<a name="nt"/>

## 1.1 Number Theory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>


<a name="ct"/>

## 1.2 Combinatorics

<a name="binCof"/>

### Binomial Coefficient


When calculating it wihout modulo, use Pascal's Formula to prevent unneccesary overflow when calculating the binomial coefficent.

**Pascal's Formula** for <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{m}">:

<img src="https://render.githubusercontent.com/render/math?math=\binom{n}{m}=\begin{cases}1,  \:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\: \text{if } m=0\\1 , \:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\: \text{if } n=m\\\binom{n-1}{m} %2B\binom{n-1}{m-1} , \:\: \text{else}\end{cases}">

Pascal's formula In code (long long overflows for n>66):
```
vector<vector<ll>>bincoefs(66, vector<ll>(66, 1));
for(int n = 1; n<66; ++n){
    for(int m = 1; m< n; ++m){
        bincoefs[n][m] = bincoefs[n-1][m] + bincoefs[n-1][m-1];
    }
}
```

With Modulo (precalculate factorials and use modulo arithmetic) - use normal Formula <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{m} = \frac{n!}{(n-m)! \cdot m!}">:
```
// out of main:
long long C(long long n, long long k, long long m, long long fact[]){
    // binomial coeffiecents with modulo m
    // n! / ((n-k)! k!) 
    // to use the modular arithmetic, we need to finde the inverse of (n-k)! and k! 
    // factorials need to be precalculated and taken modulo
    if(n < k) return 0;
    return (((fact[n] * invEea(fact[k], m)) % m) * invEea(fact[n-k], m)) % m;
}
// in main:
long long fact[100001];
// precalcualte factorials
fact[0]=1;
for(int i=1; i<100001;++i){
    fact[i] = (fact[i-1]*i)%MOD;
}
// 100000 C 5000:
long long ret = C(100000, 50000, MOD, fact);  // (100000 choose 50000)%1000000007 = 149033233
```
Note: 
* Growth for fixed m, approx: <img src="https://render.githubusercontent.com/render/math?math=O(n^m)">
* <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{p}"> is even iff you can find in the binary representation of n a zero where in p is a 1 at the same position.
* To find odd Coeficients: print pascals-triangle
* Difference to Permutations: Order doesn't matter, thus there are fewer combinations than permutations.


### When to use
* combinations of n elements taken r: <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{r}">
* Binomial Theorem <img src="https://render.githubusercontent.com/render/math?math=(a %2B b)^k = x_0 a^k %2B x_1 a^{k-1}b^1 %2B \ldots %2B x_{k}b^k">, where <img src="https://render.githubusercontent.com/render/math?math=x_i = \binom{k}{i}">.
* To get all subsets of size k from a set of size n (<img src="https://render.githubusercontent.com/render/math?math=\binom{n}{k}"> many), use backtracking: 
[comb1 and comb2
](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/combinatorics.cpp)
* **Combinations to put r elements in k bins**: <img src="https://render.githubusercontent.com/render/math?math=\binom{r %2B k-1}{r}">. To see that, create bijection: separate bins with k-1 stripes "|" (here k=4) and now calculate how many possibiliters there are, to put r dots: <img width="126" alt="Screenshot 2021-05-04 at 03 10 23" src="https://user-images.githubusercontent.com/44442845/126899072-42140c0b-4880-4b5b-bcdb-2934fd517969.png">



</br>

<a name="mulCof"/>

#
### Multinomial Coefficient


Let <img src="https://render.githubusercontent.com/render/math?math=n = b_1 %2B b_2 %2B \ldots %2B b_k"> the multinomial coefficient <img src="https://render.githubusercontent.com/render/math?math=\binom{n}{b_1, b_2, \ldots, b_k}"> is given by:

<img src="https://render.githubusercontent.com/render/math?math=\binom{n}{b_1, b_2, \ldots, b_k} = \binom{n}{b_1} \cdot \binom{n-b_1}{b_2} \cdot \binom{n-b_1-b_2}{b_3} \cdot \ldots \cdot \binom{b_k}{b_k} = \frac{n!}{b_1! \cdot b_2! \cdot \ldots \cdot b_k!} ">

### Interpretations:
1. Number of ways to put n interchangeable objets into k boxes, s.t. in box i are <img src="https://render.githubusercontent.com/render/math?math=b_i"> elements
2. Number of **unique permutations** of a word with n letters and k distinct letters, s.t. i-th letter occurs <img src="https://render.githubusercontent.com/render/math?math=b_i"> times.
   E.g. permutating a mask vector `[1, 1, 1, 1, 0, 0, 0]`, leads to  <img src="https://render.githubusercontent.com/render/math?math=\frac{7!}{4! 3!}">.


</br>

<a name="perms"/>

#
### Permutations

Difference to Binomial-Coefficients: Now the Order matters. Total Permutations of sequence of length n: <img src="https://render.githubusercontent.com/render/math?math=n!">. 


Implementation via backtracking. In c++, sortable container can be permutated lexicographically (already adjusted for same elements) via in-build
`prev_permutation` and `next_permutation`:
```
vector<int> test = {1,2,3};
while (next_permutation(test.begin(), test.end())){
    // do sth
}
```
### When to use
* permutations of n elements **taken only r**: <img src="https://render.githubusercontent.com/render/math?math=\frac{n!}{(n-r)!}">, meaning the permutatins of the remaining (n-r) are not included
* **Derangement count**: Count all permutations in which all elements are at different positions (from their initial position). Formula: `derange(n) = (n - 1) * [derange(n - 1) + derange(n - 2)]`

Recusive Forumula (long long overflows for n>21):
```
long long derange[22];
derange[1] = 0;
derange[2] = 1;
for(int i =3; i<22; ++i){
    derange[i] = (i-1) * (derange[i-1] + derange[i-2]);
    cout << derange[i] <<endl;
}
```
*Proof Derangement*: Let's consider a random permuation (e.g., [1, 2, 3, 4, 5])
Then, for the first element you have (n-1) options. Lets assume it goes to i. Now there are two possible options: <br />
**Case 1**: You have a perfect swap (i and 1) -> derange(i-2) <br />
**Case 2**: You don’t have a perfect swap. Then, the i-th element can choose all elements apart of 1 and i, the remaining j can choose all apart of j and i. Thus, all remaining (n-1) have (n-2) Possibilities -> derange(i-1)






</br>

<a name="catalan"/>

#
### Catalan Numbers

The sequence 1, 1, 2, 5, 14, 42, 132, 429, 1430, ... is called Catalan Numbers.

Recursive Formula:
without mod (wachstum <img src="https://render.githubusercontent.com/render/math?math=4^n">, thus long long **overflows at n>32**)
```
long long cat[33];
cat[0] = 1;
for(int i=1; i<33; ++i){
    cat[i] = (4*i+1) * cat[i-1] / (i+2);
    cout << cat[i] << endl;
}
```

with mod:
```
int max_n = 100001;
ll cat[max_n];
cat[0] = 1;
for(int i=1; i<=max_n; ++i){
    cat[i] = ((4*i+2)%MOD * cat[i-1]%MOD *invEea(i+2, MOD)) % MOD;
    cout << cat[i] << endl;
}

```

### When to use (Catalans)
* Number of **distinct binary** trees with n vertices
* Number of ways n pairs of **parentheses** could match: n=2 pairs: ()() (()) 
* Number of ways an expression with **binary operations** can be **bracketet**
* Number of ways a **polygon** with n+2 sides can be **triangled**
* Number of ways you can pass from (0, 0) to (n, n) in a **grid without passing/touching the diagonal** (being only in the lower half)
* More complex examples: [Totorial by Dardy](https://codeforces.com/blog/entry/87585)


### Suber-Catalan 
The sequence 1, 1, 3, 11, 45, 197, 903, 4279, 20793, 103049, ... is called Super-Catalan Numbers.

Recursive Formula:
Note, long long **overflows at n>27**
```
long long super[28];
super[0] = 0;
super[1] = 1;
for(int i=2; i<28; ++i){
    super[i] = ((6*i - 9) * super[i-1] - (i-3) * super[i-2]) / i;
    cout << super[i] << endl;
}
```
### When to use (Super-Catalan)
* Number of ways you can pass from (0, 0) to (n, n) in a **grid without passing the diagonal** (toching the diagonal is ok) (being only in the lower half)
* number of **trees** with n leaves & non-leaves **>=2 childern**
* Number of **non binary bracketing**: x(xxx)x here (xxx) has 3 and not 2 elements 


Note that there are bijective mappings between the specific usecases, e.g., between the number of non-binary backeting and the number of trees with >= 2 children.


</br>

<a name="fibs"/>

#
### Fibonacci Numbers
The sequence 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ... is called fibonaccie sequence

Code (Growth ca <img src="https://render.githubusercontent.com/render/math?math=2^n">; long long will **overflow for n>64**) for <img src="https://render.githubusercontent.com/render/math?math=O(n)"> runtime: 
```
vector<int>fibs={0,1};
for(int i =2; i<65; i++){
    fibs.push_back(fibs[i-1] + fibs[i-2]);
}
```

### Pisano Period

If calculating the Fibonaccis modulo m, eventually there will be a **circle**. Let the circle be of length l, then assume that <img src="https://render.githubusercontent.com/render/math?math=F(k \cdot l) \equiv 0 (\mod m)"> it will be on 0:

```
int pisanoPeriod(int mod){ // O(n^2)
    int fib1 = 0, fib2=1;
    int period = 0;
    while(true){ // assume, that there is indead a pisano period
        // by pigoen hole principle there is at least on tuple fib_i fib_i+1 which whill be equal to another one after n**2
        // doesnt have to be start though
        period++;
        int newFib = (fib1+fib2) % mod;
        fib1 = fib2;
        fib2 = newFib;
        if(fib1==0 && fib2==1){
            return period;
        }
    }
}
```

### Zeckendorf Theorem:
Fibonacci can be presented as a binary string 1010 means: <img src="https://render.githubusercontent.com/render/math?math=0 \cdot 1 %2B 1 \cdot 2 %2B 0 \cdot 3 %2B 1 \cdot 5">.
It can be shown that two 1 are never together, as for example, 2 and 3 would form the 5, which then sets the bit of 5 and unset bits for 2 and 3

### Fibonacci Number in Logarithmic Time with fast Matrix Power
With divide and conquer, the power p of a quadratic matrix can be computed in <img src="https://render.githubusercontent.com/render/math?math=O(\log(n))"> runtime. Note that here the dimension d of the matrix is small,
and the matrix-multiplication of <img src="https://render.githubusercontent.com/render/math?math=O(d^3)"> is neglectable. For implementation see [matrix power](https://github.com/dirkneuhaeuser/algorithms/blob/master/templates/mod_pow_mat.cpp).

Recursive Formula:

<img src="https://latex.codecogs.com/gif.latex?\begin{bmatrix}1&space;&&space;1\\1&space;&&space;0\end{bmatrix}\begin{bmatrix}\text{fib}(n&plus;1)\\\text{fib}(n)\end{bmatrix}&space;=&space;\begin{bmatrix}\text{fib}(n&plus;2)\\\text{fib}(n&plus;1)\end{bmatrix}" title="\begin{bmatrix}1 & 1\\1 & 0\end{bmatrix}\begin{bmatrix}\text{fib}(n+1)\\\text{fib}(n)\end{bmatrix} = \begin{bmatrix}\text{fib}(n+2)\\\text{fib}(n+1)\end{bmatrix}" />

```
Matrix A(2);
A.mat[0][0] = 1;
A.mat[0][1] = 1;
A.mat[1][0] = 1;
A.mat[1][1] = 0;
    
Matrix ret = modPowMat(A, n);
cout << ret.mat[0][1] << endl;  //the n-th fib number, modulo MOD in O(log n)
```

</br>
</br>
</br>
</br>
</br>

<a name="pt"/>

## 1.3 Probability Theory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>

<a name="gt"/>

## 1.4 Game Theory
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>

<a name="mp"/>

## 1.5 Fast Matrix Power
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla laoreet diam egestas libero luctus, id malesuada ex ultrices. Suspendisse vestibulum hendrerit mi, rhoncus imperdiet nisl sodales in. Morbi sit amet lobortis tellus. Duis cursus nunc et velit rhoncus porta. Pellentesque felis orci, viverra et porttitor eget, dignissim sed mi. Donec ac sagittis est. Donec at nibh sem. Suspendisse at pulvinar ligula, ut mollis mauris. Cras ultricies maximus viverra. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.


</br>
</br>
</br>
</br>
</br>

<a name="cd"/>

## 1.6 Cycle Detetection
### Floyds Cycle Detection

Usually it is better to just use a dictionary, however when you need to save memory: For example when dealing with huge strings/vectors:
Floyds Cycle Detection might be favourable.

Implementation:
Let <img src="https://render.githubusercontent.com/render/math?math=\mu"> denote the **start of cycle**, 
<img src="https://render.githubusercontent.com/render/math?math=\lambda"> the **length of cycle** and
f the step function.

We have use two pointers, the **tortoise** t and the **hare** h. h is moving two times as fast as t. When they finally meet, somewhere in the circle, then
t has made i steps, the hare has made these i steps and also circled around in the the circle a bit, thus: <img src="https://render.githubusercontent.com/render/math?math=x_i = x_{i %2B k \cdot \lambda}">.
As the hare is twice as fast, we also derive that <img src="https://render.githubusercontent.com/render/math?math=i = k \cdot \lambda">, and hence <img src="https://render.githubusercontent.com/render/math?math=x_i = x_{i %2B i}">.

### Determine, the start of circle

Setting the tortoise back to the start, then there is a **distance of i** in between both pointers. Now stepping with both one step, we keep the distance of i of both pointers; that means, when both pointers are within the cycle they have a distance of i,
 which is <img src="https://render.githubusercontent.com/render/math?math=0 \equiv i \: (\mod k \cdot \lambda)">.

### Determine, the Length of circle

Leave tortoise at the cycle start and move the hare forward until it is back to the start of the cycle.

Overall code:
```
int t = f(x0), h = f(f(x0));
while(t != h){
    t = f(t); h = f(f(h));
}
int mu = 0; h =x0; // t = k*lambda
while(t != h){ // determining cycle start index
    mu++;
    t = f(t); h = f(h);
}
h = f(t);
int lambda = 1;
while(t != h){ // determining cycle length
    lambda++;
    h = f(h);
}
```




</br>
</br>
</br>
</br>
</br>


<a name="graphs"/>

# 2 Graphs


<a name="master"/>


## 2.1 Master-Theorem

The **Master-Theorem** provides a runtime analysis for **divide and conquer** algorithms and therefore is often found when travesing throug graphs.

<img src="https://render.githubusercontent.com/render/math?math=n \:\:\:\:\: "> is the input-size <br/>
<img src="https://render.githubusercontent.com/render/math?math=t(n)"> is the effor in the inner node (time to create subproblems, time to merge results of subproblems) <br/>
<img src="https://render.githubusercontent.com/render/math?math=a  \:\:\:\:\:"> is the number of subproblems in the recursion <br/> 
<img src="https://render.githubusercontent.com/render/math?math=b  \:\:\:\:\:"> is the factor by which the subproblem size is reduced in each recursive call 


<img src="https://render.githubusercontent.com/render/math?math=T(N) = aT(\frac{n}{b}) %2B t(n)">


The criterium is the **complexity of the subproblems** is now:  <img src="https://render.githubusercontent.com/render/math?math=\text{crit} = O(aT(\frac{n}{b})) = O(n^{\log_b(a)})"> <br/>

**Proof**: As The depth of the tree is given by <img src="https://render.githubusercontent.com/render/math?math=\log_b(n)"> and at depth i
there are <img src="https://render.githubusercontent.com/render/math?math=a^i"> subproblems. 
This means, there are <img src="https://render.githubusercontent.com/render/math?math=a^{\log_b(n)} = n^{\log_b(a)}"> leaves (log-law).
So, the overall complexit of the tree <img src="https://render.githubusercontent.com/render/math?math=O(n^{\log_b(a)})">.


There are three  possibilities:

1. Subproblems **dominate** the splitting and merging: <br/> 
    <img src="https://render.githubusercontent.com/render/math?math=t(n) = O(n^{\log_b(a)}) \rightarrow T(n) = O(n^{\log_b(a)})">
      
2. Subproblems are **comparabel** to splitting and merging, thus at each level, we add the complexity for<img src="https://render.githubusercontent.com/render/math?math=t(n)">:<br/> 
   <img src="https://render.githubusercontent.com/render/math?math=t(n) = \theta(n^{\log_b(a)}) \rightarrow T(n) = \theta(n^{\log_b(a)} \log_b(n))"> <br/>
   
3. Subproblems are **dominated** by spitting and merging: <br/>
   <img src="https://render.githubusercontent.com/render/math?math=t(n) = \omega(n^{\log_b(a)}) \rightarrow T(n) = \theta(t(n))"> <br/>
   
 
### Example

Let <img src="https://render.githubusercontent.com/render/math?math=T(N) = 2T(\frac{n}{2}) %2B n/2">, then <br/>
<img src="https://render.githubusercontent.com/render/math?math=\text{crit} = O(n^{\log_2(2)}) = O(n)"> and <br/> 
<img src="https://render.githubusercontent.com/render/math?math=O(t(n)) = n/2 = O(n)"> <br/>
Thus, the second case: <img src="https://render.githubusercontent.com/render/math?math=O(T(n)) =  O(n \log(n))"> <br/>



</br>
</br>
</br>
</br>
</br>



<a name="maxflow"/>

## 2.2 Maxflow and Mincut

Given a weighted directed graph as pipeline network, then </br>
**Edges**: Pipe with given capacity</br>
**Vertices**: Splitting point</br>
**2 Special vertices**: Source s and sink t</br>


**Question**: What is the max-flow/min-cut through the network from s to t?

### Set up the Residual-Graph

**Forward edge**: Normal directed edge as a given pipeline</br>
**Backward edge** (to cancel out incorrect forward flows): each backward edge has capacity 0 at the beginning, when choosing a forward edge,
then the forward edge has +flow, and its corresponding residual edge -flow</br>
**Residual Graph**: All edges in the network which still have flow < capacity </br>

### Maxflow Algorithms

1. Ford-Fulerson Method O(Maxflow * E): A potential bottleneck with capacity of 1 is used all the time (back and forth with forward and residual graph)
2. Edmonds-Karp Algorithm O(V * E^2)
3. **Dinic’s Algorithm** O(V^2 * E)
4. Push-Relabel Algorithm O(V^3), on dense graphs theoretically faster than Dinic, but Dinic is good enough for all Network problems.


Algorithm Edmonds-Karp and Dinic
Run BFS to create level graph:
  - The L-level Graph stops after L iterations
  - The Edmonds-Karp algorithm: uses this graph to only augment one s-t path (if found)
  - The Dinic algorithm: sends a blocking flow, to augment all possible s-t paths

Problems to solve with Network-Flow
Often Problem are disguised and the difficulty is to see the max-flow behind it and model it accordingly

### When to use
1. Normal **MaxFlow** problems (check max bandwith)
2. Unweighted Maximum Cardinality Bipartite Matching (**MCBM**, The easiest kind of matching)
3. **Assignment Problem** </br>
   Example: Emeis are thirsty between a and b, but at time x only 2 emeis can drink at a lake. Assign emeis to the lake.
4. **Min-cut** </br>
   Example: [kattis - thekingofthenorth](https://open.kattis.com/problems/thekingofthenorth). Defend your ground with as few soldiers as possible.
6. **Ad-hoc** problems


### Possible Difficulties: 

1. **Vertex Capacity** (add another node after that node and add edge with capacity)
2. **Back-Coupling** (time, add sum-up nodes for current and previous not used flows, see kattis_jupiter)
3. Blowing verteces up to consider **time**
4. **Extract** how many **edges** are used, or the flow within each edge (`get_used_forward_edges(node)` and `get_used_backward_edges(node)`); this is particular useful in assignment problems.
5. Get the **partition of the min_cut** (left and right side; for left side use (`getLeftMinCut(0)`): Do a dfs from sink and only pass through residual edges (not saturated edge)
6. Get **max. Independent Paths**: Each vertex can only be used once (use vertex capacity = 1), this implies disjoint paths.
7. Get **max. Disjoint Paths**: Use each edge only once. 

### Note

Often you need to work with many offsets. Better save them as a variable
```
MaxFlow maxFlow = MaxFlow(2 + sites + people);
int offsetSites = 1;
int offsetPeople = sites+1;
int sink = 2+sites+people -1;

// add edges...

long long flow = maxFlow.dinic(0, sink);
```



</br>
</br>
</br>
</br>
</br>


<a name="dp"/>

# 3 Dynammic Programming

</br>
</br>
</br>
</br>
</br>


<a name="string"/>

# 4 String Processing

Find **all positions** of a substring a string:
```
vector<int> indices;
int pos = 0;
pos = result.find("love", 0); // O(n*m) where n is length of result and m length of query(here: "love")
while(pos != string::npos){
    indices.push_back(pos);
    pos = result.find("love", pos+1);
}
```

**Standard** string processing functions:
```
str[i] = tolower(str[i]); // or toupper
bool checkDigit = isdigit(result[i]);
bool checkAlpha = isalpha(result[i]);

bool isVowel(char x){
    char vowel[6]="aeiou";
    for(int i=0; i<6; ++i){
        if(x == vowel[i])return true;
    }
    return false;
}
```
**Tokenize** a String with a given delimiter with `str.find_first_of(delimiters, start)`:
```
int current, next = -1;
vector<string> separatedWords;
string delimiters = ", ";
do
{
    current = next + 1;
    next = result.find_first_of( delimiters, current );
    string token =  result.substr( current, next - current );
    if(token != ""){
        separatedWords.push_back(token);
        cout << token << endl;
    }
}while (next != string::npos);
```

</br>
</br>
</br>
</br>
</br>


<a name="kmp"/>

## 4.1 KMP

**Substring-Matching**: When searching for a substring p in text t, the naive way would take <img src="https://render.githubusercontent.com/render/math?math=O(nm)">, where n is the length of the text and m the length of t. A faster way offers the KMP algorithm in <img src="https://render.githubusercontent.com/render/math?math=O(n %2B m)">.

Whenever there is a mismatch, it uses pre-gathered information on whether the last characters are also a prefix to try to continue on that prefix.
```
vector<int> preProcess(string pattern){
    vector<int> prefixSuffixMatches(pattern.size()+1, 0);
    prefixSuffixMatches[0] = -1;
    int i=0,j=-1;
    while(i<pattern.size()){
        while((j>=0) && pattern[i] != pattern[j]) j = prefixSuffixMatches[j]; // no match -> reset suffix counter
        ++i; ++j;
        prefixSuffixMatches[i]=j;
    }
    return prefixSuffixMatches;
}


void search(string text, string pattern, vector<int>&prefixSuffixMatches){
    // j is counting matched characters
    int i=0,j=0;
    while(i<text.size()){
        while((j>=0) && text[i] != pattern[j]) j = prefixSuffixMatches[j]; // no match -> reset
        ++i; ++j;
        if(j==pattern.size()){
            cout << "Found pattern in text at " << i-j<< "." <<endl;
            j = prefixSuffixMatches[j]; // -> the prefix of the match might be used for the next match
        }
    }
}
//string text = "I love computer science because there is nothing else to love";
//string pattern = "love";
//vector<int> prefixSuffixMatches = preProcess(pattern);
//search(text, pattern, prefixSuffixMatches);
```

</br>
</br>
</br>
</br>
</br>


<a name="trie"/>

## 4.2 Suffix-Trie

**Substring-Matching**: With a suffix-Trie you can match subsrings in <img src="https://render.githubusercontent.com/render/math?math=O(m)">, after the prepocessing of <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">, in which we insert all suffixes of the word into the trie.

A more sophisticated version would be the **suffix-tree**, which compresses paths if they do not branch.

**Longes Common Repeated Substring** in O(vertices): <br/>
In suffix-tree: The deepest inner vertix is the answer (the path towards it) <br/>
In suffix-trie: The deepest inner vertix is the answer, with more than one branche (when using an aditional terminal symbol)<br/>


**Longes Common Substring** in O(Vertices)<br/>
Insert two words (all its suffixes) and add different terminal symbol, then dfs and mark all inner nodes which have both terminal symbols in their respective subtree


```
struct Vertex{
    char character;
    vector<Vertex*> children;
    bool end;
    Vertex(char character){
        character=character;
        end=false;
        children.assign(26, nullptr);
    }
};

class Trie{
private:
    Vertex* root;
public:
    Trie(){root = new Vertex('!');}

    void insert(string word){
        Vertex* head = root;
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(head->children[idx] == nullptr){
                head->children[idx] = new Vertex(word[i]);
            }
            head=head->children[idx];
        }
        head->end=true;
    }

    bool exist(string word){
        Vertex* head = root;
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(head->children[idx] == nullptr){
                return false;
            }
            head=head->children[idx];
        }
        return head->end;
    }

    bool startWith(string prefix){
        // to check in all suffixes if there is this prefix -> substring check in O(m), where m is the length of the prefix, after O(n*n) creating of the suffixtree
        // naive find() would require O(n*m)
        // KMP would need O(n+m);
        Vertex* head = root;
        for(int i=0; i<prefix.size(); ++i){
            int idx = prefix[i]-'a';
            if(head->children[idx] == nullptr){
                return false;
            }
            head=head->children[idx];
        }
        return true;
    }

};

// 1. normal trie -> prefix checks in O(m)
// Trie root = Trie();
//root.insert("hallo"); // create in O(n);
//cout << root.exist("hallb");
//cout << root.exist("hallo");

// STRING MATCHING
// 2. suffix-trie: add all suffixes O(n*n)
//string toInsert = "hellolover";
//for(int i=0; i<toInsert.size(); ++i){
//    root.insert(toInsert.substr(i));
//}
//// substring check in O(m)
//cout << root.startWith("ello"); // true
//cout << root.startWith("allo"); // true
```



</br>
</br>
</br>
</br>
</br>


<a name="else"/>

# 5 Else

<a name="convolution"/>

## 5.1 Convolution

Let A and B be polynomials of degree n.
With Fast-Fourir-Transformation (FFT), the **multiplication of polynomials** A and B can be solved in <img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))"> instead of <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">.


**Naive Code** in <img src="https://render.githubusercontent.com/render/math?math=O(n^2)">:
```
for(int j=0; j<=n; ++j){
    for(int k=0; k<=n; ++k){
	res[j+k] += A[j] * B[k];
    }
}
```

**Better Idea** in <img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))">:
1. Convert polynoms to point-value (degree n polynom needs n+1 distrinct points) representation  <img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))">) by FFT)
2. Do polynomial multiplication in point-value representation (<img src="https://render.githubusercontent.com/render/math?math=O(n)">)
3. Convert back to coefficient representation. (<img src="https://render.githubusercontent.com/render/math?math=O(n \log (n))"> by inversed FFT)



### FFT-Intuition

Given A, a vector of coefficents, FFT will evaluate the polynomial at n + 1 (`A.size()`) different positions in place.

To evaluate the Ploynom at the position x, use D&C:
<img src="https://render.githubusercontent.com/render/math?math=A(x) = A_0(x^2) %2B x \cdot A_1(x^2)"> ,where
<img src="https://render.githubusercontent.com/render/math?math=A_0"> is the polynom of all the even indicies of A,
and <img src="https://render.githubusercontent.com/render/math?math=A_1"> all the odds. Note, you need bit-reversal order for iterating through <img src="https://render.githubusercontent.com/render/math?math=A_0"> first and then <img src="https://render.githubusercontent.com/render/math?math=A_1">.

<img src="https://render.githubusercontent.com/render/math?math=A(x) = (a_0, a_1,a_2, \ldots, a_n) = a_0 %2B a_1x^1 %2B a_2x^2 %2B \ldots %2B a_nx^n"> <br/>
<img src="https://render.githubusercontent.com/render/math?math=A_0(x) = (a_0, a_2, a_4 \ldots) = a_0 %2B a_2x^1 %2B a_4x^2 %2B \ldots"> <br/>
<img src="https://render.githubusercontent.com/render/math?math=A_1(x) = (a_1, a_3, a_5 \ldots) = a_1 %2B a_3x^1 %2B a_5x^2 %2B \ldots">

Fast way: Use the nth-root, as the the square of the n-th root of unity can complety be reduced to the the n/2-root of unity. <br/>
All n-th roots are give by: <img src="https://render.githubusercontent.com/render/math?math=e^{i2\pi k/n} = \cos(2 \pi k/n) %2B i \sin(2 \pi k/n) \:\: \forall k \in \{0, 1, \ldots, n-1\}"> <br/>

Note:
1. A is always halved, at each iterations (due to D&C)
2. Choosing x smart (take all n-th root elements), we can retrieve all n values for A from <img src="https://render.githubusercontent.com/render/math?math=A_0"> and <img src="https://render.githubusercontent.com/render/math?math=A_1"> in one go and do not need to calculate them for each value x again (collapsing property of the n-th root of unity). 


In a nutshell, we calculate y in <img src="https://render.githubusercontent.com/render/math?math=WA = y">, given W and A, 
where W is a nxn matrix, with <img src="https://render.githubusercontent.com/render/math?math=w_{k,j} = e^{i2\pi k/n \cdot j} \:\:  \forall k,j \in \{0, 1, \ldots, n-1\} "> all elements
from the n-th root and their exponentials. The collapsing-property can now be written as <img src="https://render.githubusercontent.com/render/math?math=w_{2k, n} = w_{k, n/2}">.

**Putting things togther**:<br/>
Suppose, we have already the subproblems <img src="https://render.githubusercontent.com/render/math?math=Y_0[k] = A_0(w_{k, n/2})">
and <img src="https://render.githubusercontent.com/render/math?math=Y_1[k] = A_1(w_{k, n/2}), k \in \{ 0, \ldots ,\frac{n}{2}-1 \}">,
both vectors of length n/2. We have to combine them, to calculate Y.

First half for all <img src="https://render.githubusercontent.com/render/math?math=k, k \in \{ 0, \ldots ,\frac{n}{2}-1 \}">: <br/>
<img src="https://render.githubusercontent.com/render/math?math=Y[k] = Aw_{k,n} = A_0 w_{2k, n} %2B w_{k,n} \cdot A_1 w_{2k, n} "> <br/>
<img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:= Y_0[k] %2B w_{k,n} \cdot Y_1[k]">

Second half for all <img src="https://render.githubusercontent.com/render/math?math=\frac{n}{2} %2B k, k \in \{ 0, \ldots ,\frac{n}{2}-1 \}">: <br/>
<img src="https://render.githubusercontent.com/render/math?math=Y[k] = Aw_{k,n} = A_0 w_{2k, n} - w_{k,n} \cdot A_1 w_{2k, n} "> <br/>
<img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:= Y_0[k] - w_{k,n} \cdot Y_1[k]">

### Inverse FFT

FFT calcualted n+1 different points, <img src="https://render.githubusercontent.com/render/math?math=WA = y">,
now reverse and calcualte <img src="https://render.githubusercontent.com/render/math?math=W^{-1}Y = A"> for given <img src="https://render.githubusercontent.com/render/math?math=W^{-1}">
and <img src="https://render.githubusercontent.com/render/math?math=Y">.

It can be shown: <img src="https://render.githubusercontent.com/render/math?math=w^{-1}_{k,j} = \frac{1}{n} (1/w_{k, j})">,
in polar coordinates is that just scaling <img src="https://render.githubusercontent.com/render/math?math=(\frac{1}{n})">
and conjugation <img src="https://render.githubusercontent.com/render/math?math=w^{-1}_{k,1} = w_{k,-1} = e^{-i2\pi k/n} = \cos(-2 \pi k/n) %2B i \sin(-2 \pi k/n) = \cos(2 \pi k/n) - i \sin(2 \pi k/n)">

Thus,
<img src="https://render.githubusercontent.com/render/math?math=y_j \cdot e^{-i \Theta} = \overline{\overline{y_j} \cdot e^{i \Theta}}">
```
void IFFT(vector<cd> &Y){
    for(auto &p:Y)p=conj(p);
    FFT(Y);
    for(auto &p:Y)p = conj(p); // conjugate here acutally not neccessary, as we only need real units in our problems
    for(auto &p:Y)p /= Y.size();
}
```

### When to use

Convolution are often hidden, and do not need to come in the form of polynomial-multiplication. In the following we denote * as convolution and thus the sth element is defined as <img src="https://render.githubusercontent.com/render/math?math=(f*g)_s = \sum_{j+k=s} f_j \cdot g_k">.
* **Frequency Convolution (All Possible Sums)** <br/>
Given two arrays of non-negative integers A and B. How many ways are there to get a sum <img src="https://render.githubusercontent.com/render/math?math=y = A_j %2B B_k"> for all possible y? <br/>
Example: <br/>
<img src="https://render.githubusercontent.com/render/math?math=A = \{1, 1, 1, 3, 3, 4\}"> and
<img src="https://render.githubusercontent.com/render/math?math=B = \{1, 1, 2, 3, 3\}">. <br/>
Transform them to frequency array: <br/>
<img src="https://render.githubusercontent.com/render/math?math=f_A = [0, 3, 0, 2, 1]"> and
<img src="https://render.githubusercontent.com/render/math?math=f_B = [0, 2, 1, 2]">. <br/>
Then the convolution <img src="https://render.githubusercontent.com/render/math?math=f_A * f_B = [0, 0, 6, 3, 10, 4, 5, 2] "> gives the possibilities a sum (the index is the sum) can be calculated. <br/> 
 <img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:f_A = [\color{red} 0\color{black}, 3, 0, 2, 1] \:\:\: f_A = [\color{red} 0\color{black}, \color{blue} 3\color{black}, 0, 2, 1] \:\:\: f_A = [\color{red} 0\color{black}, \color{blue} 3\color{black}, \color{green} 0\color{black}, 2, 1] \:\:\: f_A = [\color{red} 0\color{black}, \color{blue} 3\color{black}, \color{green} 0\color{black}, \color{purple} 2\color{black}, 1] \:\:  \ldots">
 <img src="https://render.githubusercontent.com/render/math?math=\:\:\:\:\:\:\:\:f_B = [\color{red}0\color{black}, 2, 1, 2] \:\:\:\:\:\:\:\: f_B = [\color{blue}0\color{black}, \color{red}2\color{black}, 1, 2] \:\:\:\:\:\:\:\: f_B = [\color{green}0\color{black}, \color{blue}2\color{black}, \color{red}1\color{black}, 2] \:\:\:\:\:\:\:\: f_B = [\color{purple}0\color{black}, \color{green}2\color{black}, \color{blue}1\color{black}, \color{red}2\color{black}] \:\: \ldots">
 
```
vector<ll> multiply(vector<ll> &p1, vector<ll> &p2){ // O(n*log(n))
    int n = 1;
    while(n < p1.size() + p2.size() -1) n <<=1;
    vector<cd> A(p1.begin(), p1.end());
    vector<cd> B(p2.begin(), p2.end());
    A.resize(n);
    B.resize(n);
    FFT(A);
    FFT(B);
    vector<cd> mult(n);
    for(int i=0; i<n; ++i){
        mult[i] = A[i]*B[i];
    }
    IFFT(mult);
    vector<ll>ret;
    for(cd a: mult){
        ret.push_back(round(a.real()));  // rounding might be changed. When dealing with frequencies/integer-values this sould be ok!
    }
    ret.resize(p1.size() + p2.size() -1);
    return ret;
}
```

* **All Dot Products** <br/>
Given two arrays of integers A and B. Determine the dot product of B with all possible contiguous subsequences of A. <br/>
As here the multiplication is not athwart, we need to reverse B, then normal convolution. <br/>
Example: <br/>
Let <img src="https://render.githubusercontent.com/render/math?math=f = [5, 7, 2, 2, 3, 6]"> and
<img src="https://render.githubusercontent.com/render/math?math=g = [2, 1, 3, 4]"> and <img src="https://render.githubusercontent.com/render/math?math=\bar{g} = [4, 3, 1, 2]"> the reversed of g.<br/>
Then, <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g} = [20, 43, 34, \textbf{27, 31, 38,} 23, 12, 12]">.

* **Bitstring Alignments** <br/>
Let A and B be bitstrings with <img src="https://render.githubusercontent.com/render/math?math=|A| \ge |B|"> . How many substrings A' of A of length B are there, such that, if <img src="https://render.githubusercontent.com/render/math?math=B_k = 1 \rightarrow A_k^' =1">? <br/>
Reverse B and convolution will give you the alignment score at each index. Add up all 1's in B and if you can find this number in <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g}"> you have a perfect alignment. <br/>
Example: <br/>
Let <img src="https://render.githubusercontent.com/render/math?math=f = [1, 1, 0, 1, 1, 1, 1, 0]"> and
<img src="https://render.githubusercontent.com/render/math?math=g = [1, 1, 0, 1]"> and <img src="https://render.githubusercontent.com/render/math?math=\bar{g} = [1, 0, 1, 1]"> the reversed of g.<br/>
Then, <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g} = [1, 1, 1, \textbf{3, 2, 2, 3, 2}, 2, 1, 0]">.

* **Bitstring Matching** <br/>
Same as Bitstring Alignments, but we need to align both 0 and 1. <br/>
Run Alignments <img src="https://render.githubusercontent.com/render/math?math=p=f*\bar{g}"> and then flip both vectors and calculate it again, lets name it q. The alignment score at each index k is given by  <img src="https://render.githubusercontent.com/render/math?math=(p%2Bq)[k]">

* **String Matching** <br/>
More general version of Bitstring Matching. Let A and B be strings, how many times does B appear in A as substring? <br/>
Compute array f: Translate each element from A to a value <img src="https://render.githubusercontent.com/render/math?math=e^{i2\pi k/n}"> with k as encoding of the character <img src="https://render.githubusercontent.com/render/math?math=(a \rightarrow 0, b\rightarrow 1, \ldots, z \rightarrow 25)"> and <img src="https://render.githubusercontent.com/render/math?math=n=25">.
Vice versa calcualte g from B, but use <img src="https://render.githubusercontent.com/render/math?math=e^{-i2\pi k/n}">. As this is again is alignment, reverse g. <br/>
Then, only when two characters are matching, the multiplcation is 1, and else less than 1.
Thus if there is a match, you will find the `B.size()` in <img src="https://render.githubusercontent.com/render/math?math=f*\bar{g}">. Note that other string processing methods like KMP or Rabin-Karp are better, performance-wise.
* **String Matching with Wildcards** <br/>
You can search with wildcards, therefore set the specific value in g to 0 and do not look for the `B.size()` in the convultion, but for `B.size() - numsWildcards`.

* **All Distances** <br/>
Let A be a bitstring, how many ways are to choose i and j, such that, <img src="https://render.githubusercontent.com/render/math?math=A_i = A_j = 1"> and  <img src="https://render.githubusercontent.com/render/math?math=j-i = k">? <br/>
The dot-product of A with itself solves this problem for all possible k, namely:  <img src="https://render.githubusercontent.com/render/math?math=\ldots, -2, -1, 0, 1, 2, \ldots ">. Note the center is then for k=0 and left and right sides are symmetric<br/>
Example: <br/>
Let <img src="https://render.githubusercontent.com/render/math?math=A = [1, 0, 1, 1, 1]">
Then, <img src="https://render.githubusercontent.com/render/math?math=A*\bar{A} = [1, 1, 2, 2, 4, 2, 2, 1, 1]">. So there are 4 possible ways to choose p and q, such that the difference is 0, and both are 1.

</br>
</br>
</br>
</br>
</br>

<a name="bit"/>

## 5.2 Bit Manipulation

- Bitwise **not** `~x`: <br/>
  E.g. For 6, which is 110 in binary, ~6 will be 11...11001, which is -5.	
  
- Gettint the **least significant bit** `x&-x` or `x&(~x + 1)`:
  ```
  int LSOne(int num){
      return num & -num;
  }
  ```
  E.g. For 6, which is 110 in binary, it will return 010, which is 2.
  
- **Count trailing zeros**:
  ```
  __builtin_ctz(num);
  ```
  E.g., 8 is 1000, thus `__builtin_ctz(8) = 3`.

# References

<a id="1">[1]</a> 
Halim, Steven et al. (2013). 
Competitive programming 4. 
Citeseer.

<a id="2">[2]</a> 
Laaksonen, Antti (2018). 
Competitive Programmer’s Handbook. 

<a id="3">[3]</a> 
Cormen, Thomas et al. (2009). 
Introduction to algorithms. 
MIT press.

