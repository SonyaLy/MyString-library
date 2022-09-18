#include "CppUnitTest.h"
#include "..\class_string\string.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			initializer_list<char> list = { 'l', 'i', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g' };
			string string_1 = "second string";
			const char* char_string = "char string";
			
			MyString str_1, 
				str_2("first message"), 
				str_3(list), 
				str_4(string_1), 
				str_5(char_string, 4), 
				str_6(5, 'a'),
				str_copy(str_2);

			Assert::AreEqual(str_1.c_str(), "", "Constructor () - uncorrect");
			Assert::IsTrue(str_1.size() == 0, L"Constructor () - uncorrect");

			Assert::AreEqual(str_2.c_str(), "first message", "Constructor (char) - uncorrect");
			Assert::IsTrue(str_2.size() == 13, L"Constructor (char) - uncorrect");

			Assert::AreEqual(str_3.c_str(), "list string", "Constructor (list) - uncorrect");
			Assert::IsTrue(str_3.size() == 11, L"Constructor (list) - uncorrect");
			
			Assert::AreEqual(str_4.c_str(), "second string", "Constructor (string) - uncorrect");
			Assert::IsTrue(str_4.size() == 13, L"Constructor (string) - uncorrect");

			Assert::AreEqual(str_4.c_str(), "second string", "Constructor (string) - uncorrect");
			Assert::IsTrue(str_4.size() == 13, L"Constructor (string) - uncorrect");

			Assert::AreEqual(str_5.c_str(), "char", "Constructor (“char string”, count) - uncorrect");
			Assert::IsTrue(str_5.size() == 4, L"Constructor (“char string”, count) - uncorrect");

			Assert::AreEqual(str_6.c_str(), "aaaaa", "Constructor (count, char) - uncorrect");
			Assert::IsTrue(str_6.size() == 5, L"Constructor (count, char) - uncorrect");

			Assert::IsTrue((str_copy == str_2), L"Constructor (copy) - uncorrect");
		}
		TEST_METHOD(OperatorplusTest)
		{
			string string_1 = "second string";
			const char* char_string = "char string";

			MyString str_1("first message");
			MyString str_2("third message");

			MyString sum_string;
			sum_string = str_1 + " ";
			Assert::AreEqual(sum_string.c_str(), "first message ", "Operator +(“char string”)  - uncorrect");
			Assert::IsTrue(sum_string.size() == 14, L"Operator +(“char string”) - uncorrect");

			sum_string = sum_string + string_1 + " ";
			Assert::AreEqual(sum_string.c_str(), "first message second string ", "Operator +(std::string)  - uncorrect");
			Assert::IsTrue(sum_string.size() == 28, L"Operator +(std::string) - uncorrect");

			sum_string = sum_string + str_2;
			Assert::AreEqual(sum_string.c_str(), "first message second string third message", "Operator +(MyString)  - uncorrect");
			Assert::IsTrue(sum_string.size() == 41, L"Operator +(MyString) - uncorrect");

			Assert::IsTrue(string_1 == "second string");
			Assert::IsTrue(char_string == "char string");
			Assert::IsTrue(str_1 == "first message");
			Assert::IsTrue(str_2 == "third message");
			Assert::IsTrue(sum_string == "first message second string third message");
		}

		TEST_METHOD(OperatorplusequallyTest)
		{
			const char* char_string = "char string";
			string string_1 = "second string";
			initializer_list<char> list = { 'l', 'i', 's', 't', ' ', 's', 't', 'r', 'i', 'n', 'g' };

			MyString sum_string;
			sum_string += char_string;
			sum_string += " ";
			Assert::IsTrue(char_string == "char string");
			Assert::IsTrue(sum_string == "char string ");

			sum_string += string_1;
			sum_string += " ";
			Assert::IsTrue(string_1 == "second string");
			Assert::IsTrue(sum_string == "char string second string ");

			sum_string += list;
			Assert::AreEqual(sum_string.c_str(), "char string second string list string", "Operator +=() - uncorrect");
			Assert::IsTrue(sum_string.size() == 37, L"Operator +=() - uncorrect");
		}

		TEST_METHOD(OperatorassignmentTest)
		{
			MyString equally;
			MyString str_1("char string");
			MyString str_2("second string");
			MyString str_c("c");
			string string_1 = "second string";

			equally = "char string";
			Assert::IsTrue(equally == str_1, L"Operator =(“char string”) - uncorrect");
			equally = string_1;
			Assert::IsTrue(equally == str_2, L"Operator =(std::string) - uncorrect");
			equally = 'c';
			Assert::IsTrue(equally == str_c, L"Operator =(‘char’) - uncorrect");
		}

		TEST_METHOD(OperatorindexTest)
		{
			MyString str_1("char string");
			Assert::IsTrue(str_1[0] == 'c', L"Operator[] - uncorrect");
			Assert::IsTrue(str_1[12] == '\0', L"Operator[] - uncorrect");
		}

		TEST_METHOD(OperatorboolTest)
		{
			MyString first("stringa"), second("stringb");

			Assert::IsTrue(first < second, L"Operator <() - uncorrect");
			Assert::IsTrue(!(first > second), L"Operator >() - uncorrect");

			Assert::IsTrue(first != second, L"Operator !=() - uncorrect");
			Assert::IsTrue(!(first == second), L"Operator ==() - uncorrect");

			Assert::IsTrue(!(first >= second), L"Operator >=() - uncorrect");
			Assert::IsTrue(first <= second, L"Operator <=() - uncorrect");
		}

		TEST_METHOD(MethodsTest)
		{
			MyString str("first message");
			MyString str_empty;
			Assert::AreEqual(str.c_str(), "first message", "c_str() - uncorrect");
			Assert::IsTrue(str.size() == 13, L"size() - uncorrect");
			Assert::IsTrue(str.size() == str.length(), L"length() - uncorrect");
			Assert::IsTrue(str.c_str() == str.data(), L"data() - uncorrect");
			Assert::IsTrue(!(str.empty()), L"empty() - uncorrect");

			str.change_capacity();
			Assert::IsTrue(str.capacity() == 15, L"capacity() - uncorrect");
			str.shrink_to_fit();
			Assert::IsTrue(str.capacity() == 13, L"shrink_to_fit() - uncorrect");
			str.clear();
			Assert::IsTrue(str == str_empty, L"clear() - uncorrect");
		}

		TEST_METHOD(InsertTest)
		{
			MyString s("aaaaa");
			s.insert(0, 1, '!');
			s.insert(3, 2, '@');
			Assert::IsTrue(s == "!aa@@aaa", L"insert() - uncorrect");

			s = "aaaaa";
			s.insert(1, "@@@@@");
			Assert::IsTrue(s == "a@@@@@aaaa", L"insert() - uncorrect");

			s = "aaaaa";
			s.insert(1, "@@@@@", 2);
			Assert::IsTrue(s == "a@@aaaa", L"insert() - uncorrect");

			s = "aaaaa";
			s.insert(1, std::string("@@@@@"));
			Assert::IsTrue(s == "a@@@@@aaaa", L"insert() - uncorrect");

			s = "aaaaa";
			s.insert(1, std::string("@@@@@"), 2);
			Assert::IsTrue(s == "a@@aaaa", L"insert() - uncorrect");

			MyString ss("aaaaaaaaaaaaa");
			ss.insert(0, 1, '!');
			ss.insert(3, 2, '@');
			Assert::IsTrue(s == "!aaa@@aaaaaaaaaa", L"insert() - uncorrect");
		}

		TEST_METHOD(EraseTest)
		{
			MyString s("aa@@@@@aaa");
			s.erase(2, 3);
			Assert::IsTrue(s == "aa@@aaa", L"erase() - uncorrect");
		}

		TEST_METHOD(AppendTest)
		{
			MyString s;
			s.clear();
			s.append(3, '!');
			s.append(3, '@');
			Assert::IsTrue(s == "!!!@@@", L"append() - uncorrect");

			s.clear();
			s.append("hello ");
			s.append("world");
			Assert::IsTrue(s == "hello world", L"append() - uncorrect");

			s.clear();
			s.append("hello world", 0, 6);
			s.append("hello world", 6, 5);
			Assert::IsTrue(s == "hello world", L"append() - uncorrect");

			string str = "hello ";

			s.clear();
			s.append(str);
			str = "world";
			s.append(str);
			Assert::IsTrue(s == "hello world", L"append() - uncorrect");

			s.clear();
			str = "hello world";
			s.append(str, 0, 6);
			s.append(str, 6, 5);
			Assert::IsTrue(s == "hello world", L"append() - uncorrect");
		}

		TEST_METHOD(ReplaceTest)
		{
			MyString s;
			s = "hello amazing world";
			s.replace(6, 7, "wonderful");
			Assert::IsTrue(s == "hello wonderful world", L"replace() - uncorrect");

			s = "hello amazing world";
			s.replace(6, 7, std::string("wonderful"));
			Assert::IsTrue(s == "hello wonderful world", L"replace() - uncorrect");

			MyString sss = "hello amazing";
			sss.replace(6, 7, "wonderfulll");
			Assert::IsTrue(s == "hello wonderfulll", L"replace() - uncorrect");
		}

		TEST_METHOD(SubstrTest)
		{
			MyString s;
			s = "hello amazing world";
			s = s.substr(6);
			Assert::IsTrue(s == "amazing world", L"substr() - uncorrect");

			s = "hello amazing world";
			s = s.substr(6, 7);
			Assert::IsTrue(s == "amazing", L"substr() - uncorrect");
		}

		TEST_METHOD(FindTest)
		{
			MyString s;
			s = "hello amazing world";
			int find = s.find("amazing");
			Assert::IsTrue(find == 6, L"find() - uncorrect");

			find = s.find("o", 6);
			Assert::IsTrue(find == 15, L"find() - uncorrect");

			MyString str;
			str = "amazing";
			find = s.find(str);
			Assert::IsTrue(find == 6, L"find() - uncorrect");

			str = "o";
			find = s.find(str, 6);
			Assert::IsTrue(find == 15, L"find() - uncorrect");
		}
	};
}