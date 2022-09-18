#include"string.h"


MyString::MyString()
{
	_size = 0;
	this->_capacity = change_capacity();
	this->_myString = new char[_capacity]();
}

MyString::MyString(const MyString& str)
{
	this->_size = str._size;
	this->_capacity = change_capacity();
	this->_myString = new char[this->_capacity]();
	copy_str(this->_myString, str._myString, this->_size);
}

MyString::MyString(const char* str)
{
	this->_size = size_char(str);
	this->_capacity = change_capacity();
	this->_myString = new char[this->_capacity]();
	copy_str(this->_myString, str, this->_size);
}

MyString::MyString(const initializer_list<char>& list)
{
	this->_size = list.size();
	this->_capacity = change_capacity();
	this->_myString = new char[this->_capacity]();

	int count = 0;
	for (auto& item : list)
	{
		this->_myString[count] = item;
		count++;
	}
}

MyString::MyString(string& str)
{
	this->_size = str.size();
	this->_capacity = change_capacity();
	this->_myString = new char[this->_capacity]();
	copy_str(this->_myString , &str[0], this->_size);
}

MyString::MyString(const char* str, size_t count)
{
	this->_size = count;
	this->_capacity = change_capacity();
	this->_myString = new char[this->_capacity]();
	copy_str(this->_myString, str, this->_size);
}

MyString::MyString(size_t count, char c)
{
	this->_size = count;
	this->_capacity = change_capacity();
	this->_myString = new char[this->_capacity]();

	for (int i = 0; i < this->_size; i++)
	{
		this->_myString[i] = c;
	}
}

MyString::MyString(const MyString& str, size_t index, size_t count)
{
	this->_size = count;
	this->_capacity = change_capacity();
	this->_myString = new char[this->_size]();
	copy_str(this->_myString, str._myString + index, this->_size);
}

MyString::~MyString()
{
	delete[] _myString;
}

////////////////////////////////////////////////////////////////////////////////////

MyString MyString::operator+ (const MyString& str)
{
	return *this + str._myString;
}

MyString MyString::operator+ (const char* str)
{
	MyString new_str(*this);
	new_str += str;
	return new_str;
}

MyString MyString::operator+ (string& str)
{
	return *this + &str[0];
}

MyString MyString::operator+ (char c)
{
	MyString new_str(1, c);
	return *this + new_str;
}

// +=

MyString MyString::operator+= (const MyString& str)
{
	return append(str);
}

MyString MyString::operator+= (const char* s)
{
	return append(s);
}

MyString MyString::operator+= (char c)
{
	char* new_str = &c;
	return append(new_str);
}

MyString MyString::operator+= (string& str)
{
	return append(str);
}

// =

MyString& MyString::operator= (const MyString& str)
{
	return *this = str._myString;
}

MyString& MyString::operator= (const char* str)
{
	this->_size = size_char(str);
	if (this->_size > this->_capacity)
	{
		delete this->_myString;
		this->_capacity = change_capacity();
		this->_myString = new char[this->_capacity]();
	}

	copy_str(this->_myString, str, this->_size);
	this->_myString[this->_size] = '\0';

	return *this;
}

MyString& MyString::operator= (string& str)
{
	return *this = &str[0];
}

MyString& MyString::operator= (char c)
{
	char* new_str = &c;
	return *this = new_str;
}

char MyString::operator[](int i)
{
	return this->_myString[i];
}

//////////////////////////////////////////////////

bool MyString::operator> (const MyString& str)
{
	return *this > str._myString;
}

bool MyString::operator> (const char* str)
{
	if (this->_size < size_char(str))
	{
		return false;
	}
	else if (this->_size == size_char(str))
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_myString[i] < str[i])
			{
				return false;
			}
			else if (this->_myString[i] > str[i])
			{
				return true;
			}
		}
		return false;
	}
}

bool MyString::operator> (string& str)
{
	return *this > &str[0];
}

////////

bool MyString::operator<(const MyString& str)
{
	return *this < str._myString;
}

bool MyString::operator< (const char* str)
{
	return !(*this == str) && !(*this > str);
}

bool MyString::operator< (string& str)
{
	return *this < &str[0];
}

////////

bool MyString::operator>= (const MyString& str)
{
	return *this >= str._myString;
}

bool MyString::operator>= (const char* str)
{
	return !(*this < str);
}

bool MyString::operator>= (string& str)
{
	return *this >= &str[0];
}

////////

bool MyString::operator<=(const MyString& str)
{
	return *this <= str._myString;
}

bool MyString::operator<= (const char* str)
{
	return !(*this > str);
}

bool MyString::operator<= (string& str)
{
	return *this <= &str[0];
}

////////

bool MyString::operator!= (const MyString& str)
{
	return *this != str._myString;
}

bool MyString::operator!= (const char* str)
{
	return !(*this == str);
}

bool MyString::operator!= (string& str)
{
	return *this != &str[0];
}

////////

bool MyString::operator==(const MyString& str)
{
	return *this == str._myString;
}

bool MyString::operator== (const char* str)
{
	if (this->_size == size_char(str))
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_myString[i] != str[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool MyString::operator== (string& str)
{
	return *this == &str[0];
}

////////////////////////////////////////////////////////////////////////////

char* MyString::c_str()
{
	return this->_myString;
}

char* MyString::data()
{
	return c_str();
}

int MyString::length()
{
	return this->_size;
}

int MyString::size()
{
	return length();
}

bool MyString::empty()
{
	return (this->_size == 0);
}

int MyString::capacity()
{
	return _capacity;
}

void MyString::shrink_to_fit()
{
	if (this->_capacity == this->_size)
	{
		return;
	}

	char* new_str;
	new_str = new char[this->_size]();

	copy_str(new_str, this->_myString, this->_size);
	delete this->_myString;

	this->_myString = new char[this->_size]();
	copy_str(this->_myString, new_str, this->_size);
	this->_capacity = this->_size;

	delete []new_str;
}

void MyString::clear()
{
	this->_size = 0;
	this->_myString[0] = '\0';
}

int MyString::change_capacity()
{
	return ((this->_size / 16) + 1) * 16 - 1;
}

void MyString::copy_str(char* str1, const char* str2, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		str1[i] = str2[i];
	}
}

size_t MyString::size_char(const char* str)
{
	size_t size_str = 0;
	while (str[size_str] != '\0')
	{
		size_str++;
	}
	return size_str;
}

////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out, MyString str)
{
	out.write(str._myString, str._size);
	return out;
}

istream& operator>>(istream& in, MyString str)
{
	in.read(str._myString, str._size);
	return in;
}

////////////////////////////////////////////////////////////////////////////

MyString& MyString::insert(size_t index, const MyString& str)
{
	return this->insert(index, str._myString);
}

MyString& MyString::insert(size_t index, size_t count, char c)
{
	char* new_str = new char[count];
	for (int i = 0; i < count; i++)
	{
		new_str[i] = c;
	}
	new_str[count] = '\0';
	return this->insert(index, new_str);
}

MyString& MyString::insert(size_t index, const char* str)
{
	size_t size_str = size_char(str);
	if (this->_size + size_str <= this->_capacity)
	{
		copy_str(this->_myString + index + size_str, this->_myString + index, this->_size - index);
		copy_str(this->_myString + index, str, size_str);

		this->_size += size_str;
	}
	else
	{
		char* new_str = new char[this->_size + size_str];

		copy_str(new_str, this->_myString, index);
		copy_str(new_str + index, str, size_str);
		copy_str(new_str + index + size_str, this->_myString + index, this->_size - index);

		this->_size += size_str;
		this->_capacity = change_capacity();
		delete this->_myString;
		this->_myString = new char[this->_capacity]();

		copy_str(this->_myString, new_str, this->_size);
		delete[] new_str;
	}
	return *this;
}

MyString& MyString::insert(size_t index, const char* str, size_t count)
{
	char* new_str = new char[count];
	copy_str(new_str, str, count);
	new_str[count] = '\0';
	return this->insert(index, new_str);
}

MyString& MyString::insert(size_t index, string str)
{
	return this->insert(index, &str[0]);
}

MyString& MyString::insert(size_t index, string str, size_t count)
{
	return this->insert(index, &str[0], count);
}

////////////////////////////////////////////////////////////////////////////

MyString& MyString::erase(size_t index, size_t count)
{
	copy_str(this->_myString + index, this->_myString + index + count, this->_size - index - count);
	this->_size = this->_size - count;
	return *this;
}

////////////////////////////////////////////////////////////////////////////


MyString& MyString::append(const MyString& str, size_t index, size_t count)
{
	return this->append(str._myString, index, count);
}

MyString& MyString::append(const MyString& str)
{
	return this->append(str._myString, 0, str._size);
}

MyString& MyString::append(size_t count, char c)
{
	char* new_str = new char[count];
	for (int i = 0; i < count; i++)
	{
		new_str[i] = c;
	}
	new_str[count] = '\0';
	return this->append(new_str);
}

MyString& MyString::append(const char* str)
{
	return this->append(str, 0, size_char(str));
}

MyString& MyString::append(const char* str, size_t index, size_t count)
{
	if (this->_size + count <= this->_capacity)
	{
		copy_str(this->_myString + this->_size, str + index, count);
		this->_size += count;
	}
	else
	{
		char* new_str;
		new_str = new char[this->_size + count]();

		copy_str(new_str, this->_myString, this->_size);
		copy_str(new_str + this->_size, str + index, count);
		delete this->_myString;

		this->_size = this->_size + count;
		this->_capacity = change_capacity();
		this->_myString = new char[this->_capacity]();

		copy_str(this->_myString, new_str, this->_size);
		delete[]new_str;
	}
	return *this;
}

MyString& MyString::append(string& str)
{
	return this->append(&str[0]);
}

MyString& MyString::append(string& str, size_t index, size_t count)
{
	return this->append(&str[0], index, count);
}

////////////////////////////////////////////////////////////////////////////

MyString& MyString::replace(size_t index, size_t count, const MyString& str)
{
	return this->replace(index, count, str._myString);
}

MyString& MyString::replace(size_t index, size_t count, const char* str)
{
	size_t size = size_char(str);
	if (index + count <= this->_size)
	{
		if (this->_size + (size - count) < this->_capacity)
		{
			char* p; //after the change word
			p = new char[this->_size - index - count]();

			copy_str(p, this->_myString + index + count, this->_size - index - count);
			copy_str(this->_myString + index, str, size);
			copy_str(this->_myString + index + size, p, this->_size - index - count);

			this->_size = this->_size + size - count;
			delete[]p;
		}
		else
		{
			char* p1, * p2;
			p1 = new char[index](); //befor word
			p2 = new char[this->_size - index - count](); //after word

			copy_str(p1, this->_myString, index);
			copy_str(p2, this->_myString + index + count, this->_size - index - count);
			delete this->_myString;

			this->_size = this->_size + size - count;
			this->_capacity = change_capacity();
			this->_myString = new char[this->_capacity]();

			copy_str(this->_myString, p1, index);
			copy_str(this->_myString + index, str, size);
			copy_str(this->_myString + index + size, p2, this->_size - index - count);

			delete[]p1, p2;
		}
	}
	else
	{
		if (this->_size + (size - count) < this->_capacity)
		{
			this->_size = index + size;
			copy_str(this->_myString + index, str, size);
		}
		else
		{
			char* p1;
			p1 = new char[index]();

			copy_str(p1, this->_myString, index);
			delete this->_myString;

			this->_size = index + size;
			this->_capacity = change_capacity();
			this->_myString = new char[this->_capacity]();

			copy_str(this->_myString, p1, index);
			copy_str(this->_myString + index, str, size);

			delete[]p1;
		}
	}
	return *this;
}

MyString& MyString::replace(size_t index, size_t count, string str)
{
	return this->replace(index, count, &str[0]);
}

////////////////////////////////////////////////////////////////////////////////

MyString MyString::substr(size_t index)
{
	return this->substr(index, this->_size - index);
}

MyString MyString::substr(size_t index, size_t count)
{
	MyString str(this->_myString + index , count);
	return str;
}

////////////////////////////////////////////////////////////////////////////////

int MyString::find(const MyString& str)
{
	return this->find(str._myString, 0);
}

int MyString::find(const MyString& str, size_t index)
{
	return this->find(str._myString, index);
}

int MyString::find(const char* str)
{
	return this->find(str, 0);
}

int MyString::find(const char* str, size_t index)
{
	size_t size = size_char(str);
	for (int i = index; i < this->_size - size; i++)
	{
		MyString p(*this, i, size);
		if (p == str)
		{
			return i;
		}
	}
	return -1;
}

int MyString::find(string& str)
{
	return this->find(&str[0], 0);
}

int MyString::find(string& str, size_t index)
{
	return this->find(&str[0], index);
}