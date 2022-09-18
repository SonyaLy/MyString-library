import pybind11
from distutils.core import setup, Extension

ext_modules = [
    Extension(
        'mystring', # название либы
        ['string.cpp', 'main.cpp'], # файлики которые компилируем
        include_dirs=[pybind11.get_include()],  #инклюды pybind11
        language='c++',
        extra_compile_args=['-std=c++98'],
    ),
]

setup(
    name='mystring',
    version='0.0.1',
    author='user',
    author_email='user@user.ru',
    description='pybind11 extension',
    ext_modules=ext_modules,
    requires=['pybind11']  #зависимость от pybind11
)