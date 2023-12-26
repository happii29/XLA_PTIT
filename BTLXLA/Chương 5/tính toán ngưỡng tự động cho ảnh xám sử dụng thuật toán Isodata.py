def processing(image):
    value_count = {}
    for row in image:
        for value in row:
            if value in value_count:
                value_count[value] += 1
            else:
                value_count[value] = 1
    value_count = dict(sorted(value_count.items(), key=lambda x: x[0]))
    img = []
    n = len(image[0])**2
    for key,value in value_count.items():
        r = [key,value/n,value*key/n]
        img.append(r)
    return img
def isodata_threshold(image):
    img = processing(image=image)
    zp = 0
    p = 0
    for i in img:
        zp = zp + i[2]
        p = p + i[1]
    threshold = zp/p
    while True:
        zp1 = 0
        p1 = 0
        zp2 = 0
        p2 = 0
        for i in img:
            if i[0]<=threshold:
                zp1 += i[2]
                p1 += i[1]
            else:
                zp2 +=i[2]
                p2 += i[1]
        new_threshold = 0.5*(zp1/p1+zp2/p2)
        if int(new_threshold)==int(threshold): 
            break
        else:
            threshold = new_threshold
    return int(threshold)
sp = input()
size = int(input())
image = []
for _ in range(size):
    row = list(map(int, input().split()))
    image.append(row)
threshold = isodata_threshold(image)
print("Isodata threshold =", threshold)