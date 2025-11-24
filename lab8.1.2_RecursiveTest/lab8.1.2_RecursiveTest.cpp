#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab8.1.2/RecursiveFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab812RecursiveTest
{
	TEST_CLASS(lab812RecursiveTest)
	{
	public:
		
		TEST_METHOD(Test_ChangeRec)
		{
			char s1[100] = "aaaabgj";
			ChangeRec(s1);
			Assert::AreEqual("**bgj", s1);

			char s2[100] = "fjfiekkkkl";
			ChangeRec(s2);
			Assert::AreEqual("fjfie**l", s2);

			char s3[100] = "fdewwwwkkkl";
			ChangeRec(s3);
			Assert::AreEqual("fde**kkkl", s3);

			char s4[100] = "ekfekoooofqr";
			ChangeRec(s4);
			Assert::AreEqual("ekfek**fqr", s4);
		}
	};
}
