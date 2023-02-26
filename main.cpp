#include "gradebook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
int handleCommands(std::string args, gradeBook * grades){
    if(args=="close"){
        grades->saveGrades();
        return -1;
    
    //HELP commands  
    }else if(args=="help"){
        std::cout<<"The Avalable commands are (help, getGrade, getCategory, getCourse, changeGrade,  addGrade, removeGrade, close) and the category names (Labs, Assignments, Projects, and Exams)"<<std::endl; 
        std::cout<<"For detailed information about the commands use (help command name)"<<std::endl;
    
    }else if(args =="help getGrade"){
        std::cout<<std::endl;
        std::cout<<"getGrade is used to get the grade at the given location To use the command getGrade categoryName categoryNumber "<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: getGrades Labs 2"<<std::endl;
        std::cout<<"This would return the grade for the second lab"<<std::endl;
          
    }else if(args =="help getCategory"){
        std::cout<<std::endl;
        std::cout<<"getCategory is used to get all of the grades in the given category To use the command getCategory categoryName"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: getCategory Labs "<<std::endl;
        std::cout<<"This would print all of the grades in Labs"<<std::endl;
          
    }else if(args =="help getCourse"){
        std::cout<<std::endl;
        std::cout<<"getCourse is used to get all of the grades takes an addidtional arg"<<std::endl; 
        std::cout<<"this arg can be left blank for only the current course overall or all for all grades or cat for the category totals."<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: getCategory Labs "<<std::endl;
        std::cout<<"This would print all of the grades in Labs"<<std::endl;
          
    }else if(args =="help changeGrade"){
        std::cout<<std::endl;
        std::cout<<"changeGrade is used to change the grade at the given location. Use the command (changeGrade Category Name Category Number New Grade)  "<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: changeGrade Project 1 ,150"<<std::endl;
        std::cout<<"Changing Project 1's grade to 150 replacing the prior command"<<std::endl;
          
    //END HELP commands
    }else{
        
        if(args=="getGrade"){
                std::string gradeName;
                int loc;
                std::cin>> gradeName >>loc;
                std::cout<<grades->getGrades(gradeName,loc)<<std::endl;

        }else if(args=="getCategory"){
                std::string gradeName;
                std::cin>> gradeName;
                grades->printGrades(gradeName);
        }else if(args=="getCourse"){
                std::string type;
                std::cin>> type;
                if(type =="0"){
                    std::cout<<"The Current Course Grade is "<<grades->findAvg()<<" /1000"<<std::endl;
                }else if(type =="all"){
                    std::cout<<"The Current Course Grade is "<<grades->findAvg()<<" /1000"<<std::endl;
                    std::cout<<"Broken Down to:"<<std::endl;
                    grades->printGrades("Labs");
                    grades->printGrades("Assignments");
                    grades->printGrades("Projects");
                    grades->printGrades("Exams");
                }else if(type =="Category"){
                    std::cout<<"The Current Course Grade is "<<grades->findAvg()<<" /1000"<<std::endl;
                    std::cout<<"Broken Down to:"<<std::endl;
                    std::cout<<"Labs "<<grades->findAvg("Labs")<<" / "<<grades->findWorth("Labs")<<std::endl;
                    std::cout<<"Assignments"<<grades->findAvg("Assignments")<<" / "<<grades->findWorth("Assignments")<<std::endl;
                    std::cout<<"Projects"<<grades->findAvg("Projects")<<" / "<<grades->findWorth("Projects")<<std::endl;
                    std::cout<<"Exams"<<grades->findAvg("Exams")<<" / "<<grades->findWorth("Exams")<<std::endl;
                    
                }else{
                    std::cout<<"ERROR::Invalid Argument please enter getCourse followed by one of the following 0, all or category."<<std::endl;
                }

            
        }else if(args=="addGrade"){
                std::string gradeName;
                
                double grade;
                std::cin>> gradeName >>grade;
                grades->addGrade(gradeName,grade);
        }else if(args=="changeGrade"){
                std::string gradeName;
                int loc;
                double grade;
                std::cin>> gradeName >>loc>>grade;
                grades->setGrades(gradeName,loc,grade);
                grades->printGrades();
                
        }else if(args=="print"){
                grades->printGrades();
                
        }else {
            std::cout<<"ERROR:: Invalid Command"<<std::endl;
            std::cout<<"For help use the command help "<<std::endl;
        }
        
    }
     
    

    


    return 1;

}

int main(int argc, char* argv[]){
    char * file_name= (argv[1]);
                                                //Labs                          Assignment    Proj     exams
    std::vector<std::vector<double>> tempVector ={{20.5,20,20,20,20,20,20,20,20,20},{50,50,50,50},{150,350},{100}};
    std::vector<std::string> nameVector={"Labs","Assignments","Projects","Exams"};
    gradeBook * test;
    test = new gradeBook(tempVector,nameVector,file_name);

    //gradeBook test2(file_name);
    int run = handleCommands("help",test);
    std::cout<<"For help use help, print to print out current grades use to exit  to save and close the program"<<std::endl;
    while(run >0){
        std::cout<<"Enter Command: ";
        std::string inputCommand;
        

        //std:getline(std::cin, inputCommand);:
        std::cin>>inputCommand;
        
         run =handleCommands(inputCommand,test);
        
    }    
}
