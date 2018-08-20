# -*- coding: utf-8 -*-
"""
Created on Sun Aug 19 21:33:27 2018

@author: 13548
"""

import pylab,random
fair = [1,2,3,4,5,6]

def throwPair(vals1,vals2):
    d1 = random.choice(vals1)
    d2 = random.choice(vals2)
    return d1,d2
def conductTrails(numThrows,die1,die2):
    throws = []
    for i in range (numThrows):
        d1,d2 = throwPair(die1,die2)
        throws.append(d1+d2)
    return throws

numThrows = 100000
throws = conductTrails(numThrows,fair,fair)
pylab.hist(throws,11)#柱状图
#x轴添加标签
pylab.xticks(range(2,13),['2','3','4','5','6','7','8','9','10','11','12'])
pylab.title("Distribution of Values")
pylab.xlabel('sum of two die')
pylab.ylabel('Number of Throws')
#get probabilities for fair dice
pylab.figure()
sums = pylab.array([0]*14)
for val in range(2,13):
    sums[val]= throws.count(val)
probs = sums[2:13]/float(numThrows)
xVals = pylab.arange(2,13)
pylab.plot(xVals,probs,label='Probability of a Value')
pylab.xlabel("Sum of two die")
pylab.ylabel('Probability')

def craps(die1,die2):
    """return true if shooter wins at craps bybetting pass line"""
    d1,d2 = throwPair(die1,die2)
    tot = d1+d2
    if tot in [7,11]:return True
    if tot in [2,3,12]:return False
    point = tot
    while True:
        d1,d2 = throwPair(die1,die2)
        tot = d1+d2
        if tot == point:return True
        if tot == 7:return False
def simCraps(numBets,die1,die2):
    wins,losses = (0,0)
    for i in range(numBets):
        if craps(die1,die2):wins+=1
        else:losses+=1
    print(wins,losses)
    houseWin = float(losses)/float(numBets)
    print(houseWin)
    print('house winning percentage:'+str(100*houseWin)+'%')
    print('house profits per $%d bet:$%d' %(numBets,losses -wins))
#simCraps(100000,fair,fair)
#try unfair dice
pylab.figure()
weighted = [1,2,3,4,5,5,6]
throws = conductTrails(numThrows,fair,weighted)
sums = pylab.array([0]*14)
for val in range (2,13):
    sums[val]=throws.count(val)
probs = sums[2:13]/float(numThrows)
xVals = pylab.arange(2,13)
pylab.plot(xVals,probs,label='Weighted dice')
pylab.legend()
simCraps(100000,fair,weighted)