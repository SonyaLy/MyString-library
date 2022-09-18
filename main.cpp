#include <pybind11/pybind11.h>
#include "string.h"

namespace py = pybind11;

PYBIND11_MODULE(mystring, m)
{
	py::class_<MyString>(m, "MyString")

		////////////////////////////////////////////////////////

		.def(py::init())
		.def(py::init<const MyString&>())
		.def(py::init<const char*>())
		.def(py::init<const initializer_list<char>&>())
		.def(py::init<string&>())
		.def(py::init<const char*, size_t>())
		.def(py::init<size_t, char>())
		.def(py::init<const MyString&, size_t, size_t>())


		.def("insert", py::overload_cast<size_t, size_t, char>(&MyString::insert))
		.def("insert", py::overload_cast<size_t, const char*>(&MyString::insert))
		.def("insert", py::overload_cast<size_t, const char*, size_t>(&MyString::insert))
		.def("insert", py::overload_cast<size_t, string>(&MyString::insert))
		.def("insert", py::overload_cast<size_t, string, size_t>(&MyString::insert))
		.def("insert", py::overload_cast<size_t, const MyString&>(&MyString::insert))

		////////////////////////////////////////////////////////

		.def("erase", py::overload_cast<size_t, size_t>(&MyString::erase))

		////////////////////////////////////////////////////////

		.def("append", py::overload_cast<const MyString&>(&MyString::append))
		.def("append", py::overload_cast<const MyString&, size_t, size_t>(&MyString::append))
		.def("append", py::overload_cast<size_t, char>(&MyString::append))
		.def("append", py::overload_cast<const char*>(&MyString::append))
		.def("append", py::overload_cast<const char*, size_t, size_t>(&MyString::append))
		.def("append", py::overload_cast<string&>(&MyString::append))
		.def("append", py::overload_cast<string&, size_t, size_t>(&MyString::append))

		////////////////////////////////////////////////////////

		.def("replace", py::overload_cast<size_t, size_t, const MyString&>(&MyString::replace))
		.def("replace", py::overload_cast<size_t, size_t, const char*>(&MyString::replace))
		.def("replace", py::overload_cast<size_t, size_t, string>(&MyString::replace))

		////////////////////////////////////////////////////////

		.def("substr", py::overload_cast<size_t>(&MyString::substr))
		.def("substr", py::overload_cast<size_t, size_t>(&MyString::substr))

		////////////////////////////////////////////////////////

		.def("find", py::overload_cast<const MyString&, size_t>(&MyString::find))
		.def("find", py::overload_cast<const char*>(&MyString::find))
		.def("find", py::overload_cast<const char*, size_t>(&MyString::find))
		.def("find", py::overload_cast<string&>(&MyString::find))
		.def("find", py::overload_cast<string&, size_t>(&MyString::find))

		////////////////////////////////////////////////////////

		.def("__str__", py::overload_cast<>(&MyString::c_str))
		.def("__len__", py::overload_cast<>(&MyString::length))
		.def("__bool__", py::overload_cast<>(&MyString::empty))


		.def("__getitem__", py::overload_cast<int>(&MyString::operator[]))

		.def("__eq__", py::overload_cast<const MyString&>(&MyString::operator==))
		.def("__eq__", py::overload_cast<const char*>(&MyString::operator==))
		.def("__eq__", py::overload_cast<string&>(&MyString::operator==))

		.def("__ne__", py::overload_cast<const MyString&>(&MyString::operator!=))
		.def("__ne__", py::overload_cast<const char*>(&MyString::operator!=))
		.def("__ne__", py::overload_cast<string&>(&MyString::operator!=))

		.def("__lt__", py::overload_cast<const MyString&>(&MyString::operator<))
		.def("__lt__", py::overload_cast<const char*>(&MyString::operator<))
		.def("__lt__", py::overload_cast<string&>(&MyString::operator<))

		.def("__gt__", py::overload_cast<const MyString&>(&MyString::operator>))
		.def("__gt__", py::overload_cast<const char*>(&MyString::operator>))
		.def("__gt__", py::overload_cast<string&>(&MyString::operator>))

		.def("__le__", py::overload_cast<const MyString&>(&MyString::operator<=))
		.def("__le__", py::overload_cast<const char*>(&MyString::operator<=))
		.def("__le__", py::overload_cast<string&>(&MyString::operator<=))

		.def("__ge__", py::overload_cast<const MyString&>(&MyString::operator>=))
		.def("__ge__", py::overload_cast<const char*>(&MyString::operator>=))
		.def("__ge__", py::overload_cast<string&>(&MyString::operator>=))


		.def("__add__", py::overload_cast<const MyString&>(&MyString::operator+))
		.def("__add__", py::overload_cast<const char*>(&MyString::operator+))
		.def("__add__", py::overload_cast<string&>(&MyString::operator+))
		.def("__add__", py::overload_cast<char>(&MyString::operator+))

		.def("__iadd__", py::overload_cast<const MyString&>(&MyString::operator+=))
		.def("__iadd__", py::overload_cast<const char*>(&MyString::operator+=))
		.def("__iadd__", py::overload_cast<string&>(&MyString::operator+=))
		.def("__iadd__", py::overload_cast<char>(&MyString::operator+=));
};