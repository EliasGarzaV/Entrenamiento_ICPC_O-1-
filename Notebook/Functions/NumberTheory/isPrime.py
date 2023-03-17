def isPrime(n):
    if(n == 1 or ((n % 2 == 0 or n % 3 == 0) and n != 2 and n != 3)):
        return False
    d = 5
    while(d**2 <= n):
        if(n % d == 0):
            return False
        d = d + 2
        if(n % d == 0):
            return False
        d = d + 4
    return True

print(isPrime(2017))