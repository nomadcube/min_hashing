import re
from time import time
from random import randint

import minhashing

with open('/Users/wumengling/PycharmProjects/cpp_swig_test/dat_test.txt', 'w') as out_f:
    size = 10000
    s1 = ''.join([chr(n) for n in [randint(97, 107) for _ in range(size)]])
    s2 = ''.join([chr(n) for n in [randint(97, 107) for _ in range(size)]])
    s1_new = re.sub("a", " ", s1)
    s2_new = re.sub("a", " ", s2)
    out_f.write(s1_new + '\n')
    out_f.write(s2_new + '\n')

a = minhashing.read("/Users/wumengling/PycharmProjects/cpp_swig_test/dat_test.txt")
print(a)

sig_size = 100
t = time()
sig_a = minhashing.get_signature(a, sig_size)
print minhashing.jaccard_similarity(sig_a)
print "min hashing time: " + repr(time() - t)

t = time()
print minhashing.jaccard_similarity(a[0], a[1])
print "old algorithm time: " + repr(time() - t)
