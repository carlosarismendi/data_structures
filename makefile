.PHONY= doc clean

CC=g++
OPTIONS= -g -Wall -pedantic -std=c++11
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
SRCDIR=src
TADDIR=tad.cpp
_OBJ= vector.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad:    $(SRCDIR)/$(TADDIR) $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $(SRCDIR)/$(TADDIR) $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

clean:
	rm -f $(OBJ) tad output/*