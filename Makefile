.PHONY:all clean
CC = g++
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/circles

all: build/ bin/ $(EXECUTABLE)
build/:
	mkdir build/ -p
$(EXECUTABLE):	$(OD)main.o $(OD)text.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)text.o
$(OD)main.o: $(SD)main.c
	$(CC) $(CFLAGS) -c -o $(OD)main.o $(SD)main.c
$(OD)text.o: $(SD)text.c
	$(CC) $(CFLAGS) -c -o $(OD)text.o $(SD)text.c
clean:
	rm -rf $(EXECUTABLE) bin/geometry_test $(OD)*.o build/test/*.o
test: build/test bin/geometry_test
build/test:
	mkdir build/test -p
bin/geometry_test: build/test/main.o build/test/func.o
	$(CC) $(CFLAGS) build/test/main.o build/test/test.o -o bin/geometry_test -lm
build/test/main.o: test/main.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/test.c -o build/test/test.o -lm
build/test/func.o: src/text.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/test.c -o build/test/test.o -lm
