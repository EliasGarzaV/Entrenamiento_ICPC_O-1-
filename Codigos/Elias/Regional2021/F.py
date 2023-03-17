[N, M] = [int(i) for i in input().split()]

adj_lst = [[] for i in range(N)]

for i in range(M):
    [inn, out] = [int(k) - 1 for k in input().split()]
    if(inn != N - 1 and out != N - 1):
        adj_lst[inn].append(out)
        adj_lst[out].append(inn)
    
visited = set()
to_visit = [N - 2]

while(len(to_visit) > 0):
    if(to_visit[0] not in visited):
        visited.add(to_visit[0])
        for i in adj_lst[to_visit[0]]:
            if(i not in visited):
                to_visit.append(i)
        to_visit.pop(0)
    else:
        to_visit.pop(0)

s = ['A']*N

for j in list(visited):
    s[j] = 'B'
    
print(''.join(s))    