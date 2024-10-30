#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Change the check to allow for fewer processes
    if (world_size < 4) {
        if (world_rank == 0) {
            printf("Warning: This program is designed for 10 processes, but %d were provided.\n", world_size);
        }
    } 
    printf("Hello World from process %d out of %d!\n", world_rank, world_size);

    MPI_Finalize();
    return 0;
}
