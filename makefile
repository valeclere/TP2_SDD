CC = gcc
flags = -Wall -Wextra -pedantic

exe : main.o pile.o file.o truc.o
	${CC} -o exe main.o pile.o file.o truc.o ${flags}

main.o : main.c pile.h pile.c file.c file.h truc.c truc.h
	${CC} -g -c main.c pile.c file.c truc.c ${flags}

pile.o : pile.c pile.h
	${CC} -g -c pile.c ${flags}
	
file.o : file.c file.h
	${CC} -g -c file.c ${flags}

truc.o : truc.c truc.h
	${CC} -g -c truc.c ${flags}

clean :
	rm *.o exe
