#include "gradebook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
gradeBook::gradeBook(std::vector<std::vector<double>> inputGradeVector,std::vector<std::string> inputNameVector){
    gradeVector=inputGradeVector;
    nameVector=inputNameVector;
}
gradeBook::gradeBook(std::string fName){


}
void gradeBook::printGrades(){
    for(int x =0;x<gradeVector.size();x++){
        //displays the category name followed by all of the grades in that category
        std::cout<<nameVector[x]<<": ";
            for(int y =0; y<gradeVector[x].size();y++){
            std::cout<<gradeVector[x][y]<<" ";
        }   
        std::cout<<std::endl;
    }

}// prints in the terminal all of the grades



void gradeBook::printGrades(std::string categoryName){
    int found;
    //looks for the category name in the known category vector to match to be able to only display that category
    for(int i =0;i<nameVector.size();i++){
        if(nameVector[i]==categoryName){
            found = i;
        }
    }

    //couts all of the grades in the catigory found
    std::cout<<"Your "<<nameVector[found]<<" grades are: "<<std::endl;
     for(int y =0; y<gradeVector[found].size();y++){
            std::cout<<nameVector[found]<<" "<<y+1<<": "<<gradeVector[found][y]<<" "<<std::endl;
        }   


}


double gradeBook::findAvg(){
///Your Avrage for this class is 200/260

} //finds the avg of all grades 


double gradeBook::findAvg(std::string typeName){
///Your Avg for labs is a 20/20

}// find avg of the type name



double gradeBook::getGrades(std::string gradeName){
//gets the grade for given name for a grade

}
void setGrades(std::string gradeName,int grade){
//sets grade at a given name

}

        
void saveGrades(std::string fName){


}//saves the grage Vector the file

