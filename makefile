CC=g++
OPTIONS= -g -Wall -pedantic -std=c++11
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
SRCDIR=src
TADDIR=tad.cpp

tad:    $(SRCDIR)/$(TADDIR)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) $(SRCDIR)/$(TADDIR) -o tad

clean:
	rm -f tad output/*