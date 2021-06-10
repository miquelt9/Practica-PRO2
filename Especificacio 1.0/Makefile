OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: Problema.o BinTreeProblema.o Sesion.o Curso.o Usuario.o program.o
	g++ $(OPCIONS) -o program.exe Problema.o BinTreeProblema.o Sesion.o Curso.o Usuario.o program.o 

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Usuario.o: Usuario.cc Usuario.hh
	g++ $(OPCIONS) -c Usuario.cc

Problema.o: Problema.cc Problema.hh
	g++ $(OPCIONS) -c Problema.cc

Sesion.o: Sesion.cc Sesion.hh
	g++ $(OPCIONS) -c Sesion.cc

Curso.o: Curso.cc Curso.hh
	g++ $(OPCIONS) -c Curso.cc

BinTreeProblema.o: BinTreeProblema.cc BinTreeProblema.hh
	g++ $(OPCIONS) -c BinTreeProblema.cc

clean:
	rm -f *.exe *.o
