from time import perf_counter
import numpy as np
from tqdm import tqdm


def calculate(A, B, key):
    matrix = np.zeros((100, 100), dtype=int)
    if key == 1:
        for i in range(len(A)):
            for j in range(len(A[i])):
                for k in range(100):
                    matrix[i][j] += A[j][k]*B[k][j]
        return matrix
    elif key == 2:
        return np.dot(A, B)
    elif key == 3:
        return np.matmul(A, B)


def check():
    N = 1000
    matrix_A = []
    matrix_B = []
    with open("F:\\University\\ѕѕ\\MPI\\MPI\\A.txt") as A:
        for line in A:
            temp = line.split(' ')
        temp_m = []
        for i in range(N):
            for j in range(N*i, N*i+N, 1):
                temp_m.append(int(temp[j]))
            matrix_A.append(temp_m)
            temp_m = []
        A.close()
    with open("F:\\University\\ѕѕ\\MPI\\MPI\\B.txt") as B:
        for line in A:
            temp = line.split(' ')
        temp_m = []
        for i in range(N):
            for j in range(N*i, N*i+N, 1):
                temp_m.append(int(temp[j]))
            matrix_B.append(temp_m)
            temp_m = []
        B.close()
    start = perf_counter()
    matrix_C = calculate(matrix_A, matrix_B, 2)
    end = perf_counter()
    matrix_c = []
    with open("F:\\University\\ѕѕ\\MPI\\MPI\\C.txt") as c:
        for line in c:
            if len(line) != 1:
                matrix_c.append([int(c) for c in line.split()])
            else:
                break
        c.close()
    flag = True
    for i in range(len(matrix_C)):
        for j in range(len(matrix_C)):
            if matrix_C[i][j] != matrix_c[i][j]:
                flag = False
    with open("F:\\University\\ѕѕ\\MPI\\MPI\\result.txt", "w") as file:
        for i in tqdm(range(len(matrix_A)), desc="Loding: ", ascii=False, ncols=100):
            file.write(' '.join([str(a) for a in matrix_C[i]]) + '\n')
        if flag:
            file.write('\n' + "Time: " + str(end - start) + "; Task scope: matrix " + str(len(matrix_A)) + "x" +
                   str(len(matrix_B)) + ". Result successful!")
            print(f'Time: {end - start}; Task scope: matrix {len(matrix_A)}x{len(matrix_B)}. Result successful!')
        else:
            file.write('\n' + "Time: " + str(end - start) + "; Task scope: matrix " + str(len(matrix_A)) + "x" +
                       str(len(matrix_B)) + ". Result unsuccessful!")
            print(f'Time: {end - start}; Task scope: matrix {len(matrix_A)}x{len(matrix_B)}. Result unsuccessful!')
        file.close()


if __name__ == '__main__':
    check()
