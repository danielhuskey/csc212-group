#include <vector>
#include <string>

class gradeBook{
    private:
        std::vector<std::vector<double>> gradeVector;
        std::vector<std::string> nameVector;
        std::string fName;
    public:
        //contructors
        gradeBook(std::vector<std::vector<double>>tempGradeVector,std::vector<std::string> tempNameVector);
        gradeBook(std::string fName);

        void printGrades();// prints in the terminal all of the grades
        void printGrades(std::string typeName);// prints in the terminal the gradestpye given



        //not done
        double findAvg(); //finds the avg of all grades 
        double findAvg(std::string typeName);// find avg of the type name

        double getGrades(std::string gradeName);
        void setGrades(std::string gradeName,int grade);

        
        void saveGrades(std::string fName);//saves the grage Vector the file

        



};