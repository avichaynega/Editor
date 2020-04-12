#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> 
using namespace std;
class Document{
public:
void del(string line);
void replace(string line);
void find(string line);
void findback(string line);
void changelines(vector<string>);
void attachline(string line);
void addlines(string line);
void addlinesbefore(string line);
void printAll();
void printline(string line);
void quit();
Document(){}

private:
vector<string> text;
vector<string>::iterator it;

}; 
