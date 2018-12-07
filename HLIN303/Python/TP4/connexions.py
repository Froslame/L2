#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys #argv
import os
import re
import time

print("#####################LAST##########################")
########################################
# Extraction du "last" dans un tableau #
########################################

res_last = []
last = os.popen("last")
for i in last:
    res_last.append(i)
    print(i,end="")

print("###################################################")
############################################################
# Extraction données des différentes chaines de caracteres #
############################################################

login = []
date = []
duree = []
x=0

while(x==0):
    for chaine in res_last:
        tmp = re.search("^([a-z]+).*([A-Z][a-z]{2}) ([A-Z][a-z]{2}) ([0-9]{1,2}) ([0-9]{1,2}:[0-9]{1,2}) .*",chaine)
        if(x==0):#Pour la durée de la session actuelle
            login.append(tmp.group(1))
            date.append(tmp.group(4)+tmp.group(3))
            t0=time.strftime("%H:%M",time.gmtime())
            t1=tmp.group(5)
            H0,M0 = t0.split(":")
            H1,M1 = t1.split(":")
            H0=(int(H0)+1)*60
            H1=int(H1)*60
            M0=int(M0)
            M1=int(M1)
            D=int((H0+M0)-(H1+M1))
            duree.append(D)
            x+=1

for chaine in res_last:
    tmp = re.search("^([a-z]+).*([A-Z][a-z]{2}) ([A-Z][a-z]{2}) ([0-9]{1,2}) ([0-9]{1,2}:[0-9]{1,2}) .* ([0-9]{0,2}:[0-9]{0,2})  \(([0-9]{0,2}:[0-9]{0,2})",chaine)
    #1-login / 2-jour / 3-mois / 4-n°jour / 5-heure co / 6-heure déco / 7-durée
    if tmp:
        if (tmp.group(1)!="reboot"):
            login.append(tmp.group(1))
            date.append(tmp.group(4)+tmp.group(3))
            if x==1:
                H0,M0 = tmp.group(7).split(":")
                H0=int(H0)*60
                M0=int(M0)+H0
                duree.append(M0)

print("###################################################")
#############################################
# Affichage/Gestion différents dictionnaire #
#############################################

nbr_con={} # 'login':nfois
tps_con={} # durée en mm

k=0
for i in login:
    if i not in nbr_con:
        nbr_con[i]=1
        tps_con[i]=duree[k]
    else:
        nbr_con[i]+=1
        tps_con[i]+=duree[k]
    k+=1

print("###################################################")
#####################################################################
# Gestion Alerte selon le nbr max de connexion / temps de connexion #
#####################################################################

y=2
x=150
for i in nbr_con:
    if(nbr_con[i]>y):
        print("ATTENTION",i,"c'est connecté plus de",y,"fois !!")
    if(tps_con[i]>x):
        print("ATTENTION",i,"c'est connecté plus de",x,"minutes !!")
