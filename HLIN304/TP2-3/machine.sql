DROP TABLE qualifier;
DROP TABLE piece;
DROP TABLE machine;
DROP TABLE operateur;

CREATE TABLE operateur(
num CHARACTER(4)PRIMARY KEY,
nom CHARACTER(40)NOT NULL,
age NUMERIC(3)
);

CREATE TABLE machine(
refM CHARACTER(3)PRIMARY KEY,
desM CHARACTER(40)
);

CREATE TABLE piece(
refP CHARACTER(2)PRIMARY KEY,
desP CHARACTER(40),
ref_machine REFERENCES machine(refM),
num_operateur REFERENCES operateur(num),
quantite NUMERIC(5)
);

CREATE TABLE qualifier(
dates DATE,
num_operateur REFERENCES operateur(num),
ref_machine REFERENCES machine(refM),
PRIMARY KEY(num_operateur,ref_machine)
);
