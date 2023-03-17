def gcf(m,n):
    if m<n:
        (m,n) = (n,m)
    while m%n !=0:
        (m,n) = (n, m%n)
    return n

print(gcf(13,95))