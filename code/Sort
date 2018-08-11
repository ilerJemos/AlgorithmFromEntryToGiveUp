#select do less swqp than bubble
def SelSort(L):
    for j in rang(L-1):
        minIndex = j
        minValue = L[minIndex]
        i = j + 1
        while i<len(L):
            if L[i]<minValue:
                minValue = L[i]
                minIndex = i
        temp = L[j]
        L[j]=minValue
        L[minIndex]=temp

def BubbleSort(L):
    for i in range(len(L)):
        for j in range(Len(L)-1):
            if L[j]>L[j+1]:
                temp = L[j]
                L[j]=L[j+1]
                L[j+1]=temp

#添加是否swqp标志，可以提前结束循环
def BubbleSort2(L):
    swapped  = True
    while swqpped:
        swapped= False
        for i in range(len(L)):
        for j in range(Len(L)-1):
            if L[j]>L[j+1]:
                temp = L[j]
                L[j]=L[j+1]
                L[j+1]=temp
                swqpped = True

#分治思想-归并排序
#合并
def merge(left,right):
    """left and right are sorted"""
    result = []
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i]<=right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    while i < len(left):
        result.append(left[i])
        i+=1
    while j < len(right):
        result.append(right[j])
        j+=1
    return result
#归并排序
def mergeSort(L):
    if len(L)<2:return L[:]
    else:
        mid = int(len(L)/2)
        left = mergeSort(L[:mid])
        right = mergeSort(L[mid:])
        return (merge(left,right))
