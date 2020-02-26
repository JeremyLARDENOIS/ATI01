CC = gcc
CFLAGS = -Wall
LDFLAGS = 

all: matrices

clean:
	rm *.o
	rm matrices

matrices: matrices.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.c
	$(CC) -c $<  $(CFLAGS)


