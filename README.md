# Practica-PRO2
[![HitCount](https://hits.dwyl.com/miquelt9/Practica-PRO2.svg?style=flat-square&show=unique)](http://hits.dwyl.com/miquelt9/Practica-PRO2)
[![Contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat&show=unique)](/CONTRIBUTING.md)
[![GitHub stars](https://img.shields.io/github/stars/miquelt9/Practica-PRO2.svg)](https://GitHub.com/miquelt9/Practica-PRO2/stargazers/)
[![GitHub forks](https://img.shields.io/github/forks/miquelt9/Practica-PRO2.svg)](https://GitHub.com/miquelt9/Practica-PRO2/network/)
[![GitHub repo size in bytes](https://img.shields.io/github/repo-size/miquelt9/Practica-PRO2.svg)](https://github.com/miquelt9/Practica-PRO2)
[![GitHub contributors](https://img.shields.io/github/contributors/miquelt9/Practica-PRO2.svg)](https://GitHub.com/miquelt9/Practica-PRO2/graphs/contributors/)

### Informació general
________________________________________________________________________

Codi de la Pràctica de PRO2 - Evaluator

En aquest repositori trobareu les versions de la pràctica de PRO2 de l'any 2020/2021 (Q2) anomenada Evaluator.


### Enunciat
___________________________________________________________________________
- L'enunciat de la pràctica es pot llegir al fitxer [Enunciat Practica.pdf](https://github.com/miquelt9/Practica-PRO2/blob/main/Enunciat%20Practica.pdf), aquest fitxer ha estat obtingut de la web de [PROII](https://www.cs.upc.edu/pro2/index.php?id=practica-primavera-2021) de la [FIB](https://www.fib.upc.edu/).




### Carpetes Evaluator
________________________________________________________________________
- La carpeta [Evaluator 1.2](/Evaluator%201.2) conté la versió que passa la entrega intermèdia del Jutge ([Entrega Intermedia](https://jutge.org/problems/X79318_es))
- La carpeta [Evaluator 2.3](/Evaluator%202.3) conté la versió que passa la entrega final del Jutge ([Entrega Final](https://jutge.org/problems/X67518_es))

### Execució
_________________________________________________________________________
- A cadascuna de les carpetes hi trobareu un fitxer `Makefile` el qual us permetrà crear un fitxer executable de la versió de la carpeta.
  Per utilitzar el `Makefile` heu de nevagar des de terminal fins a la carpeta on heu guardat els arxius i utilizat la instrucció 
  ```sh
    make
  ```
- A més a més, a cada carpeta també hi trobareu un fitxer `Doxyfile` el qual us permetrà crear la documentació corresponent a cada carpeta. Per fer-ho s'utilitza   el programa [Doxygen](https://www.doxygen.nl/index.html) ([Doxygen repository](https://github.com/doxygen/doxygen)) i [Graphviz](https://graphviz.org/) ([Graphviz Repository](https://gitlab.com/graphviz/graphviz/)). Per instalar-lo en Debian es poden fer manualment a través dels repositoris o bé amb les següents instruccions:
```sh
  sudo apt install doxygen
  sudo apt install graphviz
  sudo apt update
```
- Per crear la doxumentació s'ha de navegar fins la carpeta de la versió desitjada i utilizar la instrucció
```sh
  doxygen
```
- Seguidament, per obrir-ho podem emprar la instrucció
```sh
  xdg-open DOC/html/index.html
```

### Jocs de prova
___________________________________________________________________________
En quant a les carpeta que contenen jocs de prova:
- La carpeta [Jocs de Proves - Pràctica](/Jocs%20de%20Proves%20-%20Pr%C3%A0ctica) conté jocs de prova que tests les diverses funcionalitats de la pràctica, els diversos tests que s'hi poden crear han estat creats per [@JoanK11](https://github.com/JoanK11)
- La carpeta [Jocs de Proves - Eficiència](/Jocs%20de%20Proves%20-%20Efici%C3%A8ncia) conté un generador de tests per provar la eficiència d'un programa

Per fer ús dels jocs de proves es trobaran les instruccions necessàries a les respectives carpetes.

