.PHONY:all clean
CC = g++
CFLAGS = -Wall -Werror
SD = src/
OD = build/
EXECUTABLE = bin/circle

all: build/ bin/ $(EXECUTABLE)
$(EXECUTABLE):	$(OD)main.o $(OD)text.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OD)main.o $(OD)text.o
$(OD)main.o: $(SD)main.c
	$(CC) $(CFLAGS) -c -o $(OD)main.o $(SD)main.c
$(OD)text.o: $(SD)text.c
	$(CC) $(CFLAGS) -c -o $(OD)text.o $(SD)text.c
clean:
	rm -rf $(EXECUTABLE) $(OD)*.o        
