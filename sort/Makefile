CFLAGS=-I/opt/local/include/ -g -Wall
LDFLAGS=-lgmp -L/opt/local/lib

all: sort generate

clean:
	-rm *.o
	-rm sort

assert.o : assert.h assert.c
	gcc ${CFLAGS} -c assert.c

data.o : data.h data.c assert.h
	gcc ${CFLAGS} -c data.c

utils.o : utils.h utils.c assert.h data.h
	gcc ${CFLAGS} -c utils.c

sorting.o: assert.o data.o utils.o sorting.c sorting.h
	gcc ${CFLAGS} -c sorting.c

sort: sort.c assert.o data.o utils.o sorting.o
	gcc ${CFLAGS} ${LDFLAGS} sort.c -o sort data.o assert.o utils.o sorting.o

generate: generate.c assert.o data.o utils.o sorting.o
	gcc ${CFLAGS} ${LDFLAGS} generate.c -o generate data.o assert.o utils.o sorting.o