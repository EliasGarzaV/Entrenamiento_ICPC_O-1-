def agujetas_gauss(points):
    """
    Utiliza agujetas de Gauss para calcular el area del poligono dado en la lista de puntos del 
    poligono orientados en contra de las manecillas del reloj. 
    """
    area = 0
    n = len(points)
    for i in range(n):
        area += points[i][0] * (points[(i + 1) % n][1] - points[(i - 1) % n][1])
    
    return area / 2

p = [(0,0), (1, 0), (1, 1), (0, 1)]
print(agujetas_gauss(p))