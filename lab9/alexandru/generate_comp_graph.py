from random import randint

n = 31         #nr noduri
m = 930        #nr muchii
       
file1 = open("testpymitro.out", "w+")
i=0
while i<n:
    j=i+1
    while j<n:
        z = randint(1, 10)
        file1.write(str(i) + " " + str(j) + " " + str(z))
        file1.write("\n")
        file1.write(str(j) + " " + str(i) + " " + str(z))
        file1.write("\n")
        j=j+1
    i=i+1


file1.close()