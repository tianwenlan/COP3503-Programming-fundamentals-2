/******************************************************************************/
/*!
 * @file COP3503su14_Proj1_WenlanTian.h
 * @brief Define the procedure of SetOperation class
 *
 * Copyright(C): Wenlan Tian 
 * Everyone is permitted to copy and distribute.
 *
 * @details Declear API functions which are provided by Set Operation
 *
 * $Date: 2014-05-30 08:43:53 $
 * $Revision: 1 $
 */
/******************************************************************************/

#ifndef __PROJ1_H__
#define __PROJ1_H__

#include <iostream>
#include <fstream>
#include <string>
#include <set>

namespace proj1
{
  class Set
  {
    public:
      void reset();
      void print();
      void printToFile(std::string fileName);
      int  getLength();
      std::string  getValue(int index);
      int  findItem(std::string& str);
      bool insertItem(std::string& value);
      bool deleteItem(std::string& value);                
      bool createSetFromFile(std::string inFileName); 
      
      /* sets operation */
      bool unionSets(Set& peerSet);
      bool subtractSets(Set& peerSet);
      bool differenceSets(Set& peerSet);
      bool intersectSets(Set& peerSets);
      
      Set();  
         
    private:
      std::string setArray[100];
      int length;
      int maxLength;
  }; 
    
}

#endif /* __PROJ1_H__ */
