#include "enor.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

Enor :: Enor(const string& file){
f.open(file.c_str());
if(f.fail()){
    throw FILE_ERROR;
}
}
istream& operator >>(istream& is , InData& d){
    string line;
    getline(is,line,'\n');
    istringstream ss(line);
    ss >> d.name >> d.chname;
    Fish tmp;
    d.vec.clear();
    while(ss>>tmp.name>>tmp.size){
        d.vec.push_back(tmp);
}
    return is;
}
void Enor ::read(){
    if(f>>dx){
        sx=norm;
    }
    else{
        sx=abnorm;
    }
}
void Enor :: next(){
    if(sx==abnorm){
        _end=true;
    }
    else{
        _end=false;
        current.chname=dx.chname;
        current.cnt=0;
        while(sx==norm && current.chname == dx.chname){
            current.cnt++;
            read();
        }
    }
}
void Enor ::first(){
    read();
    next();

}
