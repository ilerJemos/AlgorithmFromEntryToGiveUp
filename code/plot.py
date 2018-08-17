# -*- coding: utf-8 -*-
"""
Created on Thu Aug 16 13:32:35 2018

@author: 13548
"""

#import pylab
import random
#from pylab import *
import pylab


#figure()
#plot([1,2,3,4])
#plot([2,4,7,34],[1,4,9,16])
#
#figure()
#plot([1,2,3,4],[1,4,9,16],'ro')
#axis([0,6,0,20])
#xlabel('day')
#ylabel('dollars')
#title('Earning')
#
#figure()
#xAxis = array([1,2,3,4])
#print(xAxis)
#test = arange(1,5)
#print(test)
#print(test==xAxis)
#yAxis = xAxis**3
#plot(xAxis,yAxis,'ro')

pylab.figure()
vals =[]
dieVals = [1,2,3,4,5,6]
for i in range(10000):
    vals.append(random.choice(dieVals)+random.choice(dieVals))
pylab.hist(vals,bins=11)
#pylab.plot(vals)

pylab.show()