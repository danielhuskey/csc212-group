#include "gradebook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>


int main(int argc, char* argv[]){
    std::vector<std::vector<double>> tempVector ={{20,20,20,20,20,20,20,20,20,20},{50,50,50,50},{150,350},{100}};
    std::vector<std::string> nameVector={"Labs","Assignment","Projects","Exams"};
    gradeBook test(tempVector,nameVector);
    
    test.printGrades();
    test.printGrades("Labs");
}