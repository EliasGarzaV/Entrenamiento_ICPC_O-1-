[N, Q] = [int(i) for i in input().split()]

sets = [set([i]) for i in range(1, N + 1)]

for t in range(Q):
    op = input().split()
    if(op[0] == '='):
        sets[int(op[1]) - 1] = sets[int(op[1]) - 1].union(sets[int(op[2]) - 1])
        sets[int(op[2]) - 1] = sets[int(op[1]) - 1]
    else:
        if(op[2] in sets[int(op[1])] ):
            print('yes')
        else:
            print('no')
    
    print('Sets:')
    for k in range(N):
        print(sets[k])
            
            