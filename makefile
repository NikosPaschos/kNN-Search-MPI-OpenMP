CC = mpicc

all:
	$(CC) read_data.c main.c -O3 -fopenmp -o main