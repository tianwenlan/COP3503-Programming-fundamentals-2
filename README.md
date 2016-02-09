# COP3503-Programming-fundamentals-2

Lab
---------------


Homework
----------------

Project
-----------------
1. Design, document, implement, and test a system for entering, storing, manipulating, and printing sets of various sorts. The program maintained a current set and a current verbose state.
2. Modify the design for basic set operations to handle multisets, then document, implement, and test it. The program maintained a current multiset and a current verbose state. The multiset and its operations were implemented using classes. 
3. Implemented a program that reads, names, stores, and operates on recipes. Recipes consist of a title, an ingredient list, and a set of instructions. Instructions may also contain equipment information. Operations include combining a set of recipes to arrive at a combined ingredient list, combined equipment, and combined instructions. They also include taking inventory lists of available ingredients and equipment and subtracting them from combined lists to arrive at shopping lists of needed items.
4. This program took the set and multiset specifications and overloaded a number of operators: +/+=(union), -/-=(subtraction), =(deep copy), */*=(intersect), ^/^=(difference), ==(equality), <(proper subset), <=(subset), <<(stream out) and >>(stream in). 
Templates were used to allow a set or multiset holds items of any type. Multiset had an integer associated with each item that indicates the number of that item in the multiset. The base MySet class and a derived MyMultiset class from mySet were implemented.
