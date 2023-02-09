import heapq as hq
n = int(input())

lists = []
for t in range(n):
    lists.append(sorted([int(i) for i in input().split()]))

heap = [(i, lists[i][1] - lists[i][0]) for i in range(n)]
hq.heapify(heap)

ksum = sum([lst[0] for lst in lists])
for i in range(n):
    print(ksum)
    


    
    
