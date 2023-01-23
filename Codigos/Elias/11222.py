T = int(input())
for t in range(T):
    sols = [0]*10000
    
    one = [int(i) for i in input().split()[1:]]
    two = [int(i) for i in input().split()[1:]]
    three = [int(i) for i in input().split()[1:]]
    
    sol1 = len(one)
    sol2 = len(two)
    sol3 = len(three)
    
    for i in one:
        sols[i] = 1 
        
    for i in two:
        if(sols[i] == 1):
            sol1 -= 1
            sol2 -= 1
            sols[i] = 4 # 4 means done by 1 and 2
        else:
            sols[i] = 2
    
    for i in three:
        if(sols[i] == 1):
            sol1 -= 1
            sol3 -= 1
        elif(sols[i] == 2):
            sol2 -= 1
            sol3 -= 1
        elif(sols[i] == 4):
            sol3 -= 1
        else:
            sols[i] = 3
            
    sol = [sol1, sol2, sol3]
    maxSolves =  max(sol)
    
    print('Case #' + str(t + 1) + ':')
    for j in range(3):
        if(sol[j] == maxSolves):
            print(j + 1, end = ' ')
            print(sol[j], end = ' ')
            probs = []
            for i in range(10000):
                if(sols[i] == j + 1):
                    probs.append(str(i))
            print(' '.join(probs))
            
        
        
    
    
    