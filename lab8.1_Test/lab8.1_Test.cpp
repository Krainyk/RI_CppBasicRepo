#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab8.1.1/IterativeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab81Test
{
	TEST_CLASS(lab81Test)
	{
	public:
		
		TEST_METHOD(Test_Change)
		{
			char s1[100] = "aaaabgj";
			Change(s1);
			Assert::AreEqual("**bgj", s1);
		}
	};
}
