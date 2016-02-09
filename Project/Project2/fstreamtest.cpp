/* fstreamtest.cpp
 * by R. Newman 6/16/14
 * Simple file I/O program that shows a way to 
 *   read a filename from user/console input
 *   convert the string into a C string *char
 *     for use as a parameter to open()
 *   open and use input and output streams
 *     from file names
 *   read lines from the input file
 *	parse these lines as streams
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
#include <sstream>
#include <string>

using namespace std;

const bool VERBOSE(true);

int main() 
{
  ifstream input;
  ofstream output;

  cout << "Input file should have a string and a number per line" << endl;

	// Get input file name into a string
  string inFileName;
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
    cerr << "File " << inFileName << " cannot be opened" << endl;
    return -1;
  }

	// Get output file name into a string
  string outFileName;
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
    cerr << "File " << outFileName << " cannot be opened" << endl;
    return -2;
  }

  // While there is more to the input file, get a word 
  //   and copy it to the output file on its own line.
  string line;
  while (getline(input,line))
  {
    string s;
    int i;

        // convert input line into a stream
    istringstream linestream(line);
        // read from stream a string and an int
    linestream >> s >> i;

        // see if user is ready to stop
    if (s == "STOP") break;

    bool read_fail = false;
        // if the line has no printable chars
        // or if the second string is not a number
        // the input line is malformed
    if (read_fail = linestream.fail())
      {
      cerr << "input failure" << endl;
        // on input failure, just go to next line
      continue;
      }
    output << s << " " << i << endl;

        // now see if there is more stuff in the line
    if (!linestream.eof())
    {
        // try to read it
      linestream >> s;
      if (!linestream.fail())
                // if read a string, then bad line
        cerr << "line malformed: " << line << endl;
                // if fail to read a string,
                // then just white space left,
                // no big deal
    }

        // reset s to empty so we don't print junk
    s = "";
  }

        // print creepy signoff message ;)
  cout << "Bye bye for now" << endl;

  return 0;

}
