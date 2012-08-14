/******************************************************************************
 Title: DynamicStringArray.cc
 Author: Robert O'Connor
 Created on: July 21, 2012
 Description: an array capable of expanding.
 Modifications:
 *******************************************************************************/

#include "DynamicStringArray.h"
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;
// predicate function used by remove_copy_if
bool predicate(string str, string str2) {
	return str == str2;
}

DynamicStringArray::DynamicStringArray() :
		size(0), dynamicArray(NULL) {
}

DynamicStringArray::~DynamicStringArray() {
	if (this->size && this->dynamicArray) {
		delete[] this->dynamicArray;
		this->dynamicArray = NULL;
	}
}

int DynamicStringArray::getSize() {
	return this->size;
}

void DynamicStringArray::addEntry(string str) {
	if (!this->size && !this->dynamicArray) { // e.g., it's NULL or this->size=0
		this->dynamicArray = new string[++this->size];
		this->dynamicArray[0] = str; // this->size = 1
	} else { // not NULL
		size_t oldSize = size; // store so that I can access the old size.
		string *tmp = new string[++this->size];
		copy(this->dynamicArray, this->dynamicArray + oldSize, tmp);
		tmp[size - 1] = str;
		delete[] this->dynamicArray;
		this->dynamicArray = NULL;
		this->dynamicArray = tmp;
	}
}

bool DynamicStringArray::deleteEntry(string str) {
	if (!this->dynamicArray || !size) {
		return false;
	} else if(!this->containsValue(str)) {
		cout<<str<<" is not present in this array."<<endl;
		return false;
	}else {
		size_t oldSize = size;
		size_t newSize = --size;
		bool found = false;
		string *tmp = new string[newSize];
		size_t index;
		for(int i = 0;i < oldSize && !found;i++) {
			if(str == this->dynamicArray[i]) {
				index = i;
				found = true;
			}
		}
		for(int i=0,j=0;i<oldSize,j<newSize;i++) {
			if(i!=index) {
				tmp[j++] = this->dynamicArray[i];
			}
		}
		delete[] this->dynamicArray;
		this->dynamicArray = NULL;
		this->dynamicArray = tmp;
		return true;
	}
}


string* DynamicStringArray::getEntry(int index) const {
	if (!this->dynamicArray || !this->size || this->size < 0 || index > this->size - 1) {
		return NULL;
	} else {
		return &this->dynamicArray[index];
	}
}

bool DynamicStringArray::containsValue(string s) {
	for(int i=0;i<size;i++) {
		if(s==this->dynamicArray[i]) {
			return true;
		}
	}
	return false;
}
