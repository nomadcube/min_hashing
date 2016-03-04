import minhashing


a = minhashing.read("/Users/wumengling/PycharmProjects/cpp_swig_test/dat_test")
print(a)

sig_a = minhashing.get_signature(a, 10)
print sig_a

print minhashing.jaccard_similarity(sig_a)
print minhashing.jaccard_similarity(a[0], a[1])
