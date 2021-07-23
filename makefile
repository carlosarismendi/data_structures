.PHONY= doc clean

CC=g++
OPTIONS= -g -Wall -pedantic -std=c++17
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tporo.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))
TEST=src/tvectorporo/tad13.cpp

tad:    src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o tad

test:    $(TEST) $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $(TEST) $(OBJ) -o test

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

clean:
	rm -f $(OBJ) tad test */*.out