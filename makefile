main.out: *.cpp
	g++ test.cpp  -o  main.o 

clean:
	rm -f main.out

.PHONY: clean