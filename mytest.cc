//#include "parse_scores.h"

#include <cassert>
#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

std::string values[] = {
  "2",
  "1234", "3", "98.7", "87.92", "77.32", 
  "2345", "4", "93.1", "90.23", "81.21", "89.33" };
int kSize = 12;
//int flag = 0;
//int size = 0;
//std::string test = kValues[4];

int main(int argc, char* argv[]) {
    /*size = kValues[4].length();
    *cout << size << endl;
    *cout << kValues[4].at(2) << endl;
    *if(kValues[4].at(3) == '.'){
    *   flag = 1;
    *} // ending bracket for if statement
    *cout << flag << endl;
    *cout << std::stoi(kValues[0]) << endl;
    */

    int flag = 0;
    int position = 0;

        for(int i = 0; i < std::stoi(values[0]); ++i){

            ++position;
            if(values[position].length() == 4){
                cout << "id at position " << position << " is " << std::stoi(values[position]) << endl;
                if((position +1) == kSize){
                    flag = 1;
                    break;
                }else{
                    ++position;
                    int j = std::stoi(values[position]);
                    while(j > 0){
                        ++position;
                        if((position + j) > kSize){
                            flag = 1;
                            break;
                        }else{
                            if(values[position].at(2) == '.'){
                                cout << "score at position " << position << " is " << values[position] << endl;
                            }else{
                                flag = 1;
                                break;
                            }//ending bracket for if else
                        }//ending bracket for else
                        --j;
                    }// ending bracket for while loop
                    if(flag == 1){
                        break;
                    }//ending bracket for if statement
                }//ending bracket for else statement
            }// ending bracket of if statement
        } // Ending bracket of for loop

    cout << flag << endl;
    return 0;
} // ending bracket for main method