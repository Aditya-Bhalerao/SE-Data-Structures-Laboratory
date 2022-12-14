# Write a python Program for magic square. A magic square is an n * n matrix of the
# integers 1 to n2 such that the sum of each row, column, and diagonal is the same. The
# figure given below is an example of magic square for case n=5. In this example, the
# common sum is 65.

def magicSquare(n):

    magicsquare = [[0 for x in range(n)]
                   for y in range(n)]

    i = n / 2
    j = n - 1

    num = 1
    while num <= (n * n):
        if i == -1 and j == n:  # 3rd
            j = n - 2
            i = 0
        else:
            if j == n:
                j = 0

            if i < 0:
                i = n - 1

        if magicsquare[int(i)][int(j)]:  # 2nd
            j = j - 2
            i = i + 1
            continue
        else:
            magicsquare[int(i)][int(j)] = num
            num = num + 1

        j = j + 1
        i = i - 1  # 1st

    # Print
    print("Magic Square for n =", n)
    print("Sum of each row or column",
          n * (n * n + 1) / 2, "\n")

    for i in range(0, n):
        for j in range(0, n):
            print((magicsquare[i][j]), end=" ")

            if j == n - 1:
                print()


n = int(input("Enter any odd number- "))
magicSquare(n)
