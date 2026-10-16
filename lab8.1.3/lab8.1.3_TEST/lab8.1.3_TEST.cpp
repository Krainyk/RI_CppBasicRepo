#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab8.1.3/Functionschar.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab813TEST
{
	TEST_CLASS(lab813TEST)
	{
	public:
		
		TEST_METHOD(Test_ChangeStd)
		{
			char s1[100] = "aaaabgj";
			ChangeStd(s1);
			Assert::AreEqual("**bgj", s1);

			char s2[100] = "fjfiekkkkl";
			ChangeStd(s2);
			Assert::AreEqual("fjfie**l", s2);

			char s3[100] = "fdewwwwkkkl";
			ChangeStd(s3);
			Assert::AreEqual("fde**kkkl", s3);

			char s4[100] = "ekfekoooofqr";
			ChangeStd(s4);
			Assert::AreEqual("ekfek**fqr", s4);
		}
	};
}
