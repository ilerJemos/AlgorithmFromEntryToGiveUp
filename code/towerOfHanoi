#Simple Hanoi Towers
#2**n
def towersHanoi(size,fromStack,toStack,spareStack):
    if size == 1:print("Move from ",fromStack,"to ",toStack)
    else:
        towersHanoi(size - 1,fromStack,spareStack,toStack)
        towersHanoi(1,fromStack,toStack,spareStack)
        towersHanoi(size - 1,spareStack,toStack,fromStack)
