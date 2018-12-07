#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys #argv
import locale #atoi

if len(sys.argv)<2:
    print("PARAMETRE REQUIS")
print("#---------------------#")
#Affiche parametre
for i in range(len(sys.argv)): 
    if i!=0:
        print(sys.argv[i])

#Factorielle
x=1
n=locale.atoi(sys.argv[1])
while n!=0:
    x*=n
    n-=1
print("factorielle ",x)
print("#---------------------#")
#Liste n entiers premier
k=locale.atoi(sys.argv[1])#int(sys.argv[1])
q=k-1
i=0
list=[]
while k!=1:
    check=1
    for z in range(q):
        if (z!=0):
            if (z!=1): 
                if k%z == 0 :
                    check=0
    if check == 1:
        list.append(k) 
        i+=1
    k-=1
    q-=1

x=0
print("List:")
for x in range(i):
    print(list[x],end=" ")
print()
print("#---------------------#")
#Affiche les n premiers entier
tab=[]
k=int(sys.argv[1])
q=2
i=0
if(k>0):
    tab.append(q)
    i+=1
while i!=k :
    q+=1
    check=1
    for z in range(q):
        if (z>1): 
            if z!=q:
                if q%z == 0:
                    check=0
    if check == 1:
        tab.append(q)
        i+=1
x=0
print("List:")
for x in range(i):#len(range)
    print(tab[x],end=" ")
print()
print("#---------------------#")
