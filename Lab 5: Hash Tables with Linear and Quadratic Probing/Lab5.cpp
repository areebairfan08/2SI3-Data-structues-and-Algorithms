#include "TestHashTable.h"
#include <iostream>
using namespace std;

int main()
{
    int max_run = 50;
    int max_key = 1000;
    vector<int> max_size_array = { 1, 5, 10 };

    double fullMark = 0;
    double totalMark = 0;
    double bonusFullMark = 0;
    double bonusTotalMark = 0;

    TestHashTable tht(max_run, max_key, max_size_array);

    tht.testConstructorLin(totalMark, fullMark);
    tht.testInsertLin(totalMark, fullMark);
    tht.testIsInLin(totalMark, fullMark);

    tht.testConstructorQuad(totalMark, fullMark);
    tht.testInsertQuad(totalMark, fullMark);
    tht.testIsInQuad(totalMark, fullMark);

    tht.testSimProbeSuccessLin(totalMark, fullMark);
    tht.testSimProbeSuccessQuad(totalMark, fullMark);
    tht.testSimProbeUnsuccessLinBonus(bonusTotalMark, bonusFullMark);

    cout << "********************************" << endl;
    cout << "*** FINAL TOTAL MARK IS " << totalMark << "/" << fullMark << " ***" << endl;
    cout << "*** FINAL BONUS MARK IS " << bonusTotalMark << "/" << bonusFullMark << " ***" << endl;
    cout << "********************************" << endl;

	return 0;
}
