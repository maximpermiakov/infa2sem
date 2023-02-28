import matplotlib.pyplot as plt
f = open('sum2worst.txt', 'r')
lines = f.readlines()
x = []
y = []
for i in lines:
    i = i[0:-1].split(' ')
    x.append(int(i[0]))
    y.append(int(i[1]))
plt.scatter(x, y)
plt.axis([0, max(x) * 1.1, 0, max(y) * 1.1])
plt.show()
