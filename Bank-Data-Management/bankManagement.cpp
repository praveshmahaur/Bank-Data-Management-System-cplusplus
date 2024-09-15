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

void database :: withdrawAmount(){
    
	cout<<"Enter amount to withdraw :: ";
	cin>>newAmount;

	file.open("data.txt",ios::in);
	file1.open("data1.txt",ios::out|ios::app);
	file>>accountNo>>name>>fatherName>>phoneNo>>email>>amount;
	
	while(!file.eof()) {
		if(accountNo==search){
			cout<<"\ncurrent amount :: "<<amount;
			amount=amount - newAmount;
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

void database :: checkInfo(){
    
	
	fstream file;
	file.open("data.txt",ios::in);
	if(!file){
		cout<<"File opening error !";
	}
	file>>accountNo>>name>>fatherName>>phoneNo>>email>>amount;
	while(!file.eof()){
		if(accountNo==search){
            cout<<"\n---------------------------\n";
            cout<<endl<<"\t::: account Number ::: ";
            cout<<"\t   "<<accountNo<<endl;
            cout<<"\t::: User Name      ::: ";
            cout<<"\t   "<<name<<"\n";
            cout<<"\t::: Father Name    ::: ";
            cout<<"\t   "<<fatherName<<"\n";
            cout<<"\t::: Phone Number   ::: ";
            cout<<"\t   "<<phoneNo<<"\n";
            cout<<"\t::: Email          ::: ";
            cout<<"\t   "<<email<<"\n";
            cout<<"\t::: Current amount ::: ";
            cout<<"\t   "<<amount<<endl;
            cout<<"\n---------------------------\n\n";
		
	    }
		file>>accountNo>>name>>fatherName>>phoneNo>>email>>amount;
	}
	
	file.close();
}


int main(){
    database obj;
    char choice;

    cout<<"Punjab National Bank:::....."<<endl;
	cout<<"press 1 to Login  Account :: "<<endl;
	cout<<"press 2 to Create Account :: "<<endl;
	cout<<"press 0 to Exit           :: "<<endl;
    cout<<endl;
	cout<<"PLEASE ENTER YOUR CHOICE: ";
	cin>>choice;
    
    switch(choice){
        case '1':
            cout<<"Enter your account no :: ";
	        cin>>obj.search;
        while(1){

            cout<<"Punjab National Bank:::.......";
            cout<<"press 1 to Deposit  Amount  :: ";
            cout<<"press 2 to Withdraw Amount  ::";
            cout<<"press 3 to Check    Info    ::";
            cout<<"press 0 to Exit     Menu    ::";
            cout<<endl;
	        cout<<"PLEASE ENTER YOUR CHOICE: ";
            cin>>choice;

            switch (choice)
            {
            case '1':
                obj.depositAmount();
            break;
            case '2':
                obj.withdrawAmount();
            break;
            case '3':
                obj.checkInfo();
            break;
            case '0':
                return 0;
            break;
            default:
                cout<<"Invalid Choice...!";
            break;
            }
            system("pause");
            system("cls");
        }
        break;
        case '2':
            obj.createAccount();
        break;
        case '0':
            system("exit");
        break;
        default :
            cout<<"\n Invalid choice...! ";
        break;
    }
    return 0;

    
    return 0;
}