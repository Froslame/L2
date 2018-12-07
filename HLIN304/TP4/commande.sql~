--1
PROMPT 1
--CREATE VIEW Q1 (titre) AS
SELECT titre FROM film
       WHERE nbspectateurs > (SELECT AVG(nbspectateurs) FROM film)
       GROUP BY titre,idF;
--2
PROMPT 2
SELECT nom,prenom FROM realisateur,film
       WHERE idRealisateur = idR AND nbspectateurs > (SELECT AVG(nbspectateurs) FROM film)
       GROUP BY nom,prenom,idR;
--3
PROMPT 3
SELECT nom,prenom FROM acteur,jouer,film
       WHERE idA=idActeur AND idF=idFilm AND nbspectateurs = (SELECT MAX(nbspectateurs) FROM film)
       GROUP BY nom,prenom,idA;
--4
PROMPT 4
SELECT nom,prenom FROM acteur
       WHERE idA NOT IN (SELECT idA FROM acteur,jouer,film WHERE idA=idActeur AND idF=idFilm)
       GROUP BY nom,prenom,idA;
--5
PROMPT 5
SELECT description FROM genre
       WHERE idG NOT IN (SELECT idG FROM genre,film WHERE idG=idGenre)
       GROUP BY description,idG;
--6
PROMPT 6
SELECT nom,prenom FROM realisateur
       WHERE idR NOT IN (SELECT idR FROM realisateur,film WHERE idR=idRealisateur AND annee>2002)
       GROUP BY nom,prenom,idR;
--7
PROMPT 7
SELECT description FROM genre,film
       WHERE idG=idGenre AND 50000<(SELECT MIN(nbspectateurs) FROM film WHERE idG=idGenre)
       GROUP BY description,idG;
--8
PROMPT 8
SELECT description FROM genre,film,realisateur
       WHERE idG=idGenre AND idR=idRealisateur AND 50000<(SELECT MIN(nbspectateurs) FROM film WHERE idG=idGenre) --AND nationalite="Americain"
       GROUP BY description,idG;
