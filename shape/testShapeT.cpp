#include <iostream>
#include <string>
#include <vector>
#include "ShapeT.h"
#include "CircleT2.h"
using namespace std;

int main()
{
  Shape<string> s1;
  Shape<string> s2("yellow",true,"Shape 2");
  Circle<string,int> c1;
  Circle<string,int> c2(5);
  Circle<string,int> c3(3,"orange",true,"C3");
  Circle<string,double> cd1;
  Circle<string,double> cd2(6.2);
  Circle<string,double> cd3(4.3,"blue",true,"CD3");
  vector<Shape<string> > shapeList;
  vector<Shape<string> *> shapePList;

  string color;
  bool filled;

  cout << "default s1: " << s1.toString() << endl;
  cout << "s2: " << s2.toString() << endl;
  cout << "default c1: " << c1.toString() << endl;
  cout << "c2: " << c2.toString() << endl;
  cout << "c3: " << c3.toString() << endl;
  cout << "default cd1: " << cd1.toString() << endl;
  cout << "cd2: " << cd2.toString() << endl;
  cout << "cd3: " << cd3.toString() << endl;

  cout << "Enter color: " << flush;
  cin >> color;
  cout << "Enter filled (1=filled, 0=not filled): " << flush;
  cin >> filled;
  cout << (filled ? "Filled " : "Unfilled ") << color << endl;

  s1.setColor(color);
  s1.setFilled(filled);
  c1.setColor(color);
  c1.setFilled(filled);
  cd1.setColor(color);
  cd1.setFilled(filled);

  cout << "new s1: " << s1.toString() << endl;
  cout << "new c1: " << c1.toString() << endl;
  cout << "new cd1: " << cd1.toString() << endl;

  cout << endl;
  shapeList.push_back(s1);
  shapeList.push_back(c1);
  shapeList.push_back(cd1);
  shapeList.push_back(s2);
  shapeList.push_back(c2);
  shapeList.push_back(cd2);
  shapeList.push_back(c3);
  shapeList.push_back(cd3);

  shapePList.push_back(&s1);
  shapePList.push_back(&c1);
  shapePList.push_back(&cd1);
  shapePList.push_back(&s2);
  shapePList.push_back(&c2);
  shapePList.push_back(&cd2);
  shapePList.push_back(&c3);
  shapePList.push_back(&cd3);

  cout << "Shape list:" << endl;
  for (int i=0; i<shapeList.size(); ++i)
  {
    cout << "Shape " << i << ": " << shapeList[i].toString() << endl;
  }

  cout << "Shape pointer list:" << endl;
  for (int i=0; i<shapeList.size(); ++i)
  {
    cout << "Shape " << i << ": " << shapePList[i]->toString() << endl;
  }

  return 0;
}

