ln = input().split()
h = int(ln[0])

if(len(ln) == 1):
    print(2**(h + 1) - 1)
else:
    to_bin = {'L':'1', 'R':'0'}

    path = ''.join([to_bin[k] for k in ln[1]])

    number = int(path) + 1

    add = sum([2**k for k in range(len(ln) + 1, h)])
    print(add + number)


