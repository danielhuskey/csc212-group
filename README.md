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
			gradeType could be {Labs, Assignments, Exams, Projects ext}
			gradeName the Name of the item in grade type so in Exams you could have “Final exam” as gradeName
			fileName name of the file opened/ made
			openVector a vector that holds everything in the file all this information will then be saved back to the file at the end


		Command line args
			defined above -help, -new, -getGrade, -changeGrade,  -addGrade, -removeGrade, -getName, -close
			
	Main{
	get fileName
	gradebook gb(filename)	
	While input !=(close)
		if input == help
			print help
		else if input == getGrade
			gb.getGrades(type, loc);
			
		else if input = getCategory
			gb.printGrades(category)
			print(gb.findAvg(category))
		else if input = getCourse + args
			if args = "all"
				gb.printGrades()
				gb.findAvg()
			else if ags = category
				gb.findAvg(Labs)
				gb.findAvg(Assignments)
				gb.findAvg(Projects)
				gb.findAvg(Exams)
				gb.findAvg();
			else
				gb.findAvg();
		else if input = changeGrade
			gb.changeGrades(cat,loc,grade)
		else 
			print "ERROR:: Invalid Command"
			print "For help use help"
		
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

	


Compilation Command:

	g++ main.cpp gradebook.cpp -o main


Runtime Instructions:

	durning runtime use "./main {fileName}" 
	the program will print out "use for help to close and save enter close"
	after the program will loop until command == false 


Samples:
Example Of Giving an invalid Command and getting help to finally getGrade Labs 2 grade
![image](https://user-images.githubusercontent.com/79720949/221473081-832d9aec-7ee0-4375-8d76-bf29460ddf96.png)

Example Of changing the grade of Assigment 1 to 45
![image](https://user-images.githubusercontent.com/79720949/221474473-84953618-97b4-41e1-b647-c74424e43a5b.png)
Changing the the file from 
![image](https://user-images.githubusercontent.com/79720949/221474542-9d9bf053-63df-43ed-b33b-565194cd6dae.png)
TO
![image](https://user-images.githubusercontent.com/79720949/221474670-1e4fb71e-59eb-4e1a-839b-e934474e8875.png)


Example for getting the total grades in a catigory
![image](https://user-images.githubusercontent.com/79720949/221475534-3bb2977d-1f19-4b45-ac11-61347784a868.png)
![image](https://user-images.githubusercontent.com/79720949/221475614-d99915c5-cc9c-4919-9f56-b21559afbb08.png)

Example For getting a singal grade
![image](https://user-images.githubusercontent.com/79720949/221475723-e398d369-eb65-4fe9-aeaf-8bc7220d05b0.png)

	
