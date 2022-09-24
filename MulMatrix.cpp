//#include <iostream>
//#include <time.h>
//#include <fstream>
//#include <stdlib.h>
//
//
////int main() {
////    clock_t begin = clock();
////    char tmp[N] = {};
////    int A [N][N] = {};
////    int B [N][N] = {};
////    int C [N][N] = {};
////    std::ifstream A;
////    A.open("/Users/artemt/Documents/Labs/PP/A.txt");
////    if (!(A.is_open())){
////        std::cout << "File not found!\n exit";
////        //std::cin.get();
////        return -1;
////    }
////    else{
////        std::cout << "Process began!\n";
////        for(int i = 0; i < N; i++){
////            A.getline(tmp, N+1);
////            for (int j = 0; j < N; ++j){
////                A[i][j] = (int)tmp[j] - 48;
////                std::cout << A[i][j] << "\t";
////            }
////            std::cout << "\n";
////        }
////        std::cout << "\n";
////        for(int i = 0; i < N; i++){
////            A.getline(tmp, N+1);
////            for (int j = 0; j < N; ++j){
////                B[i][j] = (int)tmp[j] - 48;
////                std::cout << B[i][j] << "\t";
////            }
////            std::cout << "\n";
////        }
////        std::cout << "Process finished!\n";
////    }
////    A.close();
////    for(int i = 0; i < N; ++i){
////        for (int j = 0; j < N; ++j){
////            C[i][j] = 0;
////            for (int k = 0; k < N; ++k){
////                C[i][j] += A[i][k] * B[k][j];
////            }
////        }
////    }
////    //std::cin.get();
//////    for (int i = 0; i < N/2 + 1; i++){
//////        for (j = 0; i < N/2 + 1; j++){
//////            C[i][j] =
//////        }
//////    }
////    for(int i = 0; i < N; ++i){
////        for (int j = 0; j < N; ++j){
////            std::cout << C[i][j] << "\t";
////        }
////        std::cout << "\n";
////    }
////    A.close();
////    clock_t end = clock();
////    double time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
////    std::cout << "\n" << time_spent << "\n";
////    std::ofstream C;
////    C.open("/Users/artemt/Documents/Labs/PP/C.txt");
////    if(C.good()){
////        C << "Result Matrix: \n";
////        tmp[0] = '\n';
////        tmp[1] = '\t';
////        for(int i = 0; i < N; ++i){
////            for (int j = 0; j < N; ++j){
////                //C.write((char*)&C[i][j], sizeof(int));
////                C << C[i][j] << tmp[1];
////            }
////            //C.write((char*)&tmp[0], sizeof(char));
////            C << tmp[0];
////        }
////        //C.write((char*)&tmp[0], sizeof(char));
////        C << tmp[0] << "Time: " << time_spent;
////        //C.write((char*)&time_spent, sizeof(time_spent));
////        C.close();
////    }
////    else
////        return -1;
////    return 0;
//////    int **A = (int**)malloc(N * sizeof(int*));
//////    int **B = (int**)malloc(N * sizeof(int*));
//////    int **C = (int**)malloc(N * sizeof(int*));
//////    for (int i = 0; i < N; i++)
//////    {
//////        A[i] = (int*)malloc(N * sizeof(int));
//////        B[i] = (int*)malloc(N * sizeof(int));
//////        C[i] = (int*)malloc(N * sizeof(int));
//////    }
//////    srand(time(NULL));
//////    for (int i = 0; i < N; i++)
//////        for (int j = 0; j < N; j++)
//////        {
//////            A[i][j] = rand() % 10;
//////            B[i][j] = rand() % 10;
//////        }
//////    for(int i = 0; i < N; i++)
//////        for(int j = 0; j < N; j++)
//////        {
//////            C[i][j] = 0;
//////            for(int k = 0; k < N; k++)
//////            C[i][j] += A[i][k] * B[k][j];
//////        }
//////    std::cout << "matrix A\n";
//////    for (int i = 0; i < N; i++)
//////    {
//////        for (int j = 0; j < N; j++)
//////            printf("%d ", A[i][j]);
//////        printf("\n");
//////    }
//////    std::cout << "\nmatrix B\n";
//////    for (int i = 0; i < N; i++)
//////    {
//////        for (int j = 0; j < N; j++)
//////            printf("%d ", B[i][j]);
//////        printf("\n");
//////    }
//////    std::cout << "\nthe result of multiplying\n";
//////    for (int i = 0; i < N; i++)
//////    {
//////        for (int j = 0; j < N; j++)
//////            printf("%3d ", C[i][j]);
//////        printf("\n");
//////    }
//////    for (int i = 0; i < N; i++)
//////    {
//////        free(A[i]);
//////        free(B[i]);
//////        free(C[i]);
//////    }
//////    free(A);
//////    free(B);
//////    free(C);
////}
