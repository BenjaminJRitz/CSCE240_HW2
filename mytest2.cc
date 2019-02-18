#include "parse_scores.h"

#include <cassert>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string values[] = {
  "3",
  "1234", "3", "99.1", "87.92", "77.32",
  "2345", "4", "93.1", "99.6", "81.21", "89.33",
  "3456", "5", "99.3", "99.3", "83.49", "76.48", "99.6"};
int kSize = 19;

int ids[3];
double grades[10];




int main(int argc, char* argv[]){

    if(is_corrupted(values, kSize)==1){
        cout << "the array is corrupted" << endl;
    }else{
        cout << "The array is legit" << endl;
    }//ending bracket for if else

    //cout << get_student_ids(values, kSize, ids) << endl;



    

    //cout << get_max_grade(values, kSize) << endl;

    //cout << get_max_grade_id(values, kSize) << endl;

    //double get_grade(int id, int grade_index, const std::string values[], int size)
    //cout << get_grade(1345, 3, values, kSize) << endl;

    //int get_num_grades(int id, const std::string values[], int size)
    //cout << get_num_grades(3456, values, kSize) << endl;

    //int get_grades(int id, const std::string values[], int size, double grades[])
    cout << get_grades(3457, values, kSize, grades) << endl;
    for(int i = 0; i < get_grades(3457, values, kSize, grades); ++i){
      cout << grades[i] << endl;
    }//ending bracketfor for loop


    return 0;

}//ending bracket for method main

