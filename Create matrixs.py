import numpy as np
from tqdm import tqdm

N = 100
try:
    matrix_A = np.random.randint(0, 50, (N, N))
    print(matrix_A)
    with open("/Users/artemt/Documents/Labs/PP/A.txt", "w") as file:
        for i in tqdm(range(len(matrix_A)), desc="Loding: ", ascii=False, ncols=100):
            file.write(' '.join([str(a) for a in matrix_A[i]]) + '\n')
        file.close()
    matrix_B = np.random.randint(0, 50, (N, N))
    print(matrix_B)
    with open("/Users/artemt/Documents/Labs/PP/B.txt", "w") as file:
        for i in tqdm(range(len(matrix_A)), desc="Loding: ", ascii=False, ncols=100):
            file.write(' '.join([str(a) for a in matrix_B[i]]) + '\n')
        file.close()
    print("Successful")
except BaseException() as ex:
    print(ex)
