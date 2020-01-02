#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define RANGE 100
// #define RANGE 1000
// #define RANGE 10000
// #define RANGE 100000
#define RANGE 1000000

enum MessageType { COMMUNICATION_TYPE = 1 };

void child(int currentProcessRank) {
  double startTime = MPI_Wtime();

  MPI_Status status;
  int sourceProcessRank = 0;
  int destinationProcessRank = 0;

  float *message = (float *)calloc(RANGE, sizeof(float));
  int i = 0;
  for (; i < RANGE; ++i) {
    message[i] = currentProcessRank;
  }

  MPI_Send(message, RANGE, MPI_FLOAT, destinationProcessRank,
           COMMUNICATION_TYPE, MPI_COMM_WORLD);

  MPI_Recv(message, RANGE, MPI_FLOAT, sourceProcessRank, COMMUNICATION_TYPE,
           MPI_COMM_WORLD, &status);

  printf("[Child #%d]: Message from process of rank: %f \n", currentProcessRank,
         message[0]);

  free(message);

  printf("[Child #%d]: Communication time %lf\n", currentProcessRank,
         MPI_Wtime() - startTime);
}

void parent(int numberOfProcesses) {
  MPI_Status status;
  int currentProcessRank = 0;

  int sourceProcessRank = 1;
  int destinationProcessRank = 1;

  float *message = (float *)calloc(RANGE, sizeof(float));

  for (; sourceProcessRank < numberOfProcesses;
       ++sourceProcessRank, ++destinationProcessRank) {
    MPI_Recv(message, RANGE, MPI_FLOAT, sourceProcessRank, COMMUNICATION_TYPE,
             MPI_COMM_WORLD, &status);

    printf("[Parent]: Message from process of rank: %f \n", message[0]);

    int i;
    for (i = 0; i < RANGE; ++i) {
      message[i] = currentProcessRank;
    }

    MPI_Send(message, RANGE, MPI_FLOAT, destinationProcessRank,
             COMMUNICATION_TYPE, MPI_COMM_WORLD);
  }
  free(message);
}

main(int argc, char **argv) {
  int currentProcessRank = 0;
  int numberOfProcesses = 0;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &currentProcessRank);
  MPI_Comm_size(MPI_COMM_WORLD, &numberOfProcesses);

  if (currentProcessRank != 0) {
    child(currentProcessRank);
  } else {
    parent(numberOfProcesses);
  }

  MPI_Finalize();
}
