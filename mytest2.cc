#include "parse_scores.h"

#include <cassert>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string values[] = {
  "3",
  "1234", "3", "98.7", "87.92", "77.32",
  "2345", "4", "93.1", "90.23", "81.21", "89.33",
  "3456", "5", "99.3", "99.3", "83.49", "76.48", "65.98"};
int kSize = 19;

int ids[3];




int main(int argc, char* argv[]){

    if(is_corrupted(values, kSize)==1){
        cout << "the array is corrupted" << endl;
    }else{
        cout << "The array is legit" << endl;
    }//ending bracket for if else

    cout << get_student_ids(values, kSize, ids) << endl;



    for(int i = 0; i < 3; ++i){
        cout << ids[i] << endl;
    }//ending bracket for for loop

    return 0;

}//ending bracket for method main

