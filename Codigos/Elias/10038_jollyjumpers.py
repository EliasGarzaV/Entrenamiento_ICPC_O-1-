lst = input()
n = int(lst[0])
lst = [int(i) for i in lst[2:].split()]

mask = [False]*(n - 1)
jolly = True
for i in range(n - 1):
    # print(i)
    if(mask[abs(lst[i + 1] - lst[i]) - 1]):
        jolly = False
        break
    else:
        mask[abs(lst[i + 1] - lst[i]) - 1] = True
if(jolly):
    print('Jolly')
else:
    print('Not jolly')
        
