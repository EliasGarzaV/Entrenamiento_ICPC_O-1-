def strassen(A, B):
    n = len(A)
    
    # Base case: if matrices are 1x1, perform simple multiplication
    if n == 1:
        return [[A[0][0] * B[0][0]]]
    
    # Divide matrices into smaller submatrices
    n2 = n // 2
    A11, A12, A21, A22 = [], [], [], []
    B11, B12, B21, B22 = [], [], [], []
    for i in range(n2):
        A11.append(A[i][:n2])
        A12.append(A[i][n2:])
        A21.append(A[i+n2][:n2])
        A22.append(A[i+n2][n2:])
        B11.append(B[i][:n2])
        B12.append(B[i][n2:])
        B21.append(B[i+n2][:n2])
        B22.append(B[i+n2][n2:])
    
    # Calculate 7 products of submatrices
    P1 = strassen(add(A11, A22), add(B11, B22))
    P2 = strassen(add(A21, A22), B11)
    P3 = strassen(A11, sub(B12, B22))
    P4 = strassen(A22, sub(B21, B11))
    P5 = strassen(add(A11, A12), B22)
    P6 = strassen(sub(A21, A11), add(B11, B12))
    P7 = strassen(sub(A12, A22), add(B21, B22))
    
    # Combine products to get result
    C11 = add(sub(add(P1, P4), P5), P7)
    C12 = add(P3, P5)
    C21 = add(P2, P4)
    C22 = add(sub(add(P1, P3), P2), P6)
    
    # Construct resulting matrix
    C = [[0] * n for _ in range(n)]
    for i in range(n2):
        for j in range(n2):
            C[i][j] = C11[i][j]
            C[i][j+n2] = C12[i][j]
            C[i+n2][j] = C21[i][j]
            C[i+n2][j+n2] = C22[i][j]
    
    # Return resulting matrix
    return C

def add(A, B):
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] + B[i][j]
    return C

def sub(A, B):
    n = len(A)
    C = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] - B[i][j]
    return C
