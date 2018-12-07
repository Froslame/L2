#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys #argv
import os
import os.path
import re #analyse textuelles

if(len(sys.argv)<2):
    print("PARAMETRE REQUIS")
    exit()

ext = {} # ".sh":2
    
def decoupe(nomfichier):
    #print(nomfichier,"decoupe")
    res=re.search('(?<=\.)\w+',nomfichier)
    #print(res.group(0))
    if res:
        return res.group(0)
    return "pas de suffixe"

def parcours(repertoire):
    #print("Je suis dans "+repertoire)
    liste = os.listdir(repertoire)#Liste du repertoire
    for fichier in liste:
        #print(fichier)
        CHEMIN=repertoire+os.sep+fichier
        if os.path.isdir(CHEMIN):#test si c'est un dossier
            #print(CHEMIN,"if")
            parcours(CHEMIN)
        else: #if os.path.isfile(): #test si c'est un fichier
            #print(fichier,"else")
            txt=decoupe(fichier)
            #print(txt)
            if txt not in ext:
                ext[txt]=1
            else:
                tmp=ext.get(txt)
                ext[txt]=tmp+1
            
            
parcours(sys.argv[1])

#affichage
print("Liste des extensions : ")
k=0
for i in ext:
    print(i,":",ext.get(i))
    k+=ext.get(i)
print("TOTAL :",k)
