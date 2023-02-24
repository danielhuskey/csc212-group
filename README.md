# csc212-group project
Summary:
	

 

	Commands: 

		help displayes general help with no addition args
			avalble args {help, new, getGrade, changeGrade,  addGrade, removeGrade, close}
			ex (help getGrades) would output how to use the getGrades command

		getGrade returns the grade at a given location
			examlple getGrade Labs 1 will retrun lab one's grade 

		getCategory returns all of the grades in a given catigory 
			example getGategory Labs will reutrn all of the grades in lab

		getCourse returns coruse grades takes upto one arg(left blank,"all", "category")
			left blank only prints the current course grade ex: getCourse will return Course greade
			"all" prints out all grades within each of  the categories and the course ever all
			"category" prints out all of the catigory totals as well as the overall grade 
		 
		changeGrade takes 3 arguments (gradeCategory, GradeNum, newGrade) changes grade at given location to new grade
			ex changeGrade Lab 3 17 will change Lab 3's grade to 17
		
		close save's the new changed grades to the file taken on input
 

		

Planning:	

	Pseudocode
		Var name meanings 
			gradeType could be {Labs, *Quizzes*, Assignments, Exams, Projects ext}
			gradeName the Name of the item in grade type so in Exams you could have “Final exam” as gradeName
			fileName name of the file opened/ made
			openVector a vector that holds everything in the file all this information will then be saved back to the file at the end


		Command line args
			defined above -help, -new, -getGrade, -changeGrade,  -addGrade, -removeGrade, -getName, -close
			
	Main{
		Store initial command line args check command args to see if one is help

	If (fileName)
		openFile
		Store the elements of that file
	Else print invalid fileName
	
	While input !=(close)
		Handle Command Line args
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

	Flow Chart IMG


Compilation Command:

	g++ main.cpp gradebook.cpp -o main


Runtime Instructions:

	durning runtime use "./main {fileName}" 
	the program will print out "use for help to close and save enter close"
	after the program will loop until command == false 


Samples:



	
