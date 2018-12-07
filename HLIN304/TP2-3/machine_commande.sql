--1
PROMPT qté de piece fabriqué par chaque employé
SELECT num,sum(quantite) FROM operateur,piece
       WHERE num_operateur=num
       GROUP BY num;
--2
PROMPT nom employé qui ont fabriqué plus de 500pieces
SELECT nom FROM operateur,piece
       WHERE num_operateur=num
       GROUP BY num,nom HAVING sum(quantite) >= 500;
--3
PROMPT Nbr operateur qualifie pour chaque machine
SELECT refM,count(num) FROM operateur,machine,qualifier
       WHERE num_operateur = num AND ref_machine = refM
       GROUP BY refM;
--4
PROMPT Nbr piece fabriqué sur chaque machine
SELECT ref_machine,sum(quantite) FROM piece
       GROUP BY ref_machine;
--5
PROMPT Nbr employé qualifié sur chaque machine
SELECT num,count(ref_machine) FROM operateur,qualifier
       WHERE num_operateur = num
       GROUP BY num;
