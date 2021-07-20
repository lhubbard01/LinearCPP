all:  pyInter.c setup.py
	python3 setup.py build_ext --inplace
