CC = gcc
OBJS = general.o colorGame.o maxSumMatrix.o main.o 
EXEC = hw1
DEBUG = -g
CFLAGS = -std=c99 -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

general.o: general.c general.h
colorGame.o: colorGame.c colorGame.h general.h
maxSumMatrix.o: maxSumMatrix.c maxSumMatrix.h general.h
main.o: main.c maxSumMatrix.h colorGame.h


clean:
	rm -f $(EXEC) $(OBJS)
