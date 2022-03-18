#include "pch.h"
#include "CppUnitTest.h"
#include "../MasterMind_v2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NumberCompareTests
{
	TEST_CLASS(NumberCompareTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int *StN = new int[2];
			StN[0] = 3;
			StN[1] = 5;
			int *Otg = new int[2];
			Otg[0] = 8;
			Otg[1] = 5;

			bool NuCo = NumberCompare(StN, Otg, 2);
			Assert::AreEqual(false, NuCo);
		}

		TEST_METHOD(TestMethod2)
		{
			int* StN = new int[3];
			StN[0] = 12;
			StN[1] = 15;
			StN[2] = 4;
			int* Otg = new int[3];
			Otg[0] = 12;
			Otg[1] = 15;
			Otg[2] = 4;

			bool NuCo = NumberCompare(StN, Otg, 3);
			Assert::AreEqual(true, NuCo);

		}

		TEST_METHOD(TestMethod3)
		{
			int* StN = new int[4];
			StN[0] = 6;
			StN[1] = 2;
			StN[2] = 4;
			StN[3] = 7;
			int* Otg = new int[4];
			Otg[0] = 12;
			Otg[1] = 1;
			Otg[2] = 0;

			bool NuCo = NumberCompare(StN, Otg, 4);
			Assert::AreEqual(false, NuCo);

		}
	};
}
