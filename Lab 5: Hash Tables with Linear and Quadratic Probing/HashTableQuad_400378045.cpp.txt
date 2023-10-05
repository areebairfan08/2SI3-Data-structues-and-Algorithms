#include "HashTableQuad.h"
#include <iostream>
#include <cmath>
using namespace std;



int HashTableQuad::prime(int n) {
	//TIME: O(n^2)
	//SPACE complexity O(1)

	bool check = false; //checks if the number is prime
	int pNum = n; //n equals parameter variable

	if (pNum == 1 || pNum == 2) { //if n is 1 or 2,
		return pNum; //return pnum since it is already a prime number
	}

	else {

		while (!check) { //while check is false

			for (int i = 2; i < pNum; i++) { //for loop to check if pNum is a prime number
				if (pNum % i == 0) { //if pnum is divisible, it is NOT a prime number
					check = false;
					break; //break out of the loop
				}
				else {
					check = true; //if no factor is found, it is a prime number
				}
			}
			if (check == false) //if pNum is not found, add 1 and redo the loop
				pNum = pNum + 1;

		}
		return pNum; //is broke out of the loop, return the prime number
	}
}


HashTableQuad::HashTableQuad(int maxNum, double load)
//TIME complexity O(n^2)
//SPACE complexity O(n)
{
	keys = 0; //intiialize keys to 0
	loadFactor = load; //initialize maximum load to 

	size = (int)ceil(maxNum / load); //minimum size rounded using ceil
	size = prime(size); //uses the prime function to find the closest prime number to size

	int i = 0;
	while (i < size) { //push 0 into the table
		table.push_back(0);
		i++;
	}

}

void HashTableQuad::insert(int n)
//TIME: O(n)
//SPACE: O(n), n is size of tab;e
{
	int probes = 0;
	int position = n % size;//integer to initialize the position


	if (isIn(n) == true) { //if n is already in the table
		return; //return
	}

	//Runs until number is inserted at correct spot
	while (table[position] != 0) {
		position = (n + (probes * probes)) % size;// Calculates the next possible position using quad probing 
		probes++; // Increments the probe to keep track of how many times we have probed

		if (probes > size) { //if probe exceeds size, then rehashing is impossible 
			return; //so return
		}
	}

	//Inserts number at location found and increases key counter
	table[position] = n;
	keys = keys + 1;

	double load = (double)keys / (double)size;

	if (load > loadFactor) //if the load exceeds to loadfactor, then table is too full
		rehash();
}

void HashTableQuad::rehash()
//TIME: O(n^2)
//SPACE O(n); n = size of hash tabe
{
	HashTableQuad temp = HashTableQuad(2 * size * loadFactor, loadFactor);  //temp table with size specified by manual

	if (temp.size < 2 * size) { //ensure that the temp table is double the size of the table

		//if it is, redefine the size
		int temp_size = temp.size;
		temp.size = prime(2 * size);

		//for all extra spots, push 0
		int i = temp_size;
		while (i < temp.size) {
			(temp.table).push_back(0);
			i++;
		}

	}

	int i = 0;
	while (i < size) { //iterating through previous table
		if (table[i] != 0) { //if the element in the previous table is not 0
			temp.insert(table[i]); //add it into the temp table
		}
		i++;
	}

	table = temp.table; //adjust table pramater
	size = temp.size; //adjut size parameter

}

bool HashTableQuad::isIn(int n)
//TIME: O(n)
//SPACE: O(1)
{
	int position = n % size; //integer to initialize the position
	int probe = 0; //probe variable

	while (table[position] != n) {
		position = (n + (probe*probe)) % size; // Calculates the next possible position using linear probing 
		probe++; // Increments the probe to keep track of how many times we have probed

		if (probe > size) {	//if probe becomes larger than size, that means the key is not found 
			return false; //return false
		}
	}
	return true; //if the key is found, return true
}


void HashTableQuad::printKeys()
//TIME:  O(n)
//SPACE: O(1)
{
	int i = 0;
	while (i < size) {//iterating through each element

		if (table[i] != 0) { //if the key is not 0
			std::cout << table[i] << std::endl; //print the key
		}
		i += 1; //iterator 
	}
}

void HashTableQuad::printKeysAndIndexes()
//TIME:  O(n)
//SPACE: O(1)
{
	int i = 0;
	while (i < size) { //iterating through each element

		if (table[i] != 0) //if the key is not 0
		{
			std::cout << i << ", " << table[i] << std::endl; //print the statement
		}
		i += 1; //iterator 
	}
}


int HashTableQuad::getNumKeys() {

	return keys;
}

int HashTableQuad::getTableSize() {

	return size;
}

double HashTableQuad::getMaxLoadFactor() {

	return loadFactor;
}

int HashTableQuad::insertProbe(int n)
//TIME: O(n)
//SPACE: O(n), n is size of table
{

	if (isIn(n) == true) { //if the element is in the table
		return probeIsIn(n); //return the number of probes
	}
	int position = n % size; //integer to initialize the position
	int probe = 0;


	//Runs until number is inserted at correct spot
	while (table[position] != 0) {
		position = (n + (probe*probe)) % size; //calculates the next possible position using linear probing
		probe++; //increments the probe to keep track of how many times we have probed

		if (probe > size) { //if the probe exceeds size, then rehasing is impossible
			return size;
		}

	}

	table[position] = n; //insert n at the position
	keys++; //increase the key counter

	if (probe == 0) { //even if the value is found immediatly, a single probe was still used
		return 1;
	}
	else {
		return probe;
	}

}

int HashTableQuad::probeIsIn(int n)
//TIME: O(n)
//SPACE: O(1)
{

	int position = n % size; //integer to initialize the position
	int probe = 0;

	//Runs until identical key is found
	while (table[position] != n) {
		position = (n + (probe*probe)) % size; //calculates the next possible position using linear probing
		probe = probe + 1; //increments the probe to keep track of how many times we have probed
	}

	if (probe == 0) { //even if the value is found immediatly, a single probe was still used
		return 1;
	}
	else {
		return probe;
	}

}

std::vector<double> HashTableQuad::simProbeSuccess()
{

	vector<double> result(9); //creates a vectore of size 9

	double totalAvg = 0;
	double avg = 0;
	double loadFactor = 0;
	int probes;
	int random = 0;

	for (int i = 1; i <= 9; i++) { //iterate for each load factor

		//Defines the load factor
		loadFactor = i / 10.0; // loadFactor = 0.1,0.2,.....,0.9

		for (int x = 0; x < 50; x++) { //running the loop multiple times will make it more accurate

			//Defines new hash table of appropriate size
			HashTableQuad newHash = HashTableQuad(1000, loadFactor); //new table with size of 1000 and same laod factor

			//Adds the number of probes for each element
			for (int k = 0; k < 1000; k++) { //iterating through the size of the table

				random = (rand() + 1) * (rand() + 1); //get a random value
				probes = newHash.insertProbe(random); //add the value into the table and get the num of probes needed
				avg += probes; //add the probes needed into the avg
			}

			avg /= 1000.0; //find the average 

			totalAvg += avg; //add that average to the total average
		}

		totalAvg /= 50;

		result[(i - 1)] = totalAvg;
	}

	return result;
}
