#!/usr/bin/python3

import time
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl

fname = input("Enter the filename containing the Seq.: ")
fhand = open(fname)
seq = fhand.read()
data= "".join(seq.split("\n")[1:])
size = len(data)
print('length of dna is:', size)

xtemp=0.5
ytemp=0.5
datax=[0.5]
datay=[0.5]
i=0

start = time.time()
for i in data:
       # i=i+3
        if i=='A':
            x1=(xtemp+0)/2
            y1=(ytemp+0)/2
        elif i=='T':
            x1=(xtemp+1)/2
            y1=(ytemp+0)/2
        elif i=='G':
            x1=(xtemp+1)/2
            y1=(ytemp+1)/2
        elif i=='C':
            x1=(xtemp+0)/2
            y1=(ytemp+1)/2
        else:
            x1=xtemp
            y1=ytemp
        xtemp=x1
        ytemp=y1
        #print xtemp
        #print ytemp
        datax.append(xtemp)
        datay.append(ytemp)
end = time.time()
print("Time taken to scatter: ", end - start)

#print ('your X co-ordinates are:', datax)
#print ('your Y co-ordinates are:', datay)
x=datax
y=datay
plt.scatter(x, y, label= ("Dot Plot of DNA: "), color='red' , marker= "*", s=0.01)
plt.xlabel('A(0,0)                 t(1,0)')
plt.ylabel('c(0,1)                 g(1,1)')
xnumbers=np.linspace(0,1,15)
ynumbers=np.linspace(0,1,25)
plt.title('Dot Plot of DNA:'), i
plt.grid()
plt.xticks(xnumbers)
plt.yticks(ynumbers)
plt.axis([0,1,0,1])
#plt.plot(datax, datay)
#mpl.style.use('seaborn')
plt.show()
