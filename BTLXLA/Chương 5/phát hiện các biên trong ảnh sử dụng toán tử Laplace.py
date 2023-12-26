from sys import stdin
def laplace_operator(image):
    height = len(image)
    width = len(image[0])
    result = [[0] * width for _ in range(height)]
    for i in range(1, height - 1):
        for j in range(1, width - 1):
            edge_value = (
                    image[i - 1][j] + image[i][j - 1] - 4 * image[i][j] + image[i][j + 1] +
                    image[i + 1][j]
            )
            result[i][j] = edge_value if edge_value>0 else -edge_value

    return result

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
gradient_image = laplace_operator(image)
for i in range(size):
    for j in range(size):
        print(gradient_image[i][j], end=" ")
    print()