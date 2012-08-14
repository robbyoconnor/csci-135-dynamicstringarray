/******************************************************************************
 Title: main.cc
 Author: Robert O'Connor
 Created on: July 22, 2012
 Description: Tester for Dynamic String Array project 3.
 Usage: make (will botb build and run).
 Build with: make
 Modifications:
 *******************************************************************************/

#include <iostream>
#include <iomanip>

#include "DynamicStringArray.h"
void testMaintainsOrder();
using namespace std;

int main(int argc, char* argv[]) {
	DynamicStringArray arr;
	cout << "Adding some stuff..." << endl << endl;
	arr.addEntry("Snap");
	arr.addEntry("Crackle");
	arr.addEntry("Pop");
	arr.addEntry("I'm out of Rice Krispies :'(");
	cout << "Size should be 4: " << ((arr.getSize() == 4) ? "Success" : "Failure") << endl << endl;
	cout << "Done adding stuff! Size is now: " << arr.getSize() << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "Items in the array are: ";
	for(int i = 0;i < arr.getSize();i++) {
		cout << *arr.getEntry(i) << ((!(i != arr.getSize() - 1)) ? "" : ", ");
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------- " << endl;
	cout << "Okay, now that we know that adding works...time to see if deleting works...hold onto your hat(s)..." << endl;
	cout << "Deleting \"Snap\": " << ((arr.deleteEntry("Snap")) ? "Success" : "Failure") << endl;
	cout << "Size should be 3: " << ((arr.getSize() == 3) ? "Success" : "Failure") << endl << endl;
	cout << "After deleting \"Snap\", size is now: " << arr.getSize() << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "The array now contains: ";
	for(int i = 0;i < arr.getSize();i++) {
		cout << *arr.getEntry(i) << ((!(i != arr.getSize() - 1)) ? "" : ", ");
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "\n\nDoes deleting an item that does not exist fail (Success means it failed correctly): " << (
			!arr.deleteEntry("Captain Crunch") ? "Success" : "Failure") << endl;
	cout << "\n\nNow ensure nothing wonky happened as a result, nothing should have changed...size should still be 3." << endl;
	cout << "Size should be 3: " << ((arr.getSize() == 3) ? "Success" : "Failure") << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "Contents are: ";
	for(int i = 0;i < arr.getSize();i++) {
		cout << *arr.getEntry(i) << ((!(i != arr.getSize() - 1)) ? "" : ", ");
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "\nDelete everything and test that the size decrements correctly..." << endl;
	arr.deleteEntry("Crackle");
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "After deleting \"Crackle\", Contents are: ";
	for(int i = 0;i < arr.getSize();i++) {
		cout << *arr.getEntry(i) << ((!(i != arr.getSize() - 1)) ? "" : ", ");
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	arr.deleteEntry("Pop");
;	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << endl << "After deleting \"Pop\", Contents are: ";
	for(int i = 0;i < arr.getSize();i++) {
		cout << *arr.getEntry(i) << ((!(i != arr.getSize() - 1)) ? "" : ", ");
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	arr.deleteEntry("I'm out of Rice Krispies :'(");

	cout << "After deleting \"I'm out of Rice Krispies :'(\" Contents are: "<<endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	for(int i = 0;i < arr.getSize();i++) {
		cout << *arr.getEntry(i) << ((!(i != arr.getSize() - 1)) ? "" : ", ");
	}
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "\n\nShould be empty: " << ((arr.getSize() == 0) ? "Success" : "Failure") << endl;
	cout << "\n\nNow let's test what happens when the list is not defined and the size is equal to zero" << endl;
	cout << "\n\nGet operation should return NULL: " << ((!arr.getEntry(0)) ? "Success" : "Failure") << endl;
	cout << "\n*****************************************************************************************************" << endl;
	cout << "Create a new DynamicStringArray, but add nothing to it and test that things behave according to spec." << endl;
	DynamicStringArray arr2; // size==0, array = NULL
	cout << "\nTry to delete an item on an empty array (Success means it failed as expected): " << (
			(!arr2.deleteEntry("Toucan Sam")) ? "Success" : "Failure") << endl;
	cout << "\n\nGet operation should return NULL: " << ((!arr.getEntry(0)) ? "Success" : "Failure") << endl;
	cout << "Now test whether order is maintained." << endl;
	cout << "\n*****************************************************************************************************" << endl;
	testMaintainsOrder();
	return 0;
}

void testMaintainsOrder() {
	DynamicStringArray arr2;
	arr2.addEntry("Snap");
	arr2.addEntry("Crackle");
	arr2.addEntry("Pop");
	arr2.addEntry("I'm out of Rice Krispies :'(");
	cout << "Size should be 4: " << ((arr2.getSize() == 4) ? "Success" : "Failure") << endl << endl;
	cout << "Done adding stuff! Size is now: " << arr2.getSize() << endl << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "Items in the array are: ";
	for(int i = 0;i < arr2.getSize();i++) {
		cout << *arr2.getEntry(i) << ((!(i != arr2.getSize() - 1)) ? "" : ", ");
	}
	cout<<endl;
	arr2.deleteEntry("Pop");
	arr2.deleteEntry("Snap");
	cout<<"\nSize should be 2: "<<((arr2.getSize()==2) ? "Success" : "Failure")<<endl;
	cout << "Items in the array are (sans \"Pop\" and \"Snap\"): ";
	for(int i = 0;i < arr2.getSize();i++) {
		cout << *arr2.getEntry(i) << ((!(i != arr2.getSize() - 1)) ? "" : ", ");
	}
	cout<<endl;
}
