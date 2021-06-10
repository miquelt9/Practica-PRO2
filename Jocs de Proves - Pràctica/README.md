_____________________________________________________________________________________________________________________________________________
Aquests jocs de proves han estat creats per Joan Caballero Castro (@JoanK11 a Github), l'enllaç en el que es poden trobar els originals https://drive.google.com/drive/u/1/folders/1t_ksvy2a_4PSQkjfpI-0bEetr_6QEVR_
accesibles amb el correu @estudiantat.upc.edu
_____________________________________________________________________________________________________________________________________________

Instruccions sobre com fer servir els jocs de prova del Drive.

Pas 1: Descarrega qualsevol joc de proves amb els seus dos fitxers corresponents: input i solució.
       Desa els fitxers a la mateixa carpeta on tens l'executable de la pràctica.

Pas 2: Al compilador, executa el teu programa de la manera següent: ./program.exe < nom.inp > nom.out ,
això generarà l'arxiu "nom.out" que contindrà la resposta del teu programa.

Pas 3: Per comparar la teva resposta amb la solució, cal fer: diff nom.out nom.cor . Ara poden passar dos casos:

1) No ha passat res, això significa que la teva resposta és la mateixa que l'arxiu solució.

2) S'han escrit una sèrie de casos que indiquen les diferències entre la teva resposta i l'arxiu solució.
   Has d'intentar modificar el teu programa per eliminar aquests errors i aconseguir el que s'indica a 1).

Extra: Si voleu comparar la vostra eficiència amb un executable acceptat pel Jutge, podeu utilitzar la comanda time i comparar els “user time” amb l’executable joan.exe i el vostre:
	time ./joan.exe < nom.inp > /dev/null
	time ./program.exe < nom.inp > /dev/null
  
El “ > /dev/null” és perquè no us escrigui l’output i us sigui més fàcil comprovar.

_________________________________________________________________________________

Els jocs ef6.cor i ef7.cor no estan pujats donada la seva mida. No obstant es poden generar utilitzant el fitxer joan.exe
