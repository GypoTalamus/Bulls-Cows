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
			StN[1] = 4;
			int *Otg = new int[2];
			Otg[0] = 3;
			Otg[1] = 5;
			/*if (NumberCompare(StN, Otg))
			{
				cout << "Вы угадали число!" << endl;
				return;
			}*/

			bool NuCo = NumberCompare(StN, Otg);

			Assert::AreEqual(true, NuCo);
		}
	};
}
