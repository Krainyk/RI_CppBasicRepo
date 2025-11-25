#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab8.2/Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab82TEST
{
	TEST_CLASS(lab82TEST)
	{
	public:
		
		TEST_METHOD(Test_countWords)
		{
			char s1[256] = "househ";
			int result = countWords(s1);
			Assert::AreEqual(1, result);

			char s2[256] = "househ girjrg";
			result = countWords(s2);
			Assert::AreEqual(2, result);

			char s3[256] = "househ girjrg feifhjeuif";
			result = countWords(s3);
			Assert::AreEqual(3, result);
		}
	};
}
