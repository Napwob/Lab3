circles: src/main.c src/text.h src/text.c
	g++ -o bin/circles -Werror src/main.c src/text.c
clean :
	rm edit src/main.o src/text.o
