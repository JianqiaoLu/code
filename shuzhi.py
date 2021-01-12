from sympy import *
import sys
import math

alpha, beta,a,F,w1, delta, we, sq_a =  symbols('alpha beta a F w1 delta we sq_a')

# f = (beta**2 *(a**2 - a*F) + beta*(a - F*w1))/((w1 + beta * a) * F)
# f = diff(f, beta)
# print (solve(f,beta))
f1 =delta*(1+ delta)*a/((w1+delta) * F) - delta 
f2 = (1 + delta) - (1+delta)*delta* alpha *we/(we + delta )
ans = f2.subs(delta, we*(sq_a - 1))
print(ans)