# cython: language_level=3
import _module

cdef public void info(const char * msg) with gil:
    _module.info((<bytes> msg).decode())

cdef public void warning(const char * msg) with gil:
    _module.warning((<bytes> msg).decode())

cdef public void error(const char * msg) with gil:
    _module.error((<bytes> msg).decode())

cdef public void critical(const char * msg) with gil:
    _module.critical((<bytes> msg).decode())

cdef public int calc(int a, int b) with gil:
    return _module.calc(a, b)

# 逻辑写在单独的py文件方便修改  写在pyx里面可以编译加速