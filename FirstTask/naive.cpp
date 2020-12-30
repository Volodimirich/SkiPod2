#include <iostream>
#include <vector>
#include <mpi.h>
#include <random>

int get_resieve_amount(int rank)
{
    switch (rank%4) {
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
        case 0:
            switch (rank) {
                case 4:
                    return 11;
                case 8:
                    return 7;
                case 12:
                    return 3;
                case 0:
                    return 0;
                default:
                    throw;
            }
    }
    throw;
}

int get_send(int rank)
{
    if (rank%4)
        return rank-1;
    else
        return rank-4;
}

static void send_resieve (int rank)
{
    std::map<int, int> path_to = {{1,0}, {2,1}, {3,2},{4,0}, {5,1}, {6,2},
                                  {7, 6}, {8, 4}, {9,5}, {10, 9}, {11, 10},
                                  {12, 8}, {13, 12}, {14,13}, {15, 14}};
    int resv_amount = get_resieve_amount(rank);
    std::vector <int> data_array;
    int vec_size, send_to;
    MPI_Status status;


    if (rank%4 or rank==12) {
        for (size_t i = 0; i < resv_amount; i++) {
            send_to = rank==12 ? 8: rank-1;
            MPI_Recv(&vec_size, 1, MPI_INT, rank + 1, (rank + 1) * 10 + rank + 1, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, rank + 1, rank+1, MPI_COMM_WORLD, &status);

            MPI_Send(&vec_size, 1, MPI_INT, send_to, rank * 10 + rank, MPI_COMM_WORLD);
            MPI_Send(data_array.data(), vec_size, MPI_INT, send_to, rank, MPI_COMM_WORLD);
            data_array.clear();
        }
    } else {
        std::vector<int> sec_array;

        for (size_t i=0; i< 3; i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, rank + 1, (rank + 1) * 10 + rank + 1, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, rank + 1, rank + 1, MPI_COMM_WORLD, &status);

            MPI_Send(&vec_size, 1, MPI_INT, rank - 4, rank * 10 + rank, MPI_COMM_WORLD);
            MPI_Send(data_array.data(), vec_size, MPI_INT, rank - 4 , rank, MPI_COMM_WORLD);
            data_array.clear();

        }
        for (size_t i = 0; i < (rank==4 ? 8: 4); i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, rank + 4, (rank + 4) * 10 + rank + 4, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, rank + 4, rank+4, MPI_COMM_WORLD, &status);

            MPI_Send(&vec_size, 1, MPI_INT, rank - 4, rank * 10 + rank, MPI_COMM_WORLD);
            MPI_Send(data_array.data(), vec_size, MPI_INT, rank-4, rank, MPI_COMM_WORLD);
            data_array.clear();

        }
    }
}


int main (int argc, char* argv[])
{
    int rank, size;
    int resv_amount;

    MPI_Init (&argc, &argv);      /* starts MPI */
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);        /* get current process id */
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    MPI_Status status;
    std::vector<int> data_array(rank);
    int vec_size;
    int send_to;
    resv_amount = get_resieve_amount(rank);


    if (rank != 0) {
        for (size_t i=0; i<rank; i++) {
            data_array[i] = rank;
        }

        send_to = rank%4 ? rank-1 : rank-4;
        vec_size = data_array.size();
        MPI_Send(&vec_size,  1, MPI_INT, send_to, rank*10 + rank, MPI_COMM_WORLD);
        MPI_Send(data_array.data(), vec_size, MPI_INT, send_to, rank, MPI_COMM_WORLD);
        send_resieve(rank);

    } else {
        std::vector <std::vector <int>> result_data;
        for (size_t i=0; i< 3; i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, 1, 11, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
            result_data.emplace_back(data_array);
            printf("Get data with %d\n", data_array[0]);
            data_array.clear();
        }
        for (size_t i = 0; i < 12; i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, 4, 44, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, 4, 4, MPI_COMM_WORLD, &status);
            result_data.emplace_back(data_array);
            printf("Get data with %d\n", data_array[0]);
            data_array.clear();


        }
    }


    /* get number of processes */
    MPI_Finalize();
    return 0;
}