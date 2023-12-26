from sys import stdin
c=[]
for line in stdin:
    c+=list(map(int,line.split()))
size=c[0]
h=c[size+1:]
h3=[0]*size
h5=[0]*size
h3[0]=round(1/2*(h[0]+h[1]))
h3[-1]=round(1/2*(h[-1]+h[-2]))
for i in range(1,size-1):
    h3[i]=round(1/3*(h[i-1]+h[i]+h[i+1]))
h5[0]=round(1/3*(h[0]+h[1]+h[2]))
h5[1]=round(1/4*(h[0]+h[1]+h[2]+h[3]))
h5[-2]=round(1/4*(h[-4]+h[-3]+h[-2]+h[-1]))
h5[-1]=round(1/3*(h[-3]+h[-2]+h[-1]))
for i in range(2,size-2):
    h5[i]=round(1/5*(h[i-2]+h[i-1]+h[i]+h[i+1]+h[i+2]))
print('Smoothed Histogram w=3')
for i in range(size):
    print(c[i+1],end=' ')
print()
for i in range(size):
    print(h3[i],end=' ')
print()
print('Smoothed Histogram w=5')
for i in range(size):
    print(c[i+1],end=' ')
print()
for i in range(size):
    print(h5[i],end=' ')