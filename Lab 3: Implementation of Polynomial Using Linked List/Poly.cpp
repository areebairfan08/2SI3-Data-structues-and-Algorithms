#include "Poly.h"
#include "math.h"
#include <iostream>


Poly::Poly() //O(1)
//TIME: O(1) -> the linked list is declared once
//SPACE: O(1) -> it only allocates memory for one node regardless of the size of the polynomial.
{
	//creates an empty linked list with a dummy header node representing a zero polynomial.
	head = new PolyNode(-1, 0, NULL); //(deg, coeff, next)
}

Poly::Poly(const std::vector<int>& deg, const std::vector<double>& coeff) 
//TIME: O(n) where n is equal to the length of coeff/deg
//SPACE: O(n) because were (n) new objects to store deg/coeff values (increases as size (n) increases)
{
	head = new PolyNode(-1, 0, NULL); //serves as head of the node with -1 deg and 0 coeff //O (1)
	PolyNode* curr = head; //pointer starts at dummy node //O(1)

	for (unsigned int i = 0; i < coeff.size(); i++, curr = curr->next) { //looping through the degree and coeff arrays //O(n)
		curr->next = new PolyNode(deg[i], coeff[i], NULL); //creates a new node with degree and coeff at position i 
	}
}
Poly::~Poly() //frees the memory allocated for the linked list nodes in a polynomial
//TIME: O(n) where n is equal to # of nodes
//SPACE: O(1) because it deallocates the memory without creating more
{
	PolyNode* curr = head; //pointer starts at dummy node
	while (curr) { //iterate through each node (while curr is not NULL)
		head = curr->next; // update head to next node
		delete curr; // delete current node
		curr = head; // move to next node
	}
}

void Poly::addMono(int i, double c)
//TIME: O(n) -> where n is the numebr of nodes (worst case = lowest or in between degree)
//SPACE: complexity = O(1) //only allocates for the new node
{
	// Check if coefficient is zero, in which case we don't need to add it
	if (c == 0.0) {
		return;
	}

	// Search for a node with the same degree as the input
	PolyNode* curr;
	PolyNode* previous = head; //used to keep track of the node before curr

	for (curr = head->next; curr != NULL; curr = curr->next) {
		if (i == curr->deg) {
			// If a node with the same degree is found, update its coefficient
			curr->coeff += c;

			if (curr->coeff == 0.0) {
				// If the coefficient becomes zero after adding, remove the node
				previous->next = curr->next;
				free(curr); //free up the memory
			}
			return;
		}
		previous = curr; //keep track of the previous node in the list
	}

	// If a node with the same degree was not found, add a new node (since it can't be added onto any other node)
	
	PolyNode* temp;
	previous = head;

	for (curr = head->next; curr != NULL; curr = curr->next) {
		if (i > curr->deg) {
			// If the new node has the highest degree, insert it at the beginning
			previous->next = new PolyNode(i, c, curr);
			return;
		}

		if (i < previous->deg && i > curr->deg) {
			// If the new node has a degree between two existing nodes, insert it in between
			temp = curr->next; //store the node after the inserted node //temp shifts elements over to add the monomial between
			previous->next = new PolyNode(i, c, temp);
			return;
		}
		previous = curr;
	}

	// If the new node has the lowest degree, insert it at the end
	previous->next = new PolyNode(i, c, NULL);
}


void Poly::addPoly(const Poly& p)   //cannot be modified within the function
//TIME: O(n^2) bc of the while and nested for loop in addmono
//SPACE: O(n) -> only create temp codes and no need to allocate more memory
{
	PolyNode* curr = p.head->next; //current points to the node after the head of polynomial 'p'

	while (curr != NULL) //O(n)
	{
		addMono(curr->deg, curr->coeff); //add mono function was used to 
		curr = curr->next; // move to the next node in the input polynomial
	}
}

void Poly::multiplyMono(int i, double c) //x^4 + x^2 p = 2X^3 -> 2x^7 + 2x^5
//TIME: O(n) -> since we traverse through the list and visit each node once
//SPACE: O(1) -> we only create the 
{
	if (c == 0) { //if the coeff is 0, everything multiplied will also become zero
	head->next = NULL; 
	}

	PolyNode* newNode = head->next; 
	while (newNode) { //loop through the linked list (until NULL is reached)
		newNode->coeff *= c; //multiply each coeff by c in the list
		newNode->deg += i; //add i onto the degree of each node in the list
		newNode = newNode->next; //move onto the next node
	}
}

void Poly::multiplyPoly(const Poly& p) //multiplies this polynomial by polynomial p
//TIME: O(n^3) where n is length of polynomial -> the overall function is O(n)
//but the time for multiplyMono is also O(n)
//SPACE: O(n^2) this is because it creates two additional poly objects (temp and sum) and each can have (n) nodes
//since the space usage is not temporary, each object has space complexity O(n)

{ 
	//check to see if inputs are zero
	if (p.head->next == NULL) {
		this->~Poly(); //deletes the original list by using the deconstructor 
		head = new PolyNode(-1, 0, NULL); //create new this polynomial with value of zero 
		return;
	}

	//multiply all elements, add together all elements
	PolyNode* curr = p.head->next;
	Poly temp;
	Poly sum;

	//store the original this polynomial in another polynomial
	duplicate(temp);

	while (curr != NULL) //iterate till curr is not null
	{
		temp.multiplyMono(curr->deg, curr->coeff); //use multilyMono to go through each node in p
		sum.addPoly(temp); //adding the sum of temp into sum list
		duplicate(temp); //reset temp to original this polynomial by creating a deep copy

		curr = curr->next; //move to next node
	}

	sum.duplicate(*this);  //store multSum in this polynomial by using duplicate 

	sum.~Poly(); //deallocate sum
	temp.~Poly(); //deallocate temp 
}

void Poly::duplicate(Poly& outputPoly) //performs a deep copy
//TIME: O(n) -> where n is the number of nodes, n because it iterates through the nodes
//SPACE: O(n) -> since we're creating a deep copy of the original polynomial, 
//				the size is directly proportional to the number of nodes (n)
{
	PolyNode* nodeHead = outputPoly.head; //head of both the new node and output poly is set to be the same 
	PolyNode* newNode = head->next; //start of new node list

	while (newNode) { //iterate through each node
		nodeHead->next = new PolyNode(newNode->deg, newNode->coeff, NULL); //create a new node 'Polynode' that has the same degree and coeff as og linkedl by pointing to the elements
		nodeHead = nodeHead->next; // move the nodeHead to the newly created node
		newNode = newNode->next; // move to the next node in the original linked list
	}
}

int Poly::getDegree()
//TIME: O(1) -> the method runs once
//SPACE: O(1) -> no new memory is allocated
{
	//if theres no nodes/empty list, return -1
	if (head->next == NULL) {
		return -1;
	}
	
	//if theres a degree, return the degree of the first node
	return  head->next->deg; 
}

int Poly::getTermsNo()
//O(n) -> where n is the number of nodes, the while loop iterates n times
//SPACE: O(1) -> constant space is used no new memory allocated
{
	PolyNode* curr = head->next; // set current node to first term
	int count = 0; // initialize count to 0

	while (curr) { // while current node is not NULL
		count++; // increment count
		curr = curr->next; // move to next node
	}
	return count; // return the final count
}

double Poly::evaluate(double x)
//TIME: O(n) -> where n is the numebr of nodes in the list, the while loop iterates at least n times
//SPACE:  O(1) -> no new memory is allocated
{
	PolyNode* curr = head->next; // pointer to traverse the linked list
	double result = 0; // initialize result
	while (curr) { //iterate through the nodes until we reach NULL
		result += curr->coeff * pow(x, curr->deg); // add the current term to the result
		curr = curr->next; // move to the next term
	}
	return result; // return the evaluated polynomial
}

std::string Poly::toString()
//TIME: O(n) -> where n is the number of nodes as it iterates n times to create the string
//SPACE: O(n) -> proportional to the length/number of nodes in the list
{
	std::string deg_string = std::to_string(getDegree());
	std::string result = "degree=" + deg_string + ";";
	PolyNode* curr = head;

	while (curr != NULL) {
		result += " a(" + std::to_string(curr->deg) + ")";
		result += "=" + std::to_string(curr->coeff);
		if (curr->next != NULL) {
			result += ";";
		}
		if (curr->next == NULL) {
			break;
		}
		curr = curr->next;
	}

	return result;
}