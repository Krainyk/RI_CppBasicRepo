#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab7.3/IterativeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab72Tets
{
	TEST_CLASS(lab72Tets)
	{
	public:
		
		TEST_METHOD(Test_SmoothMatrixIter)
		{
            int n = 3;
            int** a = new int* [n];
            int** b = new int* [n];

            int sample[3][3] = { {-2,-6,-6}, {-8,-8,-12}, {-14,-16,-18} };
            int expected[3][3] = { {-6,-7,-8}, {-9,-10,-11}, {-11,-12,-13} }; // приклад очікуваного середнього

            // Виділення пам'яті та копіювання
            for (int i = 0; i < n; i++) {
                a[i] = new int[n];
                b[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    a[i][j] = sample[i][j];
                }
            }

            SmoothMatrix(a, b, n);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    Assert::AreEqual(expected[i][j], b[i][j]);

            // Звільнення пам'яті
            for (int i = 0; i < n; i++) {
                delete[] a[i];
                delete[] b[i];
            }
            delete[] a;
            delete[] b;
        }

        TEST_METHOD(Test_SumBelowDiagonal)
        {
            int n = 3;
            int** b = new int* [n];
            int sample[3][3] = { {-1,-2,-3}, {-4,-5,-6}, {-7,-8,-9} };
            int expectedSum = 4 + 7 + 8; // елементи нижче діагоналі: b[1][0], b[2][0], b[2][1]

            // Виділення пам'яті та копіювання
            for (int i = 0; i < n; i++) {
                b[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    b[i][j] = sample[i][j];
                }
            }

            // Виклик тестованої функції
            int sum = SumBelowDiagonal(b, n);
            Assert::AreEqual(expectedSum, sum);

            // Звільнення пам'яті
            for (int i = 0; i < n; i++) {
                delete[] b[i];
            }
            delete[] b;
        }

	};
}
