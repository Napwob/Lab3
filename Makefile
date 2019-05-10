.PHONY:all clean
CC = g++
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/result.exe

all: build/ bin/ $(EXECUTABLE)
build/:
	mkdir build/ -p
bin/:
	mkdir bin/ -p        
$(EXECUTABLE):	$(OD)main.o $(OD)func.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)func.o
$(OD)main.o: $(SD)main.c
	$(CC) $(CFLAGS) -c -o $(OD)main.o $(SD)main.c
$(OD)func.o: $(SD)func.c
	$(CC) $(CFLAGS) -c -o $(OD)func.o $(SD)func.c
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o        
