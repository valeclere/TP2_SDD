CC = gcc
flags = -Wall -Wextra -pedantic

exe : main.o pile.o
	${CC} -o exe main.o pile.o ${flags}

main.o : main.c pile.h pile.c
	${CC} -g -c main.c pile.c ${flags}

pile.o : pile.c pile.h
	${CC} -g -c pile.c ${flags}

clean :
	rm *.o exe
