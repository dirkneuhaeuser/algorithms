def egcd(a,b):
    """
    The extended euclidian algorithm returns the gcd, as well x and y, st:
    ax + by = gcd
    """
    if a == 0:
        return (b, 0, 1)
    else:
        gcd, x, y = egcd(b % a, a)
        return (gcd, y - (b//a) * x, x)

print(egcd(30,50))
