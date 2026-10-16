#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab7.1/IterativeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab71Test
{
	TEST_CLASS(lab71Test)
	{
	public:
		
		TEST_METHOD(Test_Create)
		{
			int rowCount = 7;
			int colCount = 5;
			int Low = -6;
			int High = 31;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				a[i] = new int[colCount];
			}

			Create(a, rowCount, colCount, Low, High);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
				}
			}
			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;

		}

		TEST_METHOD(Test_Change)
		{
			int rowCount = 2, colCount = 5;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) a[i] = new int[colCount];

			int val0[5] = { -3, 4, 27, 6, 20 };
			int val1[5] = { 17, -6, 14, 20, 25 };
			for (int j = 0; j < colCount; j++) { a[0][j] = val0[j]; a[1][j] = val1[j]; }
		    
			Change(a, 0, 1, colCount);

			for (int j = 0; j < colCount; j++) {
				Assert::AreEqual(val1[j], a[0][j]);
				Assert::AreEqual(val0[j], a[1][j]);

			}

			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}

		TEST_METHOD(Test_Calc)
		{
			int rowCount = 7, colCount = 5;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) a[i] = new int[colCount];

			int val[7][5] = {
				{-3, 4, 27, 6, 20},
				{17, -6, 14, 20, 25},
				{28, 16, 7, 8, 21},
				{11, 4, 1, 17, 6},
				{3, 10, 14, 24, 28},
				{14, 6, 22, -1, 30},
				{15, 4, 7, 29, 3}
			};
			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					a[i][j] = val[i][j];

			int S = 0, k = 0;
			Calc(a, rowCount, colCount, S, k);

			Assert::AreEqual(134, S);
			Assert::AreEqual(9, k);

			for (int i = 0; i < rowCount; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
