[N, M] = [int(i) for i in input().split()]

Jack = set()
ans = 0
for i in range(N):
    next = int(input())
    Jack.add(next)
    
for i in range(M):
    if(int(input()) in Jack):
        ans += 1

print(ans)

