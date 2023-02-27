//imports
#include "gradebook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>


//function for handling all of the posable commands 
int handleCommands(std::string args, gradeBook * grades){
    //testing to see if the command is close if it is saving the files.
    if(args=="close"){
        grades->saveGrades();
        return -1;
    
    //HELP commands  
    }else if(args=="help"){
        std::cout<<"The Avalable commands are (help, getGrade, getCategory, getCourse, changeGrade,  addGrade, removeGrade, close) and the category names (Labs, Assignments, Projects, and Exams)"<<std::endl; 
        std::cout<<"For detailed information about the commands use (help-commandName)"<<std::endl;
    
    //prints out how getGrade is used
    }else if(args =="help-getGrade"){
        std::cout<<std::endl;
        std::cout<<"getGrade is used to get the grade at the given location To use the command getGrade categoryName categoryNumber "<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: getGrades Labs 2"<<std::endl;
        std::cout<<"This would return the grade for the second lab"<<std::endl;
    //prints out how getCategory is used
    }else if(args =="help-getCategory"){
        std::cout<<std::endl;
        std::cout<<"getCategory is used to get all of the grades in the given category To use the command getCategory categoryName"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: getCategory Labs "<<std::endl;
        std::cout<<"This would print all of the grades in Labs"<<std::endl;
    //prints out how getCourse is used
    }else if(args =="help-getCourse"){
        std::cout<<std::endl;
        std::cout<<"getCourse is used to get all of the grades takes an addidtional arg"<<std::endl; 
        std::cout<<"this arg can be left blank for only the current course overall or all for all grades or cat for the category totals."<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: getCategory Labs "<<std::endl;
        std::cout<<"This would print all of the grades in Labs"<<std::endl;
    //print out how to changeGrade is used      
    }else if(args =="help-changeGrade"){
        std::cout<<std::endl;
        std::cout<<"changeGrade is used to change the grade at the given location. Use the command (changeGrade Category Name Category Number New Grade)  "<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Example: changeGrade Project 1 ,150"<<std::endl;
        std::cout<<"Changing Project 1's grade to 150 replacing the prior command"<<std::endl;
          
    //END HELP commands
    }else{
        
        //getGrade logic
        if(args=="getGrade"){
                //gets the gradeName and location and prints out that location
                std::string gradeName;
                int loc;
                std::cin>> gradeName >>loc;
                std::cout<<grades->getGrades(gradeName,loc)<<std::endl;

        //getCategory Logic
        }else if(args=="getCategory"){
                //returns the gradeName grades and avg for that gradeName
                std::string gradeName;
                std::cin>> gradeName;
                grades->printGrades(gradeName);
        
        //getCourse Logic
        }else if(args=="getCourse"){
                //get second arg
                std::string type;
                std::cin>> type;
                
                //Only Course Grade
                if(type =="0"){
                    std::cout<<"The Current Course Grade is "<<grades->findAvg()<<" /1000"<<std::endl;
                
                //All Grades
                }else if(type =="all"){
                    std::cout<<"The Current Course Grade is "<<grades->findAvg()<<" /1000"<<std::endl;
                    std::cout<<"Broken Down to:"<<std::endl;
                    grades->printGrades("Labs");
                    grades->printGrades("Assignments");
                    grades->printGrades("Projects");
                    grades->printGrades("Exams");
                //Only Gategory Grades total and course total
                }else if(type =="Category"){
                    std::cout<<"The Current Course Grade is "<<grades->findAvg()<<" /1000"<<std::endl;
                    std::cout<<"Broken Down to:"<<std::endl;
                    std::cout<<"Labs "<<grades->findAvg("Labs")<<" / "<<grades->findWorth("Labs")<<std::endl;
                    std::cout<<"Assignments "<<grades->findAvg("Assignments")<<" / "<<grades->findWorth("Assignments")<<std::endl;
                    std::cout<<"Projects "<<grades->findAvg("Projects")<<" / "<<grades->findWorth("Projects")<<std::endl;
                    std::cout<<"Exams " <<grades->findAvg("Exams")<<" / "<<grades->findWorth("Exams")<<std::endl;

                //Not Valid second Command    
                }else{
                    std::cout<<"ERROR::Invalid Argument please enter getCourse followed by one of the following 0, all or category."<<std::endl;
                }

        //Logic for addGrade    
        }else if(args=="addGrade"){
                //gets the gradeName and adds the grade to that the end of that gradeName 
                std::string gradeName;
                double grade;
                std::cin>> gradeName >>grade;
                grades->addGrade(gradeName,grade);

        //Logic for changeGrade
        }else if(args=="changeGrade"){
                //gets the gradeName and location to change and sets that location the grade
                std::string gradeName;
                int loc;
                double grade;
                std::cin>> gradeName >>loc>>grade;
                grades->setGrades(gradeName,loc,grade);
                grades->printGrades();
        
        //Prints the current grades        
        }else if(args=="print"){
                grades->printGrades();

        //Not Valid Command        
        }else {
            std::cout<<"ERROR:: Invalid Command"<<std::endl;
            std::cout<<"For help use the command help "<<std::endl;
        }
        
    }
     
    //as long as its not close return one to keep the loop
    return 1;

}

int main(int argc, char* argv[]){
    //Storing args (only arg taken in at run time is file name)
    char * file_name= (argv[1]);
    
    //dynamicly creating a newGrade book with file name
    gradeBook * test;
    test = new gradeBook(file_name);

    //Starting with displaying all of the gernal help information at runtime
    int run = handleCommands("help",test);
    std::cout<<"For help use help, print to print out current grades use to exit  to save and close the program"<<std::endl;
    
    // run makes sure command is not close if it is run will = -1 stopping the loop
    while(run >0){
        
        //geting first command 
        std::cout<<"Enter Command: ";
        std::string inputCommand;
        
        //cin that command
        std::cin>>inputCommand;
        
        //handle that command and handle if that command was to close
        run =handleCommands(inputCommand,test);
        
    }
    
}
