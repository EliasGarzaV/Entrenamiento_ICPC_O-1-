[N, M] = [int(i) for i in input().split()]

start = [False] * M
for i in range(N):
    line = list(input())
    read = [False if i == '_' else True for i in line]
    start = [start[i] or read[i] for i in range(M)]
    
print(start.count(False) + 1)
    