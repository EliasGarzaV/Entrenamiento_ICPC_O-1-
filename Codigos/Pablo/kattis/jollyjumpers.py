import sys

for line in sys.stdin:
    nums = list(map(int,line.split())) 
    s = set()

    jolly = True
    for i in range(1, nums[0]):
        diff = abs(nums[i] - nums[i + 1])
        if diff in s or diff > nums[0] - 1:
            print('Not jolly')
            jolly = False
            break
        else:
            s.add(diff)
    if jolly:
        print('Jolly')