class Solution:
    '''
    grey code: to transfrom a binary number to its gray code: write the msb as it is and for the rest and add for xor for all remaining the bit of the binary representation and its precessor.

    In other terms just xor a bit and its precessor (but not msb)
    '''
    def circularPermutation(self, n, start):
        return [start ^ i ^ (i >> 1) for i in range(1 << n)]
