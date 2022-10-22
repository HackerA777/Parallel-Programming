#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


void T(int **y, const int n){
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            std::swap(y[i][j], y[j][i]);
        }
    }
}

int main(){
    std::ifstream A;
    std::ifstream B;
    A.open("/Users/artemt/Documents/Labs/PP/A.txt");
    B.open("/Users/artemt/Documents/Labs/PP/B.txt");
    if (!(A.good()) && !(B.good())){
        std::cout << "File not found!\n";
        return -1;
    }
    else{
        double t1, t2;
        int count = 0;
        int temp, i, j, k;
        while(!A.eof()){
            A >> temp;
            count ++;
        }
        std::cout << "count: " << count << "\n";
        A.clear();
        A.seekg(0, std::ios::beg);
        int n = sqrt(count);
        int **x, **y, **c;
        x = new int* [n];
        y = new int* [n];
        c = new int* [n];
        for (int i = 0; i < n; ++i){
            x[i] = new int [n];
            y[i] = new int [n];
            c[i] = new int [n];
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                A >> x[i][j];
                B >> y[i][j];
            }
        }
        A.close();
        B.close();
        t1 = omp_get_wtime();
        T(y, n);
#pragma omp parallel for shared(x, y, c) private(i, j, k)
        for (i = 0; i < n; ++i){
            for (j = 0; j < n; ++j){
                c[i][j] = 0;
                for (k = 0; k < n; ++k){
                    c[i][j] += x[i][k] * y[j][k];
                }
            }
        }
        t2 = omp_get_wtime();
        std::cout << "Time: " << t2-t1 << "\n";
        for (int i = 0; i < n; ++i){
            delete [] x[i];
            delete [] y[i];
        }
        delete[] x;
        delete [] y;
        std::ofstream C;
        C.open("/Users/artemt/Documents/Labs/PP/C.txt");
        if(C.good()){
            for(int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    C << c[i][j] << '\t';
                }
                C << '\n';
            }
            C << '\n' << "Time: " << t2-t1 << "; Task scope: matrix " << n << "x" << n << ".";
            C.close();
            for (int i = 0; i < n; ++i){
                delete [] c[i];
            }
            delete [] c;
        }
        else
        {
            std::cout << "Open C.txt error";
            return -2;
        }
        return 0;
    }
}
