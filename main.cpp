#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>


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
        int count = 0;
        int temp;
        while(!A.eof()){
            A >> temp;
//            std::cout << temp << "\n";
//            std::cout << A.tellg() << "\n";
            count ++;
        }
        std::cout << "count: " << count << "\n";
        //std::cout << A.tellg() << "\n";
//        A.clear();
//        A.seekg(0, std::ios::beg);
//        int count_space = 0;
//        char symbol;
//        while(!A.eof()){
//            A.get(symbol);
//            if (symbol == ' ')
//                count_space ++;
//            if (symbol == '\n')
//                break;
//        }
//        A.close();
//        A.open("/Users/artemt/Documents/Labs/PP/A.txt");
        A.clear();
        A.seekg(0, std::ios::beg);
        int n = sqrt(count);
//        int m = count_space + 1;
        double **x, **y, **c;
        x = new double* [n];
        y = new double* [n];
        c = new double* [n];
        for (int i = 0; i < n; ++i){
            x[i] = new double [n];
            y[i] = new double [n];
            c[i] = new double [n];
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                A >> x[i][j];
                B >> y[i][j];
            }
        }
        A.close();
        B.close();
        std::cout << "Matrix A: \n" << x[0][0] << "\n";
//        for (int i = 0; i < n; ++i){
//            for (int j = 0; j < m; ++j){
//                std::cout << x[i][j] << "\t";
//            }
//            std::cout << "\n";
//        }
        std::cout << "Matrix B: \n" << y[0][0] << "\n";
//        for (int i = 0; i < n; ++i){
//            for (int j = 0; j < m; ++j){
//                std::cout << y[i][j] << "\t";
//            }
//            std::cout << "\n";
//        }
        clock_t begin = clock();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                c[i][j] = 0;
                for (int k = 0; k < n; ++k){
                    c[i][j] += x[i][k] * y[k][j];
                }
            }
        }
        clock_t end = clock();
        double time_work = (end - begin)/((double)CLOCKS_PER_SEC);
        std::cout << "Matrix C: \n" << c[n-1][n-1] << "\n";
        std::cout << "Time: " << time_work;
//        for (int i = 0; i < n; ++i){
//            for (int j = 0; j < m; ++j){
//                std::cout << c[i][j] << "\t";
//            }
//            std::cout << "\n";
//        }
        for (int i = 0; i < n; ++i){
            delete [] x[i];
            delete [] y[i];
        }
        delete[] x;
        delete [] y;
        std::ofstream C;
        C.open("/Users/artemt/Documents/Labs/PP/C.txt");
        if(C.good()){
            C << "Result Matrix: \n";
            for(int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    //C.write((char*)&C[i][j], sizeof(int));
                    C << c[i][j] << '\t';
                }
                //C.write((char*)&tmp[0], sizeof(char));
                C << '\n';
            }
            //C.write((char*)&tmp[0], sizeof(char));
            C << '\n' << "Time: " << time_work;
            //C.write((char*)&time_spent, sizeof(time_spent));
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
