def sterling_first(n, k):
    """
    Calculates the Sterling number of the first kind, which represents the number of ways
    to partition a set of n distinct objects into k disjoint cycles.
    """
    if n == 0 and k == 0:
        return 1
    elif n == 0 or k == 0:
        return 0
    else:
        # Create a table to store the results of subproblems
        table = [[0 for x in range(k+1)] for y in range(n+1)]
        
        # Fill in the base cases
        for i in range(n+1):
            table[i][0] = 0
        for j in range(1, k+1):
            table[0][j] = 0
        table[0][0] = 1
        
        # Fill in the remaining entries using the recurrence relation
        for i in range(1, n+1):
            for j in range(1, k+1):
                table[i][j] = (i-1)*table[i-1][j] + table[i-1][j-1]
        
        return table[n][k]
