#include <vector>
#include <string>

class gradeBook{
    private:
        std::vector<std::vector<double>> gradeVector;
        std::vector<std::string> nameVector={"Labs","Assignments","Projects","Exams"};
        char * fName;
        const double WORTHS[4] ={200,200,500,100};
     
        
    public:
        //contructors
        gradeBook(std::vector<std::vector<double>>tempGradeVector,std::vector<std::string> tempNameVector, char * fName);
        gradeBook(char * fName);

        //print grades
        void printGrades();// prints in the terminal all of the grades

        //ONLY CODE LEFT TO DO
        void printGrades(std::string typeName);// prints in the terminal the gradestpye given

        //saving the vector of grades back to the file
        void saveGrades();

        //findAvg
        double findAvg(); //finds the avg of all grades 
        double findAvg(std::string typeName);// find avg of the type name

        //Finds the max val in each category
        double findWorth(std::string typeName);

        //returns the grade at the given location
        double getGrades(std::string gradeName,int loc);

        //sets the old grade at the given location to the value of the new grade
        void setGrades(std::string gradeName,int loc,double grade);

        void addGrade(std::string gradeName,double grade);
  
};
