CFLAGS=-I/opt/local/include/ -g
LDFLAGS=-lgmp -L/opt/local/lib

all: main

clean:
	-rm *.o
	-rm st

assert.o : assert.h assert.c
	gcc ${CFLAGS} -c assert.c

data.o : data.h data.c assert.h
	gcc ${CFLAGS} -c data.c

utils.o : utils.h utils.c assert.h data.h
	gcc ${CFLAGS} -c utils.c

sorting.o: assert.o data.o utils.o sorting.c sorting.h
	gcc ${CFLAGS} -c sorting.c

main: assert.o data.o utils.o sorting.o
	gcc ${CFLAGS} ${LDFLAGS} main.c -o st data.o assert.o utils.o sorting.o
