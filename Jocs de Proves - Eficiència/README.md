Generador de samples de la pràctica de l'evaluator per fer proves d'eficiència
_______________________________________________________________________________

En aquesta carpeta es pot trobar el fitxer generator.cc, generator.x i
program.exe el primer dels quals és el codi el qual compilat genera el
segon fitxer.

*Per poder executar aquest segon fitxer s'ha d'accedir a la terminal, a la
carpeta on hem situat el fitxer i escriure:

./generator.x > sample.inp

El qual ens genererà un nou fitxer sample.inp per poder provar el nostre programa evaluator
Haurem de donar una sèrie de paràmetres segons la complexitat que volem obtenir
en el nostre input generat.

Per provar el programa hauràs d'executar (sent evaluator.x el teu executable):

time ./evaluator.x < sample.inp > sample.out

Per saber si el nivell d'eficiència del teu programa pots comparar-ho amb
l'executable program.exe tal que:

time ./program.exe < sample.inp > sample.cor

Seguidament pots comprovar si hi ha diferències entre els dos resultats generats
amb:

diff sample.out sample.cor

_______________________________________________________________________________

Com a idea general, el programa segueix els següents passos:

1- En primer lloc s'inicialitzen el problemes, sesions, cursos i usuaris segons
   els paràmetres que hem donat. Notem que només existeix una sesió i un curs.

2- A continuació s'inscriu l'usuari principal al curs i es realitzen els
   enviaments necessaris per completar-lo.

3- Tot seguit es crea una nova sesió que conté com a subconjunt els problemes
   de la última sesió creada més alguns de nous. També es crea un nou curs amb
   la sesió creada.

4- Es repeteix tantes vegades com s'hagui indicat en els paràmetres, és a dir,
   fins a arribar al curs que conté tots els problemes.

_______________________________________________________________________________
*instruccions per a terminal de linux

Nota_1: program.exe és l'executable d'un programa que ha passat tots els jocs de
      proves del jutge, així doncs, donada la impossibilitat de resoldre a mà
      els jocs de proves generats haurem de basar-nos en la sortida generada
      per program.exe per saber si és correcte o no el nostre.

Nota_2: a la carpeta també si inclouen els jocs d'entrada i sortida de complexitat 20
