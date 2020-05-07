#include <iostream>
#include "Editor.h"
#include "Document.h"
#include <string>
using namespace std;

void Editor::loop(){
    Document doc;
    string line;
    //regular expression represent all strings that start with number and end with char n
    regex end_with_n("^0|([1-9]\\d)(\\d+)(n)$");
    
    //regular expression represent all strings that start with number and end with char d
    regex end_with_d("^0|([1-9]\\d)(\\d+)(d)$");
    
    //regular expression represent all strings with the pattern like : 8,7j
    regex iandj("([[:digit:]]+)(,)([[:digit:]]+)(j)");

    //regular expression represent all strings with the pattern like : s/string1/string2/
    regex replace("(s/)(.+/)(.+/)");
    
    while (getline(cin, line))
    {
        if(line == "a"){
            
            getline(cin, line);
            while(line != "."){
            doc.addlines(line);
             getline(cin, line);
            }
            
        }

        if(line == "i"){
            getline(cin, line);
            while(line != "."){
            doc.addlinesbefore(line);
             getline(cin, line);
            }
        }
        if(line == "c"){
            getline(cin, line);
            vector<string> temp;
            while(line != "."){
                temp.push_back(line);
             getline(cin, line);
            }
            doc.changelines(temp);
            
        }
        //check if the line is pattern of 'in' for example : '2n'
        if(regex_match(line,end_with_n)){
           
            doc.printline(line);
        }
        if(line == "%p" ){
           
            doc.printAll();
        }
        if(regex_match(line,iandj)){
            doc.attachline(line);
        }
        if(regex_match(line,end_with_d)){
            doc.del(line);
        }
        if(regex_match(line,replace)){
            doc.replace(line);
        }
        if(line.at(0) == '/'){
            doc.find(line.substr(1,line.size()));
        }
        if(line.at(0) == '?'){
            doc.findback(line.substr(1,line.size()));
        }
        if(line == "Q"){
            doc.quit();
        }
        
    }
}

