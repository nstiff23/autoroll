CC=gcc

autoroll: autoroll.o parse.o tokenize.o Expr.o
	$(CC) -o autoroll autoroll.o parse.o tokenize.o Expr.o

Expr.o: Expr.cpp Expr.h
	$(CC) -c -o Expr.o Expr.cpp

tokenize.o: tokenize.cpp tokenize.h Log.h Tok.h
	$(CC) -c -o tokenize.o tokenize.cpp

parse.o: parse.cpp parse.h Expr.h Tok.h Log.h
	$(CC) -c -o parse.o parse.cpp

autoroll.o: autoroll.cpp tokenize.h parse.h Log.h Tok.h Expr.h
	$(CC) -c -o autoroll.o autoroll.cpp

.PHONY: clean

clean:
	rm -f *.o
