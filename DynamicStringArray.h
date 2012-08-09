/******************************************************************************
Title: DynamicStringArray.h
Author: Robert O'Connor
Created on: July 21, 2012
Description: A resizable array
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
     *
     * @param str the string to add
     */
    void addEntry(std::string str);


    /**
     * Delete the entry s.
     * Note: if more than one occurance of s exists, then only the first will be removed.
     */
    bool deleteEntry(std::string s);

    /**
     * Retrieve the entry at the given index
     * Pre-condition: index>0
     *
     * @param index the index
     */
    std::string  getEntry(int index);



  private:
    std::string *dynamicArray;
    int size;

};
#endif
