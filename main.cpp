#include <iostream>
#include "enor.h"
#include <fstream>
#include<vector>
#include<cstdlib>
using namespace std;
struct result{
int maxcount;
string maxname;
};
result MaximumSearch(const string& fname){
      Enor t(fname);
      t.first();
      result r;
      r.maxcount = t.curr().cnt;
      r.maxname = t.curr().chname;
      t.next();
    while(!t.end()){
        if(r.maxcount < t.curr().cnt){
            r.maxcount=t.curr().cnt;
            r.maxname=t.curr().chname;

        }
        t.next();
    }
    return r;

}
//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    string fname="input4.txt";
    try{
    Enor t(fname);
    t.first();
     if(t.end()){
        cerr<<"Empty file"<<endl;
    }
    else{
        cout<<"The championship that has the maximum number of contestants is:"<<MaximumSearch(fname).maxname<<endl<<"The number of contestants is:"<<MaximumSearch(fname).maxcount<<endl;
    }
    }
    catch(Enor::Exception e){
        cerr<<"Cannot open the file. It doesnt exist."<<endl;
    }




}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("empty","input1.txt"){
    Enor t("input1.txt");
    t.first();
    CHECK(t.end()==true);
}
TEST_CASE("regular","input.txt"){

    CHECK(MaximumSearch("input.txt").maxcount==3);
    CHECK(MaximumSearch("input.txt").maxname=="WimChampionship");
}
TEST_CASE("first chamionship has the most contestants","input2.txt"){
     CHECK(MaximumSearch("input2.txt").maxcount==3);
    CHECK(MaximumSearch("input2.txt").maxname=="WimChampionship");



}
TEST_CASE("Last one has the most contestants","input3.txt"){
    CHECK(MaximumSearch("input3.txt").maxcount==3);
    CHECK(MaximumSearch("input3.txt").maxname=="WimChampionship");



}
TEST_CASE("There is only one championship","input4.txt"){
    CHECK(MaximumSearch("input4.txt").maxcount==2);
    CHECK(MaximumSearch("input4.txt").maxname=="BigLakeChampionship");

}

#endif // NORMAL_MODE



