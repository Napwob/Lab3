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
$(EXECUTABLE):  $(OD)main.o $(OD)text.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)text.o -lm
$(OD)main.o: $(SD)main.cpp
	$(CC) $(CFLAGS) -c -o  $(OD)main.o $(SD)main.cpp -lm
$(OD)text.o: $(SD)text.cpp
	 $(CC) $(CFLAGS) -c -o  $(OD)text.o $(SD)text.cpp -lm
clean:
	rm -rf $(EXECUTABLE) bin/geometry_test $(OD)*.o build/test/*.o
test: build/test bin/geometry_test
build/test:
	mkdir build/test -p
bin/geometry_test: build/test/main.o build/test/text.o
	$(CC) $(CFLAGS) build/test/main.o build/test/text.o -o bin/geometry_test -lm
build/test/main.o: test/main.cpp
	$(CC) $(CFLAGS) -c -I thirdparty -I src test/main.cpp -o build/test/main.o -lm
build/test/text.o: src/text.cpp
	$(CC) $(CFLAGS) -c -I thirdparty -I src src/text.cpp -o build/test/text.o -lm        
