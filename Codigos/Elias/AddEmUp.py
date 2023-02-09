[n, s] = [int(i) for i in input().split()]
nums = input().split()

flip = {'1','2', '5', '6', '8', '9', '0'}
no_flip = {'3', '4', '7'}

flip_dict = {'1':'1', '2':'5', '5':'2', '6':'9', '8':'8', '9':'6', '0':'0'}

full_nums = []
for i in nums:
    if('3' in i or '4' in i or '7' in i):
        full_nums.append(int(i))
    else:
        full_nums.append(int(i))
        new_num = ''.join([flip_dict[k] for k in i[::-1]])
        full_nums.append(int(new_num))

ans = False
for i in range(len(full_nums)):
    remaining = full_nums[:i] + full_nums[i + 1:]
    if(s - full_nums[i] in remaining):
        ans = True
        

        


            