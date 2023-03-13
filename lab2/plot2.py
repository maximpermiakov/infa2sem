import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
data1 = pd.read_csv("bin.txt", sep=" ")
data2 = pd.read_csv("hib.txt", sep=" ")
data3 = pd.read_csv("fib.txt", sep=" ")
plt.scatter(data1["N"], data1["swaps"], color="r", label="bin")
plt.scatter(data2["N"], data2["swaps"], color="g", label="hib")
plt.scatter(data3["N"], data3["swaps"], color="b", label="fib")
plt.xlabel("N")
plt.ylabel("swaps")
plt.legend()
plt.show()
