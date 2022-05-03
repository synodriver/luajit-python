#include "module.h"

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#elif
#define DLLEXPORT
#endif /* _WIN32 */

DLLEXPORT void loguru_init()
{
    if (PyImport_AppendInittab("module", PyInit_module) < 0)
    {
        fprintf(stderr, "PyImport_AppendInittab wrong\n");
    }
    Py_InitializeEx(0);
    PyObject *pmodule = PyImport_ImportModule("module");  /*必须import一次 进行初始化 https://cython.readthedocs.io/en/latest/src/tutorial/embedding.html*/
    if (!pmodule)
    {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module\n");
    }
    Py_DECREF(pmodule);
}

DLLEXPORT void loguru_free()
{
    if (Py_FinalizeEx() < 0)
    {
        fprintf(stderr, "Py_FinalizeEx wrong\n");
    }
}

DLLEXPORT void loguru_info(const char *msg)
{
    info(msg);
}

DLLEXPORT void loguru_warning(const char *msg)
{
    warning(msg);
}

DLLEXPORT void loguru_error(const char *msg)
{
    error(msg);
}

DLLEXPORT void loguru_critical(const char *msg)
{
    critical(msg);
}

DLLEXPORT int loguru_calc(int a, int b)
{
    return calc(a, b);
}
