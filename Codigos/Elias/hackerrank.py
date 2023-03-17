# Enter your code here. Read input from STDIN. Print output to STDOUT

Q = int(input())

strs = ['']

for q in range(Q):
    op = input()
    curr = strs[-1] if len(strs) > 0 else ''
    
    if(op[0] == '1'):
        # print('oa')
        strs.append(curr + op[2:])
        
    elif(op[0] == '2'):
        strs.append(curr[:-int(op[2:])])
        
    elif(op[0] == '3'):
        print(curr[int(op[2:]) - 1])
    
    else:
        strs.pop()
        
    # print(strs)

        
        