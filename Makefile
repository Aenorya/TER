
main.:
	bison -d calc.y
	mv calc.tab.h calc.h
	mv calc.tab.c calc.y.c
	flex calc.lex
	mv lex.yy.c calc.lex.c
	g++ -c calc.lex.c -o calc.lex.o
	g++ -c calc.y.c -o calc.y.o
	g++  main.cpp sequent.cpp formule.cpp op_not.cpp op_binary.cpp var.cpp op_imp.cpp op_equ.cpp op_or.cpp op_and.cpp -o main calc.lex.o calc.y.o -ll -lm
	
clean:
	rm -rf *.o
