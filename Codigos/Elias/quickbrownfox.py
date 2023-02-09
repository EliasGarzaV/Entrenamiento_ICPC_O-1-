T = int(input())

for t in range(T):
    str = input().lower()
    
    table = [False]*26
    
    for i in str:
        if(ord(i) >= 97 and ord(i) <= 122):
            # print(ord(i) - 97)
            table[ord(i) - 97] = True
    
    if(False in table):
        print('missing ' + ''.join([chr(i + 97) if table[i] == False else '' for i in range(26)]))
        
    else:
        print('panagram')