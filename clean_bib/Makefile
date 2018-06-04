clean_bib: clean_bib.o
	g++ -Wall -g -o clean_bib clean_bib.o

clean_bib.o: clean_bib.cpp
	g++ -Wall -g -c clean_bib.cpp

run:
	./clean_bib

.PHONY: clean

clean:
	rm -rf *.o *.gch clean_bib
