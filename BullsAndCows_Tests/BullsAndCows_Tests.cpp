#include "pch.h"
#include "CppUnitTest.h"
#include "../MasterMind_v2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BullsAndCowsTests
{
	TEST_CLASS(BullsAndCowsTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int* StN = new int[4];
			StN[0] = 1;
			StN[1] = 2;
			StN[2] = 3;
			StN[3] = 4;
			int* Otg = new int[4];
			Otg[0] = 2;
			Otg[1] = 1;
			Otg[2] = 3;
			Otg[3] = 4;

			int CountAnswer = BullsAnd—ows(StN, Otg, 4);

			Assert::AreEqual(4, CountAnswer);
		}

		TEST_METHOD(TestMethod2)
		{
			int* StN = new int[3];
			StN[0] = 7;
			StN[1] = 5;
			StN[2] = 1;
			int* Otg = new int[3];
			Otg[0] = 7;
			Otg[1] = 0;
			Otg[2] = 5;

			int CountAnswer = BullsAnd—ows(StN, Otg, 3);

			Assert::AreEqual(2, CountAnswer);
		}

		TEST_METHOD(TestMethod3)
		{
			int* StN = new int[8];
			StN[0] = 1;
			StN[1] = 2;
			StN[2] = 3;
			StN[3] = 4;
			StN[4] = 5;
			StN[5] = 6;
			StN[6] = 7;
			StN[7] = 8;
			int* Otg = new int[8];
			Otg[0] = 2;
			Otg[1] = 1;
			Otg[2] = 5;
			Otg[3] = 9;
			Otg[4] = 4;
			Otg[5] = 0;
			Otg[6] = 7;
			Otg[7] = 3;

			int CountAnswer = BullsAnd—ows(StN, Otg, 8);

			Assert::AreEqual(6, CountAnswer);
		}

		TEST_METHOD(TestMethod4)
		{
			int* StN = new int[5];
			StN[0] = 0;
			StN[1] = 2;
			StN[2] = 3;
			StN[3] = 4;
			StN[4] = 5;
			int* Otg = new int[5];
			Otg[0] = 2;
			Otg[1] = 1;
			Otg[2] = 5;
			Otg[3] = 9;
			Otg[4] = 4;

			int CountAnswer = BullsAnd—ows(StN, Otg, 5);

			Assert::AreEqual(3, CountAnswer);
		}
	};
}
