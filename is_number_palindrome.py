def is_palindrome(num):
    reversed_num = 0
    temp = num
    while temp>0:
        reversed_num = reversed_num*10 + temp%10
        temp //= 10
    return True if reversed_num==num else False

