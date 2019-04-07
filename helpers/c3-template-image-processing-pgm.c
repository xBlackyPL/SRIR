/* @Dyzio 19-03-2019

NOTE: 
compile:
	mpicc testImage.c -lnetpbm

man: 
	https://linux.die.net/man/3/libpgm 

more:
	display image: eog/display (with ssh -Y flag)
	https://www.tutorialspoint.com/dip/laplacian_operator.htm
*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <string.h>
#include <netpbm/pgm.h> 

void laplace(gray** img, int cols, int rows, int maxval);

int main(int argc, char *argv[]) {

	gray **image;
	FILE *fp;
	FILE *fp_res;
	int cols; 
	int rows; 
	int maxval;

    /* ========== */    
	/* READ PGM  IMAGE */
	pgm_init(&argc, argv);
	fp = fopen("./dataset/foto01.pgm","r");
	if(fp != NULL) {
		image = pgm_readpgm( fp, &cols, &rows, &maxval);
	}

    /* ========== */    
    /* OPERATIONS */

	laplace(image,cols, rows, maxval);
  
    /* ========== */    
    /* WRITE PGM IMAGE */
	fp_res = fopen("./result/foto01.pgm","wb");
    pgm_writepgm( fp_res, image, cols, rows, maxval,1); 

    /* ========== */    

	printf("# Image: \n\tSize: %d x %d \n\tMaxval: %d \n",cols, rows, maxval);

    /* ========== */
	/* CLEAN */    
   
	fclose(fp);

	return 0;
}

// TODO:
// 	- getNeighbor - (sprawdza sasiada i sprawdza czy nie wychodzi poza tablice)
//	- Normalization
//  - Laplace


/* @Return: image with image border (kontury) */
void laplace(gray** img, int cols, int rows, int maxval){

/* 
mask:
	[0	1	0]
	[1  -4	1]
	[0	1	0]
*/
printf("\n::Laplace::\n");

	int i = 0; 
	int j = 0;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			//img[i][j] = 255 - img[i][j];
			/* ... operatons */
		}
	}
	

}





