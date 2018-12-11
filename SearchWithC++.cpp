#include <bits/stdc++.h>

using namespace std;

struct record{
	int year;
	string cause1, cause2, state;

	int deaths;
	double deathRate;

	record(){

	}

	record(int year, string cause1, string cause2, string state, int deaths, double deathRate){
		this->year = year;
		this->cause1 = cause1;
		this->cause2 = cause2;
		this->state = state;
		this->deaths = deaths;
		this->deathRate = deathRate;
	}

	void print(){
	    cout<<" "<<year<<" "<<" "<<cause1<<" "<<cause2<<" "<<" "<<state<<" "<<deaths<<" "<<deathRate<<endl;
	}


};

vector<string> split(string s){
	vector<string> v;
	string x = "";
	bool quote = false;
	for(char i : s){
        if (i == '"'){
            quote ^= 1;
        }
		if (i == ',' && !quote){
			v.push_back(x);
			x = "";
		}
		else {
			x += i;
		}

	}

	if (!x.empty()){
		v.push_back(x);
	}

	return v;
}

int toInt(string s){
	int x = 0;
	for(char i : s){
		x *= 10;
		x += (i - '0');
	}

	return x;

}

double toDouble(string s){
   // cerr<<"toDouble "<<s<<endl;
	double a=0.0, b=0.0;
	bool dot = false;
	double factor = 10.0;
	for(char i : s){
		if (i == '.'){
			dot = true;
			continue;
		}

		if (!dot){
			a *= 10;
			a += (i - '0');
		}
		else {
			b += (i - '0')/factor;
			factor *= 10;
		}

	}

	return a + b;

}

vector<record> records;

void f1(string cod){
    for(i : records){
        if (i.cause1.find(cod) != string::npos || i.cause2.find(cod) != string::npos){
            i.print();
        }
    }

    return;
}

void f2(int year){
    int total = 0;
    for(i : records){
        if (i.year == year){
            total += i.deaths;
        }
    }

    cout<<"Total number of deaths in "<<year<<" = "<<total<<endl;

    return;

}

void f3(string state){

     for(i : records){
        if (i.state == state){
            i.print();
        }
    }
    //cout<<"Total number of deaths in "<<state<<" = "<<total<<endl;


    return;
}


void f4(string state){
    int total = 0;
     for(i : records){
        if (i.state == state){
            total += i.deaths;
        }
    }
    cout<<"Total number of deaths in "<<state<<" = "<<total<<endl;


    return;
}


void f5(string cod){
    int total = 0;
    string cause = "'nothing found'";
    for(i : records){

        if (i.cause1.find(cod) != string::npos || i.cause2.find(cod) != string::npos){
            cause = i.cause1;
            total += i.deaths;
        }
    }
    cout<<"Total number of deaths by "<<cod<<" = "<<total<<endl;

    return;
}


void f6(string cod, int year){
    int total = 0;
    string cause = "'nothing found'";
    for(i : records){

        if (i.year==year &&  (i.cause1.find(cod) != string::npos || i.cause2.find(cod) != string::npos) ){
            cause = i.cause1;
            total += i.deaths;
        }
    }
    cout<<"Total number of deaths by "<<cod<<" in year "<<year<<" = "<<total<<endl;

    return;
}


void f7(string cod, int year){

    for(i : records){
        if (i.year==year &&  (i.cause1.find(cod) != string::npos || i.cause2.find(cod) != string::npos) ){

            i.print();
        }
    }
    //cout<<"Total number of deaths by "<<i.cause1<<<" in year "<<year<<" = "<<total<<endl;

    return;
}


int main(){
	ifstream file("NCHS_-_Leading_Causes_of_Death__United_States.csv", ifstream :: in);
	string s;
	getline(file, s);

	while(getline(file, s)){
		vector<string> v = split(s);

		//cerr<<v.size()<<endl;

		records.emplace_back(toInt(v[0]), v[1], v[2], v[3], toInt(v[4]), toDouble(v[5]));


	}
   // records[0].print();
	//cerr<<"records.size "<<records.size()<<endl;

    int choice;
    do{
        cout<<"Enter choice:\n";
        cout<<"1. Records of a particular cause of death\n";
        cout<<"2. Total number of deaths by year\n";
        cout<<"3. Records of deaths by state\n";
        cout<<"4. Total number of deaths by state\n";
        cout<<"5. Total number of deaths due to a particular cause\n";
        cout<<"6. Total number of deaths due to a particular cause in a particular year\n";
        cout<<"7. Records of deaths due to a particular cause in a particular year\n";
        cout<<"0. Exit\n";
        cin>>choice;

        if (choice == 1){
            cout<<"Enter cause of death:\n";
            cin.ignore();
            string cod;
            getline(cin, cod);
            f1(cod);

        }
        else if (choice == 2){
            cout<<"Enter year:\n";
            int year;
            cin>>year;
            f2(year);
        }
        else if (choice == 3){
            cout<<"Enter name of state:\n";
            cin.ignore();
            string cod;
            getline(cin, cod);
            f3(cod);
        }
         else if (choice == 4){
            cout<<"Enter name of state:\n";
            cin.ignore();
            string cod;
            getline(cin, cod);
            f4(cod);
        }
        else if (choice == 5){
            cout<<"Enter cause of death:\n";
            cin.ignore();
            string cod;
            getline(cin, cod);
            f5(cod);

        }
        else if (choice == 6){
            cout<<"Enter cause of death:\n";
            cin.ignore();
            string cod;
            getline(cin, cod);
            cout<<"Enter year:\n";
            int year;
            cin>>year;
            f6(cod, year);

        }
        else if (choice == 7){
            cout<<"Enter cause of death:\n";
            cin.ignore();
            string cod;
            getline(cin, cod);
            cout<<"Enter year:\n";
            int year;
            cin>>year;
            f7(cod, year);

        }


        else break;

        cout<<"\n\n";

    }while(choice!=0);







}
