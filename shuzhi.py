from sympy import *
import sys
import pdb 
pdb.set_trace()

alpha, beta,a,F,w1, delta  = symbols('alpha, beta a F w1 delta')
# f = (beta**2 *(a**2 - a*F) + beta*(a - F*w1))/((w1 + beta * a) * F)
# f = diff(f, beta)
# print (solve(f,beta))
f1 =delta*(1+ delta)*a/((w1+delta) * F) - delta 
ans =  solve(f1, delta)
print(ans)