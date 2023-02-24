#include "gradebook.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
int handleCommands(std::string args, gradeBook grades){
    if(args=="close"){
        grades.saveGrades();
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
        std::string splitArgs;
        int findLoc;

        //finding the command in the string and breaking once the frist space seperating the values is found
        //since each command takes differnt args the rest will be seperatied out in those commands. 
        for(int x =0;x<args.size();x++){
            if(args[x] ==' '){
                findLoc =x;
                break;
            }else{
                splitArgs.push_back(args[x]);
            }
        }
        //PLACE HOLDERS UNTIL METHODS ARE IMPLIMENDED
        if(splitArgs=="getGrade"){
            std::cout<<"getGrades"<<std::endl;
        }else if(splitArgs=="getCategory"){
            std::cout<<"getCategory"<<std::endl;
        }else if(splitArgs=="getCourse"){
            std::cout<<"getCourse"<<std::endl;
        }else if(splitArgs=="addGrade"){
            std::cout<<"addGrade"<<std::endl;
        }else if(splitArgs=="removeGrade"){
            std::cout<<"removeGrade"<<std::endl;
        }else if(splitArgs=="changeGrade"){
            std::cout<<"changeGrade"<<std::endl;
        }else {
            std::cout<<"ERROR:: Invalid Command"<<std::endl;
            std::cout<<"For help use -h or teshelp "<<std::endl;
        }
        
    }

    return 1;

}

int main(int argc, char* argv[]){
    char * file_name= (argv[1]);
                                                //Labs                          Assignment    Proj     exams
    std::vector<std::vector<double>> tempVector ={{20.5,20,20,20,20,20,20,20,20,20},{50,50,50,50},{150,350},{100}};
    std::vector<std::string> nameVector={"Labs","Assignments","Projects","Exams"};
    gradeBook test(tempVector,nameVector,file_name);
    
    //gradeBook test2(file_name);
    int run = handleCommands("help",test);
    std::cout<<"For help use -h or help "<<std::endl;
    while(run >0){
        std::cout<<"Enter Command: ";
        std::string inputCommand;
        
        std::getline(std::cin, inputCommand);
        
        run =handleCommands(inputCommand,test);
    }
    test.printGrades();
    test.saveGrades();
    //test.printGrades("Labs");
}
