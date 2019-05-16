.PHONY:all clean
CC = gcc
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/circles

all: build/ bin/ $(EXECUTABLE)
build/:
	mkdir build/ -p
bin/:
	mkdir bin/ -p        
$(EXECUTABLE):  $(OD)main.o $(OD)func.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)func.o -lm
$(OD)main.o: $(SD)main.cpp
	$(CC) $(CFLAGS) -c -o  $(OD)main.o $(SD)main.cpp -lm
$(OD)func.o: $(SD)func.cpp
	$(CC) $(CFLAGS) -c -o  $(OD)func.o $(SD)func.cpp -lm
clean:
	rm -rf $(EXECUTABLE) bin/geometry_test $(OD)*.o build/test/*.o
test: build/test bin/geometry_test
build/test:
	mkdir build/test -p
bin/geometry_test: build/test/main.o build/test/func.o
	$(CC) $(CFLAGS) build/test/main.o build/test/func.o -o bin/geometry_test -lm
build/test/main.o: test/main.cpp
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.ppc -o build/test/main.o -lm
build/test/func.o: src/func.cpp
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/func.cpp -o build/test/func.o -lm        
