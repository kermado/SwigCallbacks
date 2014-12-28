#include <string>
#include <Python/Python.h>

int main()
{
    Py_Initialize();
    PySys_SetPath(".");

    std::string source =
R"(
from module import *

def onEvent(arg):
    print("onEvent called")
    print(arg)

cb = Callback(onEvent)
print(cb)
cb.call("Some value")
)";

    PyRun_SimpleString(source.c_str());

    Py_Finalize();

    return 0;
}