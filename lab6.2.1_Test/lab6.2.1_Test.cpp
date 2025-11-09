#include "pch.h"
#include "CppUnitTest.h"
#include "../lab6.2.1/IterativeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab621Test
{
	TEST_CLASS(lab621Test)
	{
	public:
		
		TEST_METHOD(TestSumOddIndices_BasicCase) {
			vector<int> testArray = { 5, 2, 7, 8, 1, 4, -3 };
			int expectedSum = 12;

			int actualSum = calculateSumOddIndices(testArray);

			Assert::AreEqual(expectedSum, actualSum);
		}
	};
}
