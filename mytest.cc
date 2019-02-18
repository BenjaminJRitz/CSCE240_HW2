//#include "parse_scores.h"

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
  "3456", "5", "99.3", "99.3", "83.49", "76.48", "98.6"};
int size = 19;
//int flag = 0;
//int size = 0;
//std::string test = kValues[4];

int main(int argc, char* argv[]) {

   
    int flag = 0;
    int position = 0;
    int ids = 0;
    
    for(int i = 0; i < std::stoi(values[0]); ++i){
        if(ids > std::stoi(values[0])){
            flag = 1;
            break;
        }//ending bracke for if
        ++position;
        if(values[position].length() == 4){
            ++ids;
            cout << "id at position " << position << " is " << std::stoi(values[position]) << endl;
            if((position +1) == size){
                flag = 1;
                break;
            }else{
                ++position;
                int j = std::stoi(values[position]);
                while(j > 0){
                    ++position;
                    if((position + j) > size){
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
    return flag;

} // ending bracket for main method