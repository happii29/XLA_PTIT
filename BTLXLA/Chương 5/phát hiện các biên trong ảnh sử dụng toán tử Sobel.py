from sys import stdin
from math import sqrt
def sobel_operator(image):
    sobel_x=[[-1,0,1],[-2,0,2],[-1,0,1]]
    sobel_y=[[-1,-2,-1],[0,0,0],[1,2,1]]
    m,n=len(image),len(image[0])
    sobel=[[0]*n for _ in range(m)]
    for i in range(1,m-1):
        for j in range(1,n-1):
            img=[[image[i-1][j-1],image[i-1][j],image[i-1][j+1]],
            [image[i][j-1],image[i][j],image[i][j+1]],
            [image[i+1][j-1],image[i+1][j],image[i+1][j+1]]
            ]
            x=sum(sobel_x[k][l]*img[k][l] for k in range(3) for l in range(3))
            r_x=x**2
            y=sum(sobel_y[k][l]*img[k][l] for k in range(3) for l in range(3))
            r_y=y**2
            sobel[i][j]=int((r_x+r_y)**0.5)
    return sobel
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
gradient_image=sobel_operator(image)
for i in range(size):
    for j in range(size):
        print(gradient_image[i][j],end=' ')
    print()