import numpy as np
import pandas as pd

from pandas import Series, DataFrame

pi=np.pi; e=np.e

if __name__=='__main__':
    
    file_out = open('numbers.txt', 'w')
    
    for i in range(50000):
        randomInt = np.random.randint(-20000, 20000)
        file_out.write('{}\n'.format(randomInt))
