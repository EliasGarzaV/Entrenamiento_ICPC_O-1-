def colinear(x1, y1, x2, y2, x3, y3):
    m = (y2 - y1) / (x2 - x1)
    b = y1 - m*x1
    return y3 == m * x3 + b