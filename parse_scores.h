#include <string>
#include <iostream>
using std::cout;
using std::endl;

/*
* Checks the values array for format corruption
*Returns:
* - integer -1 if array is corrupt 
* i.e. 2 1234 1 99.2 2345
*  i.e. 1 1234 3 99.7 82.1
*/
int is_corrupted(const std::string values[], int size){
    int flag = 0;
    int position = 0;
    for(int i = 0; i < std::stoi(values[0]); ++i){
        ++position;
        if(values[position].length() == 4){
            //cout << "id at position " << position << " is " << std::stoi(values[position]) << endl;
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
                            //cout << "score at position " << position << " is " << values[position] << endl;
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

    //cout << flag << endl;
    return flag;
}//ending bracket for funtion is_corrupted

//----------------------------------------------------------------------------------------------------
/* Description:
 *   Parses the values array to determine how many grades are present for a
 *   student selected by the id parameter and returns that value.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The number of grades for student with parameter id when student id is
 *     found.
 * - Integer -1 when a match for parameter id is not found in student ids
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
int get_num_grades(int id, const std::string values[], int size){
    int grades = -1;
    if(is_corrupted(values, size) == 1){
        grades = -10;
    }else{
        for(int i = 0; i <size; ++i){
            if(std::stoi(values[i]) == id){
                grades = std::stoi(values[i+1]);
            }//ending bracket for if
        }//ending bracekt for for loop
    }//ending bracekt for else
    return grades;
}// ending bracket for function get_num_grades

//-------------------------------------------------------------------------------------------------------------
/* Description:
 *   Parses the values array to get all grades for a student matching parameter
 *   id
 * Preconditions:
 * - Parameter values has at least parameter size elements
 * - Parameter grades is large enough to hold all grades for requested student
 * Postconditions:
 * - Parameter grades has the floating point representation of the corresponding
 *     grades for student matching parameter id
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * - grades: an input parameter into which the floating point representation of
 *     student's grades are stored
 * Returns:
 * - Number of grades parsed
 * - Integer -10 if format corrupt i.e. 2 1234 1 99.2 2345
 * - Integer -1 if id not found
 */
int get_grades(int id, const std::string values[], int size, double grades[]){
    int numGrades = -1;
    if(is_corrupted(values,size)==1){
        numGrades = -10;
    }else{

        for(int i = 0; i < size; ++i){
            if(std::stoi(values[i])==id){
                numGrades = std::stoi(values[i+1]);
                for(int j = 0; j < numGrades; ++j){
                    grades[j] = std::stod(values[i+2+j]);
                }//ending bracket for inner for loop
            }//ending bracekt for if
        }//ending bracket for outer for loop
    }//ending bracket for else
    return numGrades;
}//ending bracket for function get_grades

//---------------------------------------------------------------------------------------------------
/* Description:
 *   Extracts a single grade for a given student and given grade index.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - id: the id of the student for which number of grades is returned
 * - grade_index: index of the grade to be returned for matching student
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - Grade selected
 * - Integer -1 when student is not found
 * - Integer -2 when grade_index is not found
 * - Integer -10 when values format is corrupt
 */
double get_grade(int id, int grade_index, const std::string values[], int size){
    double grade = 0;
    if(is_corrupted(values, size)==1){
        grade = -10;
    }else{
        for(int i = 0;i < size; ++i){
            if((std::stoi(values[i]) == id) && (std::stoi(values[i+1]) >= grade_index)){
                grade = std::stod(values[i+1+grade_index]);
                break;
            }else if((std::stoi(values[i]) == id) && (std::stoi(values[i+1]) < grade_index)){
                    grade = -2;
                    break;
            }else{
                grade = -1;
            }//ending bracket for if else
        }//ending bracket for for loop
    }//ending bracket for ir else
    return grade;
}//ending bracket for function get_grade

//--------------------------------------------------------------------------------------------------
/* Description:
 *   Extracts the id of the student with the highest grade.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The id of the student with the highest grade.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
int get_max_grade_id(const std::string values[], int size){
    int position = 0;
    double maxGrade = 0;
    int maxId = 0;
    int currentId = 0;
     if(is_corrupted(values, size)==1){
        maxId = -10;
    }else if(std::stoi(values[0]) == 0){
        maxId = -1;
    }else if(std::stoi(values[2])==0){
        maxId = -2;
    }else{
        for(int i = 0; i < std::stoi(values[0]); ++i){
            ++position;
            if(values[position].length() == 4){
                currentId = std::stoi(values[position]);
                ++position;
                int j = std::stoi(values[position]);
                while(j > 0){
                    ++position;
                        if(values[position].at(2) == '.'){
                            if(std::stod(values[position]) > maxGrade){
                                maxGrade = std::stod(values[position]);
                                maxId = currentId;
                            }//ending bracket for if
                            //cout << "score at position " << position << " is " << values[position] << endl;
                        }//ending bracket for if
                    --j;
                }// ending bracket for while loop
            
            }// ending bracket of if statement
        } // Ending bracket of for loop
    } // ending bracket for else
    return maxId;
}//ending bracket for function get_max_id

//---------------------------------------------------------------------------------------------------------------------
/* Description:
 *   Extracts the highest grade.
 * Preconditions:
 * - Parameter values has at least parameter size elements.
 * - Grades are nonnegative. Adjust accordingly.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * Returns:
 * - The highest grade found.
 * - Integer -1 when no students exist
 * - Integer -2 when no grades exist
 * - Integer -10 when the format is corrupt i.e. 1 1234 3 99.7 82.1
 */
double get_max_grade(const std::string values[], int size){
    double maxGrade = 0;
    if(is_corrupted(values, size)==1){
        maxGrade = -10;
    }else if(std::stoi(values[0]) == 0){
        maxGrade = -1;
    }else if(std::stoi(values[2])==0){
        maxGrade = -2;
    }else{
        for(int i = 0; i < size; ++i){
            if(values[i].length() >= 3){
                if(values[i].at(2) == '.'){
                    //cout << values[i] << endl;
                    if(std::stod(values[i]) > maxGrade){
                        maxGrade = std::stod(values[i]);
                    }//ending bracket for if
                }//ending bracket for if
            }//ending bracket for if
        }//ending bracket for for loop
    }//ending bracket for else
    return maxGrade;
}//ending bracket for functino get_max_grade

//-------------------------------------------------------------------------------------------------------------
/* Description:
 *   Parses the values array to extract all student ids. Stores the values in
 *   the parameter ids
 * Preconditions:
 * - Parameter values has at least parameter size elements
 * - Parameter ids is large enough to hold all student id values
 * Postconditions:
 * - Parameter ids has the integer values of the corresponding student ids.
 * Parameters:
 * - values: a series of string input representing students and grades
 * - size: number of elements in values array
 * - ids: an input parameter into which student ids are stored
 * Returns:
 * - Number of grades parsed
 * - Integer -10 if format corrupt i.e. 2 1234 1 99.2 2345
 */
int get_student_ids(const std::string values[], int size, int ids[]){
    int retValue = 0;
    int valuesPosition = 1;
    int idsPosition = 0;
    int numGrade = 0;

    if(is_corrupted(values, size) == 1){
        retValue = -10;
    }else{
        for(int i = 0; i < std::stoi(values[0]); i++){
            ids[idsPosition] = std::stoi(values[valuesPosition]);
            ++numGrade;
            ++valuesPosition;
            valuesPosition += std::stoi(values[valuesPosition]);
            ++valuesPosition;
            ++idsPosition;
        }// ending bracket of for loop
        retValue = numGrade;
    }//ending bracket of else

    return retValue;

}//ending bracket for function ge_student_ids

//-----------------------------------------------------------------------------------------------------


