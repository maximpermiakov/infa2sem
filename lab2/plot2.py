import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
data1 = pd.read_csv("bin.txt", sep=" ")
data2 = pd.read_csv("hib.txt", sep=" ")
data3 = pd.read_csv("fib.txt", sep=" ")
plt.scatter(data1["N"], data1["time"], color="r", label="bin")
plt.scatter(data2["N"], data2["time"], color="g", label="hib")
plt.scatter(data3["N"], data3["time"], color="b", label="fib")
plt.xlabel("N")
plt.ylabel("time, mcs")
plt.legend()
plt.show()
