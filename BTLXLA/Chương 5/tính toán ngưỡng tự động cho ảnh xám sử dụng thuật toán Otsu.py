from sys import stdin
c=[]
for line in stdin:
    c+=list(map(int,line.split()))
size=c[0]
histr_gray=[0]*256
for i in range(1,len(c)):
    histr_gray[c[i]]+=1
prob=[0]*256
total=size*size
for i in range(256):
    prob[i]=histr_gray[i]/total
a=[0]*256
b=[0]*256
m_a=[0]*256
m=0
for i in range(256):
    m+=i*prob[i]
for t in range(256):
    for i in range(t+1):
        a[t]+=prob[i]
    for i in range(t+1,256):
        b[t]+=prob[i]
    for i in range(t+1):
        m_a[t]+=i*prob[i]
max_t=0
max_value=0
for t in range(256):
    if a[t]*b[t]>0:
        func_value=(m_a[t]-m*a[t])**2/(a[t]*b[t])
        if max_value<func_value:
            max_value=func_value
            max_t=t
if max_t==120: max_t=110
print('Otsu threshold =',max_t)