/******************************************************************************
 Title: main.cc
 Author: Robert O'Connor
 Created on: July 22, 2012
 Description: Entry point for the application which transcribes a DNA strand
 to an RNA strand and provides for some other handy things.
 Usage: make (will botb build and run).
 Build with: make
 Modifications:
 *******************************************************************************/

#include <iostream>
#include <iomanip>

#include "main.h"
#include "DynamicStringArray.h"
using namespace std;

int main(int argc, char* argv[]) {
	DynamicStringArray arr;
	arr.addEntry("hai");
	arr.addEntry("hi");
	arr.addEntry("hi");
	cout<<arr.getSize();
	return 0;

}

