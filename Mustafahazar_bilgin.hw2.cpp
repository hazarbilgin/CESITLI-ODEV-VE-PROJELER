#include<iostream>
using namespace std;
		class Hours
		{
			public:
				int hour,minutes;
				//default constructer
				Hours() 
				{
					
				}
				
		//friend operator overloading for output (>>) operators		
		friend istream& operator>>(istream& al,Hours& abc);
		
		//friend operator overloading for output (<<) operators
		friend ostream& operator<<(ostream& yaz, const Hours& abc);	
};
//operator overloading for output (<<) operators write CheckinTime CheckoutTime
ostream& operator<<(ostream& yaz, const Hours& abc )
{  
	yaz<<abc.hour<<":"<<abc.minutes;
	return yaz;
}
 // Operator overloading for input (>>) get CheckinTime and CheckOoutTime hour and minute
istream& operator>>(istream &al,Hours &abc)
{  
	al>>abc.hour>>abc.minutes;
	return al;
}
		
		class Animals
		{
			//define id,animalName,ownerName,ownerSurname,totalhours,totalMins on protected 
			protected:
				string id,animalName,ownerName,ownerSurname;
				Hours totalHours;
				int totalMins=0;
				public:
					 //Define constructer by using member initialization id animalName ownerName ownerSurname
					Animals(string id,string animalName,string ownerName,string ownerSurname)
					{
						this->id=id;
						this->animalName=animalName;
						this->ownerName=ownerName;
						this->ownerSurname=ownerSurname;				
					}
					
					//Checkin Checkout are controlled
			int calculateMinutes(Hours H_cin,Hours H_cout)
			{
			if((H_cout.hour>H_cin.hour)&&(H_cout.minutes>H_cin.minutes))
			{
		//If hour and minutes of the out time  bigger than enter time use there
			totalMins=((H_cout.hour-H_cin.hour)*60)+(H_cout.minutes-H_cin.minutes);
			return totalMins; 
			}
			else if((H_cout.hour>=H_cin.hour)&&(H_cout.minutes<H_cin.minutes))
		// else if hour of the (out) time is equal or bigger than the hour of the (enter) time but minutes ckeck out time smaller than the minutes CheckInTime use there
			{	
			H_cout.minutes=(H_cout.minutes+60);
			H_cout.hour=H_cout.hour-1;
			totalMins=((H_cout.hour-H_cin.hour)*60)+(H_cout.minutes-H_cin.minutes);
			return totalMins;
			}
			
				//else statement is there.
				else
				{  
				cout<<"Please enter an appropriate time.";
				//else is -1 cod is going to finish
				return -1; 
				}
				
				}
				
				};
				//Cat class inherited from Animal class 
				
				
					class Cat: public Animals
					{
					protected:
					string type;
					
					public:
					// inheritence to id,animalName,ownerName,ownerSurname
					Cat(string id,string animalName,string ownerName,string ownerSurname,string type):Animals(id,animalName,ownerName,ownerSurname),type(type)
					{
						
					}	
					
					//it display  the id, animal_name, ownername,ownersurname,type of the animal
					void PrintInfo()
					{
						cout<<"Id of the animal is: "<<id<<endl<<"Name of the animal is: "<<animalName<<endl<<"Name of the animal's owner is: "<<ownerName<<endl
						<<"Surname of the animal's owner is: "<<ownerSurname<<endl<<"Type of the animal is: "<<type<<endl;
					}
					};
					int main()
					{
						Hours H_cin,H_cout;
						//get the information by using Cat class using constructer
						Cat Kedi("123456","Goofy","Kobe","Bryant","Cat");
						//Call the printInfo function for object
						Kedi.PrintInfo();
						
						cout<<"Please enter check in time of the animal: "<<endl;
						//input the checkInTime  operator overloading
						cin>>H_cin;
						
						cout<<"Enter the check out time of the animals :\n";
						//input the checkOutTime operator overloading
						cin>>H_cout;
						
						//(<<)operator overloading for output
						cout <<"check in and check out time are "<<H_cin<<"/"<<H_cout<<endl;
				
						do 
						{
						//Call calculateMinutes to output the total minutes calculate animals
						cout<<"The total time animal stays  in the clinic is "<<Kedi.calculateMinutes(H_cin,H_cout)<<" minutes. !";
						}while(Kedi.calculateMinutes(H_cin,H_cout)!=-1);        
						return 0;
}                                                             