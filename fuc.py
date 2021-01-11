global eps, m
def func(alpha):
  global eps, m
  return alpha * (1 -  alpha * (eps/m )**2)
eps = 1e-2
m = 10
initial_alpha = 10.00
for i in range(100):
  initial_alpha = func(initial_alpha)
  print("alpha is know %f" % initial_alpha)
  