#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class student{
	private:
    int id;        //student's id #
    string lname;        //student's last name
    string name;        //student's first name
    string mname;        //student's middle name
    string course;    //student's course    
    string address;
    string contact__no;
	int year;            //student's year level
    int age; 
    public:
   	void menu();
   	void insert();
   	void display();
   	void modify();
   	void search();
   	void deleted();
};
int main()
 {
	student s;
	s.menu();
}

void student::menu()
{
	menustart:
	int choice;;
	char x;
	cout<<setfill('*')<<endl;
	cout<<setw(9);
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t********|STUDENT MANAGEMENT SYSTEM|******"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t\t1.NEW STUDENT REGESTRATION"<<endl;
	cout<<"\t\t\t\t2.DISPLAY RECORDS"<<endl;
	cout<<"\t\t\t\t3.SEARCH RECORDS"<<endl;	
	cout<<"\t\t\t\t4.MODIFY RECORDS"<<endl;
    cout<<"\t\t\t\t5.DELETE RECORDS"<<endl;
	cout<<"\t\t\t\t6.EXIT"<<endl;
	
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t Choose Option :(1,2,3,4,5,6)"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t----------Please enter your Choice-----------:  ";
	cin>>choice;
	switch(choice)
	{
	 case 1:
	do{
	 insert();
	 cout<<"\n\t\t\t Add another Student record (Y,N): ";
	 cin>>x;
       }while(x== 'y'||x=='Y');
	 break;
	 case 2:
	 	display();
	 	break;
	    case 3:
	 	modify();
	 	break;
	 	case 4:
	 	search();
	 	break;
	 	case 5:
	 	deleted();
	 	break;
	    case 6:
	 	exit(0);
	    default:
	    cout<<"\t\t\t********invalid choice!!!!!******"<<endl;
	 break;	
	}
	getch();
	goto menustart;
}
void student::insert()
{
	system("cls");
	fstream file;
	
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t********ADD NEW STUDENTS RECORDS******"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t enter your first name:";
    cin>>name;
	cout<<"\t\t\t enter your middle name: ";
	cin>>mname;
	cout<<"\t\t\t enter your last name:" ;
	cin>>lname;
	cout<<"\t\t\t enter your id: ";
	cin>>id;
	cout<<"\t\t\t enter your address: ";
	cin>>address;
	cout<<"\t\t\t enter your age: ";
	cin>>age;
	cout<<"\t\t\t enter your course: ";
	cin>>course;
	cout<<"\t\t\t enter your course year: ";
	cin>>year;
	cout<<"\t\t\t enter your contact__no: ";
	cin>>contact__no;
	file.open("regestratiton.txt", ios::app | ios::out);
	if(!file)
     {
     	cout<<"new regestration is unsuccessiful please try again!!";
	 }
	 else{
	 	cout<<"\t\t\t********new regestrarion is successfully created**********";
	 }
	file<<" "<<name<<" "<<mname<<" "<<lname<<" "<<id<<" "<<address<<" "<<age<<" "<<course<<" "<<year<<" "<<contact__no<<"\n";
	file.close();
	
}
void student::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t********STUDENT RECORDS TABLE******"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	file.open("regestratiton.txt",ios::in);
	if(!file)
     {
     	cout<<"\n\t\t\tStudent records cannot be found please try again!!";
     	file.close();
	 }
	 else{
	file>>name>>mname>>lname>>id>>address>>age>>course>>year>>contact__no;
	while(!file.eof())
	{
	cout<<"\n\n\t\t\t\t Student no:"<<total++<<endl;
	cout<<"\n\t\t\t\t Student first name:"<<name<<endl;
	cout<<"\n\t\t\t\t Student middle name:"<<mname<<endl;
	cout<<"\n\t\t\t\t Student lastname:"<<lname<<endl;
	cout<<"\n\t\t\t\t Student id:"<<id<<endl;
	cout<<"\n\t\t\t\t Student address:"<<address<<endl;
	cout<<"\n\t\t\t\t Student age:"<<age<<endl;
	cout<<"\n\t\t\t\t Student course:"<<course<<endl;
	cout<<"\n\t\t\t\t Student course year:"<<year<<endl;
	cout<<"\n\t\t\t\t Student contact no:"<<contact__no<<endl;
	file>>name>>mname>>lname>>id>>address>>age>>course>>year>>contact__no;

	}
	if(total==0)
	{
	cout<<"\n\t\t\tStudent records cannot be found please try again!!";	
	}
	file.close();
	    }
	
}
void student::modify()
{
	system("cls");
	fstream file,file1;
	int found=0;
	int st_id;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t********TO MODIFY THE RECORDS OF STUDENTS******"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;	
	file.open("regestration.txt",ios::in);
		if(!file)
     {
     	cout<<"\n\t\t\tStudent records cannot be found please try again!!";
     	file.close();
	 }
	 else{
	 	cout<<"\enter the id of student which you want to modify: ";
	 	cin>>st_id;
	 	file1.open("newrecord.txt",ios::app|ios::out);
	 	file>>name>>mname>>lname>>id>>address>>age>>course>>year>>contact__no;
	 	while(!file.eof())
	 	{
	 	if(st_id!=id)
		 {
		 file<<" "<<name<<" "<<mname<<" "<<lname<<" "<<id<<" "<<address<<" "<<age<<" "<<course<<" "<<year<<" "<<contact__no<<"\n";
		 
		 }	
		 else{
		 	cout<<"\t\t\t enter your first name:";
     		cin>>name;
	 		cout<<"\t\t\t enter your middle name: ";
    		cin>>mname;
			cout<<"\t\t\t enter your last name:" ;
			cin>>lname;
			cout<<"\t\t\t enter your id: ";
			cin>>id;
			cout<<"\t\t\t enter your address: ";
			cin>>address;
			cout<<"\t\t\t enter your age: ";
			cin>>age;
			cout<<"\t\t\t enter your course: ";
			cin>>course;
			cout<<"\t\t\t enter your course year: ";
			cin>>year;
			cout<<"\t\t\t enter your contact__no: ";
			cin>>contact__no;
			file<<" "<<name<<" "<<mname<<" "<<lname<<" "<<id<<" "<<address<<" "<<age<<" "<<course<<" "<<year<<" "<<contact__no<<"\n";
		 found++;
		 }
		 	file<<" "<<name<<" "<<mname<<" "<<lname<<" "<<id<<" "<<address<<" "<<age<<" "<<course<<" "<<year<<" "<<contact__no<<"\n";
		if(found==0){
		cout<<"\n\t\t\t\t student rollno not found!!"<<endl;
		}
		}	
		file1.close();
		file.close();
		remove("regestration.txt");
		rename("newrecord.txt","regestration.txt");
		
	 }
	
}
void student::search(){
	system("cls");
	fstream file;
	int st_id;
	file.open("regestration.txt",ios::in);
	if(!file){
		cout<<setfill('*')<<"searching"<<setw(8)<<setfill('*')<<setw(8)<<"no data found"<<endl;
	}
	else{
	    cout<<"\nenter the id of student which you want to modify: ";
	 	cin>>st_id;
	 	int found=0;
	 	file.open("regestration.txt",ios::app|ios::out);
	 	file>>name>>mname>>lname>>id>>address>>age>>course>>year>>contact__no;
	 	while(!file.eof())
	 	{
	 	if(st_id==id)
		 {
		 	cout<<"\n\t\t\t\t Student first name:"<<name<<endl;
    		cout<<"\n\t\t\t\t Student middle name:"<<mname<<endl;
			cout<<"\n\t\t\t\t Student lastname:"<<lname<<endl;
			cout<<"\n\t\t\t\t Student id:"<<id<<endl;
			cout<<"\n\t\t\t\t Student address:"<<address<<endl;
			cout<<"\n\t\t\t\t Student age:"<<age<<endl;
			cout<<"\n\t\t\t\t Student course:"<<course<<endl;
			cout<<"\n\t\t\t\t Student course year:"<<year<<endl;
			cout<<"\n\t\t\t\t Student contact no:"<<contact__no<<endl;
		    found++;
		 }	
		 	file>>name>>mname>>lname>>id>>address>>age>>course>>year>>contact__no;
	   }
    	if(found==0){
		cout<<"\n\t\t\t student roll no Not found!!!!!"<<endl;
	 }
	file.close();
}
}
   void student::deleted(){
	system("cls");
	int st_id;
	fstream file,file1;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	cout<<"\t\t\t********TO DELETE THE RECORDS OF STUDENTS******"<<endl;
	cout<<"\t\t\t-----------------------------------------"<<endl;
	file.open("regestration.txt",ios::in);
		if(!file)
     {
     	cout<<"\n\t\t\tStudent records cannot be found please try again!!";
     	file.close();
	 }
	  else{
	 	cout<<"\enter the id of student which you want to modify: ";
	 	cin>>st_id;
	 	int found=0;
	 	file.open("regestration.txt",ios::app|ios::out);
	 	file>>name>>mname>>lname>>id>>address>>age>>course>>year>>contact__no;
	 	while(!file.eof())
	 	{
	    	if(st_id==id)
		  {
	 	
	 	  file<<" "<<name<<" "<<mname<<" "<<lname<<" "<<id<<" "<<address<<" "<<age<<" "<<course<<" "<<year<<" "<<contact__no<<"\n";
		   found++;
		  }
		 	file<<" "<<name<<" "<<mname<<" "<<lname<<" "<<id<<" "<<address<<" "<<age<<" "<<course<<" "<<year<<" "<<contact__no<<"\n";
	   	  if(found==0){
	  	cout<<"\n\t\t\t\t student rollno not found!!"<<endl;
	  	}
	 	}	
	 	 file1.close();
	 	 file.close();
		 remove("regestration.txt");
	  	 rename("newrecord.txt","regestration.txt");
		
	
   }
}

