import csv

flag = 1

while flag == 1:

        def searchByDisease():
                disease = input("Enter disease name: \n")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                for row in csv_file:
                        if disease == row[2]:
                                print (row)
                
            
        def searchByState():
                state = input("Enter State name: \n")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                for row in csv_file:
                        if state== row[3]:
                                print (row)

        def searchByYear():
                year = input("Enter a year:  \n")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                for row in csv_file:
                        if year== row[0]:
                                print (row)

        def deathByYear():
                year = input("Enter a year:  \n")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                total=0
                for row in csv_file:
                        if year == row[0]:
                                total+=int(row[4])
                print ("Total death in year",year,"is : ",total)

        def deathForSpecificDisease():
                disease = input("Enter a disease or cause name to find out total death by that disease or cause:  \n")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                total=0
                for row in csv_file:
                        if disease == row[2]:
                                total+=int(row[4])
                print ("Total death caused by ",disease,"is : ",total)


        def deathInAyearForSpecificDisease():
                disease = input("Enter a disease or cause name to find out total death in a year caused by that disease or cause:  \n")
                year = input("Enter a year: ")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                total=0
                for row in csv_file:
                        if disease == row[2] and year == row[0]:
                                total+=int(row[4])
                print ("Total death in ",year," caused by ",disease,"is : ",total)

        def searchByStateDiseaseYear():
                state = input("Enter a state name: \n")
                disease = input("Enter a disease name: \n")
                year = input("Enter a year name: \n")
                csv_file = csv.reader(open('NCHS_-_Leading_Causes_of_Death__United_States.csv'))
                for row in csv_file:
                        if state == row[3] and disease == row[2] and year == row[0] :
                                print (row)
       
        

        print("Enter 1 to search by State")
        print("Enter 2 to search by Disease")
        print("Enter 3 to search by Year")
        print("Enter 4 to find out total death in a year")
        print("Enter 5 to find out total death by a disease or cause")
        print("Enter 6 to find out total death in a year happend by specific disease or cause")
        print("Enter 7 to search by State, Disease and Year ")
        print("Enter 8 to Exit")


        userInput = int(input("Enter here: \n"))

        if userInput == 1:
                searchByState()
        elif userInput==2:
                searchByDisease()
        elif userInput==3:
                searchByYear()
        elif userInput==4:
                deathByYear()
        elif userInput==5:
                deathForSpecificDisease()
        elif userInput==6:
                deathInAyearForSpecificDisease()
        elif userInput==7:
                searchByStateDiseaseYear()
        elif userInput==8:
                break

        
        else: 
                print("Please try again! Something went wrong ")

       



