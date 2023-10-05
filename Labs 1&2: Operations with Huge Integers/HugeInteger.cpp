#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger(const std::string& val) {
	/*

	creates a HugeInteger from the decimal string representation val.The string contains an
	optional minus sign at the beginning followed by one or more decimal digits.No other
	characters are allowed in the string.

	*/

	if (val[0] != '-' && (val[0] > 57 || val[0] < 48))  //making sure the first element is either '-' or 0-9
	{
		throw std::invalid_argument("invalid input"); //if out of bounds, throw the exception
	}

	//starts from 1 since we have already checked the first index
	for (int i = 1; i < val.length(); i++)
	{
		if (val[i] > 57 || val[i] < 48) //making sure that every other element is between 0-9
		{
			throw std::invalid_argument("invalid input"); //if out of bounds, throw the exception
		}

	}

	if (val[0] == '-') //if the number contains a minus sign, set it to negative
	{
		negative = true;
		newInteger = val;
		
	}

	else
	{
		negative = false; //the value is positive
		//we don't want the minus sign so we return the string by cutting out the first character
		newInteger = val.substr(1); //cut out the first character (which will be the '-')
	}

	
	//making sure the integer values are in the right format so that there aren't an excessive amount of 0s in my answers

	int i = 0;

	if (val[0] != '-') {
		negative = true;
		i = 0;
	}
	else {
		negative = false; 
		i = 1;
	}

	while (val[i] == '0' && i < val.length()) { //keep adding to i while theres 0
		i++;
	}

	if (i == val.length()) { //if we go through the whole length, then the number is 0
		negative = true;
		newInteger = "0";
		return;
	}

	newInteger = val.substr(i, val.length()); //extract the number from all the leading zeros


}

HugeInteger::HugeInteger(int n) {
	/*
		 creates a random HugeInteger of n digits, the first digit being different from 0;
		 n must be larger or equal to 1.
	*/

	if (n < 1) {
		throw ("the length must be at least 1 digit"); //if our of bounds, throw an exception
	}

	newInteger = "";
	for (int i = 0; i < n; i++) {
		char digit = char((rand() % 9) + 49); //for each iteration, a random number is generated 
		newInteger += digit; //the number generated is added to the empty string
		negative = true;
	}

}

HugeInteger HugeInteger::add(const HugeInteger& h) {

	if (negative != h.negative) { //if the numbers have diff signs
		HugeInteger opposite = HugeInteger(h.newInteger); // if different signs, get the opposite sign
		opposite.negative = !h.negative;
		return subtract(opposite); // and then subtract
	}

	string summation = "";

	string int1 = newInteger;
	int size1 = int1.size();

	string int2 = h.newInteger;
	int size2 = int2.size();

	//to add both numbers, we need to ensure that there is the same amount of digits for both
	int zeros = max(size1, size2);

	//create new strings to add the leading zeros to the smaller number 
	//the larger number will stay unchanged
	int1 = string(zeros - size1, '0') + int1;
	int2 = string(zeros - size2, '0') + int2;

	int carryOver = 0;

	for (int i = int1.size() - 1; i >= 0; i--) //we want to start from the last digit, so wel will increment backwards
	{
		//to do the addition, it will be more simple to turn each character into integers as we add them
		//also accounts for numbers going above 9 when added together
		int num1 = (int)(int1[i] - 48); //example: i = '6', 54 - 48 = 6 
		int num2 = (int)(int2[i] - 48);

		int digit = num1 + num2 + carryOver;
		carryOver = digit / 10; //this will take into account the carry over for the addition of the next pair of digits
		summation = (char)(digit % 10 + 48) + summation; //when we have the sum of each pair of digits, convert back to char and add to the final string
	}

	//we have to take into account the final carry over for the last pair of digits
	if (carryOver == 1)
	{
		summation = "1" + summation;
	}

	HugeInteger finalInt(summation);

	if (finalInt.newInteger != "0") {
		finalInt.negative = negative;
	}

	return finalInt;

}

HugeInteger HugeInteger::subtract(const HugeInteger& h) {
	if (negative != h.negative) { //if the numbers have different signs, add them
		HugeInteger opposite = HugeInteger(h.newInteger); //get the opposite sign of h
		opposite.negative = !h.negative;
		return add(opposite);
	}

	bool positive = negative;


	string difference = "";

	string int1 = newInteger;
	int size1 = int1.size();

	string int2 = h.newInteger;
	int size2 = int2.size();
	
	//0 --> same magnitude
	//1 --> h is bigger
	//2 --> huge integer is bgger

	int largest = 0;

	if (size1 < size2) {
		largest = 1;
	}
	else if (size1 > size2) {
		largest = 2;
	}

	else { //if the magnitudes the same, compare each element

		for (int i = 0; i < size1; i++) {

			if (int1[i] < int2[i]) {
				largest = 1;
				break;
			}
			else if (int1[i] > int2[i]) {
				largest = 2;
				break;
			}
		}
	}

	if (largest == 1) { //if h is bigger, assign it to int1

		positive = !positive;
		string temp;
		temp = int1;
		int1 = int2;
		int2 = temp;
	}

	int carryOver = 0;
	int shorter = std::min(size1, size2); //getting the smaller number using min
	int longer = std::max(size1, size2); //getting the bigger number using max

	for (int i = longer - 1; i > longer - 1 - shorter; i--) { //iterating through all the shorter numbers elements

		int num1 = (int)(int1[i]) - 48; //from ascii to int
		int num2 = (int)(int2[i - longer + shorter]) - 48; //from ascii to int

		int digit = num1 - num2 - carryOver; //subtract the integer nums

		if (digit < 0) { //if the difference is less than 0

			digit += 10;  // borrow from the next digit
			carryOver = 1;
		}
		else { //if differece is greater than 0
			carryOver = 0; //no need to borrow
		}

		difference = (char)(digit + 48) + difference; // convert back to char ad add to summation
	}

	//iterate through the longer string and add the remaining numbers to the final difference
	for (int i = longer - 1 - shorter; i >= 0; i--) { 
		if (int1[i] - carryOver < 48) {
			difference = "9" + difference;
			carryOver = 1;
		}
		else {
			difference = (char)(int1[i] - carryOver) + difference;
			carryOver = 0;
		}
	}


	HugeInteger finalInt(difference); 
	
	if (finalInt.newInteger != "0") {
		finalInt.negative = positive;
	}
	return finalInt;
}



HugeInteger HugeInteger::multiply(const HugeInteger& h) {

	int shorter;
	int longer;

	string product = "";

	string int1 = newInteger;
	int size1 = int1.size();

	string int2 = h.newInteger;
	int size2 = int2.size();

	//Ensure that num1 is always bigger number and num2 smaller number
	//number and n the length of the longer

	if (size1 >= size2) { //setting the numbers to short and long
		int1 = newInteger;
		int2 = h.newInteger;
		longer = size1;
		shorter = size2;
	}
	else {
		int1 = h.newInteger;
		int2 = newInteger;
		longer = size2;
		shorter = size1;
	}

	int carryOver = 0;

	//represents the position of the digit that we are currently computing in the final answer (power of ten)
	int k = 0;

	//The maximum power of 10 for k is the shorter number + the longer number
	while (k < shorter + longer) {

		int i = 0;	//incremetor 

		int j = k; //incremetor 

		while (j >= longer) {
			i += 1; //increment
			j -= 1; //decrement
		
		}

		int sumOfPower = carryOver; //keeps track of all the sums of the products including the carry over


		//convert each digit to int and do the multiplication
		while (j >= 0 && i < shorter) {
			int digit = (int2[shorter - 1 - i] - 48) * (int1[longer - 1 - j] - 48);
			sumOfPower += digit;

			i += 1; //increment
			j -= 1; //decrement
		}

		carryOver = sumOfPower / 10;
		product = (char)((sumOfPower % 10) + 48) + product; //convert bac to char and add to the string

	
		k += 1; //move to next power of ten
	}

	HugeInteger finalInt(product);

	if (negative != h.negative && finalInt.newInteger != "0") { //if either number is negative than the whole number is negative

		finalInt.negative = false;
	}

	return finalInt;
}

int HugeInteger::compareTo(const HugeInteger& h) {


	if ((negative) && !(h.negative)) //this is positive, h is negative so this is bigger
		return 1;

	if (!(negative) && (h.negative)) //this is negative, h is positive so h is bigger
		return -1; 

	string int1 = newInteger;
	int size1 = int1.size();

	string int2 = h.newInteger;
	int size2 = int2.size();


	if (!(negative) && !(h.negative)) { //if theyre both negative

		if (size1 > size2) { //if this is bigger than h, h is bigger
			return -1;
		}

		if (size1 < size2) { //if this is less than h, this is bigger
			return 1;
		}

		//if theyre the same length
		for (int i = 0; i < size1; i++) {//iterate through the elements

			if (int1[i] > int2[i]) { 
				return -1;
			}

			else if (int1[i] < int2[i]) {
				return 1;
			}

		}
	}

	//comparin is both are positive
	if ((negative) && (h.negative)) {

		if (size1 > size2) {
			return 1;
		}

		if (size2 > size1) {
			return -1;
		}


		//if theyre the same length
		for (int i = 0; i < size1; i++) {//iterate through the elements

			if (int1[i] > int2[i]) {
				return 1;
			}

			else if (int1[i] < int2[i]) {
				return -1;
			}

		}
	}
	//else theyre the same so return 0
	return 0;

}

std::string HugeInteger::toString() {

	if (negative) {
		return newInteger;
	}

	else return "-" + newInteger;
}


