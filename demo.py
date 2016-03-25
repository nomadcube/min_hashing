import minhashing

sig_size = 10

sig_a = minhashing.read_into_signature("/Users/wumengling/PycharmProjects/cpp_swig_test/dat_test.txt", sig_size)
print(sig_a)

print minhashing.jaccard_similarity(sig_a)

a = minhashing.read("/Users/wumengling/PycharmProjects/cpp_swig_test/dat_test.txt")
print minhashing.jaccard_similarity(a[0], a[1])


def prime(x):
    p = x + 10000
    while not isprime(p):
        p += 1
    return p


def isprime(x):
    is_prime = True
    for i in xrange(2, x):
        if x % i == 0:
            is_prime = False
    return is_prime
