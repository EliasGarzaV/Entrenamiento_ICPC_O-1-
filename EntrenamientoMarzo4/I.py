def mod(x,mod):
    return ((x%mod)+mod)%mod


def fun(st, n):
    inicio = (st - n)


    inicioInv = inicio

    inicio = -n
    dias = 0

    if(inicioInv % 7 == 0): #lunes
        

        dias = -((-inicio) % 91) 

 

        cuenta = 0
        if -n < 0:

            while(dias < 0):

                cuenta += 1
                dias += (30 + (cuenta%3 == 0))

        else: 
            dias = 30
    
    elif(inicioInv % 7 == 1):
        inicio += 30

        if(inicio < 0):
            inicio += 32


        if(inicio < 0):
            dias = -((-inicio) % 91)

            cuenta = 0
            while(dias < 0):
                cuenta += 1
                dias += (30 + (cuenta%3 == 0))
    
        else:
            dias = inicio
        

    elif(inicioInv % 7 == 2):
        
        dias = -((-inicio) % 91) 

        cuenta = 0
        if -n < 0:
            while(dias < 0):
                cuenta += 1
                dias += (30 + (cuenta%3 == 2))
        else:
            dias = 30
    

    elif(inicioInv % 7 == 3):
        inicio += 32

        if(inicio < 0):
            dias = -((-inicio) % 91)
            cuenta = 0
            while(dias < 0):
                cuenta += 1
                dias += (30 + (cuenta%3 == 0))
    
        else:
            dias = inicio

    elif(inicioInv % 7 == 4):
        
        dias = -((-inicio) % 91) 

        cuenta = 0
        if -n < 0:
            while(dias < 0):

                cuenta += 1
                dias += (30 + (cuenta%3 == 1))
        else: 
            dias = 31
    

    return dias


d = {"Mon": 0, "Tue": 1, "Wed": 2, "Thu": 3, "Fri": 4, "Sat": 5, "Sun": 6}

st = d[input().split()[0]]

l = [int(i) for i in input().split()]

vals = []

for n in l: 

    vals.append(fun(st, n) )


#print(vals)
print(min(vals))