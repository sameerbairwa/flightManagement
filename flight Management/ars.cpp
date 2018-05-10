
#include <iomanip>
#include <iostream>
#include <string.h>
#include <Windows.h>
#include<conio.h>
using namespace std;
bool isdigits(const string &str);
void show_reserve_menu();
void flights_info();
bool check(string);
bool check_alphabet(string);
void flight_passenger();
struct passenger
{								//Structure of passenger is made to store passenger's attributes.
	int ticketno;
	string name;
	string passport;
	string cell;
	string flight;
	string address;
};
class queue
{
	private:
		passenger arr[100];
		int front,rear,size,seat_count,ticket_number;
		int counter;
	public:
		queue()
		{
			front=rear=-1;
			size=20;
			seat_count=20;
			ticket_number=12301;
			counter=0;
		}
		bool isEmpty()
		{
			if(front==-1 && rear==-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isFull()
		{
			if(front==0 && rear==size-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void enqueue(string nm,string pp,string cl,string flt,string adrs)
		{
			if (isEmpty())
			{
				front++;
				rear++;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
			else if(isFull())
			{
				cout<<"\nFAILED TO ENQUEUE BECAUSE QUEUE IS FULL..."<<endl;
	    	}
			else if(front!=0 && rear==size-1)
			{
				rear=0;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
			else if(front!=0 && rear<=front-1)
			{
				rear++;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
			else
			{
				rear++;
				arr[rear].ticketno=ticket_number;
				arr[rear].name=nm;
				arr[rear].passport=pp;
				arr[rear].cell=cl;
				arr[rear].flight=flt;
				arr[rear].address=adrs;
				ticket_number++;
				seat_count--;
			}
		}
		void dequeue()
		{
			if(isEmpty())
			{
				cout<<"\nCANNOT DEQUEUE ELEMENT BECAUSE QUEUE IS ALREADY EMPTY..."<<endl;
			}
			else if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else if(front==size-1)
			{
				front=0;
			}
			else
			{
				front=front+1;
			}
		}
		void display()
		{
				int x=4;
				int y=8;
				int s=2;
			if(front>rear)
			{
				for(int i=front;i<=size-1;i++)
				{
				gotoxy(s,y);
                gotoxy(s,y+1);
				gotoxy(s+75,y+1);

				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);

				y=y+3;
				}
				gotoxy(s,y+1);
                gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

				for(int i=0;i<=rear;i++)
				{
				gotoxy(s,y);
				gotoxy(s,y+1);
				gotoxy(s+75,y+1);
				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);
				y=y+3;
				}
				gotoxy(s,y+1);
				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

			}
			else if (front<rear)
			{
				for(int i=front;i<=rear;i++)
				{
				gotoxy(s,y);

				gotoxy(s,y+1);

				gotoxy(s+75,y+1);

				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);

				y=y+3;
				}
				gotoxy(s,y+1);

				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

			}
			else if(rear==front)
			{
				for(int i=front;i<=rear;i++)
				{
				gotoxy(s,y);

				gotoxy(s,y+1);

				gotoxy(s+75,y+1);

				gotoxy(x,y+1);
				cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
				gotoxy(s,y+2);

				y=y+3;
				}
				gotoxy(s,y+1);

				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

			}
		}
		void display_by_flight(string flt_no)
		{
			int x=4;
			int y=8;
			int s=2;
			//
			gotoxy(2,3);

			gotoxy(2,4);

			gotoxy(77,4);

			gotoxy(2,5);

			gotoxy(77,5);

			gotoxy(2,6);

			gotoxy(77,6);

			gotoxy(2,7);

			gotoxy(31,4);
			cout<<"PASSENGER DETAILS";
			gotoxy(4,6);
			cout<<left<<setw(10)<<"Ticket#"<<setw(10)<<"Name"<<setw(15)<<"Passport No."<<setw(15)<<"Cell No."<<setw(13)<<"Flight No."<<"Address";
			//
			if(front>rear)
			{
				for(int i=front;i<=size-1;i++)
				{
					if(flt_no==arr[i].flight)
					{
						gotoxy(s,y);

						gotoxy(s,y+1);

						gotoxy(s+75,y+1);

						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);

						y=y+3;
					}
				}
				gotoxy(s,y+1);

				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

				//
				for(int i=0;i<=rear;i++)
				{
					if(flt_no==arr[i].flight)
					{
						gotoxy(s,y);

						gotoxy(s,y+1);

						gotoxy(s+75,y+1);

						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);

						y=y+3;
					}
				}
				gotoxy(s,y+1);

				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

			}
			else if (front<rear)
			{
				for(int i=front;i<=rear;i++)
				{
					if(flt_no==arr[i].flight)
					{
						gotoxy(s,y);

						gotoxy(s,y+1);

						gotoxy(s+75,y+1);

						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);

						y=y+3;
					}
				}
				gotoxy(s,y+1);

				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

			}
			else if(rear==front)
			{
				for(int i=front; i<=rear;i++)
				{
					if(flt_no==arr[rear].flight)
					{
						gotoxy(s,y);

						gotoxy(s,y+1);

						gotoxy(s+75,y+1);

						gotoxy(x,y+1);
						cout<<left<<setw(10)<<arr[i].ticketno<<setw(10)<<arr[i].name<<setw(15)<<arr[i].passport<<setw(15)<<arr[i].cell<<setw(13)<<arr[i].flight<<arr[i].address;
						gotoxy(s,y+2);

						y=y+3;
					}
				}
				gotoxy(s,y+1);

				gotoxy(s,y+2);

				gotoxy(s+75,y+2);

				gotoxy(x+31,y+2);
				cout<<"Finish";
				gotoxy(s,y+3);

			}
		}

		void display_ticket(int ticket_no)
		{
			bool run=false;
			for(int i=0;i<=size-1;i++)
			{
				if(arr[i].ticketno==ticket_no)
				{
					gotoxy(19,6);
					cout<<"Ticket No:             "<<arr[i].ticketno;
					gotoxy(19,8);
					cout<<"Name:                  "<<arr[i].name;
					gotoxy(19,10);
					cout<<"Passport:              "<<arr[i].passport;
					gotoxy(19,12);
					cout<<"Cell No:               "<<arr[i].cell;
					gotoxy(19,14);
					cout<<"Flight No:             "<<arr[i].flight;
					gotoxy(19,16);
					cout<<"Address:               "<<arr[i].address;
					gotoxy(17,5);

					gotoxy(17,6);

					gotoxy(63,6);

					gotoxy(17,7);

					gotoxy(63,7);

					gotoxy(17,8);

					gotoxy(63,8);

					gotoxy(17,9);

					gotoxy(63,9);

					gotoxy(17,10);

					gotoxy(63,10);

					gotoxy(17,11);

					gotoxy(63,11);

					gotoxy(17,12);

					gotoxy(63,12);

					gotoxy(17,13);

					gotoxy(63,13);

					gotoxy(17,13);

					gotoxy(63,13);

					gotoxy(17,13);

					gotoxy(63,13);

					gotoxy(17,13);

					gotoxy(63,13);

					gotoxy(17,14);

					gotoxy(63,14);

					gotoxy(17,15);

					gotoxy(63,15);

					gotoxy(17,16);

					gotoxy(63,16);

					gotoxy(17,17);

					gotoxy(63,17);

					gotoxy(17,18);

					run=true;
				}
			}
			if(run==false)
			{
				system("CLS");
				cout<<"Ticket Number You Entered Is Not Valid..."<<endl<<endl;
			}
		}







	void flight_passenger()
	{
	int ch;
	gotoxy(2,19);
	cout<<"Enter Serial No. of Flight Whose Passengers You Want To Know: ";
	cin>>ch;
	switch (ch)
	{
		case 1:
			system("CLS");
			display_by_flight("INA-108");
			break;
		case 2:
			system("CLS");
			display_by_flight("INA-320");
			break;
		case 3:
			system("CLS");
			display_by_flight("INA-170");
			break;
		case 4:
			system("CLS");
			display_by_flight("INA-102");
			break;
		case 5:
			system("CLS");
			display_by_flight("INA-101");
			break;
		default:
			system("CLS");
			cout<<"Invalid Flight Number..."<<endl;
			break;
		}
	}



	void input()
	{
		system("CLS");
		gotoxy(2,2);

		gotoxy(2,3);

		gotoxy(77,3);

		gotoxy(2,4);

		gotoxy(2,5);

		gotoxy(2,6);

		gotoxy(77,6);

		gotoxy(2,7);

		gotoxy(2,8);

		gotoxy(2,9);

		gotoxy(77,9);

		gotoxy(2,10);

		gotoxy(2,11);

		gotoxy(2,12);

		gotoxy(77,12);

		gotoxy(2,13);


	}






	void show_reserve_menu()
	{
		int choice;
		char ch='y';
		string name,passport,cell,flight,address;
		system("CLS");
		while(ch=='y' || ch=='Y')
		{
			flights_info();
			gotoxy(2,19);
			cout<<"ENTER THE SERIAL NO. OF FLIGHT IN WHICH YOU WANT TO RESERVE SEAT:  ";
			cin>>choice;
			switch(choice)
			{
				case 1:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);
					flight="INA-108";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 2:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=front;i<=rear;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);
					flight="INA-320";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 3:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);
					flight="INA-170";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 4:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);
					flight="INA-102";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				case 5:
					system("CLS");
					input();
					gotoxy(23,3);
					cout<<"Enter Passenger Name: ";
					cin>>name;
					while(check(name)==false)
					{
						gotoxy(45,3);
						cout<<"                       "<<endl;
						gotoxy(45,3);
						cin>>name;
					}
					gotoxy(23,6);
					cout<<"Enter Passport Number: ";
					cin>>passport;
					for(int i=0;i<=size-1;i++)
					{
						if(passport==arr[i].passport)
						{
							gotoxy(46,6);
							cout<<"                       "<<endl;
							gotoxy(46,6);
							cin>>passport;
						}
					}
					while(check_alphabet(passport)== false)
					{
						gotoxy(46,6);
						cout<<"                       "<<endl;
						gotoxy(46,6);
						cin>>passport;
					}
					gotoxy(23,9);
					cout<<"Enter Cell Number: ";
					cin>>cell;
					for(int i=0;i<=size-1;i++)
					{
						if(cell==arr[i].cell)
						{
							gotoxy(42,9);
							cout<<"                       "<<endl;
							gotoxy(42,9);
							cin>>cell;
						}
					}
					while(check_alphabet(cell)==false)
					{
						gotoxy(42,9);
						cout<<"                   "<<endl;
						gotoxy(42,9);
						cin>>cell;
					}
					gotoxy(23,12);
					cout<<"Enter Address: ";
					cin>>address;
					while(check(address)==false)
					{
						gotoxy(38,12);
						cout<<"                       ";
						gotoxy(38,12);
						cin>>address;
					}
					gotoxy(23,15);
					flight="INA-101";
					enqueue(name,passport,cell,flight,address);
					cout<<"\nYOUR RECORD HAS BEEN SUCCESSFULLY ENTERED..."<<endl;
					break;
				default:
					system("CLS");
					cout<<"Please Enter A Valid Serial Number....!! \n"<<endl;
					system("pause");
					break;
			}
			system("CLS");
			cout<<"Do you want to enter again(Y/N):  ";
			cin>>ch;
			system("CLS");
		}
	}

		void flight_info()
		{
			gotoxy(2,2);

			gotoxy(2,3);

			gotoxy(77,3);

			gotoxy(2,4);

			gotoxy(77,4);

			gotoxy(2,5);

			gotoxy(77,5);

			gotoxy(2,6);

			gotoxy(77,6);

			gotoxy(2,7);

			gotoxy(77,6);

			gotoxy(2,7);

			gotoxy(77,7);

			gotoxy(2,8);

			gotoxy(77,8);

			gotoxy(2,9);

			gotoxy(77,9);

			//
			gotoxy(2,10);

			gotoxy(77,10);

			gotoxy(2,11);

			gotoxy(77,11);

			gotoxy(2,12);

			gotoxy(77,12);

			gotoxy(2,13);

			gotoxy(77,13);

			gotoxy(2,14);

			gotoxy(77,14);

			gotoxy(2,15);

			gotoxy(77,15);

			gotoxy(2,16);

			gotoxy(77,16);

			gotoxy(2,17);

		}
	void flights_info()
	{
		flight_info();
		gotoxy(31,1);
		cout<<"AVAILABLE FLIGHTS";
		gotoxy(4,4);
		cout<<left<<setw(6)<<"No."<<setw(15)<<"Flight. No"<<setw(14)<<"From"<<setw(17)<<"Destination"<<setw(14)<<"Time"<<"Fare";
		gotoxy(4,6);
		cout<<left<<setw(6)<<"1"<<setw(15)<<"INA-108"<<setw(14)<<"Delhi"<<setw(17)<<"Mumbai"<<setw(14)<<"11:00 PM"<<"Rs.1500";
		gotoxy(4,8);
		cout<<left<<setw(6)<<"2"<<setw(15)<<"INA-320"<<setw(14)<<"Mumbai"<<setw(17)<<"Hyderabad"<<setw(14)<<"12:00 PM"<<"Rs.2500";
		gotoxy(4,10);
		cout<<left<<setw(6)<<"3"<<setw(15)<<"INA-170"<<setw(14)<<"Mumabi"<<setw(17)<<"Goa"<<setw(14)<<"03:00 PM"<<"Rs.3000";
		gotoxy(4,12);
		cout<<left<<setw(6)<<"4"<<setw(15)<<"INA-102"<<setw(14)<<"Mumbai"<<setw(17)<<"Delhi"<<setw(14)<<"02:00 AM"<<"Rs.5000";
		gotoxy(4,14);
		cout<<left<<setw(6)<<"5"<<setw(15)<<"INA-101"<<setw(14)<<"Lucknow"<<setw(17)<<"Delhi"<<setw(14)<<"09:00 AM"<<"Rs.1700";
	}
	void Menu()
	{
		gotoxy(2,2);

		gotoxy(2,3);

		gotoxy(77,3);

		gotoxy(2,4);

		gotoxy(77,4);

		gotoxy(2,5);

		gotoxy(77,5);

		gotoxy(2,6);

		gotoxy(77,6);

		gotoxy(2,7);

		gotoxy(77,7);

		gotoxy(2,8);

		gotoxy(77,8);

		gotoxy(2,9);

		gotoxy(77,9);

		gotoxy(2,10);

		gotoxy(77,10);

		gotoxy(2,11);

		gotoxy(77,11);

		gotoxy(2,12);

		gotoxy(77,12);

		gotoxy(2,13);

		gotoxy(77,13);

		gotoxy(2,14);

		gotoxy(77,14);

		gotoxy(2,15);

		gotoxy(77,15);

		gotoxy(2,16);

		//
		gotoxy(35,3);
		cout<<"MAIN MENU"<<endl;
		gotoxy(28,1);
		cout<<"What do you want to do?"<<endl;
		gotoxy(4,6);
		cout<<"1-Reserve Seat"<<endl;
		gotoxy(4,8);
		cout<<"2-My Ticket"<<endl;
		gotoxy(4,10);
		cout<<"3-Flights Schedule"<<endl;
		gotoxy(4,12);
		cout<<"4-Display Passengers"<<endl;
		gotoxy(4,14);
		cout<<"5-Quit Program"<<endl;
	}
};

queue obj;

int main()
{
	int choice,tcno;
	system("CLS");
	obj.Menu();
	obj.gotoxy(4,18);
	cout<<"Enter Your Choice: ";
	l:
	char c=getch();
  		if(c>='1' && c<='8')
		{
		choice=c-48;
		cout<<c;
	  		goto l2;
		}
		else
		{
			choice=getch();
		}
  	goto l;
	l2:
  	Sleep(200);
  	system("CLS");
	switch(choice)
	{
		case 1:
			system("CLS");
			obj.show_reserve_menu();
			system("pause");
			system("CLS");
			main();
			break;
		case 2:
			system("CLS");
			if(obj.isEmpty())
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
				cout<<"Enter Your Ticket Number: ";
				cin>>tcno;
				obj.display_ticket(tcno);
			}
			system("pause");
			system("CLS");
			main();
			break;
		case 3:
			system("CLS");
			if(obj.isEmpty())
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
				obj.flights_info();
				obj.flight_passenger();
			}
			system("pause");
			system("CLS");
			main();
			break;
		case 4:
			system("CLS");
			if(obj.isEmpty())
			{
				cout<<"Record Is Empty....! \n"<<endl;
			}
			else
			{
			obj.gotoxy(2,3);

			obj.gotoxy(2,4);

			obj.gotoxy(77,4);

			obj.gotoxy(2,5);

			obj.gotoxy(77,5);

			obj.gotoxy(2,6);

			obj.gotoxy(77,6);

			obj.gotoxy(2,7);

			obj.gotoxy(31,4);
			cout<<"PASSENGER DETAILS";
			obj.gotoxy(4,6);
			cout<<left<<setw(10)<<"Ticket#"<<setw(10)<<"Name"<<setw(15)<<"Passport No."<<setw(15)<<"Cell No."<<setw(13)<<"Flight No."<<"Address";
			obj.display();
			}
			system("pause");
			system("CLS");
			main();
			break;
		case 5:
			return 0;
			break;
		default:					//Default value for invalid Input.
			cout<<"Invalid Number..."<<endl;
			system("pause");
			system("CLS");
			main();
			}
	return 0;
}
bool check(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=48 && a[i]<=57)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
bool check_alphabet(string a)
{
	int i=0;
	while(a[i]!=0)
	{
		if(a[i]>=65 && a[i]<=122)
		{
			return false;
		}
		else
		{
			i++;
		}
	}
	return true;
}
