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
			int Nq = 5;
			int Nm = 10;   // не больше 15 !
			int *qNumber = new int[15];   // Результат
			GenSetN(Nq, Nm, qNumber);
			for (int i = 0; i < Nq; i++)
				cout << qNumber[i];
			return;
		}
	};
}
