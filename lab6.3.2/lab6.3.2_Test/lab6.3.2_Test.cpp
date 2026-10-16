#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.3.2/RecursiveFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab632Test
{
	TEST_CLASS(lab632Test)
	{
	public:
		
		TEST_METHOD(TestSum)
		{
			const int n = 10;
			int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			int expectedSum = 25;
			int actualSum = Sum(a, n);
			Assert::AreEqual(expectedSum, actualSum);
		}
	};
}
