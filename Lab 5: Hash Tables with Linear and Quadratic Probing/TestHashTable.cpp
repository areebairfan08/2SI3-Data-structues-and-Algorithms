#include "TestHashTable.h"
#include "HashTableLin.h"
#include "HashTableQuad.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <iterator>

TestHashTable::TestHashTable()
{
	this->gen.seed((unsigned int)std::time(nullptr));
}

TestHashTable::TestHashTable(int max_run, int max_key, vector<int> max_size_array)
{
	this->MAX_RUN = max_run;
	this->MAX_KEY = max_key;
	this->MAX_SIZE_ARRAY = max_size_array;
	this->gen.seed((unsigned int)std::time(nullptr));
}

void TestHashTable::testConstructorLin(double& total, double& full)
{
	/*
	Two main test cases for constructor linear (total 4 marks)
	1. no get methods
	2. get methods
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 1;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark };
	vector<string> mainCaseMsg = { "no get methods",
								   "get methods" };

	vector<TestType> mainCaseTestType = { TestType::CONSTRUCTOR_NOCHECK,
										  TestType::CONSTRUCTOR_CHECK };

	string msg;

	cout << "BEGIN TEST CONSTRUCTOR LINEAR" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "constructor linear with " + mainCaseMsg[mainIdx];
		result = testConstructorLin(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test constructor default PASS: ALL" << endl;
	}
	else {
		cerr << "Test constructor default FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST CONSTRUCTOR LINEAR, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testConstructorQuad(double& total, double& full)
{
	/*
	Two main test cases for constructor quadratic (total 4 marks)
	1. no get methods
	2. get methods
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 1;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark };
	vector<string> mainCaseMsg = { "no get methods",
								   "get methods" };

	vector<TestType> mainCaseTestType = { TestType::CONSTRUCTOR_NOCHECK,
										  TestType::CONSTRUCTOR_CHECK };

	string msg;

	cout << "BEGIN TEST CONSTRUCTOR QUADRATIC" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "constructor quadratic with " + mainCaseMsg[mainIdx];
		result = testConstructorQuad(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test constructor quadratic PASS: ALL" << endl;
	}
	else {
		cerr << "Test constructor quadratic FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST CONSTRUCTOR QUADRATIC, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testInsertLin(double& total, double& full)
{
	/*
	Five main test cases for insert linear (total 18 marks)
	(each test case tested without/with get methods)
	1) empty table
		i) no get methods
		ii) with get methods
	2) simple cases
		i) no get methods
		ii) with get methods
	3) duplicate keys
		i) no get methods
		ii) with get methods
	3) collision
		i) no get methods
		ii) with get methods
	5) rehash
		i) no get methods
		ii) with get methods
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_1_mark = 2;
	double case_1_2_mark = 1;
	double case_2_1_mark = 2;
	double case_2_2_mark = 1;
	double case_3_1_mark = 2;
	double case_3_2_mark = 1;
	double case_4_1_mark = 2;
	double case_4_2_mark = 1;
	double case_5_1_mark = 5;
	double case_5_2_mark = 1;
	double markSum = 0;

	vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark},
										 {case_2_1_mark,case_2_2_mark},
										 {case_3_1_mark,case_3_2_mark},
										 {case_4_1_mark,case_4_2_mark},
										 {case_5_1_mark,case_5_2_mark} };
	vector<string> mainCaseMsg = { "empty table",
								   "simple cases",
								   "duplicate keys",
								   "collision",
								   "rehash" };
	vector<string> subCaseMsg = { "no get methods",
								  "with get methods" };
	vector<TestType> mainCaseTestType = { TestType::INSERT_EMPTY,
										  TestType::INSERT_SIMPLE,
										  TestType::INSERT_DUPLICATE,
										  TestType::INSERT_COLLISION,
										  TestType::INSERT_REHASH };
	vector<TestType> subCaseTestType = { TestType::INSERT_WITH_NOCHECK,
										 TestType::INSERT_WITH_CHECK };
	string msg;

	cout << "BEGIN TEST INSERT LINEAR" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		for (size_t subIdx = 0; subIdx < subCaseTestType.size(); subIdx++) {
			markSum += caseMarks[mainIdx][subIdx];
			msg = "insert linear for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
			result = testInsertLin(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
			fails += (result == false);
			if (result == true) {
				totalMark += caseMarks[mainIdx][subIdx];
				cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
			else {
				cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
		}
	}

	if (fails == 0) {
		cout << "Test insert linear PASS: ALL" << endl;
	}
	else {
		cerr << "Test insert linear FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST INSERT LINEAR, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testInsertQuad(double& total, double& full)
{
	/*
	Five main test cases for insert quadratic (total 18 marks)
	(each test case tested without/with get methods)
	1) empty table
		i) no get methods
		ii) with get methods
	2) simple cases
		i) no get methods
		ii) with get methods
	3) duplicate keys
		i) no get methods
		ii) with get methods
	3) collision
		i) no get methods
		ii) with get methods
	5) rehash
		i) no get methods
		ii) with get methods
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_1_mark = 2;
	double case_1_2_mark = 1;
	double case_2_1_mark = 2;
	double case_2_2_mark = 1;
	double case_3_1_mark = 2;
	double case_3_2_mark = 1;
	double case_4_1_mark = 2;
	double case_4_2_mark = 1;
	double case_5_1_mark = 5;
	double case_5_2_mark = 1;
	double markSum = 0;

	vector<vector<double>> caseMarks = { {case_1_1_mark,case_1_2_mark},
										 {case_2_1_mark,case_2_2_mark},
										 {case_3_1_mark,case_3_2_mark},
										 {case_4_1_mark,case_4_2_mark},
										 {case_5_1_mark,case_5_2_mark} };
	vector<string> mainCaseMsg = { "empty table",
								   "simple cases",
								   "duplicate keys",
								   "collision",
								   "rehash" };
	vector<string> subCaseMsg = { "no get methods",
								  "with get methods" };
	vector<TestType> mainCaseTestType = { TestType::INSERT_EMPTY,
										  TestType::INSERT_SIMPLE,
										  TestType::INSERT_DUPLICATE,
										  TestType::INSERT_COLLISION,
										  TestType::INSERT_REHASH };
	vector<TestType> subCaseTestType = { TestType::INSERT_WITH_NOCHECK,
										 TestType::INSERT_WITH_CHECK };
	string msg;

	cout << "BEGIN TEST INSERT QUADRATIC" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		for (size_t subIdx = 0; subIdx < subCaseTestType.size(); subIdx++) {
			markSum += caseMarks[mainIdx][subIdx];
			msg = "insert quadratic for " + mainCaseMsg[mainIdx] + " and " + subCaseMsg[subIdx];
			result = testInsertQuad(sizes, maxRun, mainCaseTestType[mainIdx], subCaseTestType[subIdx], msg);
			fails += (result == false);
			if (result == true) {
				totalMark += caseMarks[mainIdx][subIdx];
				cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
			else {
				cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx][subIdx] << " ) " << endl;
			}
		}
	}

	if (fails == 0) {
		cout << "Test insert quadratic PASS: ALL" << endl;
	}
	else {
		cerr << "Test insert quadratic FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST INSERT QUADRATIC, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testIsInLin(double& total, double& full)
{
	/*
	Three main test cases for isIn linear (total 9 marks)
	1. empty table
	2. simple cases
	3. collision
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty table",
								   "simple cases",
								   "collision" };
	vector<TestType> mainCaseTestType = { TestType::ISIN_EMPTY,
										  TestType::ISIN_SIMPLE,
										  TestType::ISIN_COLLISION };

	string msg;

	cout << "BEGIN TEST ISIN LINEAR" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "isIn linear for " + mainCaseMsg[mainIdx];
		result = testIsInLin(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test isIn linear PASS: ALL" << endl;
	}
	else {
		cerr << "Test isIn linear FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST ISIN LINEAR, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testIsInQuad(double& total, double& full)
{
	/*
	Three main test cases for isIn quadratic (total 9 marks)
	1. empty table
	2. simple cases
	3. collision
	*/

	int fails = 0;
	int maxRun = MAX_RUN;
	vector<int> sizes = MAX_SIZE_ARRAY;
	bool result = false;

	double totalMark = 0;
	double case_1_mark = 3;
	double case_2_mark = 3;
	double case_3_mark = 3;
	double markSum = 0;

	vector<double> caseMarks = { case_1_mark, case_2_mark, case_3_mark };
	vector<string> mainCaseMsg = { "empty table",
								   "simple cases",
								   "collision" };
	vector<TestType> mainCaseTestType = { TestType::ISIN_EMPTY,
										  TestType::ISIN_SIMPLE,
										  TestType::ISIN_COLLISION };

	string msg;

	cout << "BEGIN TEST ISIN QUADRATIC" << endl;

	for (size_t mainIdx = 0; mainIdx < mainCaseTestType.size(); mainIdx++) {
		markSum += caseMarks[mainIdx];
		msg = "isIn quadratic for " + mainCaseMsg[mainIdx];
		result = testIsInQuad(sizes, maxRun, mainCaseTestType[mainIdx], msg);
		fails += (result == false);
		if (result == true) {
			totalMark += caseMarks[mainIdx];
			cout << "Test cases in " << msg << " success ( +" << caseMarks[mainIdx] << " ) " << endl;
		}
		else {
			cerr << "Test cases in " << msg << " fail ( -" << caseMarks[mainIdx] << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test isIn quadratic PASS: ALL" << endl;
	}
	else {
		cerr << "Test isIn quadratic FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST ISIN QUADRATIC, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testSimProbeSuccessLin(double& total, double& full)
{
	/*
	Linear probing simulations for successful search (total 9 marks)
	*/

	int fails = 0;
	double totalMark = 0;
	double case_mark = 1;
	double markSum = 0;
	vector<double> avgProbeGet;

	cout << "BEGIN TEST simProbeSuccess LINEAR" << endl;
	cout << "Test cases in simulation for successful linear probing:" << endl;

	try {
		avgProbeGet = HashTableLin::simProbeSuccess();
	}
	catch (const std::exception& e) {
		cerr << "Error in simProbeSuccess linear ->" << endl;
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Error in simProbeSuccess linear ->" << endl;
		cerr << "Unknown exception" << endl;
	}

	for (size_t i = 1; i <= 9; i++) {
		double loadFactor = 0.1 * i;
		double avgProbeExp = 0.5 * (1 + (1 / (1 - loadFactor))); // theoretical value
		markSum += case_mark;
		if (i <= avgProbeGet.size()) {
			if (abs(avgProbeGet[i - 1] - avgProbeExp) < 0.1 * avgProbeExp) {
				totalMark += case_mark;
				cout << "Load factor : " << loadFactor << ", Average # probes : " << avgProbeGet[i - 1] << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
				cout << "Load factor : " << loadFactor << " -> Test success(+" << case_mark << ") " << endl;
			}
			else {
				fails++;
				cerr << "Load Factor : " << loadFactor << ", Average # probes : " << avgProbeGet[i - 1] << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
				cerr << "Load factor : " << loadFactor << " -> Test fail ( -" << case_mark << " ) " << endl;
			}
		}
		else {
			fails++;
			cerr << "Load Factor : " << loadFactor << ", Average # probes : " << "N/A" << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
			cerr << "Load factor : " << loadFactor << " -> Test fail ( -" << case_mark << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test simProbeSuccess linear PASS: ALL" << endl;
	}
	else {
		cerr << "Test simProbeSuccess linear FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST simProbeSuccess LINEAR, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testSimProbeSuccessQuad(double& total, double& full)
{
	/*
	Quadratic probing simulations for successful search (total 9 marks)
	*/

	int fails = 0;
	double totalMark = 0;
	double case_mark = 1;
	double markSum = 0;
	vector<double> avgProbeGet;

	cout << "BEGIN TEST simProbeSuccess QUADRATIC" << endl;
	cout << "Test cases in simulation for successful quadratic probing:" << endl;

	try {
		avgProbeGet = HashTableQuad::simProbeSuccess();
	}
	catch (const std::exception& e) {
		cerr << "Error in simProbeSuccess quadratic ->" << endl;
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Error in simProbeSuccess quadratic ->" << endl;
		cerr << "Unknown exception" << endl;
	}

	for (size_t i = 1; i <= 9; i++) {
		double loadFactor = 0.1 * i;
		double avgProbeExp = (1 / loadFactor) * (log(1 / (1 - loadFactor))); // theoretical value
		markSum += case_mark;
		if (i <= avgProbeGet.size()) {
			if (abs(avgProbeGet[i - 1] - avgProbeExp) < 0.1 * avgProbeExp) {
				totalMark += case_mark;
				cout << "Load factor : " << loadFactor << ", Average # probes : " << avgProbeGet[i - 1] << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
				cout << "Load factor : " << loadFactor << " -> Test success(+" << case_mark << ") " << endl;
			}
			else {
				fails++;
				cerr << "Load Factor : " << loadFactor << ", Average # probes : " << avgProbeGet[i - 1] << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
				cerr << "Load factor : " << loadFactor << " -> Test fail ( -" << case_mark << " ) " << endl;
			}
		}
		else {
			fails++;
			cerr << "Load Factor : " << loadFactor << ", Average # probes : " << "N/A" << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
			cerr << "Load factor : " << loadFactor << " -> Test fail ( -" << case_mark << " ) " << endl;
		}
	}

	if (fails == 0) {
		cout << "Test simProbeSuccess quadratic PASS: ALL" << endl;
	}
	else {
		cerr << "Test simProbeSuccess quadratic FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST simProbeSuccess QUADRATIC, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

void TestHashTable::testSimProbeUnsuccessLinBonus(double& total, double& full)
{
	/*
	Linear probing simulations for unsuccessful search (total 10 marks)
	*/

	int fails = 0;
	double totalMark = 0;
	double case_mark = 1;
	double markSum = 1;
	vector<double> avgProbeGet;

	cout << "BEGIN TEST simProbeUnsuccess LINEAR BONUS" << endl;
	cout << "Test cases in simulation for unsuccessful linear probing:" << endl;

	try {
		avgProbeGet = HashTableLin::simProbeUnsuccess();
	}
	catch (const std::exception& e) {
		cerr << "Error in simProbeUnsuccess linear bonus ->" << endl;
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Error in simProbeUnsuccess linear bonus ->" << endl;
		cerr << "Unknown exception" << endl;
	}

	for (size_t i = 1; i <= 9; i++) {
		double loadFactor = 0.1 * i;
		double avgProbeExp = 0.5 * (1 + (1 / ((1 - loadFactor) * (1 - loadFactor)))); // theoretical value
		markSum += case_mark;
		if (i <= avgProbeGet.size()) {
			if (abs(avgProbeGet[i - 1] - avgProbeExp) < 0.1 * avgProbeExp) {
				totalMark += case_mark;
				cout << "Load factor : " << loadFactor << ", Average # probes : " << avgProbeGet[i - 1] << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
				cout << "Load factor : " << loadFactor << " -> Test success(+" << case_mark << ") " << endl;
			}
			else {
				fails++;
				cerr << "Load Factor : " << loadFactor << ", Average # probes : " << avgProbeGet[i - 1] << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
				cerr << "Load factor : " << loadFactor << " -> Test fail ( -" << case_mark << " ) " << endl;
			}
		}
		else {
			fails++;
			cerr << "Load Factor : " << loadFactor << ", Average # probes : " << "N/A" << ", Theoretical # probes(LP) : " << avgProbeExp << endl;
			cerr << "Load factor : " << loadFactor << " -> Test fail ( -" << case_mark << " ) " << endl;
		}
	}

	totalMark = (totalMark == 0 ? 0 : (totalMark + 1));

	if (fails == 0) {
		cout << "Test simProbeUnsuccess linear bonus PASS: ALL" << endl;
	}
	else {
		cerr << "Test simProbeUnsuccess linear bonus FAILED for " << fails << " case(s)" << endl;
	}

	cout << "*** END TEST simProbeUnsuccess LINEAR BONUS, TOTAL MARK IS " << totalMark << "/" << markSum << " ***" << endl;

	total += totalMark;
	full += markSum;
}

bool TestHashTable::testConstructorLin(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			uniform_int_distribution<> distLoad(1, 9);

			int maxNum = dist(gen);
			double load = distLoad(gen) * 0.1;

			switch (mainTestType) {
			case TestType::CONSTRUCTOR_NOCHECK: {
				result = testConstructorLinExd(maxNum, load, false, msg);
				break;
			}
			case TestType::CONSTRUCTOR_CHECK: {
				result = testConstructorLinExd(maxNum, load, true, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}
		}

		if (testFail)
			break;
	}

	return result;
}

bool TestHashTable::testConstructorQuad(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			uniform_int_distribution<> distLoad(1, 9);

			int maxNum = dist(gen);
			double load = distLoad(gen) * 0.1;

			switch (mainTestType) {
			case TestType::CONSTRUCTOR_NOCHECK: {
				result = testConstructorQuadExd(maxNum, load, false, msg);
				break;
			}
			case TestType::CONSTRUCTOR_CHECK: {
				result = testConstructorQuadExd(maxNum, load, true, msg);
				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}
		}

		if (testFail)
			break;
	}

	return result;
}

bool TestHashTable::testInsertLin(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
	bool result = false;
	int maxValue = MAX_KEY;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			uniform_int_distribution<> distLoad(1, 9);

			int maxNum = dist(gen);
			double load = distLoad(gen) * 0.1;
			int size = 0;

			for (size = (int)ceil(maxNum / load); ; size++) {
				if (isPrime(size))
					break;
			}

			switch (mainTestType) {
			case TestType::INSERT_EMPTY: {
				vector<int> values(1, 0);
				uniform_int_distribution<> distVal(1, maxValue);
				values[0] = distVal(gen);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertLinExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertLinExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_SIMPLE: {
				int len = maxNum;
				vector<int> values = generateKeys(len, 0, 0, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertLinExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertLinExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_DUPLICATE: {
				int dupLen = maxNum / 2;
				int len = maxNum - dupLen;

				if (dupLen <= 0)
					continue;

				vector<int> values = generateKeys(len, dupLen, 0, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertLinExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertLinExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_COLLISION: {
				int colLen = maxNum / 2;
				int len = maxNum - colLen;

				if (colLen <= 0)
					continue;

				vector<int> values = generateKeys(len, 0, colLen, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertLinExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertLinExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_REHASH: {
				int lenMin = (int)floor(size * load) + 1;
				int len = lenMin;
				vector<int> values = generateKeys(len, 0, 0, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertLinExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertLinExd(maxNum, load, values, true, msg);
				if (result == false) { break; }

				int colLen = lenMin / 2;
				len = lenMin - colLen;
				values = generateKeys(len, 0, colLen, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertLinExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertLinExd(maxNum, load, values, true, msg);

				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}
		}

		if (testFail)
			break;
	}

	return result;
}

bool TestHashTable::testInsertQuad(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg)
{
	bool result = false;
	int maxValue = MAX_KEY;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			uniform_int_distribution<> distLoad(1, 9);

			int maxNum = dist(gen);
			double load = distLoad(gen) * 0.1;
			int size = 0;

			for (size = (int)ceil(maxNum / load); ; size++) {
				if (isPrime(size))
					break;
			}

			switch (mainTestType) {
			case TestType::INSERT_EMPTY: {
				vector<int> values(1, 0);
				uniform_int_distribution<> distVal(1, maxValue);
				values[0] = distVal(gen);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertQuadExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertQuadExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_SIMPLE: {
				int len = maxNum;
				vector<int> values = generateKeys(len, 0, 0, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertQuadExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertQuadExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_DUPLICATE: {
				int dupLen = maxNum / 2;
				int len = maxNum - dupLen;

				if (dupLen <= 0)
					continue;

				vector<int> values = generateKeys(len, dupLen, 0, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertQuadExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertQuadExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_COLLISION: {
				int colLen = maxNum / 2;
				int len = maxNum - colLen;

				if (colLen <= 0)
					continue;

				vector<int> values = generateKeys(len, 0, colLen, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertQuadExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertQuadExd(maxNum, load, values, true, msg);

				break;
			}
			case TestType::INSERT_REHASH: {
				int lenMin = (int)floor(size * load) + 1;
				int len = lenMin;
				vector<int> values = generateKeys(len, 0, 0, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertQuadExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertQuadExd(maxNum, load, values, true, msg);
				if (result == false) { break; }

				int colLen = lenMin / 2;
				len = lenMin - colLen;
				values = generateKeys(len, 0, colLen, size, maxValue);
				if (subTestType == TestType::INSERT_WITH_NOCHECK)
					result = testInsertQuadExd(maxNum, load, values, false, msg);
				else if (subTestType == TestType::INSERT_WITH_CHECK)
					result = testInsertQuadExd(maxNum, load, values, true, msg);

				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}
		}

		if (testFail)
			break;
	}

	return result;
}

bool TestHashTable::testIsInLin(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;
	int maxValue = MAX_KEY;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			uniform_int_distribution<> distLoad(1, 9);

			int maxNum = dist(gen);
			double load = distLoad(gen) * 0.1;
			int size = 0;

			for (size = (int)ceil(maxNum / load); ; size++) {
				if (isPrime(size))
					break;
			}

			switch (mainTestType) {
			case TestType::ISIN_EMPTY: {
				vector<int> values;
				uniform_int_distribution<> distVal(1, maxValue);
				int checkVal = distVal(gen);
				result = testIsInLinExd(maxNum, load, values, checkVal, false, msg);
				break;
			}
			case TestType::ISIN_SIMPLE: {
				int len = maxNum;
				vector<int> values = generateKeys(len, 0, 0, size, maxValue);
				uniform_int_distribution<> distIdx(0, values.size() - 1);
				int checkVal = values[distIdx(gen)];
				result = testIsInLinExd(maxNum, load, values, checkVal, false, msg); // isIn true
				if (result == false) { break; }

				std::set<int> numSet(values.begin(), values.end());
				uniform_int_distribution<> distVal(1, maxValue);
				while (true) {
					checkVal = distVal(gen);
					if (!numSet.count(checkVal))
						break;
				}
				result = testIsInLinExd(maxNum, load, values, checkVal, false, msg); // isIn false
				break;
			}
			case TestType::ISIN_COLLISION: {
				int colLen = maxNum / 2;
				int len = maxNum - colLen;

				if (colLen <= 0)
					continue;

				vector<int> values = generateKeys(len, 0, colLen, size, maxValue);
				uniform_int_distribution<> distIdx(len, values.size() - 1);
				int checkVal = values[distIdx(gen)];
				result = testIsInLinExd(maxNum, load, values, checkVal, false, msg); // isIn true
				if (result == false) { break; }

				std::set<int> numSet(values.begin(), values.end());
				uniform_int_distribution<> distVal(1, maxValue);
				while (true) {
					checkVal = distVal(gen);
					if (!numSet.count(checkVal))
						break;
				}
				result = testIsInLinExd(maxNum, load, values, checkVal, false, msg); // isIn false

				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}
		}

		if (testFail)
			break;
	}

	return result;
}

bool TestHashTable::testIsInQuad(vector<int> sizes, int maxRun, TestType mainTestType, string msg)
{
	bool result = false;
	int maxValue = MAX_KEY;

	for (int i = 0; i < maxRun; i++) {
		bool testFail = false;
		for (size_t j = 0; j < sizes.size(); j++) {
			uniform_int_distribution<> dist(1, sizes[j]);
			uniform_int_distribution<> distLoad(1, 9);

			int maxNum = dist(gen);
			double load = distLoad(gen) * 0.1;
			int size = 0;

			for (size = (int)ceil(maxNum / load); ; size++) {
				if (isPrime(size))
					break;
			}

			switch (mainTestType) {
			case TestType::ISIN_EMPTY: {
				vector<int> values;
				uniform_int_distribution<> distVal(1, maxValue);
				int checkVal = distVal(gen);
				result = testIsInQuadExd(maxNum, load, values, checkVal, false, msg);
				break;
			}
			case TestType::ISIN_SIMPLE: {
				int len = maxNum;
				vector<int> values = generateKeys(len, 0, 0, size, maxValue);
				uniform_int_distribution<> distIdx(0, values.size() - 1);
				int checkVal = values[distIdx(gen)];
				result = testIsInQuadExd(maxNum, load, values, checkVal, false, msg); // isIn true
				if (result == false) { break; }

				std::set<int> numSet(values.begin(), values.end());
				uniform_int_distribution<> distVal(1, maxValue);
				while (true) {
					checkVal = distVal(gen);
					if (!numSet.count(checkVal))
						break;
				}
				result = testIsInQuadExd(maxNum, load, values, checkVal, false, msg); // isIn false
				break;
			}
			case TestType::ISIN_COLLISION: {
				int colLen = maxNum / 2;
				int len = maxNum - colLen;

				if (colLen <= 0)
					continue;

				vector<int> values = generateKeys(len, 0, colLen, size, maxValue);
				uniform_int_distribution<> distIdx(len, values.size() - 1);
				int checkVal = values[distIdx(gen)];
				result = testIsInQuadExd(maxNum, load, values, checkVal, false, msg); // isIn true
				if (result == false) { break; }

				std::set<int> numSet(values.begin(), values.end());
				uniform_int_distribution<> distVal(1, maxValue);
				while (true) {
					checkVal = distVal(gen);
					if (!numSet.count(checkVal))
						break;
				}
				result = testIsInQuadExd(maxNum, load, values, checkVal, false, msg); // isIn false

				break;
			}
			default:
				break;
			}

			if (!result) {
				testFail = true;
				break;
			}
		}

		if (testFail)
			break;
	}

	return result;
}

bool TestHashTable::testConstructorLinExd(int maxNum, double load, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		HashTableLin htl(maxNum, load);

		vector<int> tableGet = htl.getTable();

		int sizeGet = tableGet.size();
		int len = (int)ceil(maxNum / load);

		if (!isMinPrime(len, sizeGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Constructor: not minimum prime size" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Output   size= " << sizeGet << endl;
			cerr << "output  table= " << vector2String(tableGet) << endl;
		}

		if (passFlag == true && !checkTable(tableGet, 0)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Constructor: not empty" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Output   size= " << sizeGet << endl;
			cerr << "output  table= " << vector2String(tableGet) << endl;
		}

		if (checkFlag && passFlag) {
			int tableSizeGet = htl.getTableSize();
			int tableSizeExp = sizeGet;
			int numKeysGet = htl.getNumKeys();
			int numKeysExp = 0;
			double maxLoadFactorGet = htl.getMaxLoadFactor();
			double maxLoadFactorExp = load;

			if ((tableSizeGet != tableSizeExp) || (numKeysGet != numKeysExp) || (abs(maxLoadFactorGet - maxLoadFactorExp) > 1e-6)) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Constructor: check get methods error" << endl;
				cerr << "Input maxNum= " << maxNum << endl;
				cerr << "Get   tbSize= " << tableSizeGet << endl;
				cerr << "Get  numKeys= " << numKeysGet << endl;
				cerr << "Get  maxLoad= " << maxLoadFactorGet << endl;
				cerr << "Expect  tbSize= " << tableSizeExp << endl;
				cerr << "Expect numKeys= " << numKeysExp << endl;
				cerr << "Expect maxLoad= " << maxLoadFactorExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Constructor error" << endl;
		cerr << e.what() << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Constructor error" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
	}

	return passFlag;
}

bool TestHashTable::testConstructorQuadExd(int maxNum, double load, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		HashTableQuad htq(maxNum, load);

		vector<int> tableGet = htq.getTable();

		int sizeGet = tableGet.size();
		int len = (int)ceil(maxNum / load);

		if (!isMinPrime(len, sizeGet)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Constructor: not minimum prime size" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Output   size= " << sizeGet << endl;
			cerr << "output  table= " << vector2String(tableGet) << endl;
		}

		if (passFlag == true && !checkTable(tableGet, 0)) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Constructor: not empty" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Output   size= " << sizeGet << endl;
			cerr << "output  table= " << vector2String(tableGet) << endl;
		}

		if (checkFlag && passFlag) {
			int tableSizeGet = htq.getTableSize();
			int tableSizeExp = sizeGet;
			int numKeysGet = htq.getNumKeys();
			int numKeysExp = 0;
			double maxLoadFactorGet = htq.getMaxLoadFactor();
			double maxLoadFactorExp = load;

			if ((tableSizeGet != tableSizeExp) || (numKeysGet != numKeysExp) || (abs(maxLoadFactorGet - maxLoadFactorExp) > 1e-6)) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Constructor: check get methods error" << endl;
				cerr << "Input maxNum= " << maxNum << endl;
				cerr << "Get   tbSize= " << tableSizeGet << endl;
				cerr << "Get  numKeys= " << numKeysGet << endl;
				cerr << "Get  maxLoad= " << maxLoadFactorGet << endl;
				cerr << "Expect  tbSize= " << tableSizeExp << endl;
				cerr << "Expect numKeys= " << numKeysExp << endl;
				cerr << "Expect maxLoad= " << maxLoadFactorExp << endl;
			}
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Constructor error" << endl;
		cerr << e.what() << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Constructor error" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
	}

	return passFlag;
}

bool TestHashTable::testInsertLinExd(int maxNum, double load, vector<int> elements, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		passFlag = testConstructorLinExd(maxNum, load, checkFlag, msg);
		if (passFlag == false)
			return passFlag;

		HashTableLin htl(maxNum, load);
		std::set<int> numSetExp;
		passFlag = doInsertLin(htl, numSetExp, maxNum, load, elements, checkFlag, msg);
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}

	return passFlag;
}

bool TestHashTable::testInsertQuadExd(int maxNum, double load, vector<int> elements, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		passFlag = testConstructorQuadExd(maxNum, load, checkFlag, msg);
		if (passFlag == false)
			return passFlag;

		HashTableQuad htq(maxNum, load);
		std::set<int> numSetExp;
		passFlag = doInsertQuad(htq, numSetExp, maxNum, load, elements, checkFlag, msg);
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}

	return passFlag;
}

bool TestHashTable::testIsInLinExd(int maxNum, double load, vector<int> elements, int checkVal, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {
		passFlag = testConstructorLinExd(maxNum, load, checkFlag, msg);
		if (passFlag == false)
			return passFlag;

		HashTableLin htl(maxNum, load);
		std::set<int> numSetExp;

		passFlag = doInsertLin(htl, numSetExp, maxNum, load, elements, checkFlag, msg);

		bool resGet = htl.isIn(checkVal);
		bool resExp = numSetExp.count(checkVal);

		if (passFlag == true && resGet != resExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(htl.getTable()) << endl;
			cerr << "Check     num= " << checkVal << endl;
			cerr << "Output result= " << resGet << endl;
			cerr << "Expect result= " << resExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}

	return passFlag;
}

bool TestHashTable::testIsInQuadExd(int maxNum, double load, vector<int> elements, int checkVal, bool checkFlag, string msg)
{
	bool passFlag = true;
	try {

		passFlag = testConstructorQuadExd(maxNum, load, checkFlag, msg);
		if (passFlag == false)
			return passFlag;

		HashTableQuad htq(maxNum, load);
		std::set<int> numSetExp;

		passFlag = doInsertQuad(htq, numSetExp, maxNum, load, elements, checkFlag, msg);

		bool resGet = htq.isIn(checkVal);
		bool resExp = numSetExp.count(checkVal);

		if (passFlag == true && resGet != resExp) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(htq.getTable()) << endl;
			cerr << "Check     num= " << checkVal << endl;
			cerr << "Output result= " << resGet << endl;
			cerr << "Expect result= " << resExp << endl;
		}
	}
	catch (const std::exception& e) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << e.what() << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}
	catch (...) {
		passFlag = false;
		cerr << "Error in " << msg << " ->" << endl;
		cerr << "Unknown exception" << endl;
		cerr << "Input  maxNum= " << maxNum << endl;
		cerr << "Input maxLoad= " << load << endl;
		cerr << "Insert   seqs= " << vector2String(elements) << endl;
	}

	return passFlag;
}

bool TestHashTable::doInsertLin(HashTableLin& htl, std::set<int>& numSetExp, int maxNum, double load, vector<int> elements, bool checkFlag, string msg)
{
	bool passFlag = true;

	vector<int> tablePre = htl.getTable();

	for (size_t i = 0; i < elements.size(); i++) {
		htl.insert(elements[i]);

		bool resInsert = checkInsertSuccessLin(tablePre, elements[i], false);
		if (resInsert == true) {
			numSetExp.insert(elements[i]);
		}

		vector<int> tableCur = htl.getTable();

		double outLoad = 0;
		bool resLoad = checkValidLoadFactor(tableCur, load, outLoad, false);

		if (passFlag == true && resLoad == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: load factor error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
			cerr << "Output   load= " << outLoad << endl;
		}

		bool resTableSize = checkValidTableSize(tablePre, tableCur, false);

		if (passFlag == true && resTableSize == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: table size error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
			cerr << "Output   size= " << tableCur.size() << endl;
		}

		bool resNum = checkValidElements(tableCur, numSetExp, false);

		if (passFlag == true && resNum == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: elements (number) error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
			cerr << "Expect eleNum= " << numSetExp.size() << endl;
		}

		bool resLoc = checkValidElementLocationLin(tableCur, false);

		if (passFlag == true && resLoc == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: element location error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
		}

		if (checkFlag && passFlag) {
			int tableSizeGet = htl.getTableSize();
			int tableSizeExp = tableCur.size();
			int numKeysGet = htl.getNumKeys();
			int numKeysExp = numSetExp.size();
			double maxLoadFactorGet = htl.getMaxLoadFactor();
			double maxLoadFactorExp = load;

			if ((tableSizeGet != tableSizeExp) || (numKeysGet != numKeysExp) || (abs(maxLoadFactorGet - maxLoadFactorExp) > 1e-6)) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Insert: check get methods error" << endl;
				cerr << "Input  maxNum= " << maxNum << endl;
				cerr << "Input maxLoad= " << load << endl;
				cerr << "Insert   seqs= " << vector2String(elements) << endl;
				cerr << "Input   table= " << vector2String(tablePre) << endl;
				cerr << "Input  tbSize= " << tablePre.size() << endl;
				cerr << "Insert    num= " << elements[i] << endl;
				cerr << "Output  table= " << vector2String(tableCur) << endl;
				cerr << "Get    tbSize= " << tableSizeGet << endl;
				cerr << "Get   numKeys= " << numKeysGet << endl;
				cerr << "Get   maxLoad= " << maxLoadFactorGet << endl;
				cerr << "Expect  tbSize= " << tableSizeExp << endl;
				cerr << "Expect numKeys= " << numKeysExp << endl;
				cerr << "Expect maxLoad= " << maxLoadFactorExp << endl;
			}
		}

		tablePre = tableCur;

		if (passFlag == false) {
			break;
		}
	}

	return passFlag;
}

bool TestHashTable::doInsertQuad(HashTableQuad& htq, std::set<int>& numSetExp, int maxNum, double load, vector<int> elements, bool checkFlag, string msg)
{
	bool passFlag = true;

	vector<int> tablePre = htq.getTable();

	for (size_t i = 0; i < elements.size(); i++) {
		htq.insert(elements[i]);

		bool resInsert = checkInsertSuccessQuad(tablePre, elements[i], false);
		if (resInsert == true) {
			numSetExp.insert(elements[i]);
		}

		vector<int> tableCur = htq.getTable();

		double outLoad = 0;
		bool resLoad = checkValidLoadFactor(tableCur, load, outLoad, false);

		if (passFlag == true && resLoad == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: load factor error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
			cerr << "Output   load= " << outLoad << endl;
		}

		bool resTableSize = checkValidTableSize(tablePre, tableCur, false);
		if (passFlag == true && resTableSize == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: table size error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
			cerr << "Output   size= " << tableCur.size() << endl;
		}

		bool resNum = checkValidElements(tableCur, numSetExp, false);

		if (passFlag == true && resNum == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: elements (number) error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
			cerr << "Expect eleNum= " << numSetExp.size() << endl;
		}

		bool resLoc = checkValidElementLocationQuad(tableCur, false);

		if (passFlag == true && resLoc == false) {
			passFlag = false;
			cerr << "Error in " << msg << " ->" << endl;
			cerr << "Insert: element location error" << endl;
			cerr << "Input  maxNum= " << maxNum << endl;
			cerr << "Input maxLoad= " << load << endl;
			cerr << "Insert   seqs= " << vector2String(elements) << endl;
			cerr << "Input   table= " << vector2String(tablePre) << endl;
			cerr << "Input  tbSize= " << tablePre.size() << endl;
			cerr << "Insert    num= " << elements[i] << endl;
			cerr << "Output  table= " << vector2String(tableCur) << endl;
		}

		if (checkFlag && passFlag) {
			int tableSizeGet = htq.getTableSize();
			int tableSizeExp = tableCur.size();
			int numKeysGet = htq.getNumKeys();
			int numKeysExp = numSetExp.size();
			double maxLoadFactorGet = htq.getMaxLoadFactor();
			double maxLoadFactorExp = load;

			if ((tableSizeGet != tableSizeExp) || (numKeysGet != numKeysExp) || (abs(maxLoadFactorGet - maxLoadFactorExp) > 1e-6)) {
				passFlag = false;
				cerr << "Error in " << msg << " ->" << endl;
				cerr << "Insert check get methods error" << endl;
				cerr << "Input  maxNum= " << maxNum << endl;
				cerr << "Input maxLoad= " << load << endl;
				cerr << "Insert   seqs= " << vector2String(elements) << endl;
				cerr << "Input   table= " << vector2String(tablePre) << endl;
				cerr << "Input  tbSize= " << tablePre.size() << endl;
				cerr << "Insert    num= " << elements[i] << endl;
				cerr << "Output  table= " << vector2String(tableCur) << endl;
				cerr << "Get    tbSize= " << tableSizeGet << endl;
				cerr << "Get   numKeys= " << numKeysGet << endl;
				cerr << "Get   maxLoad= " << maxLoadFactorGet << endl;
				cerr << "Expect  tbSize= " << tableSizeExp << endl;
				cerr << "Expect numKeys= " << numKeysExp << endl;
				cerr << "Expect maxLoad= " << maxLoadFactorExp << endl;
			}
		}

		tablePre = tableCur;

		if (passFlag == false) {
			break;
		}
	}

	return passFlag;
}

bool TestHashTable::isPrime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool TestHashTable::isMinPrime(int len, int size)
{
	if (len > size)
		return false;

	for (int i = len; i < size; i++) {
		if (isPrime(i))
			return false;
	}

	if (isPrime(size))
		return true;
	else
		return false;
}

bool TestHashTable::checkTable(vector<int> table, int val)
{
	for (size_t i = 0; i < table.size(); i++) {
		if (table[i] != val)
			return false;
	}

	return true;
}

bool TestHashTable::checkValidElements(vector<int> table, std::set<int> numSetExp, bool isInFlag)
{
	bool result = true;
	int size = table.size();

	std::set<int> numSetGet;
	size_t numGet = 0;
	for (int i = 0; i < size; i++) {
		if (table[i] != 0) {
			numSetGet.insert(table[i]);
			numGet++;
		}
	}

	if (numGet != numSetGet.size())
		result = false;

	if (numSetExp != numSetGet)
		result = false;

	return result;
}

bool TestHashTable::checkInsertSuccessLin(vector<int> table, int val, bool isInFlag)
{
	bool result = false;
	int size = table.size();

	for (int i = 0; i < size; i++) {
		int index = (val % size + i) % size;
		if (table[index] == 0) {
			result = true;
			break;
		}
		else if (table[index] == val) {
			result = false;
			break;
		}
	}

	return result;
}

bool TestHashTable::checkInsertSuccessQuad(vector<int> table, int val, bool isInFlag)
{
	bool result = false;
	int size = table.size();

	for (int i = 0; i < size; i++) {
		int index = (val % size + i * i) % size;
		if (table[index] == 0) {
			result = true;
			break;
		}
		else if (table[index] == val) {
			result = false;
			break;
		}
	}

	return result;
}

bool TestHashTable::checkValidLoadFactor(vector<int> table, double maxLoad, double& outLoad, bool isInFlag)
{
	bool result = true;
	int size = table.size();

	int num = 0;
	for (int i = 0; i < size; i++) {
		if (table[i] != 0) {
			num++;
		}
	}

	outLoad = num * 1.0 / size;

	if (outLoad > maxLoad)
		result = false;
	else
		result = true;

	return result;
}

bool TestHashTable::checkValidTableSize(vector<int> tablePre, vector<int> tableCur, bool isInFlag)
{
	bool result = false;

	int sizePre = tablePre.size();
	int sizeCur = tableCur.size();

	int numPre = 0;
	for (int i = 0; i < sizePre; i++) {
		if (tablePre[i] != 0) {
			numPre++;
		}
	}

	int numCur = 0;
	for (int i = 0; i < sizeCur; i++) {
		if (tableCur[i] != 0) {
			numCur++;
		}
	}

	if ((sizeCur == sizePre) && (numCur >= numPre)) { // no rehash
		result = true;
	}
	else if (sizeCur >= 2 * sizePre && (numCur > numPre)) { // rehash
		if (isMinPrime(2 * sizePre, sizeCur))
			result = true;
	}

	return result;
}

bool TestHashTable::checkValidElementLocationLin(vector<int> table, bool isInFlag)
{
	bool result = true;
	int size = table.size();
	for (int i = 0; i < size; i++) {
		// check each element valid or not
		bool eleRes = false;
		if (table[i] != 0) {
			for (int j = 0; j < size; j++) {
				int idx = (table[i] % size + j) % size;
				if (table[idx] == 0) { // empty
					eleRes = false;
					break;
				}
				else if (i == idx) {
					eleRes = true;
					break;
				}
			}
		}
		else {
			eleRes = true;
		}

		if (eleRes == false) {
			result = false;
			break;
		}
	}

	return result;
}

bool TestHashTable::checkValidElementLocationQuad(vector<int> table, bool isInFlag)
{
	bool result = true;
	int size = table.size();
	for (int i = 0; i < size; i++) {
		// check each element valid or not
		bool eleRes = false;
		if (table[i] != 0) {
			for (int j = 0; j < size; j++) {
				int idx = (table[i] % size + j * j) % size;
				if (table[idx] == 0) { // empty
					eleRes = false;
					break;
				}
				else if (i == idx) {
					eleRes = true;
					break;
				}
			}
		}
		else {
			eleRes = true;
		}

		if (eleRes == false) {
			result = false;
			break;
		}
	}

	return result;
}

string TestHashTable::vector2String(vector<int> num)
{
	std::ostringstream oss;
	oss << "[";

	if (num.size() == 1) {
		oss << num[0];
	}
	else if (num.size() > 1) {
		std::copy(num.begin(), num.end() - 1, std::ostream_iterator<int>(oss, ","));
		oss << num.back();
	}

	oss << "]";

	return oss.str();
}

vector<int> TestHashTable::generateKeys(int len, int dupLen, int colLen, int size, int maxValue)
{
	if (colLen > len)
		throw std::invalid_argument("colLen > len");

	if (len > size)
		throw std::invalid_argument("len > size");

	vector<int> vec(len);
	vector<int> table(size, 0);
	std::set<int> numSet;
	uniform_int_distribution<> distVal(1, maxValue);

	// generate non duplicate & non collision elements
	for (int i = 0; i < len; ) {
		int num = distVal(gen);
		int idx = num % size;

		if (table[idx] == 0) { // no collision
			table[idx] = num;
			vec[i] = num;
			i++;
		}
	}

	if (colLen > 0) {
		vec.resize(len + colLen);
		uniform_int_distribution<> distColIdx(0, len - 1);
		for (int i = len; i < len + colLen; ) {
			int num = vec[distColIdx(gen)] + size;
			if (!numSet.count(num)) {
				numSet.insert(num);
				vec[i] = num;
				i++;
			}
		}
	}

	if (dupLen > 0) {
		vec.resize(len + dupLen);
		uniform_int_distribution<> distDupIdx(0, len - 1);
		for (int i = len; i < len + dupLen; i++) {
			vec[i] = vec[distDupIdx(gen)];
		}
	}

	return vec;
}
