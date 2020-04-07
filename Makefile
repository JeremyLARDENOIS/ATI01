CC = gcc
CFLAGS = -Wall
LDFLAGS = 

all: matrices factoriel polynomes resolv

clean:
	rm *.o &2>/dev/null
	rm *~ &2>/dev/null
	rm matrices &2>/dev/null
	rm factoriel &2>/dev/null
	rm polynomes &2>/dev/null

matrices: matrices.o
	$(CC) -o $@ $^ $(LDFLAGS)

factoriel: factoriel.o
	$(CC) -o $@ $^ $(LDFLAGS)

polynomes: polynomes.o
	$(CC) -o $@ $^ $(LDFLAGS)

resolv: resolv.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $<  $(CFLAGS)


