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


def main():
    matrix_A = []
    matrix_B = []
    with open("/Users/artemt/Documents/Labs/PP/A.txt") as A:
        for line in A:
            matrix_A.append([int(x) for x in line.split()])
        A.close()
    with open("/Users/artemt/Documents/Labs/PP/B.txt") as B:
        for line in B:
            matrix_B.append([int(x) for x in line.split()])
        B.close()

    print(f'{matrix_A[0]}\n\n{matrix_B[0]}')
    start = perf_counter()
    matrix_C = calculate(matrix_A, matrix_B, 2)
    end = perf_counter()
    print(f'\nMatrix result: \n{matrix_C}')
    with open("/Users/artemt/Documents/Labs/PP/result.txt", "w") as file:
        for i in tqdm(range(len(matrix_A)), desc="Loding: ", ascii=False, ncols=100):
            file.write(' '.join([str(a) for a in matrix_C[i]]) + '\n')
        file.write('\n' + "Time: " + str(end - start))
        file.close()
    print(f'Time: {end - start}')


if __name__ == '__main__':
    main()
