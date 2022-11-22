# Write a python program that determines the location of a saddle point of matrix if one
# exists. An m x n matrix is said to have a saddle point if some entry a[i][j] is the smallest
# value in row i and the largest value in j.

def saddle(m):
    for i in range(0, len(m)):

        min_row = m[i][0]
        col_ind = 0
        for j in range(1, len(m[0])):
            if min_row > m[i][j]:
                min_row = m[i][j]
                col_ind = j

        counter = 0
        for k in range(0, len(m)):
            if min_row < m[k][col_ind]:
                counter = 1
                break

        if counter == 0:
            print("Saddle point is : ", min_row)
            print(
                "Saddle point is present at location m[{0}][{1}]".format(i, col_ind))
            return
    print("No Saddle point present")
    return


def read_mat():
    row = int(input("Enter the rows in the matrix : "))
    col = int(input("Enter the columns in the matrix : "))
    mat = []
    print("Enter the elements rowwise: ")

    for i in range(0, row):
        a = []
        for j in range(0, col):
            a.append(int(input("Enter element : ")))
        mat.append(a)
    return mat, row, col


matrix = []

matrix, row, col = read_mat()

print("The matrix is : ")
for i in range(0, row):
    for j in range(0, col):
        print(matrix[i][j], end=" ")
    print()

saddle(matrix)
