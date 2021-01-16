# import cvxpy as cp 
# x  =  cp.Variable(2)
# objective = x[0]**(1/3) * x[1]**(2/3)  
# objective =cp.Maximize(objective)
# constraints = [0.0000001 <=x,  sum(x) == 1 ]
# prob = cp.Problem(objective, constraints)
# result = prob.solve()
# print("The first", x.value)
# y  =  cp.Variable(2)
# objective2 = y[0]*y[1] /(y[0]*1 +  y[0]*4)
# objective2 =cp.Maximize(objective2)
# constraints2= [0.0000001 <=y,  sum(y) == 1 ]
# prob1 = cp.Problem(objective2, constraints2)
# result1 = prob1.solve()
# print("The second", y.value)

import matplotlib
matplotlib.use('Agg')
import numpy as np
from matplotlib import pyplot as plt
c1 = 1
c2 = 4 
x = np.array(range(0,100,1))/100
y = x**(c1/(c1+c2))*(1-x)**(c2/(c1+c2))

y2 = x*(1-x)/(x*c2**2+ (1-x)*c1**2)
plt.plot(x,y)                                             
plt.plot(x,y2)
a= np.argmax(y)
print(a)
print(np.argmax(y2))
print(x[a])

plt.show()

plt.savefig('f1.png')