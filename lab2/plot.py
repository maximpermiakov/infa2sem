import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
filename = input()
data = pd.read_csv(filename + ".txt", sep=" ")
data["ln(N)"] = data["N"].apply(lambda x: math.log(x))
data["ln(t/1 mcs)"] = data["time"].apply(lambda x: math.log(x))
data["ln(swaps)"] = data["swaps"].apply(lambda x: math.log(x))
X = data["ln(N)"]
Y = data["ln(t/1 mcs)"]
plt.scatter(X, Y)
plt.xlabel("ln(N)")
plt.ylabel("ln(t/1 mcs)")
intercept, slope = np.polynomial.polynomial.polyfit(X, Y, 1)
plt.plot(X, X*slope + intercept)
plt.legend([filename + ", slope = " + str(round(slope, 2))])
plt.show()


