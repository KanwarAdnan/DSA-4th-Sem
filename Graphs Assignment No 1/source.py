# -*- coding: utf-8 -*-
"""Assignment Graphs 1

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/16G-1Z-crBF6iiyE2Ka20md5XZKESJgJx
"""

# Commented out IPython magic to ensure Python compatibility.
from numpy import arange, log
from matplotlib import pyplot as plt
# %matplotlib inline

# Data
X = arange(1,1500)
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
Y = log(X)
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
Y = (X**2)
myPlot("",X,Y)
Y = 1000*X
myPlot("Y = x^2 vs Y = 1000x",X,Y)
plt.legend(['y = x^2', 'y = 1000x'])
plt.show()

"""They are intersecting at point (0,0) and at x=1000."""