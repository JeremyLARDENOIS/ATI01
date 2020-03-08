CC = gcc
CFLAGS = -Wall
LDFLAGS = 

all: matrices

clean:
	rm *.o
	rm matrices
	rm *~


matrices: matrices.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.c
	$(CC) -c $<  $(CFLAGS)


