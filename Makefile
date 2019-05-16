.PHONY:all clean
CC = gcc
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/result.exe

all: build/ bin/ $(EXECUTABLE)
build/:
	mkdir build/ -p
bin/:
	mkdir bin/ -p        
$(EXECUTABLE):  $(OD)main.o $(OD)func.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)func.o -lm
$(OD)main.o: $(SD)main.c
	$(CC) $(CFLAGS) -c -o  $(OD)main.o $(SD)main.c -lm
$(OD)func.o: $(SD)func.c
	 $(CC) $(CFLAGS) -c -o  $(OD)func.o $(SD)func.c -lm
clean:
	rm -rf $(EXECUTABLE) bin/geometry_test $(OD)*.o build/test/*.o
test: build/test bin/geometry_test
build/test:
	mkdir build/test -p
bin/geometry_test: build/test/main.o build/test/func.o
	$(CC) $(CFLAGS) build/test/main.o build/test/func.o -o bin/geometry_test -lm
build/test/main.o: test/main.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.c -o build/test/main.o -lm
build/test/func.o: src/func.c
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/func.c -o build/test/func.o -lm        
