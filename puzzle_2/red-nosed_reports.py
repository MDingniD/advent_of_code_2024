
def typeOfIncrement(a):
    if a == 0 or abs(a) > 3: 
        return 0
    elif a < 0 and abs(a) <= 3:
        return -1
    elif a > 0 and abs(a) <= 3:
        return 1

def safeIndicator(A):
    i = 0
    indicator = typeOfIncrement(A[1] - A[0])
    end = len(A) - 1
    if indicator == 0: return 0
    for i in range(end):
        diff = A[i + 1] - A[i]
        if indicator != typeOfIncrement(diff):
            return 0
    return 1

"""
safeIndicator for problem 2:
"""


    

def safeIndicatorUpgrade(A): # file is safe if only one anomoly is eliminated
    
    def safeIndicatorUpgrade(A): # return -1 if it's safe , otherwise return 
        i = 0
        indicator = typeOfIncrement(A[1] - A[0])
        end = len(A) - 1
        if indicator == 0: return i
        for i in range(end):
            diff = typeOfIncrement(A[i + 1] - A[i])
            if indicator != diff or diff == 0 :
                return i
        return -1
    
    if safeIndicatorUpgrade(A) == -1: 
        return 1
    else:
        i = safeIndicatorUpgrade(A)
        if i == 1: # when i = 1, the anomoly could be i - 1, i or i + 1
            D = A[i:]
        else:
            D = A
        B = A[:i]   + A[i+1:]
        if i + 2 == len(A): # prevent index out of range
            C2 = []
        else:
            C2 = A[i+2:]
        C = A[:i+1] + C2
        if safeIndicator(B) == 1 or safeIndicator(C) == 1 or safeIndicator(D) == 1:
            return 1
        else:
            return 0
    

    
    """
    
    Stupid Code:
        
    if safeIndicator(A) == 1: return 1
    anomolyCounter = 0
    i = 0
    indicator = typeOfIncrement(A[1] - A[0])
    end = len(A) - 1
    start = 1
    #find the right indicator
    indicator1 = typeOfIncrement(A[2] - A[1])
    if indicator == 0:  #either the first or the second is the anomoly
        anomolyCounter += 1
        start = 2
        indicator2 = typeOfIncrement(A[2] - A[0])
        indicator3 = typeOfIncrement(A[3] - A[2])
        if indicator3 == indicator1 and indicator1 != 0:
            indicator = indicator1
        elif indicator3 == indicator2 and indicator2 != 0:
            indicator = indicator2
        else:
            return 0
    elif indicator != indicator1: #the first or the second or the third is the anomoly
        indicator2 = typeOfIncrement(A[2] - A[0])
        indicator3 = typeOfIncrement(A[3] - A[1])
        indicator4 = typeOfIncrement(A[3] - A[2])
        anomolyCounter += 1
        start = 3
        if indicator1 == indicator4 and indicator1 != 0: #the first is anomoly
            indicator = indicator1
        elif indicator2 == indicator4 and indicator2 != 0:
            indicator = indicator2
        elif indicator == indicator3:
            indicator = indicator
        else:
            return 0

    for i in range(start, end):
        diff1 = typeOfIncrement(A[i + 1] - A[i])
        if indicator != diff1:
            if anomolyCounter == 0:
                if i < len(A) - 2 and i > 2:
                    diff2 = typeOfIncrement(A[i + 2] - A[i])
                    diff3 = typeOfIncrement(A[i + 1] - A[i - 1])
                    if indicator != diff2 and indicator != diff3:
                        return 0
                elif i == len(A) - 2:
                    return 1
                anomolyCounter += 1
            else:
                return 0
    return 1
    """
    
    

def stringToInt(A):
    return [int(a) for a in A]

def main():
    numOfSafeFile = 0
    with open("/Users/yidingma/Desktop/Advent_of_Code_2024/puzzle_2/input.txt","r") as file:
        lines = file.readlines()
        
        for line in lines:
         
            line = line.split(" ")
            line = stringToInt(line)
            #numOfSafeFile = numOfSafeFile + safeIndicator(line)
            numOfSafeFile = numOfSafeFile + safeIndicatorUpgrade(line)
    
    print("number of safe files is:", numOfSafeFile)
    
    
    
    
if __name__ == "__main__":
    main()