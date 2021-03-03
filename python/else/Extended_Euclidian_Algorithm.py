def gcd(a,b):
    """
    The extended euclidian algorithm returns the gcd, as well x and y, st:
    ax + by = gcd
    """
    if a == 0:
        return (b, 0, 1)
    else:
        gcd, x, y = gcd(b % a, a)
        return (gcd, y - (b//a) * x, x)


def lcm(a, b):
    """
    least common multiple of two numbers are calculateble by using gcd
    """
    return abs(a*b)/gcd(a, b)


print(egcd(30,50))
