def get_root(n):
    curr = trees[n]
    while(curr[1] != 'root'):
        # print(curr)
        curr = trees[curr[0]]
    return curr[0]
    
[N, Q] = [int(i) for i in input().split()]

trees = [[i, 'root'] for i in range(N)]

for t in range(Q):
    op = input().split()
    op[1] = int(op[1]) - 1
    op[2] = int(op[2]) - 1
    
    if(op[0] == '='):
        if(trees[op[1]][1] == trees[op[2]][1]):
            trees[max(op[2], op[1])][0] = min(op[2], op[1])
            trees[max(op[2], op[1])][1] = 'branch'
        else:
            if(trees[op[1]][1] == 'branch'):
                trees[op[2]][0] = op[1]
                trees[op[2]][1] = 'branch'
            else:
                trees[op[1]][0] = op[2]
                trees[op[1]][1] = 'branch'
                
    else:
        if(get_root(op[1]) == get_root(op[2])):
            print('yes')
        else:
            print('no')
            
    print('Raices')
    for i in range(N):
        print(trees[i])
        # print(f'{i} : {get_root(i)}')