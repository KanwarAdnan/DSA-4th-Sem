import numpy as np
import matplotlib.pyplot as plt
# %matplotlib inline

# Function to plot
X = np.arange(1,20)
print(f"X = {X}")

# Plotting Function
def myPlot(title,x,y):
  plt.title(title)
  plt.xlabel("X-Axis")
  plt.ylabel("Y-Axis")
  print(f"Y = {y}")
  plt.plot(x,y)

# Function 1
Y = (2*X)
myPlot("Y = 2x",X,Y)
plt.show()

# Function 2
Y = (3*X)
myPlot("Y = 3x",X,Y)
plt.show()

# Function 3
Y = (X**3)
myPlot("Y = x^3",X,Y)
plt.show()

# Function 4
Y = np.log(X)
myPlot("Y = log x",X,Y)
plt.show()

# Function 5
Y = (2*(X**2))+(3*X)
myPlot("Y=2x^2 + 3x",X,Y)
plt.show()

# Function 6
Y = (3*X)+2
myPlot("Y = 3x + 2",X,Y)
plt.show()

# Function 7
Y = (X^2)
myPlot("",X,Y)
Y = 1000*X
myPlot("Y = x^2 vs Y = 1000x",X,Y)
plt.legend(['y = x^2', 'y = 1000x'])
plt.show()

"""They are not intersecting at any point."""