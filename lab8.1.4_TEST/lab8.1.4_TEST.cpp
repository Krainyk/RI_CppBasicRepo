	#include "pch.h"
	#include "CppUnitTest.h"
	#include "..//lab8.1.4/Functions.h"

	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace lab814TEST
	{
		TEST_CLASS(lab814TEST)
		{
		public:
		
			TEST_METHOD(Test_ChangeStr)
			{
				char s1[100] = "aaaabgj";
				ChangeStr(s1);
				Assert::AreEqual(std::string("**bgj"), std::string(s1));

				char s2[100] = "fjfiekkkkl";
				ChangeStr(s2);
				Assert::AreEqual(std::string("fjfie**l"), std::string(s2));

				char s3[100] = "fdewwwwkkkl";
				ChangeStr(s3);
				Assert::AreEqual(std::string("fde**kkkl"), std::string(s3));

				char s4[100] = "ekfekoooofqr";
				ChangeStr(s4);
				Assert::AreEqual(std::string("ekfek**fqr"), std::string(s4));
			}
		};
	}