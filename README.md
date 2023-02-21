# csc212-group project
comp with
g++ main.cpp gradebook.cpp -o testMain

# Pseudocode
Var name meanings 
gradeType could be {Labs, *Quizzes*, Assignments, Exams, Projects ext}
gradeName the Name of the item in grade type so in Exams you could have “Final exam” as gradeName
fileName name of the file opened/ made
Command line args defined above -help, -new, -getGrade, -changeGrade,  -addGrade, -removeGrade, -getName, -close
openVector a vector that holds everything in the file all this information will then be saved back to the file at the end

Main{
	
do
If (fileName)
		openFile
		Store the elements of that file
    print file name was opened 
Else{
    print invalid file name please enter a valid file name
}
while(filename!=true)
 
	
  print(input help for help, or any valid command to view and edit fileName)
  
  
While input !=(close)
	Handle Command Line args will be its own function
	Output based on the command line args 
End while 
save(elements);

gradeBook{
getGrades(gradeType) takes in a vector of a vector that is the grades returns the grades for grade type 
	setGrades(gradeName, grade) finds grade name and sets it to grade
	printGrades() C outs the grades 
printGrades(gradeType) prints out the grades in grade type
saveGrades(); saves the changes to the file
findAvg(conn); finds the avg of conn could be all or gradeType both will be stored as strings

}
