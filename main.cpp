#include <iostream>
#include <chrono>
#include <mpi.h>
#include <stdio.h>
#include <string>
#include <fstream>


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    double all_time = 0.0;
    double startwtime = 0.0, endwtime;
    MPI_Init(&argc, &argv);
    int my_rank, proc_num;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int dimension = 0, n = 0, N = 0;
    int* x = nullptr, * y = nullptr, * matrix_result = nullptr, * y_transponse = nullptr;
    if (my_rank == 0)
    {
        std::ifstream A;
        std::ifstream B;
        A.open("F:\\University\\ѕѕ\\MPI\\MPI\\A.txt");
        B.open("F:\\University\\ѕѕ\\MPI\\MPI\\B.txt");
        if (!(A.good()) && !(B.good())) {
            std::cout << "File not found!\n";
            return -1;
        }
        int count = 0;
        int temp;
        while (!A.eof()) {
            A >> temp;
            count++;
        }
        //std::cout << "count: " << count << "\n";
        A.clear();
        A.seekg(0, std::ios::beg);
        N = count - 1;
        n = sqrt(count);
        x = new int[N];
        y = new int[N];
        for (int i = 0; i < N; ++i) {
            A >> x[i];
            B >> y[i];
        }
        A.close();
        B.close();
        y_transponse = new int[N];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                y_transponse[i * n + j] = y[j * n + i];
            }
        }
        delete[] y;
        y = nullptr;
       /* for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << x[i * n + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << y_transponse[i * n + j] << " ";
            }
            std::cout << std::endl;
        }*/
        startwtime = MPI_Wtime();
        matrix_result = new int[N];
        dimension = n;
    }
        MPI_Bcast(&dimension, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if (my_rank)
        {
            y_transponse = new int[dimension * dimension];
        }
        int local_size = dimension / proc_num;
        int* local_a_part = new int[local_size * dimension];
        int* local_result = new int[local_size * dimension];
        MPI_Scatter(x + my_rank * dimension * local_size, dimension * local_size, MPI_INT, local_a_part, dimension * local_size, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Bcast(y_transponse, dimension * dimension, MPI_INT, 0, MPI_COMM_WORLD);
        for (int i = 0; i < local_size; ++i)
        {
            for (int j = 0; j < dimension; ++j)
            {
                local_result[i * dimension + j] = 0;
                for (int k = 0; k < dimension; ++k)
                {
                    local_result[i * dimension + j] += local_a_part[i * dimension + k] * y_transponse[j * dimension + k];
                }
            }
        }
        MPI_Gather(local_result, local_size * dimension, MPI_INT, matrix_result, dimension * local_size, MPI_INT, 0, MPI_COMM_WORLD);
        endwtime = MPI_Wtime();
        if (my_rank)
        {
            delete[] y_transponse;
            delete[] local_result;
            delete[] local_a_part;
        }
        MPI_Finalize();
        delete[] x;
        delete[] y_transponse;
        std::ofstream C;
        C.open("F:\\University\\ѕѕ\\MPI\\MPI\\C.txt");
        if (C.good()) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    C << matrix_result[i * n + j] << '\t';
                }
                C << '\n';
            }
            C << '\n' << "Time: " << (endwtime - startwtime) << "; Task scope: matrix " << n << "x" << n << ".";
            C.close();
        }
        delete[] matrix_result;
        std::cout << "Operation successfully completed" << std::endl;
        std::cout << "N: " << dimension << std::endl;
        std::cout << "Number of Processes: " << proc_num << std::endl;
        std::cout << "Time in seconds: " << (endwtime - startwtime) << std::endl;
        return 0;
}
