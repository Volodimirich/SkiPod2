#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <mpi.h>
#include "mpi-ext.h"

void prt1a(char *t1, double *v, int n, char *t2);

void print_matrix(double *a);

int N;
double *A;
#define A(i, j) A[(i) * (N + 1) + (j)]
double *X;
int proc_num, myrank;


static void verbose_errhandler(MPI_Comm* pcomm, int* perr, ...)
{
    MPI_Comm comm = *pcomm;
    int err = *perr;
    char errstr[MPI_MAX_ERROR_STRING];
    int i, rank, size, nf, len, eclass;
    MPI_Group group_c, group_f;
    int *ranks_gc, *ranks_gf;

    MPI_Error_class(err, &eclass);
    if( MPIX_ERR_PROC_FAILED != eclass ) {
        MPI_Abort(comm, err);
    }

    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &size);

    MPIX_Comm_failure_ack(comm);
    MPIX_Comm_failure_get_acked(comm, &group_f);
    MPI_Group_size(group_f, &nf);
    MPI_Error_string(err, errstr, &len);
    printf("Rank %d / %d: Notified of error %s. %d found dead: { ",
           rank, size, errstr, nf);

    ranks_gf = (int*)malloc(nf * sizeof(int));
    ranks_gc = (int*)malloc(nf * sizeof(int));
    MPI_Comm_group(comm, &group_c);
    for(i = 0; i < nf; i++)
        ranks_gf[i] = i;
    MPI_Group_translate_ranks(group_f, nf, ranks_gf,
                              group_c, ranks_gc);
    for(i = 0; i < nf; i++)
        printf("%d ", ranks_gc[i]);
    printf("}\n");

}

static void data_save()
{
    if (myrank == 0) {
        FILE* f = fopen("before_bcast.txt", "w");
        fwrite(&A[0], sizeof(double), 1, f);
        fclose(f);
    }
//    MPI_Barrier(MPI_COMM_WORLD);
}

static void data_load()
{
    FILE* f = fopen("before_bcast", "r");
    fread(&A(0,0), sizeof(double), (N-1)*N, f);
    fclose(f);
    MPI_Barrier(MPI_COMM_WORLD);
}


int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    MPI_Errhandler errh;
    MPI_Comm_create_errhandler(verbose_errhandler, &errh);
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, errh);

//    MPI_Barrier(MPI_COMM_WORLD);
//    if (myrank == 0)
//        throw;

    int i, j, k;
    N = atoi(argv[1]);

    /* create arrays */
    A = (double *)malloc(N * (N + 1) * sizeof(double));
    X = (double *)malloc(N * sizeof(double));
    if (myrank == 0) printf("GAUSS %dx%d\n----------------------------------\n", N, N);
    srand(12345);
    /* initialize array A*/
    for (i = 0; i <= N - 1; i++)
        for (j = 0; j <= N; j++)
            if (i == j || j == N)
                A(i, j) = 1.f;
            else
                A(i, j) = 0.f;

    double time0 = MPI_Wtime();
    /* elimination */

    data_save();
//    data_load();

    for (i = 0; i < N - 1; i++)
    {
        MPI_Bcast(&A(i, i + 1), N - i, MPI_DOUBLE, i % proc_num, MPI_COMM_WORLD);
        for (k = myrank; k <= N - 1; k += proc_num) {
            if (k < i + 1) {
                continue;
            }
            for (j = i + 1; j <= N; j++) {
                A(k, j) = A(k, j) - A(k, i) * A(i, j) / A(i, i);
            }
        }
    }
    /* reverse substitution */
    X[N - 1] = A(N - 1, N) / A(N - 1, N - 1);
    for (j = N - 2; j >= 0; j--)
    {
        for (k = myrank; k <= j; k += proc_num)
            A(k, N) = A(k, N) - A(k, j + 1) * X[j + 1];
        MPI_Bcast(&A(j, N), 1, MPI_DOUBLE, j % proc_num, MPI_COMM_WORLD);
        X[j] = A(j, N) / A(j, j);
    }
    double time1 = MPI_Wtime();

    if (myrank == 0) {
        printf("Time in seconds=%gs\n", time1 - time0);
        prt1a("X=(", X, N > 9 ? 9 : N, "...)\n");
    }
    free(A);
    free(X);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}

void prt1a(char *t1, double *v, int n, char *t2)
{
    int j;
    printf("%s", t1);
    for (j = 0; j < n; j++)
        printf("%.4g%s", v[j], j % 10 == 9 ? "\n" : ", ");
    printf("%s", t2);
}

void print_matrix(double* a) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++)
            printf("%lf ", A(i, j));
        printf("\n");
    }
    printf("\n");
}


