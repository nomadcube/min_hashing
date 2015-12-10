from distutils.core import setup, Extension

minhashing_module = Extension('_minhashing',
                           sources=['minhashing_wrap.cxx', 'minhashing.cpp'],)


setup(name='minhashing',
      version='0.1',
      author='me',
      description='swig test',
      ext_modules=[minhashing_module],
      py_modules=["minhashing"],
      )
