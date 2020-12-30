CC=g++
CFLAGS= -Wall -Wextra -pedantic -std=c++14

autoroll: autoroll.o parse.o tokenize.o Expr.o
	$(CC) -o autoroll autoroll.o parse.o tokenize.o Expr.o $(CFLAGS)

Expr.o: Expr.cpp Expr.h
	$(CC) -c -o Expr.o Expr.cpp $(CFLAGS)

tokenize.o: tokenize.cpp tokenize.h Log.h Tok.h
	$(CC) -c -o tokenize.o tokenize.cpp $(CFLAGS)

parse.o: parse.cpp parse.h Expr.h Tok.h Log.h
	$(CC) -c -o parse.o parse.cpp $(CFLAGS)

autoroll.o: autoroll.cpp tokenize.h parse.h Log.h Tok.h Expr.h
	$(CC) -c -o autoroll.o autoroll.cpp $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
