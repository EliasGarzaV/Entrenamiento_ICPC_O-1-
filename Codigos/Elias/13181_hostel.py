beds = input()
spaces = [len(dots) for dots in beds.split('X')]

spaces[0] = spaces[0] - 1
spaces[-1] = spaces[-1] - 1

for i in range(1, len(spaces) - 1):
    spaces[i] = int(spaces[i] / 2)
    
print(max(spaces))

    