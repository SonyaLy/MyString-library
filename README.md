# MyString-library (STRING CLASS)
## Course «OOP»

1.	Implement a class to represent a character string in C++. Should not use the STL library containers and algorithms. The basic class must follow next requirements:

•	Constructor() - default constructor, copy constructor, char array constructor, initializer list constructor, std::string constructor, init class with count characters of “char string”, init class with count of characters;

•	Destructor();

•	Operator +() - concatenate with Mystring, char array, std::string;

•	Operator +=() - assignment concatenate with char array, std::string;

•	Operator=() - char string assignment, std::string assignment, char assignment;

•	Opearator[] – index operator;

•	Operator>(), Operator<(), Operator>=(), Operator<=(), Operator!=(), Operator==() - lexicographically comparing;

•	c_str() - return a pointer to null-terminated character array;

•	data()	 - return a pointer to array data that not required to be null-terminated;

•	length() 	- same as size;

•	size() - return the number of char elements in string;

•	empty() - true if string is empty;

•	capacity() - return the current amount of allocated memory for array;

•	shrink_to_fit() - reduce the capacity to size;

•	clear() - remove all char element in string;

•	Operator<<(std::basic_ostream), Operator>>(std::basic_istream);

•	insert(); erase(); append(); replace(); substr(); find().

2.	Extend python interpreter functionality with implemented class
3.	Additional task: Implement unit tests for created class. Each implemented method should be covered by 2-3 test cases.
