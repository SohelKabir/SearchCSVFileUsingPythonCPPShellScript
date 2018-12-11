flag=1
while [ $flag -eq 1 ]
do

searchByState()
{
echo "Enter state name to search: "
read state 
grep $state NCHS_-_Leading_Causes_of_Death__United_States.csv 
}

searchByYear()
{
echo "Enter a year  to search: "
read year
grep $year NCHS_-_Leading_Causes_of_Death__United_States.csv
}
searchByCause()
{
echo "Enter a cause or disease name  to search: "
read cause
grep $cause NCHS_-_Leading_Causes_of_Death__United_States.csv
}
searchByStateYearCause()
{
echo "Enter a  state name: "
read State
echo "Enter a  year: "
read Year
echo "Enter a  cause or disease name: "
read Cause
grep "$Year.*$State" NCHS_-_Leading_Causes_of_Death__United_States.csv | grep "$Cause"

}
totalDeathInYear()
{
	echo "Enter a year: "
	read year
	
	#awk -F "," '{ sum += $2 } END { print sum }' test1.csv
	#awk -F',' '{sum+=$6} END {print sum}' test1.csv 
	#ls -l | awk '{print $5}'
	#awk '{for (i=1;i<=NF;i++) sum[i]+=$i;}; END{for (i in sum) print "for column "i" is " sum[i];}' FileA
	#awk -F "," '{print $6}' test1.csv 
	#f=test1.csv; colnum=`head -1 ${f} | sed 's/,/\n/g' | nl | grep 'Deaths$' | cut -f 1 `; cut -d, -f ${colnum} ${f}
	awk -vFPAT='[^,]*|"[^"]*"' '{ gsub("^\"|\"$","",$1); gsub("^\"|\"$","",$4); } { if ($1 == '$year') sum += $5 } END { print sum } ' NCHS_-_Leading_Causes_of_Death__United_States.csv
}
totalDeathInAYearByACause()
{
	echo "Enter a year: "
	read year
	echo "Enter a cause or disease name: "
	read cause
	
	
	#awk -vFPAT='[^,]*|"[^"]*"' '{ gsub("^\"|\"$","",$1); gsub("^\"|\"$","",$4); } { if ($1 == '$year' && $3 == '$cause') sum += $5 } END { print sum } ' NCHS.csv
	awk -v c="$cause" -v y="$year" -vFPAT='[^,]*|"[^"]*"' '{ gsub("^\"|\"$","",$1); gsub("^\"|\"$","",$4); } { if ($1 == y && $3 == c) sum += $5 } END { print sum } ' NCHS_-_Leading_Causes_of_Death__United_States.csv
}
totalDeathByACause() #done
{
	echo "Enter a cause or disease name: "
	read cause
	
	
	awk -v c="$cause" -vFPAT='[^,]*|"[^"]*"' '{ gsub("^\"|\"$","",$1); gsub("^\"|\"$","",$4); } { if ($3 == c) sum += $5 } END { print sum } ' NCHS_-_Leading_Causes_of_Death__United_States.csv
}

	echo "enter 1 to search by state name "
	echo "Enter 2 to search by year"
	echo "Enter 3 to search by Cause or Disease"
	echo "Enter 4 to search by State, Year, Cause or Disease"
	echo "Enter 5 to find total death in a year happened by all kind of causes  that year"
	echo "Enter 6 to find total death in that year happened by specific cause or disease"
	echo "Enter 7 to find total death happened by that cause or disease over the all years"
	echo "Enter 8 to Exit from program"
	read choice

if [ "$choice" -eq 1 ]
then 
	searchByState
elif [ "$choice" -eq 2 ]
then
	searchByYear
elif [ "$choice" -eq 3 ]
then
	searchByCause
elif [ "$choice" -eq 4 ]
then
	searchByStateYearCause
elif [ "$choice" -eq 5 ]
then
	totalDeathInYear
elif [ "$choice" -eq 6 ]
then
	totalDeathInAYearByACause
elif [ "$choice" -eq 7 ]
then
	totalDeathByACause
elif [ "$choice" -eq 8 ]
then
	break
else 
	echo "Please Enter a valid number "
fi 

done