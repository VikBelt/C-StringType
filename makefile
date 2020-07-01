CC = gcc
CFLAGS = -I.
DEPS = stringtype.h
OBJ = stringtype.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stringtype: stringtype.c main.c
	  $(CC) -o $@ $^ $(CFLAGS)
