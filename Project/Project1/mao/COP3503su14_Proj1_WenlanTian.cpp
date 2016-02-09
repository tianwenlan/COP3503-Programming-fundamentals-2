/******************************************************************************/
/*!
 * @file COP3503su14_Proj1_WenlanTian.cpp
 * @brief Define the procedure of SetOperation class
 *
 * Copyright(C): Wenlan Tian 
 * Everyone is permitted to copy and distribute.
 *
 * @details Define detail API functions which are provided by Set Operation
 *
 * $Date: 2014-05-30 08:43:53 $
 * $Revision: 1 $
 */
/******************************************************************************/

#include "COP3503su14_Proj1_WenlanTian.h"

namespace proj1
{
  
  void Set::reset()
  {
      int i;
      for (i = 0; i < maxLength; i++)
      {
          setArray[i] = std::string("");
      }
      length = 0;
      std::cout << "Reset completed" << std::endl;
  }
  
  void Set::print()
  {
      int i;
      for (i = 0; i < length; i++)
      {
          std::cout << "Item " << i << ": " <<setArray[i].c_str() << std::endl;
      }
      std::cout << i << " items in total" << std::endl;
      std::cout << "Print completed" << std::endl; 
  }
  
  void Set::printToFile(std::string fileName)
  {
       //you need define this one.
  } 
  
  int Set::getLength()
  {
      return length;
  }
  
  std::string Set::getValue(int index)
  {
      return setArray[index];
  }
  
  int Set::findItem(std::string& str)
  {
      int i;
      for (i = 0; i < length; i++)
      {
          if(setArray[i] == str)
	  {
	     // std::cout << "Find completed: Item index: " << i << std::endl;
	      return i;
	  }
      }
      //std::cout << "Find completed: Item not found." << std::endl;
      return -1;
  }
  
  bool Set::insertItem(std::string& str)
  {
      int i;
      int j;
      
      i = findItem(str);      
      if ( i != -1)
      {
          //std::cout << "WARN: Item already exist!" << std::endl;
	  return true;
      }
      else if(length == maxLength)
      {
	  std::cout << "Error: setArray overflow" << std::endl;
	  return false;
      }
      
      setArray[length] = str;
      
      length++;
      //std::cout << "Insert completed!" << std::endl;
      return true;
  }
  
  bool Set::deleteItem(std::string& value)
  {
      int i;
      
      i = findItem(value);
      if( i != -1)
      {
          while(i < (length-1) )
	  {
	    setArray[i] = setArray[i+1];
	    i++;
	  }
	  setArray[length-1] = std::string("");
	  length--;
      }
      else
      {
          //std::cout << "WARN Item: " << value << " doesn't exist!" << std::endl;
      }
      //std::cout << "Delete completed!" << std::endl;
      return true;
  }

  bool Set::createSetFromFile(std::string inFileName)
  {
       std::string tempStr;
       std::ifstream inStream;
       
       inStream.open(inFileName.c_str(), std::ifstream::in);        
       if( !inStream.is_open())
       {
           std::cout << "Error: file can't be open!" << std::endl;
	   return false;
       }
       if( inStream.fail())
       {
           std::cout << "Error: open operation failed!" << std::endl;
	   return false;
       }
       
       while(inStream >> tempStr)
       {
	 // std::cout << "file element: " << tempStr << std::endl;
	  insertItem(tempStr);
       }
       
       //print();
       
       std::cout << "New Set Loaded" << std::endl;
       
       return true;
  }
  
  bool Set::unionSets(Set& peerSet)
  {
      int i;
      std::string tempValue;
      int len = peerSet.getLength();
      for (i=0; i < len; i++)
      {
          tempValue = peerSet.getValue(i);
	  this->insertItem(tempValue);
      }
      this->print();
      std::cout << "Union Completed!" << std::endl;
      return true;
  }
  
  bool Set::subtractSets(Set& peerSet)
  {
      int i;      
      std::string tempValue;
      int len = peerSet.getLength();
      for (i=0; i < len; i++)
      {
          tempValue = peerSet.getValue(i);
	  this->deleteItem(tempValue);
      }
      this->print();std::cout << "Subtract Completed!" << std::endl;
      return true;
  }
  
  bool Set::differenceSets(Set& peerSet)
  {
      int i;      
      std::string tempValue;
      int len = peerSet.getLength();
      for (i=0; i < len; i++)
      {
          tempValue = peerSet.getValue(i);
	  if( this->findItem(tempValue) == -1)
	  {
	      this->insertItem(tempValue);
	  }
	  else
	  {
	      this->deleteItem(tempValue);
	  }
      }
      this->print();
      std::cout << "Difference Completed!" << std::endl;
      return true;
  } 
  
  bool Set::intersectSets(Set& peerSet)
  {
      int i;      
      std::string tempValue;
      int len = this->getLength();
      for (i= len -1; i >= 0; i--)
      {
          tempValue = this->getValue(i);
	  if( peerSet.findItem(tempValue) == -1)
	  {
	      this->deleteItem(tempValue);
	  }
      }
      
      this->print();
      std::cout << "Intersetction Completed!" << std::endl;
      return true; 
  }

  Set::Set():length(0),maxLength(100)
  {
      std::cout << "Init set length is " << length << std::endl;
      std::cout << "Max Item number is " << maxLength << std::endl;
  } 

  
} /*namespace proj1 */



/*******************************************************/
/*                                                     *
 *    Main function to use the class, as an example    *
 *                                                     */
/*******************************************************/

using namespace proj1;

int main()
{
   
   Set mySet;
   Set urSet;
   
   Set& refUrSet = urSet;
   

   mySet.createSetFromFile("list1.txt");
   urSet.createSetFromFile("list2.txt");       
   std::cout << "-----------------\n";
   std::cout << "Print mySet:\n";
   mySet.print();
   std::cout << "-----------------\n";
   std::cout << "print urSet:\n";
   urSet.print();
   std::cout << "-----------------\n"; 
 
 
   
   std::cout << "*******************************************" << std::endl;
   std::cout << "Initialize mySet and your set, do union" << std::endl;   
   mySet.unionSets(refUrSet);
   
   
   std::cout << "*******************************************" << std::endl;   
   std::cout << "Initialize mySet and your set, do subtract" << std::endl;
   mySet.createSetFromFile("list1.txt");
   urSet.createSetFromFile("list2.txt");  
   mySet.subtractSets(refUrSet);  

   std::cout << "*******************************************" << std::endl;
   std::cout << "Initialize mySet and your set, do different" << std::endl;   
   mySet.createSetFromFile("list1.txt");
   urSet.createSetFromFile("list2.txt");  
   mySet.differenceSets(refUrSet);

   std::cout << "*******************************************" << std::endl;
   std::cout << "Initialize mySet and your set, do intersect" << std::endl;      
   mySet.createSetFromFile("list1.txt");
   urSet.createSetFromFile("list2.txt");  
   mySet.intersectSets(refUrSet);   
   
   return 1;
}
