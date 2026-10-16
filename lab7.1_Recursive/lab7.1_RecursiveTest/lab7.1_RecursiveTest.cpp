#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab7.1_Recursive/RecursiveFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab71RecursiveTest
{
	TEST_CLASS(lab71RecursiveTest)
	{
	public:
		
		TEST_METHOD(Test_SortRec)
		{
            int rowCount = 7, colCount = 5;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) a[i] = new int[colCount];

            int val[7][5] = {
                {16, 6, 25, 3, 8},
                {29, -3, 11, -4, 28},
                {19, 12, 31, 28, 28},
                {10, -4, 26, 1, 29},
                {28, -3, 16, 2, 8},
                {29, 1, 10, 30, -1},
                {20, 16, 17, -4, 10}
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = val[i][j];

            SortRec(a, rowCount, colCount);

            int expected[7][5] = {
                {10, -4, 26, 1, 29},
                {16, 6, 25, 3, 8},
                {19, 12, 31, 28, 28},
                {20, 16, 17, -4, 10},
                {28, -3, 16, 2, 8},
                {29, 1, 10, 30, -1},
                {29, -3, 11, -4, 28}
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    Assert::AreEqual(expected[i][j], a[i][j]);

            for (int i = 0; i < rowCount; i++) delete[] a[i];
            delete[] a;
		}

        TEST_METHOD(Test_CalcRec)
        {
            int rowCount = 7, colCount = 5;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) a[i] = new int[colCount];

            int val[7][5] = {
                {16, 6, 25, 3, 8},
                {29, -3, 11, -4, 28},
                {19, 12, 31, 28, 28},
                {10, -4, 26, 1, 29},
                {28, -3, 16, 2, 8},
                {29, 1, 10, 30, -1},
                {20, 16, 17, -4, 10}
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = val[i][j];

            int S = 0, k = 0;
            CalcRec(a, rowCount, colCount, S, k);

            Assert::AreEqual(102, S);
            Assert::AreEqual(6, k);

            for (int i = 0; i < rowCount; i++) delete[] a[i];
            delete[] a;
        }
	};
}
