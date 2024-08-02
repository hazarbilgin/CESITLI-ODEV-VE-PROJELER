	#include<iostream>
	#include<string>
	#include<fstream>
	using namespace std;
	class Date
	{
	public:
	int day,year;
	string month;
	Date(int day,int year,string month):day(day),year(year),month(month){	}	
	Date()
	{
	}
	};
	
	class Player{
	private:
	string first,last;
	Date birthDate;
	public:

		Player(){		}
		Player(string first,string last,Date birthDate):first(first),last(last)	
		{this->birthDate=birthDate;	}
		
	
		string Months[6]={"August","September", "February","December","Octaber","April"};  
	
		
	
		
		string getMonth() const
		{
			return birthDate.month;
		}
		  
		void printInfo() {
	    cout << first << " " << last << "  " << birthDate.month << " " << birthDate.day << ", " << birthDate.year << endl; }

		int getDay() const
		{return birthDate.day;	}
		 int getYear() const
		{return birthDate.year;}
	
		friend ostream& operator<<(ostream& yaz, const Player &P);
			friend istream& operator>>(istream& yaz, const Player &P);	 
		
		string checkMonth(){
			
		fstream input;
		input.open("input.txt");
		fstream output;
		output.open("output.txt");
		
		
		while(!input.eof()){
		input>>first>>last>>birthDate.day>>birthDate.month>>birthDate.year;
			Date D(birthDate.day,birthDate.year,birthDate.month);
			Player P(first,last,D);
		for(int i=0;i<6;i++){	
	

		if(birthDate.month.substr(0,3)==Months[i].substr(0,3)){
		birthDate.month=Months[i];			
		output<<first<<" "<<last<<" "<<birthDate.day<<" "<<Months[i]<<" "<<birthDate.year<<" "<<endl;
		output<<""<<endl;
		output<<P;
		throw P;
				return Months[i];		}
		else{
			output<<first<<" "<<last<<" "<<birthDate.day<<" "<<Months[i]<<" "<<birthDate.year<<" "<<endl;
				return Months[i]; 	} } }
		input.close();
		output.close();
		}     
	};
	ostream& operator<<(ostream& yaz,const Player &P)
	{
		yaz<<" name: "<<P.first<<" lastName: "<<P.last<<" birthdate day,month,year: "<<P.getDay()<<"."<<P.getMonth()<<"."<<P.getYear()<<endl;
		return yaz;
	}
	/*
	istream& operator>>(istream& al,const Player &P)
	{
		al>>" name: ">>P.first>>" lastName: ">>P.last>>" birthdate day,month,year: ">>P.getDay()>>".">>P.getMonth()>>".">>P.getYear()>>endl;
		return al;
	}
	*/
	int main()
	{
	/*	fstream input;
		string line;
		input.open("input.txt");
		fstream output;
		output.open("output.txt");
		string fName,lName;
		string Months[6]={"August","September", "February","December","Octaber","April"};  
		string Month;
		int Day,Year;		
		*/
		
		try
		{
		//	while(!input.eof())
			//{			
		//	input>>fName>>lName>>Day>>Month>>Year;
		//	Date D(Day,Year,Month);
			//Player P(fName,lName,D);
			
		Player P;
			P.checkMonth();
			P.printInfo();
		
		
		/*	for(int i=0;i<6;i++){
		
			if(Months[i].substr(0,3)==Month.substr(0,3)){
			
			output<<fName<<" "<<lName<<" "<<Day<<" "<<Months[i]<<" "<<Year<<endl;
			throw Month;
			}                                                                
			}
			*/
	//	}	
	}
		catch(Player &P){
			
		for(int i=0;i<6;i++)
		{
		cout<<" inccorrect Months: "<<P.getMonth()<<" Correct one is: "<<P.Months[i]<<endl;
		}
		}
		return 0;
	}