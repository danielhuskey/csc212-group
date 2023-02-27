#include "gradebook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
//test constructor used when giving a premade vector outside of the class not normally used but kepts just incase needed in the future 
gradeBook::gradeBook(std::vector<std::vector<double>> inputGradeVector,std::vector<std::string> inputNameVector, char * file_name){
    gradeVector=inputGradeVector;
    nameVector=inputNameVector;
    fName = file_name;

}
// constructor normally used takes in a file and extrapualtes that into a 2D vector of doubles broken right now use the test constructor for now 
gradeBook::gradeBook(char * file_name){
    //setting the object var fname
    this->fName = file_name;

    //Opening file_name
    std::fstream openFile;
    openFile.open(file_name);

    //setting up temp vars
    std::string inString;
    std::string toint;
    std::vector<double> tempVect;

    //Getting lines from input_file
    while (std::getline(openFile, inString)){
       //Handling each line
        for(int x =0;x<inString.size();x++){
            //testing to see if location is a space to push that to the tempVect
            if(inString[x]==' '){
                tempVect.push_back(stod(toint));
                toint.clear();
            // pushing the presplit char to a temp string    
            }else{
                    toint.push_back(inString[x]);
            }
        }
        //testing if there is a space at the end of the inString
        if(inString[inString.size()-1]!=' '){
            //pushing last val to tempVect
            tempVect.push_back(stod(toint));
            //Clear toint for furture use
            toint.clear();
        }
        
        //Pushing tempVect to the man vect
        gradeVector.push_back(tempVect);
        //Clearing tempVect
        tempVect.clear();
        
}
//Close File
openFile.close();
}


int gradeBook::breakName(std::string typeName){
    int fristVal;
    if(typeName =="Labs"){
            fristVal = 0;
        }else if(typeName =="Assignments"){
            fristVal = 1;
        }else if(typeName =="Projects"){
            fristVal = 2;
        }else if (typeName == "Exams"){
            fristVal = 3;
        }else{
            std::cout<<"Grade Type Please use one of the fallowing Labs, Assignments, Projects, Exams"<<std::endl;
            fristVal =-1;
        }
        return fristVal;
}


//prints out all of the grades that are in the "grade vector" seperating the prints by categoryName ie ("Labs","Assignment","Projects","Exams")
void gradeBook::printGrades(){
    //Looping through gradeVector and printing out grades
    for(int x =0;x<gradeVector.size();x++){
        //displays the category name followed by all of the grades in that category
        std::cout<<nameVector[x]<<": "<<std::endl;
            for(int y =0; y<gradeVector[x].size();y++){
            std::cout<<nameVector[x]<<" "<<y<<": "<<gradeVector[x][y]<<" "<<std::endl;
        }   
        std::cout<<std::endl;
    }

}// prints in the terminal all of the grades


//prints out the grades in the categoryName ie ("Labs","Assignment","Projects","Exams") 
void gradeBook::printGrades(std::string categoryName){
    int found;
    //looks for the category name in the known category vector to match to be able to only display that category
    for(int i =0;i<nameVector.size();i++){
        if(nameVector[i]==categoryName){
            found = i;
        }
    }

    //couts all of the grades in the catigory found    
    std::cout<<"Your "<<nameVector[found]<<" total is "<<this->findAvg(nameVector[found])<<" / "<<WORTHS[found]<<std::endl;
    
    //Looping through subVector to print out
     for(int y =0; y<gradeVector[found].size();y++){
            std::cout<<nameVector[found]<<" "<<y<<": "<<gradeVector[found][y]<<" "<<std::endl;
        }   


}

//Find the max worth for the given Catigory
double gradeBook::findWorth(std::string typeName){
    int fristVal =breakName(typeName);
        //finding the first val in the 2D vector by name
        
        if(fristVal!=-1){
            return WORTHS[fristVal];
        }
        
    return -1;
}

//Appending to type name grade
void gradeBook::addGrade(std::string typeName,double grade){
    int fristVal =breakName(typeName);
        if(fristVal!=-1){  
            gradeVector[fristVal].push_back(grade);
        }
}

//finds the avg of all grades 
double gradeBook::findAvg(){
    double total;
    //loops through the gradeVector to get a total
    for(int i =0;i<gradeVector.size();i++){
        for (int x=0;x<gradeVector[i].size();x++){
            total+=gradeVector[i][x];
        }
    }
    return total;


} 

// find avg of the type name
double gradeBook::findAvg(std::string typeName){
    int fristVal=breakName(typeName);
    double total=0;

    if(fristVal!=-1){
        //looping through subVect to get total        
        for (int x=0;x<gradeVector[fristVal].size();x++){
            total+=gradeVector[fristVal][x];
        }    
    }

    return total;

}



//gets and returns grade at a given location
double gradeBook::getGrades(std::string gradeName,int loc){
//gets the grade for given name for a grade
    int fristVal= breakName(gradeName);
    return gradeVector[fristVal][loc];
    
}
//sets grade a given point to new grade
void gradeBook::setGrades(std::string gradeName,int loc,double grade){
    int fristVal= breakName(gradeName);
    //finding the first val in the 2D vector by name
    if(fristVal!=-1){
        gradeVector[fristVal][loc]=grade;
    }
}


//Saves "gradeVector" to "fName"      
void gradeBook::saveGrades(){
    std::fstream openFile;
    //opens the file and clears it before resaving the new information back to the file
    openFile.open(fName, std::ofstream::out | std::ofstream::trunc);

    //goes through the 2d vector and adds it to the file breaking line at the end of each vector to seperate the vector
    for(int y =0; y<gradeVector.size();y++){
        for(int x =0; x<gradeVector[y].size();x++){
            openFile <<gradeVector[y][x]<<" ";
        }
        openFile <<"\n";
    }

    openFile.close();
    
}
