#include "pch.h"
#include "CppUnitTest.h"
#include "ArrayFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab61Test
{
	TEST_CLASS(ArrayFunctionsTests)
	{
	public:
		
		// Test for countPositive function
		TEST_METHOD(TestCountPositive)
		{
			int testArray[] = { 1, 3, -5, 0, 7, 8, -2, 11 };
			int size = 8;
			int expectedCount = 4; // Positive odd numbers are 1, 3, 7, 11

			int actualCount = countPositive(testArray, size);

			Assert::AreEqual(expectedCount, actualCount);
		}

		// Test for sumPositive function
		TEST_METHOD(TestSumPositive)
		{
			int testArray[] = { 1, 3, -5, 0, 7, 8, -2, 11 };
			int size = 8;
			int expectedSum = 22; // Sum of positive odd numbers: 1 + 3 + 7 + 11 = 22
			
			int actualSum = sumPositive(testArray, size);
			
			Assert::AreEqual(expectedSum, actualSum);
		}

		// Test for replaceWithzero function
		TEST_METHOD(TestReplaceWithZero) {
			int testArray[] = { 1, 3, -5, 0, 7, 8, -2, 11 };
			int size = 8;
			int expectedArray[] = { 0, 0, -5, 0, 0, 8, -2, 0 }; // Positive odd numbers replaced with zero

			replaceWithzero(testArray, size);

			for (int i = 0; i < size; i++) {
				Assert::AreEqual(expectedArray[i], testArray[i]);
			}
		}
	};
}
