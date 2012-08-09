/******************************************************************************
Title: DynamicStringArray.cc
Author: Robert O'Connor
Created on: July 21, 2012
Description: Represents an Amino Acid
Modifications:
*******************************************************************************/
#include "DynamicStringArray.h"
#include <string>

using namespace std;

DynamicStringArray::DynamicStringArray(){
    this->dynamicArray = NULL;
    this->size = 0;
}

DynamicStringArray::~DynamicStringArray() {
	delete[] this->dynamicArray;
	this->dynamicArray = NULL;
}


int DynamicStringArray::getSize() {
	return this->size;
}

void DynamicStringArray::addEntry(string str) {
	if(!this->dynamicArray) { // e.g., it's NULL
		this->dynamicArray = new string[++this->size];
		this->dynamicArray[0] = str; // size = 1
	} else { // not NULL
		string *tmp = new string[++this->size];
		for(int i=0;i<size-1;i++) {
			tmp[i] = this->dynamicArray[i];
		}
		tmp[this->size-1] = str;
		delete[] this->dynamicArray;
		this->dynamicArray = NULL;
		this->dynamicArray = tmp;
		delete[] tmp;
		tmp = NULL;
	}
}

bool  DynamicStringArray::deleteEntry(string s) {
	if(!this->dynamicArray) {
		return false; // NEIGHHHH -- uh-oh.
	} else {

		bool found = false;
		for( int i=0;i<this->size && found; i++) {
			/*
			 * find the string and set it to an empty string; this only does it for the first
			 * occurance.
			 */
			if(this->dynamicArray[i]==s) {
				this->dynamicArray[i] = "";
				found = true;
			}
		}
		//copy things over except the empty string from the above loop... this is the conditional.
		string *tmp = new string[this->size--];
		for(int i=0;i<this->size;i++) {
			if(this->dynamicArray[i]!="") {
				tmp[i] = this->dynamicArray[i];
			}
		}
		--size;
		// switch shit and pray it doesn't leak.
		delete[] this->dynamicArray;
		this->dynamicArray = NULL;
		this->dynamicArray = tmp;
		delete[] tmp;
		tmp = NULL;
		return true; // SUCCESSSSSSSSSSSSSSSSSSSSSSSSSSS IS MINEEEEEEEEEEEEEEEEEEEEEEE..
	}
}
