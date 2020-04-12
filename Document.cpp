#include "Document.h"

void Document::printAll(){ 
    for (it = text.begin();it!=text.end();it++){
        cout << *it << endl;
    }  
    }
void Document::addlines(string line){ 
    if(text.empty()){
        text.push_back(line);
        it = text.begin();
    }
    else{
        it++;
        it = text.emplace ( it, line );
    }
    
    }

void Document::changelines(vector<string> vec){
    text.erase(it);
    it = text.insert(it,vec.begin(),vec.end()) +vec.size() -1;
}

void Document::addlinesbefore(string line){
    if(text.empty()){
        text.push_back(line);
        it = text.begin();
    }
    else{
        it = text.emplace ( it, line );
        it++;
    }
}
void Document::printline(string line){
    stringstream l(line); 
    int x = 0;
    l >> x; 
    it = text.begin()+(x-1);
    cout << x << "\t"<<*it<<endl;
}

void  Document::attachline(string line){
    stringstream l(line); 
    char temp ;
    int firstline =0,secondline=0;
    l >> firstline;
    l >> temp;
    l >> secondline;
    firstline--;
    secondline--;
    string s1 = *(text.begin()+firstline);
    string s2 = *(text.begin()+secondline);
    s1 = s1 + " "+s2;
    text.erase(text.begin()+secondline);
    *(text.begin()+firstline) = s1;
    it = text.begin()+firstline;
}

void Document::find(string line){
    for(it ; it != text.end();it++){
        size_t found =  (*it).find(line);
        if (found!=std::string::npos){
            cout << *it << endl;
            break;
        }
    }    
}
void Document::findback(string line){
    for(it ; it != text.begin();it--){
        size_t found =  (*it).find(line);
        if (found!=std::string::npos){
            cout << *it <<endl;
            break;
        }
    }    
}
void Document::replace(string line){
    vector<string> words;
    istringstream f(line);
    string s;    
    while (getline(f, s, '/')) {
        words.push_back(s);
    }
    string old  = words.at(1) ,nw = words.at(2);
    (*it).replace((*it).find(old),old.length(),nw);
}

void Document::del(string line){
    stringstream l(line); 
    int x = 0;
    l >> x; 
    it = text.begin()+(x-1);
    text.erase(it);
}
void Document::quit(){
    string filename = text.at(0);
    filename.append(".txt");
    ofstream outFile(filename);
    // the important part
    for (const auto &e : text) outFile << e << "\n";
}
