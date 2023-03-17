import math
def catalan(n):
    return math.comb(2 * n, n) / (n + 1)

def Catalan(n):
    """
    - Cantidad de arboles binarios completos posibles de formar con n vertices. 
    - Cantidad de Strings binarios de tamaño 2n tales que tienen n 0's y n 1's de forma que
    ningun substring inicial tiene mas 0's que 1's. 
    """
    if (n == 0 or n == 1):
        return 1
 
    # Table to store results of subproblems
    catalan = [0]*(n+1)
 
    # Initialize first two values in table
    catalan[0] = 1
    catalan[1] = 1
 
    # Fill entries in catalan[]
    # using recursive formula
    for i in range(2, n + 1):
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i-j-1]
 
    return catalan[n]
 
