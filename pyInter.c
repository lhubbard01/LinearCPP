// DOESNT WORK IN PROGESS (meant to pass data matrix, etc to linear models in cpp

#include <Python.h>
#include <stdio.h>
#include <numpy/ndarraytypes.h>
#include <numpy/npy_3kcompat.h>
// 
/*
static PyObject * keywordF1C(PyObject * arg1, PyObject * kwargs){
  PyObject * input;
  PyArray_Descr * dtype;
   
    return NULL; //i.e. if this fails to meet the format, raise error
*/


static PyObject *
example(PyObject * _X, PyObject * args)
{

  PyObject * arg1 = NULL, * arg2 = NULL, *out = NULL;
  PyObject * arr1 = NULL, * arr2 = NULL, *oarr = NULL;

  double * dptr;
  int nd;
  npy_intp *len;


  if(!PyArg_ParseTuple(args, "OOO!", &arg1, &arg2, &PyArray_Type, &out)) //"OO&", &input, PyArray_DescrConverter, &dtype)) 
		return NULL;
  arr1 = PyArray_FROM_OTF(arg1, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
  
	if (!arr1)
    return NULL;
  

	arr2 = PyArray_FROM_OTF(arg2, NPY_DOUBLE, NPY_ARRAY_IN_ARRAY);
  if (!arr2) 
    goto fail;

  oarr = PyArray_FROM_OTF(out, NPY_DOUBLE, NPY_ARRAY_INOUT_ARRAY2);

  if (!oarr) goto fail;
  //Now preprocessing steps for pytypes to numpy arrays is done. 
  //can use 
 
  

  len = PyArray_DIMS(arr1);

  nd = PyArray_NDIM(arr1);


  dptr = (double*)PyArray_DATA(arr1);

  
  
	printf("nd %d\npositions in len structure: \n" , nd);
	for(int i = 0; i < nd; i++)
		printf("%d ", len[i]);

  int count = atoi(len[0]);
	printf("count %d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%lf\n", dptr[i]);
		printf("%d\n",i);
	}
  puts("");


  
  Py_DECREF(arr1);
  Py_DECREF(arr2);

  PyArray_ResolveWritebackIfCopy(oarr);

  

  Py_DECREF(oarr);
  Py_INCREF(Py_None);

  return Py_None;
fail:
  Py_XDECREF(arr1);
  Py_XDECREF(arr2);


  PyArray_DiscardWritebackIfCopy(oarr);
  Py_XDECREF(oarr);
  return NULL;
}




//Declare methods in python, corresponding C, how args are expected, then doc.
static PyMethodDef RegMethods [] = {
  {"examplePy", example, METH_VARARGS, "initial interface as example"},
  {NULL, NULL, 0, NULL} // SENTINEL
};



static struct PyModuleDef RegCPP_def = {
	PyModuleDef_HEAD_INIT,
	"RegCPP",
	"linear models in cpp access numpy objects",
-1, RegMethods
};



PyMODINIT_FUNC
PyInit_RegCPP(void)
{
	Py_Initialize();
  import_array();
	return PyModule_Create(&RegCPP_def);
}
/*static PyObject*
callRegCpp(PyObject * X, PyObject* y)
{
  PyArray_FromAny

  
  //PyArray_NewFromDescr PyArray_DATA PyArray_NDIM PyArray_DIMS*/
