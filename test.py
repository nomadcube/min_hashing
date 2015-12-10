import minhashing


a = minhashing.read("/Users/wumengling/PycharmProjects/cpp_swig_test/dat_test")
print(a)

b = minhashing.t_set()
for line in a:
    for word in line:
        b.add(word)

c = minhashing.generate_sig(a, b, 3)
print(c)
