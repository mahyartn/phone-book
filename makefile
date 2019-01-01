main.out: *.cpp *.h
	g++ main.cpp  basic.cpp contact.cpp -o  main.o  -l sqlite3

clean:
	rm -f main.out

.PHONY: clean