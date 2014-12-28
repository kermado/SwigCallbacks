#ifndef CALLBACK_HPP
#define CALLBACK_HPP

#include <Python/Python.h>

class Callback
{
public:
    Callback(PyObject* fn)
    : m_fn(fn)
    {
        Py_INCREF(m_fn);
    }

    ~Callback()
    {
        Py_DECREF(m_fn);
    }

    void call(PyObject* arg)
    {
        PyObject_CallFunctionObjArgs(m_fn, arg);
    }

private:
    Callback(const Callback&) = delete;
    Callback& operator=(const Callback&) = delete;

private:
    PyObject* m_fn;
};

#endif