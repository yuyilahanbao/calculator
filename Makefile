objects = main.o fraction.o preexpr.o
make: $(objects)
	edit
	gcc $(objects) -o main
edit: $(objects)
	gcc -g -o edit $(objects)
main.o: fraction.h preexpr.h
preexpr.o: fraction.h preexpr.h
fraction.o: fraction.h

clean:
	rm edit $(objects)
