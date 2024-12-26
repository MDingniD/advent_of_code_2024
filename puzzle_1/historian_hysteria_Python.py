from sortedcontainers import SortedList
import math

def binarySearch(A, m, n, element):
    distance = n - m
    mid = math.floor((m + n)/2)
    if distance <= 1:
        if element == A[n]:
            return n
        else:
            return -1
    else:
        if element == A[mid]: 
            return mid
        elif element < A[mid]:
            return binarySearch(A, m, mid, element)
        elif element > A[mid]:
            return binarySearch(A, mid, n, element)
    
def numOfDuplicate(A, element):
    i = 0
    for a in A:
        if element == a:
            i += 1
    return i

def numOfDuplicateUpgrade(A, element):
    n = len(A) - 1
    m = 0
    position = binarySearch(A, m, n, element)
    if position == -1:
        return 0
    else:
        numberOfAppearanceUp   = 0
        numberOfAppearanceDown = 0
        while element == A[position + numberOfAppearanceUp + 1]:
            numberOfAppearanceUp += 1
        while element == A[position - numberOfAppearanceDown - 1]:
            numberOfAppearanceDown += 1
        return (1 + numberOfAppearanceDown + numberOfAppearanceUp)
    

def main():
    with open("/Users/yidingma/Desktop/Advent_of_Code_2024/puzzle_1/input.txt", "r") as file:
        lines = file.readlines()
        listA = SortedList()
        listB = SortedList()
        for line in lines:
            twoNumbers = []
            twoNumbers = line.split("   ")
            listA.add(int(twoNumbers[0]))
            listB.add(int(twoNumbers[1]))
    
    i = 0
    sumOfDistance = 0
    sumOfScore = 0
    
    for num in listA:
    
        distance = abs(num - listB[i])
        sumOfDistance = sumOfDistance + distance #Sum of distance for part1
        score = numOfDuplicateUpgrade(listB, num) * num
        sumOfScore = sumOfScore + score
        i += 1
    
    print(sumOfDistance)
    print(sumOfScore)
    
if __name__ == "__main__":
    main()