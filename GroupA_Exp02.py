# Write a Python program to store marks scored in subject “Fundamental of Data Structure” by N students in the class. Write functions to compute following:
# a) The average score of class
# b) Highest score and lowest score of class
# c) Count of students who were absent for the test
# d) Display mark with highest frequency

import statistics
from statistics import mode

marks = []
n = int(input("Enter number of students - "))


def get_marks():

    for i in range(n):
        m = int(input(
            "Enter marks of student (Press enter after every entry) (For absent enter -1) - "))
        marks.append(m)


def avg_marks():
    counter = 0
    for i in range(n):
        if marks[i] == -1:
            counter += 1
    total = sum(marks) + counter
    avg = total/(n-counter)
    print(
        f"a) Average marks of the class (Calculating only for present students) = {avg}")


def high_low():
    counter = 0
    for i in range(n):
        if marks[i] == -1:
            counter += 1
    marks.sort()
    low = marks[counter]
    high = marks[-1]
    print(f"b) Lowest marks scored = {low}")
    print(f"   Highest marks scored = {high}")


def absent():
    counter = 0
    for i in range(n):
        if marks[i] == -1:
            counter += 1
    print(f"c) Number of absent students = {counter}")


def high_freq():
    b = []  # list of marks without -1
    for i in marks:
        if i == -1:
            pass
        else:
            b.append(i)
    print(f"d) Mark with highest frequency = {mode(b)}")


get_marks()
print("Answers:- ")
print(f"List of marks {marks}")
avg_marks()
high_low()
absent()
high_freq()
