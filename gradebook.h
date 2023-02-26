#include <vector>
#include <string>

class gradeBook{
    private:
        std::vector<std::vector<double>> gradeVector;
        std::vector<std::string> nameVector={"Labs","Assignments","Projects","Exams"};
        char * fName;
        const double LABSWORTH =200;
        const double ASSIGMENTSWORTH=200;
        const double PROJECTSWORTH =500;
        const double EXAMSWORTH =100;
        
    public:
        //contructors
        gradeBook(std::vector<std::vector<double>>tempGradeVector,std::vector<std::string> tempNameVector, char * fName);
        gradeBook(char * fName);

        //print grades
        void printGrades();// prints in the terminal all of the grades
        void printGrades(std::string typeName);// prints in the terminal the gradestpye given

        //saving the vector of grades back to the file
        void saveGrades();//saves the grage Vector the file

        //gets the grades at the given location
        double getGrades(std::string gradeName,int loc);
        //set the grade at the given location to new grade
        void setGrades(std::string gradeName,int loc,double grade);
    
        //not done
        double findAvg(); //finds the avg of all grades 
        double findAvg(std::string typeName);// find avg of the type name

        

        

        
        



};
