#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double* read_data(){

	FILE *fileptr;
	double *buffer;
	long filelen;

	fileptr = fopen("train_x2.bin","rb");
	fseek(fileptr, 0, SEEK_END);
	filelen = ftell(fileptr);
	rewind(fileptr);

	buffer = (double*)malloc((filelen+1)*sizeof(double));
	size_t res = fread(buffer, filelen, 1, fileptr);
	fclose(fileptr);

	return buffer;
}

double* read_data_custom(int begin, int end){

	const int DIM = 30;
	FILE *fileptr;
	double *buffer;
	long filelen,file_begin,file_end;

	fileptr = fopen("train_x2.bin","rb");
	fseek(fileptr, DIM*end*sizeof(double), SEEK_SET);
	file_end = ftell(fileptr);
	fseek(fileptr, DIM*begin*sizeof(double), SEEK_SET);
	file_begin = ftell(fileptr);
	filelen = file_end - file_begin;
	fseek(fileptr, DIM*begin*sizeof(double), SEEK_SET);

	buffer = (double*)malloc((filelen+1)*sizeof(double));
	size_t res = fread(buffer, filelen, 1, fileptr);
	fclose(fileptr);

	return buffer;
}

double* read_labels(){
	FILE *fileptr;
	double *buffer;
	long filelen;

	fileptr = fopen("train_l.bin","rb");
	fseek(fileptr, 0, SEEK_END);
	filelen = ftell(fileptr);
	rewind(fileptr);

	buffer = (double*)malloc((filelen+1)*sizeof(double));
	size_t res = fread(buffer, filelen, 1, fileptr);
	fclose(fileptr);

	return buffer;
}
