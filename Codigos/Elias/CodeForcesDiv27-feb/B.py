T = int(input())

for t in range(T):
    n = int(input())
    nums = sorted([int(i) for i in input().split()])
    
    
    if(nums[-1] != 1):
        print(-1)
    else:
        ops = 0
        
        
        