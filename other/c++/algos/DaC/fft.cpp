void FFTRecursive(vector<cd> &A){
    // Slow recursive FFT
    // Given A, a vector of coefficents, FFT will evaluate the polynomial at n different positions in place
    //
    //
    // Main Idea (D&C): A(x) = A_0(x**2) + x*A_1(x**2), where A_0 are all the even indicies of A, and A_1 all the odds
    // A is always halved, at each iteration, we want to get A.size() evaluation. 
    // Fast way: Use the nth-root, as the the square of the n-th root of unity can complety be reduced to the the n/2-root of unity
    // 
    // In other words, it will calculate y in W*a = y
    // W is the matrix of (kth element from the nth root of uniity) x (it exponential, from 0 to (n-1))
    int n = A.size();
    if (n==1) return;

    vector<cd> A0(n/2), A1(n/2);

    for(int k=0; 2*k < n; ++k){
        A0[k] = A[2*k];
        A1[k] = A[2*k+1];
    }

    FFTRecursive(A0);
    FFTRecursive(A1);


    for(int k=0; 2*k < n; ++k){
        cd x = cd(cos(2*PI*k/n), sin(2*PI*k/n));
        A[k] = A0[k] + x*A1[k];
        A[k+n/2] = A0[k] - x*A1[k];

    }
}
