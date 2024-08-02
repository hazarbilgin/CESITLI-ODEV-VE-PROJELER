		#include<iostream>
		using namespace std;
		class Person
		{
			protected:
				string name,surname;
				int age,starvationRate=100;
				public:
				
					Person(string name,string surname,int age):name(name),surname(surname),age(age)
					{
						starvationRate=100;
					}
				string getName()
				{
					return name;
				}
				
				
					string getSurname()
				{
					return surname;
				}
				
				
					string getFullName()
				{
					return name+" "+surname;
				}
				
					int getAge()
				{
					return age;
				}
					int getStarvationRate()
				{
					return starvationRate;
				}
				
				void SetAge(int age)
				{
					this->age=age;
				}
				
				void setStravationRate(int starvationRate)
				{
					this->starvationRate=starvationRate;
				}
			virtual	bool checkStravation()
				{
					if(starvationRate>20)
					{
					return true;	
					}
					else
					{
						return false;
					}
					
				}
				virtual ~Person()
				{
					cout<<getFullName()<<"  is left the hospital"<<endl;
					
				}
		};
		
		class Patient:public Person
		{
			protected:
				string illnessName;
				public:
					Patient(string name,string surname,int age,string illnessName):Person(name,surname,age),illnessName(illnessName)
					{
						
					}
					void setillnessName(string illnessName)
					{
						this->illnessName=illnessName;
					}
					
					bool checkStarvation()
					{
						if(starvationRate>50)
						return true;
						else
						{
							return false;
						}
					}
					 void takeACare()
					{
				setStravationRate(getStarvationRate()-15);
					
						if(checkStarvation())
						{
						cout<<getFullName()<<" is  (patient) Hungry! "<<endl;		
						}
						
					}	
					 ~Patient()
					{
						cout<<getFullName()<<" was  (patient) discharged! "<<endl;
					}					
		};
		
		class Employee:public Person
		{
			protected:
				int employeeId;
			public:
				
					Employee(string name,string surname,int age,int employeeId):Person(name,surname,age),employeeId(employeeId) { 	}

					int getEmployeeId()
					{
						return employeeId;
					}
					
					bool checkStarvation()
					{
						if(getStarvationRate()<20)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					
				virtual	void checkPatient(Patient &P)
					{
					setStravationRate(getStarvationRate()-5);
						cout<<"The patient:  "<<getFullName()<<"  is checking..."<<endl;
						if(checkStarvation())
						{
							cout<<getFullName()<<" is starving!"<<endl;
						}
					}
					
					virtual ~Employee()
					{
						cout<<getFullName()<<" quit the job! "<<endl;
						
					}
					
		};
		
		class Nurse:public Employee
		{
		public:
		Nurse(string name,string surname ,int age,int employeeId):Employee(name,surname,age,employeeId)
		{
		
		}
		void checkPatient(Patient &P)	
		{
		setStravationRate(getStarvationRate()-10);
			cout<<P.getFullName()<<"  is checking..."<<endl;
			P.takeACare();
			cout<<getFullName()<<"  took care of the patient"<<endl;
			if(checkStarvation()==1)
					{
				cout<<P.getFullName()<<" is (patient) starving!. "<<endl;
				cout<<endl;
			}
		}
		~Nurse()
		{
			cout<<getFullName()<<"   is quit being Nurse!. "<<endl;	
		}
		
			};
		class Doctor:public Employee
		{
		public:
			Doctor(string name,string surname,int age,int employeeId):Employee(name,surname,age,employeeId)
		{
			
		}
		 void checkPatient(Patient &P)
		{
			setStravationRate(getStarvationRate()-5);
			cout<<P.getFullName()<<" is checking..."<<endl;
			P.takeACare();
			cout<<getFullName()<<"  gives medicine to the patient ."<<endl;
			
			if(checkStarvation())
			{
				cout<<P.getFullName()<<" is  (patient) starving!."<<endl;
			}	
		}
		~Doctor()
		{
			cout<<getFullName()<<" quit  being Doctor!. "<<endl;
			
		}	
		};

int main()
{	
	Nurse N("Lauren","Jackson",38,971371);
	Doctor D("Johnny","Deep",56,150717);
	Patient P("Stephen","Curry",32,"something");
	
	cout<<N.getFullName()<<endl;
	
	
	N.checkPatient(P);
	cout<<endl<<endl;
	N.checkStarvation();
	
	cout<<D.getFullName()<<endl;
	
	D.checkPatient(P);
	cout<<endl<<endl;
	D.checkStarvation();
		
	
	return 0;
}