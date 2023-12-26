from sys import stdin
def prewitt_operator(image):
    prewitt_x = [[-1, 0, 1], [-1, 0, 1], [-1, 0, 1]]
    prewitt_y = [[-1, -1, -1], [0, 0, 0], [1, 1, 1]]
    m,n=len(image),len(image[0])
    prewitt=[[0]*n for _ in range(m)]
    for i in range(1, m-1):
        for j in range(1, n-1):
            img=[
                [image[i-1][j-1],image[i-1][j],image[i-1][j+1]],
                [image[i][j-1],image[i][j],image[i][j+1]],
                [image[i+1][j-1],image[i+1][j],image[i+1][j+1]]
                ]
            x=sum(prewitt_x[k][l]*img[k][l] for k in range(3) for l in range(3))
            r_x=x**2
            y=sum(prewitt_y[k][l]*img[k][l] for k in range(3) for l in range(3))
            r_y=y**2
            prewitt[i][j]=int((r_x+r_y)**0.5)
    return prewitt
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
gradient_image = prewitt_operator(image)
for i in range(size):
    for j in range(size):
        print(gradient_image[i][j], end=" ")
    print()