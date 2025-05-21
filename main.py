#Problem 61

def triangleNums():
    tri = []
    currNum = 0
    index = 1
    while currNum < 10000:
        currNum = (int)(index*(index+1)/2)
        if currNum>999:
            tri.append(currNum)
        index+=1
    return tri
    
def squareNums():
    sq = []
    currNum = 0
    index = 1
    while currNum < 10000:
        currNum = (int)(index*index)
        if currNum>999:
            sq.append(currNum)
        index+=1
    return sq
    
def pentNums():
    pent = []
    currNum = 0
    index = 1
    while currNum < 10000:
        currNum = (int)(index*(3*index-1)/2)
        if currNum>999:
            pent.append(currNum)
        index+=1
    return pent

def hexaNums():
    arr = []
    currNum = 0
    index = 1
    while currNum < 10000:
        currNum = (int)(index*(2*index-1))
        if currNum>999:
            arr.append(currNum)
        index+=1
    return arr
    
def heptNums():
    arr = []
    currNum = 0
    index = 1
    while currNum < 10000:
        currNum = (int)(index*(5*index-3)/2)
        if currNum>999:
            arr.append(currNum)
        index+=1
    return arr
    
def octNums():
    arr = []
    currNum = 0
    index = 1
    while currNum < 10000:
        currNum = (int)(index*(3*index-2))
        if currNum>999:
            arr.append(currNum)
        index+=1
    return arr
    
    
    
x=1
if ((x in triangleNums()) ^ (x in squareNums()) ^ (x in pentNums())):
    print('hi')