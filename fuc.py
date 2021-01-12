global eps, m
def func(alpha):
  global eps, m
  return alpha * (0.75 * alpha**(1/2) -  0.25 * alpha **(1.5) + 0.5)
def func2(alpha):
  global eps, m
  return alpha*( - alpha**1.5*((eps/m)**2) + alpha *(2*(eps/m)**2 - eps/m) + alpha**0.5*(2*eps/m - (eps/m)**2) + 1)

def func3(alpha):
  global eps, m
  return (eps/m) **2 *(2*alpha - alpha**1.5 - alpha**0.5) + eps/m *(2 * alpha**0.5 - alpha - 1)  + 1

def func4(alpha):
  return alpha * (1 - (alpha**0.5 - 1)**2 * eps /m)

def func5(alpha):
  return alpha * (1 - alpha* eps /m)
eps = 1e-3
m = 10
initial_alpha = 100.00
for i in range(100):
  print("alpha is know %f" % initial_alpha)
  initial_alpha = func3(initial_alpha)
  