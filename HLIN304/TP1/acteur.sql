DROP TABLE jouer;
DROP TABLE film;
DROP TABLE genre;
DROP TABLE realisateur;
DROP TABLE acteur;

CREATE TABLE acteur(
idA NUMERIC(5)PRIMARY KEY,
nom CHARACTER(40) NOT NULL,
prenom CHARACTER(40),
nationalite CHARACTER(40)
);

CREATE TABLE realisateur(
idR NUMERIC(5)PRIMARY KEY,
nom CHARACTER(40) NOT NULL,
prenom CHARACTER(40),
nationalite CHARACTER(40)
);

CREATE TABLE genre(
idG NUMERIC(5)PRIMARY KEY,
description CHARACTER(40)
);

CREATE TABLE film(
idF NUMERIC(5)PRIMARY KEY,
titre CHARACTER(40),
annee NUMERIC(4),
pays CHARACTER(40),
CONSTRAINT nbspectateurs NUMERIC CHECK(nbspectateurs>0),
idRealisateur NUMERIC(5)REFERENCES realisateur(idR),
idGenre NUMERIC(5)REFERENCES genre(idG)
);

CREATE TABLE jouer(
idActeur NUMERIC(5)REFERENCES acteur(idA),
idFilm NUMERIC(5)REFERENCES film(idF),
salaire NUMERIC CHECK(salaire>0),
PRIMARY KEY (idActeur,idFilm)
);
