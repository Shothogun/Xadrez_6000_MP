IDIR = ../include
CC = g++
CFLAGS = -std=c++11 -I$(IDIR) -ftest-coverage -fprofile-arcs -g

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = tabuleiro.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = tabuleiro.o testa_tabuleiro.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = tabuleiro.o main.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

teste: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

main: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 