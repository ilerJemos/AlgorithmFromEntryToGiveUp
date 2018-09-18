#Sample Hash
#复杂度为 常数阶
#以空间获取时间
#trade off


def create(smallest,largest):
    intSet=[]
    for i in range(smallest,largest):
        intSet.append(i)
    return intSet

def insert(intSet,e):
    intSet[e] = 1

def member(intSet,e):
    return intSet[e]==1


def hashChar(c):
    # c is a char
    # return a integer in range  0 ` 255
    return ord(c)`
