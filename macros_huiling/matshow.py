import matplotlib.pyplot as plt
import numpy as np
def samplemat(dims):
    aa = np.zeros(dims)
    for i in range(min(dims)):
        aa[i, i] = i
    return aa

dimlist = [(12, 12)]
for d in dimlist:
    plt.matshow(samplemat(d))
    
plt.matshow(np.random.rand(64, 64), fignum=100, cmap=plt.cm.gray)
