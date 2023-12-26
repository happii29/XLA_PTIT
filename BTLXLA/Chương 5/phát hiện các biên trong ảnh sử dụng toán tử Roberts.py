from sys import stdin
from math import sqrt
def roberts_operator(image):
    m,n=len(image),len(image[0])
    roberts_x=[[-1,0],[0,1]]
    roberts_y=[[0,-1],[1,0]]
    roberts=[[0]*n for _ in range(m)]
    for i in range(1,m-1):
        for j in range(1,n-1):
            img=[[image[i-1][j-1],image[i-1][j]],[image[i][j-1],image[i][j]]]
            r_x=sum(img[i][j]*roberts_x[i][j] for i in range(2) for j in range(2))**2
            r_y=sum(img[i][j]*roberts_y[i][j] for i in range(2) for j in range(2))**2
            roberts[i][j]=int((r_x+r_y)**0.5)
    return roberts
c=[]
for line in stdin:
    c+=list(map(int,line.split()))
size=c[0]
image=[]
j=1
for i in range(size):
    row=c[j:j+size]
    image.append(row)
    j+=size
gradient_image=roberts_operator(image)
for i in range(size):
    for j in range(size):
        print(gradient_image[i][j],end=' ')
    print()