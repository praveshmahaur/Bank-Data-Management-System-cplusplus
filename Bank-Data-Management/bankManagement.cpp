#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class database{
    private:
        int accountNo;
        char name[25];
        char fatherName[25];
        char phoneNo[25];
        char email[25];
        float amount;
        int newAmount;
        fstream file,file1;

    public:
	    int search;

        void createAccount(void);   // create account function
        void depositAmount(void);   // depositAmount function
        void withdrawAmount(void);  // withdrawAmount function
        void checkInfo(void);       // checkInfo function
};

void database :: createAccount(){

    srand(time(0));
	accountNo=rand()*rand()+rand()*rand();
	
	cout<<"Enter Your name : ";
	cin>>name;
	
	cout<<"Enter Your Father name : ";
	cin>>fatherName;
	
	cout<<"Enter Your phone no. : ";
	cin>>phoneNo;
	
	cout<<"Enter Your email : ";
	cin>>email;
	
	cout<<"Enter Your amount : ";
	cin>>amount;
	
	cout<<endl<<"your account number is:: "<<accountNo<<endl;
	cout<<"Please save YOUR ACCOUNT NUMBER\n\n";
	
	file.open("data.txt",ios::out|ios::app);
	file<<accountNo<<"\t "<<name<<"\t "<<fatherName<<"\t "<<"\t "<<phoneNo<<"\t "<<email<<"\t "<<amount<<endl;
	file.close();
}

void database :: depositAmount(){
   
	cout<<"Enter amount to deposit :: ";
	cin>>newAmount;

	file.open("data.txt",ios::in);
	file1.open("data1.txt",ios::out|ios::app);
	file>>accountNo>>name>>fatherName>>phoneNo>>email>>amount;
	
	while(!file.eof()) {
		if(accountNo==search){
			cout<<"\ncurrent amount :: "<<amount;
			amount=amount + newAmount;
			cout<<"\nupdated amount :: "<<amount<<endl;
			file1<<accountNo<<"\t"<<name<<"\t"<<fatherName<<"\t"<<phoneNo<<"\t"<<email<<"\t"<<amount<<endl;
		}else{
			file1<<accountNo<<"\t"<<name<<"\t"<<fatherName<<"\t"<<phoneNo<<"\t"<<email<<"\t"<<amount<<endl;
		}
		file>>accountNo>>name>>fatherName>>phoneNo>>email>>amount;
	}
	
	file.close();
	file1.close();
	remove("data.txt");
	rename("data1.txt","data.txt");
}

int main(){
    database obj;
    obj.createAccount();
    
    return 0;
}