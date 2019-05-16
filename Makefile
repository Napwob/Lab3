.PHONY:all
CC = g++
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/circles

all: build/ bin/ $(EXECUTABLE)
build/:
        mkdir build/ -p
$(EXECUTABLE): $(OD)main.o $(OD)func.o
	      $(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)func.o
$(OD)main.o: $(SD)main.c
        $(CC) $(CFLAGS) -c -o $(OD)main.o $(SD)main.c

test: bin/circles_test

bin/circles_test: build/circles_test.o build/func.o bin
        $(CC) $(CFLAGS) build/circles_test.o build/func.o -o bin/circles_test -lm
build/circles_test.o: test/main.c build
        $(CC) $(CFLAGS) -c -I thirdparty -I src test/main.c -o build/circles_test.o
build/func.o: $(SD)func.c
        $(CC) $(CFLAGS) -c -I thirdparty -I src src/func.c -o build/func.o 
clean:
        rm -rf build/*.o bin/circles bin/circles_test     
