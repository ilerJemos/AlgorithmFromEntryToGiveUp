from enum import Enum,unique

towers = Enum('tower',('A','B','C'))

@unique
class Tower(Enum):
    A = 'A'
    B = 'B'
    C = 'C'


# 汉诺塔问题
def hanoti_tower(n,x,y,z):
    if n:
        hanoti_tower(n-1,x,z,y)
        print('move top disk from tower ',x,'to top of tower ',y,'\n')
        hanoti_tower(n-1,z,y,x)

# hanoti_tower(3,'A','B','C')

for name, member in towers.__members__.items():
    print(name, '=>', member, ',', member.value)

print(towers)


