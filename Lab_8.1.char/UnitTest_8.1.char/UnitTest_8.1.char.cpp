#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1.char/Lab_8.1.char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:


		TEST_METHOD(TestMethod1)
		{
			char str[] = "abcaabbccdef";
			char* result = Change(str);
			Assert::AreEqual("abcaabbccdef", result);
			delete[] result;
		}
	};
}
