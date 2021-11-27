#include "pch.h"
#include "CppUnitTest.h"
#include "..\\algo\DoublyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestList
{
	TEST_CLASS(UnitTestList)
	{
		TEST_METHOD(GetSize_test) {
			List list;
			Assert::IsTrue(list.GetSize() == 0);
			list.push_back(0);
			Assert::IsTrue(list.GetSize() == 1);
			for (int i = 0; i < 10; i++)
				list.push_back(i);

			Assert::IsTrue(list.GetSize() == 11);


			for (int i = 0; i < 8; i++)
				list.pop_front();
			Assert::IsTrue(list.GetSize() == 3);

			list.insert(9, 1);
			Assert::IsTrue(list.GetSize() == 4);
		}

		TEST_METHOD(push_front_test) {
			List list;
			list.push_front(3);
			Assert::IsTrue(list.GetSize() == 1);
			list.push_front(2);
			Assert::IsTrue(list.GetSize() == 2);
			list.push_front(1);
			Assert::IsTrue(list.GetSize() == 3);
			list.push_front(0);
			Assert::IsTrue(list.GetSize() == 4);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
		}

		TEST_METHOD(push_back_test) {
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
			Assert::IsTrue(list.at(4) == 4);
			Assert::IsTrue(list.at(5) == 5);

			List list1;
			list1.push_back(6);
			list1.push_back(7);
			list1.push_back(8);
			list.push_back(list1);
			Assert::IsTrue(list.GetSize() == 9);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
			Assert::IsTrue(list.at(4) == 4);
			Assert::IsTrue(list.at(5) == 5);
			Assert::IsTrue(list.at(6) == 6);
			Assert::IsTrue(list.at(7) == 7);
			Assert::IsTrue(list.at(8) == 8);
		}

		TEST_METHOD(pop_back_test) {
			List list;
			Assert::IsTrue(list.isEmpty() == 1);
			try {
				list.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
			list.push_back(0);
			list.push_back(1);
			list.push_back(2);
			Assert::IsTrue(list.GetSize() == 3);
			list.pop_back();
			Assert::IsTrue(list.GetSize() == 2);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			list.pop_back();
			Assert::IsTrue(list.GetSize() == 1);
			list.pop_back();
			Assert::IsTrue(list.GetSize() == 0);
		}

		TEST_METHOD(pop_front_test) {
			List list;
			Assert::IsTrue(list.isEmpty() == 1);
			try {
				list.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
			list.push_back(0);
			list.push_back(1);
			list.push_back(2);
			Assert::IsTrue(list.GetSize() == 3);
			list.pop_front();
			Assert::IsTrue(list.GetSize() == 2);
			Assert::IsTrue(list.at(0) == 1);
			Assert::IsTrue(list.at(1) == 2);
			list.pop_front();
			Assert::IsTrue(list.GetSize() == 1);
			list.pop_front();
			Assert::IsTrue(list.GetSize() == 0);
		}

		TEST_METHOD(insert_test)
		{
			List list;

			list.push_back(0);
			list.push_back(1);
			list.push_back(2);

			list.insert(4, 0);
			Assert::IsTrue(list.GetSize() == 4);
			Assert::IsTrue(list.at(0) == 4);
			Assert::IsTrue(list.at(1) == 0);
			Assert::IsTrue(list.at(2) == 1);
			Assert::IsTrue(list.at(3) == 2);

			list.insert(7, 2);
			Assert::IsTrue(list.GetSize() == 5);
			Assert::IsTrue(list.at(0) == 4);
			Assert::IsTrue(list.at(1) == 0);
			Assert::IsTrue(list.at(2) == 7);
			Assert::IsTrue(list.at(3) == 1);
			Assert::IsTrue(list.at(4) == 2);

			list.insert(9, 5);
			Assert::IsTrue(list.GetSize() == 6);
			Assert::IsTrue(list.at(0) == 4);
			Assert::IsTrue(list.at(1) == 0);
			Assert::IsTrue(list.at(2) == 7);
			Assert::IsTrue(list.at(3) == 1);
			Assert::IsTrue(list.at(4) == 2);
			Assert::IsTrue(list.at(5) == 9);

			try {
				list.insert(5, 10);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}

			try {
				list.insert(5, -1);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
		}

		TEST_METHOD(remove_test)
		{
			List list;
			list.push_back(0);
			list.push_back(1);
			list.push_back(2);

			try {
				list.remove(-1);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}

			try {
				list.remove(3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}

			list.remove(1);
			Assert::IsTrue(list.GetSize() == 2);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 2);

			list.remove(0);
			Assert::IsTrue(list.GetSize() == 1);
			Assert::IsTrue(list.at(0) == 2);
		}

		TEST_METHOD(setTest) {
			List list;
			list.push_back(6);
			list.push_back(7);
			Assert::IsTrue(list.GetSize() == 2);
			try {
				list.set(10, -1);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}

			try {
				list.set(20, 2);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
			list.set(10, 0);
			Assert::IsTrue(list.GetSize() == 2);
			Assert::IsTrue(list.at(0) == 10);
			Assert::IsTrue(list.at(1) == 7);
			list.set(20, 1);
			Assert::IsTrue(list.GetSize() == 2);
			Assert::IsTrue(list.at(0) == 10);
			Assert::IsTrue(list.at(1) == 20);
		}

		TEST_METHOD(isEmpty_test) {
			List list1;
			list1.push_back(9);
			Assert::IsTrue(!list1.isEmpty());
			list1.pop_front();
			Assert::IsTrue(list1.isEmpty());

			List list2;
			Assert::IsTrue(list2.isEmpty());
		}

		TEST_METHOD(at_test) {
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			Assert::IsTrue(list.at(0) == 0);
			Assert::IsTrue(list.at(1) == 1);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(3) == 3);
			Assert::IsTrue(list.at(4) == 4);
			Assert::IsTrue(list.at(5) == 5);
		}

		TEST_METHOD(clear_test) {
			List list;
			for (int i = 0; i < 3; i++)
				list.push_back(i);
			Assert::IsFalse(list.isEmpty());
			list.clear();
			Assert::IsTrue(list.isEmpty());
		}

	};
}
