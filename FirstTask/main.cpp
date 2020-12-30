#include <iostream>
#include <vector>
#include <mpi.h>
#include <random>

std::map<int, int> send_to = {{1,0}, {2,1}, {3,2},{4,0}, {5,1}, {6,2},
                              {7, 6}, {8, 4}, {9,5}, {10, 9}, {11, 10},
                              {12, 8}, {13, 12}, {14,13}, {15, 14}};

std::map<int, int> get_from = {{4, 8}, {5, 9}, {6,7}, {8, 12}, {9, 10}, {10,11},
                               {12, 13}, {13, 14}, {14,15}};

std::map<int, int> resieve_amount = {{3, 0}, {4,5}, {5, 3}, {6,1}, {7, 0}, {8, 4},
                                     {9,2}, {10, 1}, {11, 0}, {12, 3}, {13,2},
                                     {14,1}, {15,0}};

static void send_resieve (int rank, std::vector<int> some_data = {})
{


    int resv_amount;
    std::vector <int> data_array;
    std::vector <int> result = some_data;
    int vec_size;
    MPI_Status status;

    if (rank == 1) {

        for (size_t i=0; i<4; i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, 5, 5 * 10 + 5, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, 5, 5, MPI_COMM_WORLD, &status);
            result.insert(result.end(), data_array.begin(), data_array.end());
            data_array.clear();
        }
        MPI_Recv(&vec_size, 1, MPI_INT, 2, 2 * 10 + 2, MPI_COMM_WORLD, &status);
        data_array.resize(vec_size);
        MPI_Recv(&data_array[0], vec_size, MPI_INT, 2, 2, MPI_COMM_WORLD, &status);
        result.insert(result.end(), data_array.begin(), data_array.end());

        vec_size = result.size();
        MPI_Send(&vec_size, 1, MPI_INT, 0, 1 * 10 + 1, MPI_COMM_WORLD);
        MPI_Send(result.data(), vec_size, MPI_INT, 0, 1, MPI_COMM_WORLD);
        data_array.clear();
        result.clear();

    } if (rank == 2) {
        for (size_t i=0; i<2; i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, 6, 6 * 10 + 6, MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, 6, 6, MPI_COMM_WORLD, &status);
            result.insert(result.end(), data_array.begin(), data_array.end());
            data_array.clear();
        }
        MPI_Recv(&vec_size, 1, MPI_INT, 3, 3 * 10 + 3, MPI_COMM_WORLD, &status);
        data_array.resize(vec_size);
        MPI_Recv(&data_array[0], vec_size, MPI_INT, 3, 3, MPI_COMM_WORLD, &status);
        result.insert(result.end(), data_array.begin(), data_array.end());


        vec_size = result.size();
        MPI_Send(&vec_size, 1, MPI_INT, 1, 2 * 10 + 2, MPI_COMM_WORLD);
        MPI_Send(result.data(), vec_size, MPI_INT, 1, 2, MPI_COMM_WORLD);
        data_array.clear();
        result.clear();
    } else {
        resv_amount = resieve_amount[rank];
        for (size_t i=0; i< resv_amount; i++) {
            MPI_Recv(&vec_size, 1, MPI_INT, get_from[rank], get_from[rank] * 10 + get_from[rank], MPI_COMM_WORLD, &status);
            data_array.resize(vec_size);
            MPI_Recv(&data_array[0], vec_size, MPI_INT, get_from[rank], get_from[rank], MPI_COMM_WORLD, &status);

            MPI_Send(&vec_size, 1, MPI_INT, send_to[rank], rank * 10 + rank, MPI_COMM_WORLD);
            MPI_Send(data_array.data(), vec_size, MPI_INT, send_to[rank], rank, MPI_COMM_WORLD);
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


    if (rank != 0) {
        for (size_t i = 0; i < rank; i++) {
            data_array[i] = rank;
        }


        vec_size = data_array.size();
        if (rank != 1 and rank != 2) {
            MPI_Send(&vec_size, 1, MPI_INT, send_to[rank], rank * 10 + rank, MPI_COMM_WORLD);
            MPI_Send(data_array.data(), vec_size, MPI_INT, send_to[rank], rank, MPI_COMM_WORLD);
        }
        send_resieve(rank);

    } else {
        std::vector <std::vector <int>> result_data;
        MPI_Recv(&vec_size, 1, MPI_INT, 1, 11, MPI_COMM_WORLD, &status);
        data_array.resize(vec_size);
        MPI_Recv(&data_array[0], vec_size, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
        result_data.emplace_back(data_array);
        printf("Get data with %d\n", data_array[0]);
        data_array.clear();

        for (size_t i = 0; i < 6; i++) {
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