#include "parse_scores.h"


int is_corrupted(const std::string values[], int size) {
    int flag = 0;
    int parsedsize = 0;

    for (int i = 0; i < std::stoi(values[0]); ++i) {
        parsedsize +=2;
        parsedsize += stoi(values[parsedsize]);
    }  // ending bracket for for loop
    ++parsedsize;
    if (parsedsize > size) {
        flag = 1;
    }  // Ending bracket for if statement
    return flag;
}  // ending bracket for funtion is_corrupted

int get_num_grades(int id, const std::string values[], int size) {
    int grades = -1;
    if (is_corrupted(values, size) == 1) {
        grades = -10;
    } else {
        for (int i = 0; i <size; ++i) {
            if (std::stoi(values[i]) == id) {
                grades = std::stoi(values[i+1]);
            }  // ending bracket for if
        }  // ending bracekt for for loop
    }  // ending bracekt for else
    return grades;
}  // ending bracket for function get_num_grades

int get_grades(int id, const std::string values[], int size, double grades[]) {
    int numGrades = -1;
    if (is_corrupted(values, size) == 1) {
    numGrades = -10;
    } else {
        for (int i = 0; i < size; ++i) {
            if (std::stoi(values[i]) == id) {
                numGrades = std::stoi(values[i+1]);
                for (int j = 0; j < numGrades; ++j) {
                    grades[j] = std::stod(values[i+2+j]);
                }  // ending bracket for inner for loop
            }  // ending bracekt for if
        }  // ending bracket for outer for loop
    }  // ending bracket for else
    return numGrades;
}  // ending bracket for function get_grades

double get_grade(int id, int grade_index, const std::string values[],
 int size) {
    double grade = 0;
    if (is_corrupted(values, size) == 1) {
        grade = -10;
    } else {
        for (int i = 0; i < size; ++i) {
            if ((std::stoi(values[i]) == id) &&
             (std::stoi(values[i+1]) > grade_index)) {
                grade = std::stod(values[i+2+grade_index]);
                break;
            } else if ((std::stoi(values[i]) == id) &&
             (std::stoi(values[i+1]) <= grade_index)) {
                    grade = -2;
                    break;
            } else {
                grade = -1;
            }  // ending bracket for if else
        }  // ending bracket for for loop
    }  // ending bracket for ir else
    return grade;
}  // ending bracket for function get_grade

int get_max_grade_id(const std::string values[], int size) {
    int position = 0;
    double maxGrade = 0;
    int maxId = 0;
    int currentId = 0;
     if (is_corrupted(values, size) == 1) {
        maxId = -10;
    } else if (std::stoi(values[0]) == 0) {
        maxId = -1;
    } else if (std::stoi(values[2]) == 0) {
        maxId = -2;
    } else {
        for (int i = 0; i < std::stoi(values[0]); ++i) {
            ++position;
            if (values[position].length() == 4) {
                currentId = std::stoi(values[position]);
                ++position;
                int j = std::stoi(values[position]);
                while (j > 0) {
                    ++position;
                        if (values[position].at(2) == '.') {
                            if (std::stod(values[position]) > maxGrade) {
                                maxGrade = std::stod(values[position]);
                                maxId = currentId;
                            }  // ending bracket for if
                        }  // ending bracket for if
                    --j;
                }  // ending bracket for while loop
            }  // ending bracket of if statement
        }  // Ending bracket of for loop
    }  // ending bracket for else
    return maxId;
}  // ending bracket for function get_max_id

double get_max_grade(const std::string values[], int size) {
    double maxGrade = 0;
    if (is_corrupted(values, size) == 1) {
        maxGrade = -10;
    } else if (std::stoi(values[0]) == 0) {
        maxGrade = -1;
    } else if (std::stoi(values[2]) == 0) {
        maxGrade = -2;
    } else {
        for (int i = 0; i < size; ++i) {
            if (values[i].length() >= 3) {
                if (values[i].at(2) == '.') {
                    // cout << values[i] << endl;
                    if (std::stod(values[i]) > maxGrade) {
                        maxGrade = std::stod(values[i]);
                    }  // ending bracket for if
                }  // ending bracket for if
            }  // ending bracket for if
        }  // ending bracket for for loop
    }  // ending bracket for else
    return maxGrade;
}  // ending bracket for functino get_max_grade

int get_student_ids(const std::string values[], int size, int ids[]) {
    int retValue = 0;
    int valuesPosition = 1;
    int idsPosition = 0;
    int numGrade = 0;

    if (is_corrupted(values, size) == 1) {
        retValue = -10;
    } else {
        for (int i = 0; i < std::stoi(values[0]); i++) {
            ids[idsPosition] = std::stoi(values[valuesPosition]);
            ++numGrade;
            ++valuesPosition;
            valuesPosition += std::stoi(values[valuesPosition]);
            ++valuesPosition;
            ++idsPosition;
        }  // ending bracket of for loop
        retValue = numGrade;
    }  // ending bracket of else

    return retValue;
}  // ending bracket for function ge_student_ids


