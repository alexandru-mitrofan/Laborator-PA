from random import randint

n = 100         #nr noduri
m = 230        #nr muchii
file1 = open("testpymitro.out", "w+")

mat = [ [ 0 for i in range(n) ] for j in range(n) ]
while m > 0:
    x = randint(0, n-1)
    y = randint(0, n-1)
    if mat[x][y]!=1 and x!=y:
        mat[x][y]=1
        z = randint(0, 10)
        file1.write(str(x) + " " + str(y) + " " + str(z))
        file1.write("\n")
        m=m-1
file1.close()