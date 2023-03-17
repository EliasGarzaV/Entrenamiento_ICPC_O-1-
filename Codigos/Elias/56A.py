n = int(input())

lst = ['ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE']
check = 0
for i in range(n):
    line = input()
    try:
        age = int(input())
        if(age < 18):
            check += 1
    except:
        if(line in lst):
            check += 1
    print((i, check))
print(check)