#include "pch.h"
#include "CppUnitTest.h"
#include "../MasterMind_v2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenSetNTests
{
	TEST_CLASS(GenSetNTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int pTemp, step = 0, Level = 4;
			int* StN = new int[4];
			int Mas[4] = { 1,2,3,4 };
			while (step < Level)
			{
				pTemp = step+1;
				if (GenSetN(step, pTemp, StN))
					step++;
			}
			for (int i = 0; i < Level; i++)
			{
				Assert::AreEqual(Mas[i], StN[i]);
			}
			delete[] StN;
		}

		TEST_METHOD(TestMethod2)
		{
			int pTemp, step = 0, Level = 8;
			int* StN = new int[Level];
			int Mas[] = { 7,0,3,6,9,2,5,8 };
			while (step < Level)
			{
				pTemp = ((step*3)+7) % 10;
				if (GenSetN(step, pTemp, StN))
					step++;
			}
			for (int i = 0; i < Level; i++)
			{
				Assert::AreEqual(Mas[i], StN[i]);
			}
			delete[] StN;
		}
	};
}
