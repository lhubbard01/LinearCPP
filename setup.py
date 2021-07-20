from distutils.core import setup, Extension
import numpy as np
module1 = Extension("RegCPP", sources = ["pyInter.c"], include_dirs = [np.get_include()])
setup(name = "RegCPP", 
      version = "0.0.1",
      description = "first", 
      ext_modules =[module1])


