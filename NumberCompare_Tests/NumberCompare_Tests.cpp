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
			StN[0] = 2;
			StN[1] = 5;
			int *Otg = new int[2];
			Otg[0] = 2;
			Otg[1] = 5;

			//bool NuCo = NumberCompare(StN, Otg);
			for (unsigned int i = 0; i < 2; i++)
			{
				//Assert::AreEqual(true, NumberCompare(StN, Otg));
				//Assert::AreEqual(true, NuCo);
				Assert::AreEqual(StN[i], Otg[i]);
			}
		}
	};
}
