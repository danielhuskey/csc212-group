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
    std::fstream openFile;
    openFile.open(file_name);
    std::string temp;
    std::string toint;
    std::vector<double> test;
    int indl;
    
    while (std::getline(openFile, temp)){
       
        
        for(int x =indl;x<temp.size();x++){
            if(temp[x]==' '){
                test.push_back(stoi(toint));
                
                //toint.clear();
                //test.clear();
            }else{
                    toint.push_back(temp[x]);

            }
        }
      
        


        //gradeVector.push_back(test);
        //test.clear();

       
            //gradeVector[indl].push_back(stoi(temp));
            
    

}
}

//prints out all of the grades that are in the "grade vector" seperating the prints by categoryName ie ("Labs","Assignment","Projects","Exams")
void gradeBook::printGrades(){
    for(int x =0;x<gradeVector.size();x++){
        //displays the category name followed by all of the grades in that category
        std::cout<<nameVector[x]<<": ";
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
    std::cout<<"Your "<<nameVector[found]<<" total is "<<" grades are: "<<std::endl;
                                    //                ^ findAvg(<nameVector[found])   
     for(int y =0; y<gradeVector[found].size();y++){
            std::cout<<nameVector[found]<<" "<<y<<": "<<gradeVector[found][y]<<" "<<std::endl;
        }   


}


double gradeBook::findAvg(){
///Your Avrage for this class is 200/260

} 
//finds the avg of all grades 


double gradeBook::findAvg(std::string typeName){
///Your Avg for labs is a 20/20

}
// find avg of the type name



double gradeBook::getGrades(std::string gradeName,int loc){
//gets the grade for given name for a grade
    int fristVal;
    //finding the first val in the 2D vector by name
    if(gradeName =="Labs"){
        fristVal = 0;
    }else if(gradeName =="Assignments"){
        fristVal = 1;
    }else if(gradeName =="Projects"){
        fristVal = 2;
    }else if (gradeName == "Exams"){
        fristVal = 3;
    }else{
        std::cout<<"Grade Type Please use one of the fallowing Labs, Assignments, Projects, Exams"<<std::endl;
        fristVal =-1;
    }
    if(fristVal!=-1){
        return gradeVector[fristVal][loc];
    }
}
void gradeBook::setGrades(std::string gradeName,int loc,double grade){
    int fristVal;
    //finding the first val in the 2D vector by name
    if(gradeName =="Labs"){
        fristVal = 0;
    }else if(gradeName =="Assignments"){
        fristVal = 1;
    }else if(gradeName =="Projects"){
        fristVal = 2;
    }else if (gradeName == "Exams"){
        fristVal = 3;
    }else{
        std::cout<<"Grade Type Please use one of the fallowing Labs, Assignments, Projects, Exams"<<std::endl;
        fristVal =-1;
    }
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

