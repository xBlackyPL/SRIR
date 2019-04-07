#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <string.h>

// #define RANGE 100
// #define RANGE 1000
// #define RANGE 10000
// #define RANGE 100000
#define RANGE 100


int main(int argc, char **argv) {
	int currentProcessRank = 0;
	int numberOfProcesses = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &currentProcessRank);
	MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcesses);
    // double procTime;
	
	if (currentProcessRank != 0) {
		// procTime = MPI_Wtime();
		float *msg = malloc(RANGE * sizeof(float));
		MPI_Bcast(msg, RANGE, MPI_FLOAT, 0, MPI_COMM_WORLD);

		int i;
		for( i = 0; i < RANGE; i++){ 
			msg[i] = 2.0; 
		}	

		free(msg);

	} else {
		
	  	double timeChild = MPI_Wtime();
		float *msg = malloc(RANGE * sizeof(float));
		MPI_Bcast(msg, RANGE, MPI_FLOAT, 0, MPI_COMM_WORLD);
		
		free(msg);
	}

	MPI_Barrier(MPI_COMM_WORLD);

    // if (currentProcessRank != 0) {
    //     printf("Time: %f",currentProcessRank,(MPI_Wtime() - procTime));		
    // } 

	MPI_Finalize();

	printf("Finish with success\n");
    return 0;
}