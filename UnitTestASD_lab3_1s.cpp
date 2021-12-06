#include "pch.h"
#include "CppUnitTest.h"
#include "../tree_project/tree.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace treeunittest
{
	TEST_CLASS(treeunittest)
	{
	public:

		TEST_METHOD(insert_test_dft)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			base_iterator it = t.create_dft_iterator();

			string expected_result = "2513120171621263031";

			string result;
			while (!it.is_last())
			{
				result += to_string(*it);
				++it;
			}

			Assert::AreEqual(expected_result, result);
		}

		TEST_METHOD(insert_test_bft)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			base_iterator it = t.create_bft_iterator();

			string expected_result = "2513261203017213116";

			string result;
			while (!it.is_last())
			{
				result += to_string(*it);
				++it;
			}

			Assert::AreEqual(expected_result, result);
		}

		TEST_METHOD(contains_test_true)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			base_iterator it = t.create_dft_iterator();

			bool result = true;
			while (result != false && it.is_last() != false)
			{
				result = t.contains(*it);
				++it;
			}

			Assert::AreEqual(true, result);
		}

		TEST_METHOD(contains_test_false)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			bool result = false;
			for (int i = 100; i < 123; ++i)
			{
				result = t.contains(i);
				if (result == true) break;
			}


			Assert::AreEqual(false, result);
		}

		TEST_METHOD(contains_test_empty)
		{
			tree t;

			bool result = false;
			for (int i = 0; i < 123; ++i)
			{
				result = t.contains(i);
				if (result == true) break;
			}

			Assert::AreEqual(false, result);
		}

		TEST_METHOD(remove_test_first)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			t.remove(25);

			base_iterator it = t.create_dft_iterator();

			string expected_result = "26131201716213031";

			string result;
			while (!it.is_last())
			{
				result += to_string(*it);
				++it;
			}

			Assert::AreEqual(expected_result, result);
		}

		TEST_METHOD(remove_test_last)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			t.remove(16);

			base_iterator it = t.create_dft_iterator();

			std::string expected_result = "25131201721263031";

			std::string result;
			while (!it.is_last())
			{
				result += to_string(*it);
				++it;
			}

			Assert::AreEqual(expected_result, result);
		}

		TEST_METHOD(remove_test_middle)
		{
			tree t;
			t.insert(25);
			t.insert(13);
			t.insert(1);
			t.insert(20);
			t.insert(17);
			t.insert(16);
			t.insert(21);
			t.insert(26);
			t.insert(30);
			t.insert(31);

			t.remove(20);

			base_iterator it = t.create_dft_iterator();

			string expected_result = "25131211716263031";

			string result;
			while (!it.is_last())
			{
				result += to_string(*it);
				++it;
			}

			Assert::AreEqual(expected_result, result);
		}
	};
}
