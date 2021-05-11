#include"bits/stdc++.h" // using "" instead of <>, so it will search locally for the precompiled version first
using namespace std; 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long, long> pll;
typedef pair<int, int> pii;
#define FOR(i, n) for(int i=0; i<n; i++)
#define FORS(i, n) for(; i<n; i++)
#ifdef DIRK
#include "/Users/dirk/development/algorithms/templates/debug.h"
#endif

#define EPSILON 0.000001
#define CROSS(dest, v1, v2)\
	dest[0]=v1[1]*v2[2]-v1[2]*v2[1];\
	dest[1]=v1[2]*v2[0]-v1[0]*v2[2];\
	dest[2]=v1[0]*v2[1]-v1[1]*v2[0];
#define DOT(v1,v2) (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2])
#define SUB(dest, v1, v2)\
	dest[0]=v1[0]-v2[0];\
	dest[1]=v1[1]-v2[1];\
	dest[2]=v1[2]-v2[2];


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
//
ll smod(ll a, ll m){return((a%m) +m) %m;}
ll modPow(ll b, ll p, ll m){if(p == 0){return 1;}ll a=modPow(b,p/2,m);a=smod(a*a,m);if(p&1)a=smod(a*b,m);return a;}
ll invFerm(ll a, ll m){ return modPow(a, m-2,m);}
ll eea(ll a, ll n, ll &s, ll &t){ll xx = t = 0; ll yy = s = 1;while(n){ll q = a/n;ll u = n; n =a%n; a=u; u = xx; xx = s-q*xx; s = u;u = yy; yy = t-q*yy; t = u;}return a;}
ll invEea(ll b, ll m){ll s, t; ll d = eea(b, m, s, t); if(d!=1) return -1; return smod(s,m);}
const int MOD = 1000000007;

int moller_trumbore_ray_triangle_commented(
	double orig[3], double dir[3],
	double vert0[3], double vert1[3], double vert2[3],
	double*t, double*u, double*v)	//out params
{
	double edge1[3], edge2[3], tvec[3], pvec[3], qvec[3];
	double det, inv_det;

	/* find vectors for two edges sharing vert0 */
	SUB(edge1, vert1, vert0);												//vec3 edge1 = vert1 - vert0;
	SUB(edge2, vert2, vert0);												//edge2 = vert2 - vert0;

	/*begin calculating determinant - also used to calculate u parameter*/
	CROSS(pvec, dir, edge2);												//pvec = cross(dir, edge2);		//this is first half scalar triple product

	/*if determinant is near zero, ray lies in plane of triangle */
	det = DOT(edge1, pvec);													//dot(cross(dir, edge2), edge1) - second half of scalar triple product, basically is dot(cross(dir, edge2), edge1) but ordered in a weird way

	if (det > -EPSILON && det < EPSILON)									//don't divide by zero, if det of system is 0; no unique solution -- ray paralel (or within tri plane)
		return 0;
    cout << "main det is: " <<det << endl;
	inv_det = 1.0 / det;													//part of cramers rule; we ultimately divide by determinat of entire matrix (same as multiplying by inverse)

	/* calculate distances from vert0 to ray origin */
	SUB(tvec, orig, vert0);													//tvec = ori-vert0;		//this is the RHS of system of equations (ie vec from V0 to origin)

	/* calculate U parameter and test bounds */
	*u = DOT(tvec, pvec) * inv_det;											//1. rearranged: dot(cross(dir,edge2),ori-v0) / det => scalarTripleProduct/det => that is: determinant(byScalarTripleProduct)/determinant(fullMatrix)
	if (*u < 0.0 || *u > 1.0)
		return 0;															//if the barycentric coordinate u is out of bounds, then we know we didn't hit triangle; early out

	/* prepare to test V parameter */
	CROSS(qvec, tvec, edge1);												//qvec = cross(ori-v0, edge1);	//setting up to calculate another detminant from another scalar triple product

	/* calculate V parameter and test bounds */
	*v = DOT(dir, qvec) * inv_det;											//2. dot(cross(ori-v0,edge1), dir) / det => scalarTripleProduct/det => cramers rule => det(matrixWithAdjustColumn)/det(fullmatrix)
	if (*v < 0.0 || *u + *v > 1.0)											//by checking the sum of barycentrics u and v, we can tell if the 3rd w is negative (as they should sum to 1); we can test v and w in one check this way. we know u<1.0; so we really just need to see if u+v<1.0 too
		return 0;															//if this barycentric (or if the 3rd barycentric will be out of bounds), then early out

	*t = DOT(edge2, qvec) * inv_det;										//3. the last bit of cramers rule, dot(cross(ori-v0,edge1), edge2) / det => scalarTripleProduct/det => det(adjustedMatrix)/det(systemOfEqMatrix)
    cout << "t det is :" << *t << endl;
	return 1;																//we hit triangle, return true!
}

void solve(); 
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    solve();
    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
} 

void solve() 
{
	double orig[3] = {0,0,-1};
	double dir[3] = {0,0,1};
	double vert0[3] ={-0.5,0,0};
	double vert1[3]= {-1,2,0};
	double vert2[3]= {2,0,1};
	double t, u, v; //barycentrics
    if (moller_trumbore_ray_triangle_commented(orig, dir, vert0, vert1, vert2, &t, &u, &v)){
        cout << "Collision at " << orig[0] + t*dir[0] << " " <<  orig[1] + t*dir[1] << " "<<  orig[2] + t*dir[2]<<endl;
    }


}

