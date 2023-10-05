#ifndef TESTHASHTABLE_H_
#define TESTHASHTABLE_H_

#include "HashTableLin.h"
#include "HashTableQuad.h"
#include <random>
#include <vector>
#include <string>
#include <set>
using namespace std;

enum class TestType
{
	CONSTRUCTOR_NOCHECK,
	CONSTRUCTOR_CHECK,
	INSERT_EMPTY,
	INSERT_SIMPLE,
	INSERT_DUPLICATE,
	INSERT_COLLISION,
	INSERT_REHASH,
	INSERT_WITH_NOCHECK,
	INSERT_WITH_CHECK,
	ISIN_EMPTY,
	ISIN_SIMPLE,
	ISIN_COLLISION
};

class TestHashTable
{
private:
	int MAX_RUN = 50;
	int MAX_KEY = 1000;
	vector<int> MAX_SIZE_ARRAY = { 1, 5, 10 };
	std::mt19937 gen;

public:
	TestHashTable();
	TestHashTable(int max_run, int max_key, vector<int> max_size_array);

	void testConstructorLin(double& total, double& full);
	void testIsInLin(double& total, double& full);
	void testInsertLin(double& total, double& full);

	void testConstructorQuad(double& total, double& full);
	void testInsertQuad(double& total, double& full);
	void testIsInQuad(double& total, double& full);

	void testSimProbeSuccessLin(double& total, double& full);
	void testSimProbeSuccessQuad(double& total, double& full);
	void testSimProbeUnsuccessLinBonus(double& total, double& full);

private:
	bool testConstructorLin(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testInsertLin(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	bool testIsInLin(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testConstructorLinExd(int maxNum, double load, bool checkFlag, string msg);
	bool testInsertLinExd(int maxNum, double load, vector<int> elements, bool checkFlag, string msg);
	bool testIsInLinExd(int maxNum, double load, vector<int> elements, int checkVal, bool checkFlag, string msg);
	bool checkValidElementLocationLin(vector<int> table, bool isInFlag);
	bool checkInsertSuccessLin(vector<int> table, int val, bool isInFlag);
	bool doInsertLin(HashTableLin& htl, std::set<int>& numSetExp, int maxNum, double load, vector<int> elements, bool checkFlag, string msg);

	bool testConstructorQuad(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testInsertQuad(vector<int> sizes, int maxRun, TestType mainTestType, TestType subTestType, string msg);
	bool testIsInQuad(vector<int> sizes, int maxRun, TestType mainTestType, string msg);
	bool testConstructorQuadExd(int maxNum, double load, bool checkFlag, string msg);
	bool testInsertQuadExd(int maxNum, double load, vector<int> elements, bool checkFlag, string msg);
	bool testIsInQuadExd(int maxNum, double load, vector<int> elements, int checkVal, bool checkFlag, string msg);
	bool checkValidElementLocationQuad(vector<int> table, bool isInFlag);
	bool checkInsertSuccessQuad(vector<int> table, int val, bool isInFlag);
	bool doInsertQuad(HashTableQuad& htq, std::set<int>& numSetExp, int maxNum, double load, vector<int> elements, bool checkFlag, string msg);

	bool isPrime(int n);
	bool isMinPrime(int len, int size);
	bool checkTable(vector<int> table, int val);
	string vector2String(vector<int> num);
	bool checkValidElements(vector<int> table, std::set<int> numSetExp, bool isInFlag);
	bool checkValidLoadFactor(vector<int> table, double maxLoad, double& outLoad, bool isInFlag);
	bool checkValidTableSize(vector<int> tablePre, vector<int> tableCur, bool isInFlag);
	vector<int> generateKeys(int len, int dupLen, int colLen, int size, int maxNum);
};

#endif /* TESTHASHTABLE_H_ */
