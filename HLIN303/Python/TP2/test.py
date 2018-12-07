#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys #argv
import locale #atoi
import random
import csv #lecture fichier csv
import re
import glob
import string

if (len(sys.argv)<3):
    print("PARAMETRE REQUIS")
else:
    doc=[]
    nb=0
    with open('capitales.csv', newline='') as csvfile:
        reader = csv.reader(csvfile,delimiter=' ')
        for row in reader:
            #print(''.join(row))
            doc.append(''.join(row))
            nb+=1
    print("Il y a ",nb," questions possibles !")
    tenta=int(sys.argv[1])
    print("Vous jouez avec ",tenta," questions !")
    
    pays=[]
    capitales=[]
    for k in range(nb):
        j=""
        i=0
        while j!="(":
            j=doc[k][i]
            i+=1
            if j==",":
                j="("
        i-=1
        x=doc[k]
        y=doc[k]
        x=x[:i]
        while j!=",":
            j=doc[k][i]
            i+=1
        y=y[i:]
        pays.append(x)
        capitales.append(y)
        #print(pays[k])
        #print(capitales[k])

    if(tenta>nb):
        print("MAXIMUM",nb,"QUESTIONS")
        exit()
    
    score=0
    score_rate=100
    tab_check=[]
    k=0
    brr=tenta

    #Check si rdm déjà utilisé
    def check(rdm_check):
        for i in range(k):
            if tab_check[i]==rdm_check:
                return 0
        return 1
    
    #Mode Pays -> Capitale
    if(int(sys.argv[2])==0):
        print("Donne la capitale correspondante : ")
        while tenta !=0:
            rdm=random.randint(0,nb)
            if(check(rdm)==1):
                tab_check.append(rdm)
                k+=1
                print(pays[rdm],":",end=" ")
                rep=input()
                if(capitales[rdm]==rep):
                    tab_check.append(rdm)
                    k+=1
                    score+=1
                tenta-=1
        
    #Mode Capitale -> Pays    
    if(int(sys.argv[2])==1):
        print("Donne la capitale correspondante : ")
        while tenta !=0:
            rdm=random.randint(0,nb)
            if(check(rdm)==1):
                tab_check.append(rdm)
                k+=1
                print(capitales[rdm],":",end=" ")
                rep=input()
                if(pays[rdm]==rep):
                    tab_check.append(rdm)
                    k+=1
                    score+=1
                tenta-=1

    #Mode ezWin
    if(int(sys.argv[2])==2):
        print("Donne la capitale correspondante : ")
        while tenta !=0:
            rdm=random.randint(0,nb)
            if(check(rdm)==1):
                tab_check.append(rdm)
                k+=1
                print(pays[rdm],":","(",capitales[rdm],")",end=" ")
                rep=input()
                if(capitales[rdm]==rep):
                    tab_check.append(rdm)
                    k+=1
                    score+=1
                tenta-=1

    print("Score : ",score," / ",sys.argv[1])
    print("WRate : ",(score/brr)*100,"%")
