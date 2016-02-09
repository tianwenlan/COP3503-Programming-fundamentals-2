all: Proj3

Proj3: COP3503su14_Proj3_WenlanT_main.o COP3503su14_Proj3_WenlanT_menuList.o tinyxml.o tinyxmlerror.o  tinyxmlparser.o tinystr.o
	g++ -o Proj3 COP3503su14_Proj3_WenlanT_main.o COP3503su14_Proj3_WenlanT_menuList.o tinyxml.o tinyxmlerror.o tinyxmlparser.o tinystr.o


COP3503su14_Proj3_WenlanT_main.o: COP3503su14_Proj3_WenlanT_main.cpp COP3503su14_Proj3_WenlanT_main.h COP3503su14_Proj3_WenlanT_menuList.h
	g++ -c COP3503su14_Proj3_WenlanT_main.cpp

COP3503su14_Proj3_WenlanT_menuList.o: COP3503su14_Proj3_WenlanT_menuList.cpp COP3503su14_Proj3_WenlanT_menuList.h tinyxml.h
	g++ -c COP3503su14_Proj3_WenlanT_menuList.cpp



tinyxml.o: tinyxml.cpp tinyxml.h
	g++ -c tinyxml.cpp
tinyxmlerror.o: tinyxmlerror.cpp tinyxml.h
	g++ -c tinyxmlerror.cpp
tinyxmlparser.o: tinyxmlparser.cpp tinyxml.h
	g++ -c tinyxmlparser.cpp
tinystr.o: tinystr.cpp tinystr.h
	g++ -c tinystr.cpp


clean:
	rm -rf *.o Proj3
