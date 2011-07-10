CFLAGS=-I/opt/local/include/ -g -Wall
#Uncomment this line to enable debugging
#You need to make clean after reconfiguring
#CFLAGS=-I/opt/local/include/ -g -Wall -DDEBUG
LDFLAGS=-lgmp -L/opt/local/lib
CC=gcc

all: sort generate

clean:
	-rm *.o
	-rm sort
	-rm generate
	-rm -r sort.dSYM
	-rm -r generate.dSYM

assert.o : assert.h assert.c
	${CC} ${CFLAGS} -c assert.c

data.o : data.h data.c assert.h
	${CC} ${CFLAGS} -c data.c

utils.o : utils.h utils.c assert.h data.h
	${CC} ${CFLAGS} -c utils.c

algorithms.o: assert.h data.h utils.h algorithms.c algorithms.h
	${CC} ${CFLAGS} -c algorithms.c

merge.o: assert.h data.h utils.h  algorithms.h merge.h merge.c
	${CC} ${CFLAGS} -c merge.c

sort: sort.c assert.o data.o utils.o algorithms.o merge.o
	${CC} ${CFLAGS} ${LDFLAGS} sort.c data.o assert.o utils.o merge.o algorithms.o -o sort

generate: generate.c assert.o data.o utils.o
	${CC} ${CFLAGS} ${LDFLAGS} generate.c data.o assert.o utils.o -o generate 