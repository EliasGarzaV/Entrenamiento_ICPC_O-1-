def hungarian_algorithm(cost_matrix):
    n = len(cost_matrix)
    # Step 1: Subtract the minimum cost of each row from the row
    for i in range(n):
        min_cost = min(cost_matrix[i])
        for j in range(n):
            cost_matrix[i][j] -= min_cost
    # Step 2: Subtract the minimum cost of each column from the column
    for j in range(n):
        min_cost = float('inf')
        for i in range(n):
            if cost_matrix[i][j] < min_cost:
                min_cost = cost_matrix[i][j]
        for i in range(n):
            cost_matrix[i][j] -= min_cost
    # Step 3: Construct a matching using the minimum number of lines
    num_lines = 0
    row_covered = [False] * n
    col_covered = [False] * n
    stars = [[False] * n for i in range(n)]
    primes = [[False] * n for i in range(n)]
    while num_lines < n:
        # Find an uncovered zero and mark its row and column
        row, col = find_uncovered_zero(cost_matrix, row_covered, col_covered)
        if row is not None:
            stars[row][col] = True
            col_covered[col] = True
            row_covered[row] = True
            num_lines += 1
        else:
            # No uncovered zero found, apply step 4
            step4(cost_matrix, row_covered, col_covered, stars, primes)
    # Step 5: Calculate the minimum cost matching
    matching = []
    for i in range(n):
        for j in range(n):
            if stars[i][j]:
                matching.append((i, j))
    min_cost = sum(cost_matrix[i][j] for i, j in matching)
    return min_cost, matching

def find_uncovered_zero(cost_matrix, row_covered, col_covered):
    n = len(cost_matrix)
    for i in range(n):
        for j in range(n):
            if cost_matrix[i][j] == 0 and not row_covered[i] and not col_covered[j]:
                return i, j
    return None, None

def step4(cost_matrix, row_covered, col_covered, stars, primes):
    n = len(cost_matrix)
    # Find the smallest uncovered value
    min_val = float('inf')
    for i in range(n):
        if not row_covered[i]:
            for j in range(n):
                if not col_covered[j]:
                    if cost_matrix[i][j] < min_val:
                        min_val = cost_matrix[i][j]
    # Add the minimum value to covered rows and subtract it from uncovered columns
    for i in range(n):
        if row_covered[i]:
            for j in range(n):
                cost_matrix[i][j] += min_val
        if not row_covered[i]:
            for j in range(n):
                cost_matrix[i][j] -= min_val
    for j in range(n):
        if col_covered[j]:
            for i in range(n):
                cost_matrix[i][j] -= min_val
        if not col_covered[j]:
            for i in range(n):
                cost_matrix[i][j] += min_val
    # Add and remove primes and stars
    for i in range(n):
        for j in range(n):
            if not row_covered[i] and not col_covered[j] and cost_matrix[i][j] == 0:
                if not stars[i][j] and primes[i][j]:
                    row_covered[i] = True
                    col_covered[j] = False
                    primes[i][j] = False
                    stars[i][j] = True
                    return
    return

adj = []
n = int(input())

for i in range(n):
    l = [int(i) for i in input().split()]
    adj.append(l)




print(hungarian_algorithm(adj))


