#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab7.2/IterativeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab72Test
{
	TEST_CLASS(lab72Test)
	{
	public:
		
		TEST_METHOD(Test_SearchMaxOfMinOddRows)
		{
			const int n = 4;
			
			int** a = new int* [n];
			for (int i = 0; i < n; i++) {
				a[i] = new int[n];
			}

			int data[4][4] = {
				{16, 6, 25, 3},
				{8, 29, -3, 11},
				{-4, 28, 19, 12},
				{31, 28, 28, 10}
			};

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = data[i][j];
				}
			}
			int result;
			bool found = SearchMaxOfMinOddRows(a, n, result);

			Assert::IsTrue(found);
			Assert::AreEqual(10, result);

			for (int i = 0; i < n; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
