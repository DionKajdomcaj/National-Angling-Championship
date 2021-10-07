#ifndef ENOR_H
#define ENOR_H
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
struct Fish{
string name;
int size;
};

struct InData{
string name;
string chname;
vector<Fish> vec;
friend istream& operator >>(istream& is , InData& d);
};

struct Res{
string chname;
int cnt;
};

class Enor{

public:
    enum Status{norm,abnorm};
    enum Exception{FILE_ERROR,EMPTY};
    Enor(const string& file);
    void first();
    void next();
    Res curr(){return current;}
    bool end(){return _end;}
private:
    bool _end;
    InData dx;
    Status sx;
    ifstream f;
    Res current;
    void read();

};
#endif // ENOR_H
