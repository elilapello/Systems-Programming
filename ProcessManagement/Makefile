CC = gcc
CFLAGS = -Wall -g

all: Coordinator Checker

Coordinator: Coordinator.c
	$(CC) $(CFLAGS) Coordinator.c -o coordinator

Checker: Checker.c
	$(CC) $(CFLAGS) Checker.c -o checker

clean:
	@rm -f coordinator checker

zip:
	zip Eli-Lapello-HW2.zip Coordinator.c Checker.c Makefile README.txt

	

