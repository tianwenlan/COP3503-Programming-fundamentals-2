/* fileIODemo.cpp
 * by R. Newman 5/20/14
 * Simple file I/O program that shows a way to 
 *   read a filename from user/console input
 *   convert the string into a C string *char
 *     for use as a parameter to open()
 *   open and use input and output streams
 *     from file names
 *   read strings from the input file
 *   write strings to the ouput file
 *   test for end of input file
 *   handle situation where input file is not
 *     yet at eof, but has read the last 
 *     word (including puctuation) from the
 *     input stream by clearing the string
 *     (otherwise the last word will appear
 *     twice on the output).
 *   perform some string operations:
 *     length()
 *     clear()
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const bool VERBOSE(true);

int main() 
{
  ifstream input;
  ofstream output;

  string inFileName;
  string outFileName;
  string tempString;

	// Get input file name into a string
  cout << "Input file name: " << flush;
  cin >> inFileName;

  if (VERBOSE)
  {
    cout << "Input file name is " << inFileName << endl;
  }

  // Convert filenames to C strings and use stream.open()
  input.open(inFileName.c_str());
  if (input.fail())
  {
    cout << "File " << inFileName << " cannot be opened" << endl;
    return -1;
  }

	// Get output file name into a string
  cout << "Output file name: " << flush;
  cin >> outFileName;

  if (VERBOSE)
  {
    cout << "Output file name is " << outFileName << endl;
  }

  // Convert filenames to C strings and use stream.open()
  // When opening output file, it will create the file if it
  // does not exist, and will clobber it if it does.
  output.open(outFileName.c_str());
  if (output.fail())
  {
    cout << "File " << outFileName << " cannot be opened" << endl;
    return -2;
  }

  // While there is more to the input file, get a word 
  //   and copy it to the output file on its own line.
  while (!input.eof())
  {
    input >> tempString;
    if (VERBOSE)
    {
      cout << " Length is " << tempString.length() << " for " << flush;
    }

    if (tempString.length() > 0)
    {
      if (VERBOSE)
      {
        cout << tempString << endl;
      }
      output << tempString << endl;
    }
    else
    {
    if (VERBOSE)
      {
        cout << "No more input" << endl;
      }
    }

    // This is needed to keep the last non-whitespace word
    // read in from being printed twice if the file ends in
    // whitespace, including a newline.
    tempString.clear();
  }
  cout << endl;

  return 0;

}
