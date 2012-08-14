/******************************************************************************
Title: DynamicStringArray.h
Author: Robert O'Connor
Created on: July 21, 2012
Description: an array capable of expanding (and shrinking) its size.
*******************************************************************************/
#ifndef DYNAMICSTRINGARRAY_H
#define	DYNAMICSTRINGARRAY_H
#include <string>

class DynamicStringArray {
  public:
    /**
     * Creates an empty array
     */
    DynamicStringArray();


    /**
     * Destructor
     */
    ~DynamicStringArray();



    /**
     * Returns the current size.
     */
    int getSize();

    /**
     * Add an entry.
     * Pre-condition: str is defined.
     * Post-condition: str is added to the array.
     *
     * @param str the string to add
     */
    void addEntry(std::string str);


    /**
     * Delete the entry s.
     * Pre-condition: s is defined
     * Post-condition: if s is in the array, then it is removed.
     * Note: if more than one occurance of s exists, then only the first will be removed.
     * @param str the string to remove.
     */
    bool deleteEntry(std::string str);

    /**
     * Retrieve the entry at the given index
     * Pre-condition: index>0
     * Post-condition: the element at the given index is returned.
     *
     * @param index the index
     */
    std::string*  getEntry(int index) const;



  private:
    std::string *dynamicArray;
    int size;

    /**
     * Pre-condition: s is defined.
     *
     * Simply determine if a given value.
     *
     * @param s the string to searcb for
     * @return true or false depending on if it exists.
     */
    bool containsValue(std::string s);

};
#endif
