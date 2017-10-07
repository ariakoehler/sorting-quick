import numpy as np
import pandas as pd

from pandas import Series, DataFrame

pi=np.pi; e=np.e

if __name__=='__main__':
    
    file_out = open('numbers.txt', 'w')

    num_words = 50

    file_out.write('{}\n{}\n'.format(num_words, num_words))

    for i in range(num_words):
        alpha = list('qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123645789')
        np_alpha = np.array(alpha)
        random_word = np.random.choice(np_alpha, 30)
        
        for j in range(random_word.size - 1):
            file_out.write('{}'.format(random_word[j]))
            
        file_out.write('\n')
