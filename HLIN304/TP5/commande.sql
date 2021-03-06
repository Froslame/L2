--1
PROMPT 1
SELECT COUNT(id) FROM personne;
--2
PROMPT 2
SELECT COUNT(id) FROM personne
       WHERE prenom IS NULL;
--3
PROMPT 3
SELECT id,COUNT(id) FROM personne,voiture
       WHERE id=idProp
       GROUP BY id;
--4
PROMPT 4
SELECT nom,prenom,SUM(prix) FROM personne,voiture
       WHERE id=idProp
       GROUP BY nom,prenom,id;
--5
PROMPT 5
SELECT marque,AVG(prix) AS Prix_Moyen FROM voiture
       GROUP BY marque;
--6
PROMPT 6
SELECT nom,prenom,COUNT(*) FROM personne,voiture
       WHERE id=idProp AND prix>20000
       GROUP BY nom,prenom,id;
--7
PROMPT 7
SELECT id,SUM(prix) FROM personne,voiture
       WHERE id=idProp AND 50000<(SELECT SUM(prix) FROM voiture WHERE id=idProp)
       GROUP BY id;
--8
PROMPT 8
SELECT id,annee,SUM(Prix) AS Capitale FROM personne,voiture
       WHERE id=idProp
       GROUP BY id,annee;
--9
PROMPT 9
SELECT nom,prenom,SUM(Prix) AS Capitale FROM personne,voiture
       WHERE id=idProp
       GROUP BY id,annee,nom,prenom;
