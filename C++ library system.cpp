#include  <iostream> // input and output in c++
#include <string> // for string characters
#include <ctime> // initializing date and time
#include <vector> // manage collections like books and members
#include <fstream> // file handling
#include <typeinfo>

using namespace std;

#define NUMBER 100 //number of maximum members and books
#define NUMBERS 10000 //number of maximum transactions

// book class definition
class Book 
{
	private:
	  int bookID;
	  string title;
	  string author;
	  string genre;
	  string status; // Available or Borrowed
	  // constructor to initialize the books
	public:
		Book(int BookID,string Title,string Author,string Genre,string Status){
			bookID = BookID;
      title = Title;
	    author = Author;
	    genre = Genre;
	    status = Status;
		}
		//getter functions to provide access to the private data of the class
		int getBookID(){
			return bookID;
		}
		string getTitle(){
			return title;
		}
		string getAuthor(){
			return author;
		}
		string getGenre(){
			return genre;
		}
		string getStatus(){
			return status;
		}
		//setter function allow modificatiion of the data
		void setBookID(int bookID){
			int i; // i is a created storage location to store any book details
			while(1) { 
        cout<<" Enter bookId: ";
        cin>> bookID;
        
        if (cin.good()) // check if input is valid
         {
           if (bookID <= 0) // make sure no negative or 0 input is put
		   {
              cout << "No Negative or zero ID.\n";
					  }
						else{ 
						  break; 
			   	  }
		     }               
         else
         {
           cout << "Not an integer.\n";
           cin.clear(); // clears the error flag
           cin.ignore(INT_MAX, '\n');  //discard invalid input
       }
    }
			this->bookID = bookID;
		}
		void setTitle(string title){
			this->title = title;
		}
		void setAuthor(string author){
			this->author = author;
		}
		void setGenre(string genre){
			this->genre = genre;
		}
		void setStatus(string status){
			this->status = status;
		}
};
// i is a created storage location to store any book details, num represents the number of books you want to enter
// count represents the number of boooks inputted to the system, j is anaother created storage location for book details 
// function to add book details
void addNewBook(Book books[],int counter)
{
	int num,i,j,count=0; 
	int bookID;
	string title,author,genre,status;
	cout << "Enter the number of books to key in: ";
	cin >> num;
	for (i=counter;i<num+counter;i++) // loop for book entry details
	{
		cout<<"New book details: "<<endl;
		books[i].setBookID(bookID);
		cout<<" Enter bookTitle: ";
		cin.ignore();
		getline(cin,title);
		books[i].setTitle(title);
		cout<<" Enter author of the book: ";
		getline(cin,author);
		books[i].setAuthor(author);
		cout<<" Enter bookGenre: ";
		getline(cin,genre);
		books[i].setGenre(genre);
		while (1) 
		{
			cout<<" Enter bookStatus: (Available or Borrowed)";
		  cin>> status;
		  // make sure status inputted is only eaither Available or Borrowed
			if (status == "Available" || status == "Borrowed"){break;
			}else{
				cout << "Incorrect input.Either 'Available' or 'Borrowed'\n";
        cin.clear(); // clears error flag
        cin.ignore(INT_MAX, '\n'); // discards invalid input
			}
		 }
		books[i].setStatus(status);
		// file handling for book details
		fstream myFile;
		myFile.open("MaryBookLibrary.txt",ios::app);
    if(myFile.is_open()){
		myFile<<"BOOKID: "<<books[i].getBookID()<<"\t";
		myFile<<"BOOKTITLE: "<<books[i].getTitle()<<"\t";
		myFile<<"BOOKAUTHOR: "<<books[i].getAuthor()<<"\t";
		myFile<<"BOOKGENRE: "<<books[i].getGenre()<<"\t";
		myFile<<"BOOKSTATUS: "<<books[i].getStatus()<<"\n";
		myFile.close();
	}
		}
		counter=num+counter;
		
	}
// function to edit book details	
void editBookDetails(Book books[]){
		cout<<"EDIT BOOK: "<<endl;
		int bookID,i,j,count=0,choice = 0,bookid=0;
		string title,author,genre,status;
		for(i=0;i<NUMBER;i++) 
		{
			if(books[i].getBookID() > 0){
				count++;
			}
		}
		cout<< "Enter bookID of the book to be EDITED: ";
		cin>>bookID;
		for(i=0;i<count;i++)
		{
			if(books[i].getBookID() == bookID)
			{
				cout<<"Book Found!Do you want to edit??[1] YES \t [2] NO"<<endl;
				while(1) { 
          cout<< "Enter choice: ";
				  cin >> choice;
          if (cin.good()) // check if input is valid
          {
            if (choice > 0) {break;} // make sure choice is 1 or 2 only
		         }else{
              cout << "Input interger choices, 1 or 2 : \n";
              cin.clear(); // clears error flag
              cin.ignore(INT_MAX, '\n'); // discards invalid input 
          }
        }
				bookID = books[i].getBookID();
        title = books[i].getTitle();
	      author = books[i].getAuthor();
	      genre = books[i].getGenre();
	      status = books[i].getStatus();
	      if (choice ==1) // if one choices 1 which is to edit the book then
		  {
	      	cout<<"Book titled: "<<title<<" by author: "<<author<<" is being edited..."<<endl; // shows what is being edited
       
		     books[i].setBookID(bookid);
		   cout<<" Enter bookTitle: ";
		     cin.ignore();
		     getline(cin,title);
		     books[i].setTitle(title);
		   cout<<" Enter author of the book: ";
		     getline(cin,author);
		     books[i].setAuthor(author);
		   cout<<" Enter bookGenre: ";
		     cin.ignore();
		     getline(cin,genre);
	       books[i].setGenre(genre);
	       while (1){
			cout<<" Enter bookStatus:(Available or Borrowed) ";
		  cin>> status;
		  // ensure status to be inputted is either Available or Borrowed
			if (status == "Available" || status == "Borrowed"){break;
			}else{
				cout << "Incorrect input.Either 'Available' or 'Borrowed'\n";
        cin.clear(); // clears error flag
        cin.ignore(INT_MAX, '\n'); // discards invalid input
			}
		 }
	      books[i].setStatus(status);
				}
	      	      
			}
			
		}
	  }
// function to delete a book
void deleteAnyBook(Book books[],int counter){
		cout<<"DELETE BOOK: "<<endl;
		int bookID,i,j,count=0,choice = 0;
		string title,author,genre,status;
		for(i=0;i<NUMBER;i++){
			if(books[i].getBookID() > 0){
				count++;
			}
		}
		cout<< "Enter bookID: ";
		cin>>bookID;
		for(i=0;i<count;i++){
			if(books[i].getBookID() == bookID) // make sure of the book you want to delete
			{
				cout<<"Book Found!Do you want to delete?[1] YES \t [2] NO"<<endl;
				while(1) { 
          cout<< "Enter choice: ";
				  cin >> choice;
          if (cin.good())
          {
            if (choice > 0) {break;}
		         }else{
              cout << "Input interger choices, 1 or 2 : \n";
              cin.clear(); // clears error flag
              cin.ignore(INT_MAX, '\n');  // discards invalid input
          }
        }
				bookID = books[i].getBookID();
        title = books[i].getTitle();
	      author = books[i].getAuthor();
	      genre = books[i].getGenre();
	      status = books[i].getStatus();
	      // deletion of the book after choice of deleting
	      if (choice ==1){
	      	cout<<"Book titled: "<<title<<" by author: "<<author<<" will be deleted"<<endl;
	        books[i].setBookID(0);
          books[i].setTitle("NULL");
	        books[i].setAuthor("Null");
	        books[i].setGenre("NULL");
	        books[i].setStatus("NULL");
	        cout <<"Deletion done!"<<endl;
	        counter = count;
          for (int j = i; j < count; j++){
              books[j] = books[j + 1];
						}
				  break;
				}
	      	      
			}
			
		}
	  }
// function to view all the books inputted
void viewAllBooks(Book books[]){
	int i,count=0;
	for(i=0;i<NUMBER;i++){
			if(books[i].getBookID() > 0){
				count++;
			}
		}
		cout<<"Showing all books in Library: "<<endl;
		for (i=0;i<count;i++)  // loop to initialize the displaying of all the books inputted
		{
			cout<<"BookID: "<<books[i].getBookID()<<"\t";
			cout <<"Title: "<<books[i].getTitle()<<"\t";
			cout<<"Author: "<<books[i].getAuthor()<<"\t";
			cout<<"Genre: "<<books[i].getGenre()<<"\t";
			cout <<"Status: "<<books[i].getStatus()<<endl;
		}	
		cout<<"Read from file:"<<endl;
		// file handling of the books
		fstream myFile;
		string line;
		myFile.open("MaryBookLibrary.txt",ios::in);
	   if(myFile.is_open()){
		string line;
		while(getline(myFile,line)){
			cout<< line<<endl;
		}
		myFile.close();
	 }
	  }

// class member definition
class Member {
	private:
	  int memberID;
	  string name;
	  string address;
     int phoneNumber;
     // constructor to initialize the members
	public:
		Member(int MemberID,string Name,string Address,int PhoneNumber){
			memberID = MemberID;
      name = Name;
	    address = Address;
	    phoneNumber = PhoneNumber;
		}
		// getter function to give access to data in private member class
		int getMemberID(){
			return memberID;
		}
		string getName(){
			return name;
		}
		string getAddress(){
			return address;
		}
		int getPhoneNumber(){
			return phoneNumber;
		}
		// setter function to modify the member data
		void setMemberID(int memberID){
			while(1) { 
      cout<<" Enter memberId: ";
		  cin>> memberID;
      if (cin.good())
      {
        if (memberID < 0)  // ensure no negative interger input
		{cout << "No Negative ID.\n";}
        else { break;
				
        } 
		  }                         
       else
      {
        cout << "Not an integer.\n";
        cin.clear(); // clears error flag
        cin.ignore(INT_MAX, '\n'); // discards invalid data
       }
     }
			this->memberID = memberID;
		}
		void setName(string name){
			this->name = name;
		}
		void setAddress(string address){
			this->address = address;
		}
		void setPhoneNumber(int phoneNumber){
			while(1) { 
          cout<<" Enter phonenumber: ";
		    cin>> phoneNumber;
        if (cin.good())
        {
        if (phoneNumber < 0)  // ensure no negative phonenumber input
		{cout << "No Negative phoneNumber.\n";}
        else { break;}
					}                         
       else
       {
        cout << "Not an integer.\n";
        cin.clear(); // clears error flag
        cin.ignore(INT_MAX, '\n');  // discards invalid input
     }
    }
			this->phoneNumber = phoneNumber;
		}
};
// num represent the number of members you wnat to input, i and j represent the storage location for member details
// function to add new members
void addNewMember(Member members[],int memberCounter){
		cout<<"NEW MEMBER: "<<endl;
		int num,i,j;
    int memberID =0,phoneNumber;
	   string name,address;
	  cout << "Enter the number of members to key in: ";
	  cin >> num;
	  for (i=memberCounter;i<num+memberCounter;i++){
		  cout<<"New member details: "<<endl;
		  
		members[i].setMemberID(memberID);
		cout<<" Enter member Name: ";
		cin.ignore();
		getline(cin,name);
		members[i].setName(name);
		cout<<" Enter address of the book: ";
		getline(cin,address);
		members[i].setAddress(address);
		
		members[i].setPhoneNumber(phoneNumber);
		// file handling for members
		fstream myFile;
		myFile.open("MaryMemberLibrary.txt",ios::app);
    if(myFile.is_open()){
		myFile<<"MEMBERID: "<<members[i].getMemberID()<<"\t";
		myFile<<"MEMBERNAME: "<<members[i].getName()<<"\t";
		myFile<<"MEMBERADDRESS: "<<members[i].getAddress()<<"\t";
		myFile<<"MEMBERPHONE: "<<members[i].getPhoneNumber()<<"\n";
		myFile.close();
	}
		}
		memberCounter=num+memberCounter;
	}
// function for editting members
void editMemberDetails(Member members[]){
		cout<<"EDIT MEMBER: "<<endl;
		int memberID,i,j,count=0,choice = 0,phoneNumber,memberid=0;
		string name,address;
		for(i=0;i<NUMBER;i++){
			if(members[i].getMemberID() > 0){
				count++;
			}
		}
		cout<< "Enter memberID of the member to be EDITED: ";
		cin>>memberID;
		for(i=0;i<count;i++) 
		{
			if(members[i].getMemberID() == memberID) //confirms the member to be editted
			{
				cout<<"Member Found!Do you want to edit??[1] YES \t [2] NO"<<endl;
				while(1) { 
          cout<< "Enter choice: ";
				  cin >> choice;
          if (cin.good()) // check if data inputted is valid
          {
            if (choice > 0) {break;}
		         }else{
              cout << "Input interger choices, 1 or 2 : \n";
              cin.clear(); // clears error flag
              cin.ignore(INT_MAX, '\n');  // discards invalid input
          }
        }
			memberID = members[i].getMemberID();
            name = members[i].getName();
	      address = members[i].getAddress();
	      phoneNumber = members[i].getPhoneNumber();
	      if (choice ==1) // editing is initialized
		  {
	      	cout<<"Member named: "<<name<<" with ID: "<<memberID<<" is being edited..."<<endl;
      		
		     members[i].setMemberID(memberid);
		   cout<<" Enter memberName: ";
		     cin.ignore();
		     getline(cin,name);
		     members[i].setName(name);
		   cout<<" Enter address of the member: ";
		     getline(cin,address);
		     members[i].setAddress(address);
		     
		   members[i].setPhoneNumber(phoneNumber);
			  
				}
	      	      
			}
		}
		cout<<"Member Edited successfuly"<<endl;
	}
// function to delete any member
void deleteAnyMember(Member members[],int memberCounter){
		cout<<"MEMBER DELETION"<<endl;
		int memberID,phoneNumber,i,j,count=0,choice = 0;
		string name,address;
		for(i=0;i<NUMBER;i++)
		{
			if(members[i].getMemberID() > 0){
				count++;
			}
		}
		cout<< "Enter memberID: ";
		cin>>memberID;
		for(i=0;i<count;i++)
		{
			if(members[i].getMemberID() == memberID){
				cout<<"Member Found!Do you want to delete?[1] YES \t [2] NO"<<endl;
				while(1) { 
          cout<< "Enter choice: ";
				  cin >> choice;
          if (cin.good()) // check if data inputted is valid
          {
            if (choice > 0) {break;}
		         }else{
              cout << "Input interger choices, 1 or 2 : \n";
              cin.clear(); // clears error flag
              cin.ignore(INT_MAX, '\n'); // NB: preferred method for flushing cin,clears input buffers prompting \n to the next line
          }
        }
				memberID = members[i].getMemberID();
        name = members[i].getName();
	      address = members[i].getAddress();
	      phoneNumber = members[i].getPhoneNumber();
	      if (choice ==1){
	      	cout<<"Member called: "<<name<<" with ID : "<<memberID<<" will be deleted"<<endl;
	        members[i].setMemberID(0);
          members[i].setName("NULL");
	        members[i].setAddress("NULL");
	        members[i].setPhoneNumber(0);
	        cout <<"Deletion done!"<<endl;
	        memberCounter = count;
          for (int j = i; j < count; j++){
              members[j] = members[j + 1];
						}
				  break;
				}
	      	      
			}
		}
	}
// function to view all members
void viewAllMembers(Member members[]){
		int i,count=0;
	  for(i=0;i<NUMBER;i++){
			if(members[i].getMemberID() > 0){
				count++;
			}
		}
		cout<<"Showing all members: "<<endl;
		for (i=0;i<count;i++){
			cout<<"MemberID: "<<members[i].getMemberID()<<"\t";
			cout<<"Name: "<<members[i].getName()<<"\t";
			cout<<"Address: "<<members[i].getAddress()<<"\t";
			cout<<"PhoneNumber: "<<members[i].getPhoneNumber()<<endl;
		}	
		cout<<"Read from file(MaryMemberLibrary.txt):"<<endl;
		// file handling for members
		fstream myFile;
		string line;
		myFile.open("MaryMemberLibrary.txt",ios::in);
    if(myFile.is_open()){
		string line;
		while(getline(myFile,line)){
			cout<< line<<endl;
		}
		myFile.close();
	 }
	}
// transaction class definition
class Transaction { 
	public:
	 unsigned long long int transactionID; // store positive values of size 64 bytes
	 int memberID;
	 int bookID;
	 char* borrowDate;
	 char* returnDate;
	 
	 string holdBorrowDate;
	 time_t borrowDateInSeconds;
	 time_t returnDateInSeconds;
	 
};
//i is created storage location  
// function to borrow book
void borrowBook(Book books[], Member members[], Transaction transactions[],int transactionCounter){
  	string borrowedBook,borrowerName,checkName="NULL"; // check name for help in finding the book to be borrowed
  	int borrowerID,i;
  	char rrd= '0';
  	char* rrrD = &rrd;
  	cout<<"Enter name of book to be borrowed: ";
  	cin.ignore();
  	getline(cin,borrowedBook);
  	cout<<"Name of borrower: ";
  	getline(cin,borrowerName);
  	cout<<"ID of the borrower:";
  	cin>>borrowerID;
  	for(i=0;i<NUMBER;i++)
	  {
			 if(members[i].getName() == borrowerName && members[i].getMemberID() == borrowerID){
			 	checkName = "NOT NULL";
			}}
		if(checkName == "NOT NULL")	{
		
	  for(i=0;i<NUMBER;i++){
			if(books[i].getTitle() == borrowedBook && books[i].getStatus()=="Available") // check if book is available
			{
				cout<<"Book found!"<< endl;
				time_t now = time(0); //intialix=zing date and time
				transactions[i].bookID = books[i].getBookID();
				transactions[i].memberID = borrowerID;
				transactions[i].borrowDate = ctime(&now); // give time on the day you are borrowing
				transactions[i].holdBorrowDate = (string)transactions[i].borrowDate;
				transactions[i].returnDate = rrrD;
				transactions[i].borrowDateInSeconds = time(NULL);
				transactions[i].transactionID = transactions[i].borrowDateInSeconds / 10;
				books[i].setStatus("Borrowed");
				cout<<"\tBook titled: "<<books[i].getTitle()<<" was successful borrowed at: "<< transactions[i].borrowDate;
				cout << "\tby "<<borrowerName<<" with ID of: "<<borrowerID<<endl;
				// file handling in transaction
				fstream myFile;
		    myFile.open("MaryTransactionLibrary.txt",ios::app);
        if(myFile.is_open()){
        myFile<<"\nBorrow Record: "<<"\n";	
        myFile<<"TRANSACTIONID: "<<transactions[i].transactionID<<"\t";	
		    myFile<<"BOOKID: "<<transactions[i].bookID<<"\t";
		    myFile<<"MEMBERID: "<<transactions[i].memberID<<"\n";
		    myFile<<"BORROWDATE: "<<transactions[i].borrowDate<<"\n";
		    myFile<<"RETURNDATE: "<<transactions[i].returnDate<<"\n"<<"\n";
		    myFile.close();
	      }
	      cout<<"Transaction stored in file successfully"<<endl;
			}
			}
  	cout<<"NOTE: if you dont receive a confirmation message with borrow details then its either: borrowed or not in library!"<<endl;
  	cout<<"You can view all books available an their status to confirm!.\n";
		cout<< "OTHERWISE: \n"<<endl;
  	cout<<"Return book in 14 days."<<endl;
		}else{ 
		  cout<<"Member not found!Please register!"<<endl;
			}
 	}
	// function to return book
	void returnBook(Book books[], Member members[], Transaction transactions[],int transactionCounter){
		string returnedBook,returneeName,checkName="NULL",holdBorrowDate;
  	cout<<"Enter name of book being returned: ";
  	cin.ignore();
  	getline(cin,returnedBook);
  	cout<<"Name of returnee: ";
  	getline(cin,returneeName);
  	int i,bookid,memid;
  	double diff,difff,diffff;
	// time_t initalize time in seconds	
  	time_t rD,bD; 
  	char bbD ='0';
  	char* bbbD;
  	bbbD = &bbD;
  	for(i=0;i<NUMBER;i++){
			 if(members[i].getName() == returneeName){
			 	memid = members[i].getMemberID();
			 	checkName = "NOT NULL";
			}}
		for(i=0;i<NUMBERS;i++){
			if(transactions[i].memberID == memid){
				//bbD = transactions[i].borrowDate;
				holdBorrowDate= transactions[i].holdBorrowDate;
				bD = transactions[i].borrowDateInSeconds;
				break;
			}
		}	
		if(checkName == "NOT NULL"){
		
	  for(i=0;i<NUMBER;i++){
			if(books[i].getTitle() == returnedBook && books[i].getStatus()=="Borrowed") {
				cout<<"Book finally returned!"<<endl;
				transactions[i].borrowDate = bbbD;
				time_t now = time(0);
				transactions[i].bookID = books[i].getBookID();
				transactions[i].memberID = memid;
				transactions[i].returnDate = ctime(&now); // gives time when you are returning
				transactions[i].returnDateInSeconds = time(NULL);
				rD = transactions[i].returnDateInSeconds;
				books[i].setStatus("Available");
				cout<<"Book returned at: "<< transactions[i].returnDate<<"BY: "<<returneeName<<" with ID: "<<transactions[i].memberID<<endl;
				transactions[i].transactionID = transactions[i].returnDateInSeconds / 10;
				difff = difftime(rD,bD);
				cout<<"\n"<<endl;
				diffff = difff/3600; // gets difference in seconds
				cout<<"You took "<<diffff<<" days."<<endl;		
				if(diffff > 14.0000) // checks the 14 day limit for borrowing if its due
				{
	 	     cout<< "You overstayed with the book by "<< diffff<<"!."<<endl;
	 	     cout<<"Your overdue charges are: "<< (int)diffff*1<<"$."<<endl;
 	        }else{
	 	       cout<<"You brought the book in time.No overdues.\n"<<endl;
				 }
				 // file handling
			  fstream myFile;
		    myFile.open("MaryTransactionLibrary.txt",ios::app);
        if(myFile.is_open()){
        myFile<<"\nReturn Record: "<<"\n";	
        myFile<<"TRANSACTIONID: "<<transactions[i].transactionID<<"\t";	
		    myFile<<"BOOKID: "<<transactions[i].bookID<<"\t";
		    myFile<<"MEMBERID: "<<transactions[i].memberID<<"\n";
		    myFile<<"BORROWDATE: "<<holdBorrowDate<<"\n";
		    myFile<<"RETURNDATE: "<<transactions[i].returnDate<<"\n"<<"\n";
		    myFile.close();
	      }
	      cout<<"Transaction stored in file successfully"<<endl;
	      cout<<"Book successfully returned.Thank you."<<endl;
				}
				}
		}else{
	    cout<<"PLEASE input the name of returnee as per what is in the system in FULL!!!"<<endl;
		}
 }
	
	 // function for searching member
	 void searchMember(Member members[]){
	 	int i,count=0;
	 	string nameMember;
	  for(i=0;i<NUMBER;i++){
			if(members[i].getMemberID() > 0){
				count++;
			}
		}
		cout <<"enter the name of the member: ";
		cin.ignore();
  	getline(cin,nameMember);
	
		for (i=0;i<count;i++){
			if(members[i].getName() == nameMember){
			  cout<<"MemberID: "<<members[i].getMemberID()<<"\t";
			  cout<<"Name: "<<members[i].getName()<<"\t";
			  cout<<"Address: "<<members[i].getAddress()<<"\t";
			  cout<<"PhoneNumber: "<<members[i].getPhoneNumber()<<"\t";
			}
		}	
	 }
	 // function for searching book
	 void searchBook(Book books[]){
	 	int i,count=0,idBook;
	 	string titleBook;
	  for(i=0;i<NUMBER;i++){
			if(books[i].getBookID() > 0){
				count++;
			}
		}
		
		cout<<"Enter the ID of the book: ";
		cin >>idBook;
		cout<<"Enter the title of the book: ";
		cin.ignore();
  	getline(cin,titleBook);

		for (i=0;i<count;i++){
			if(books[i].getBookID() == idBook && books[i].getTitle() == titleBook){
			  cout<<"BookID: "<<books[i].getBookID()<<"\t";
			  cout <<"Title: "<<books[i].getTitle()<<"\t";
			  cout<<"Author: "<<books[i].getAuthor()<<"\t";
			  cout<<"Genre: "<<books[i].getGenre()<<"\t";
			  cout <<"Status: "<<books[i].getStatus()<<endl;
			}
		}	
	 }

// function to view all transacrtions made
void viewAllTransactions(Transaction transactions[]){
	int i,count=0;
	  for(i=0;i<NUMBERS;i++){
			if(transactions[i].transactionID > 0){
				count++;
			}
		}
		cout<<"Showing all transactions: "<<endl;
		for (i=0;i<count;i++){
			cout<<"TransactionID: "<<transactions[i].transactionID<<"\t";
			cout<<"BookID: "<<transactions[i].bookID<<"\t";
			cout<<"MemberID: "<<transactions[i].memberID<<"\n";
			//Optional:
			//cout<<"BorrowDate: "<<transactions[i].borrowDate<<"\t";
			///cout<<"ReturnedDate: "<<transactions[i].returnDate<<"\n";
		}
		cout<<"Read from file(MaryTransactionLibrary.txt):"<<endl;
		// file handling in transactions
		fstream myFile;
		string line;
		myFile.open("MaryTransactionLibrary.txt",ios::in);
    if(myFile.is_open()){
		string line;
		while(getline(myFile,line)){
			cout<< line<<endl;
		}
		myFile.close();
	 }	
}
// the main function
int main(){
  Book books[NUMBER] = Book(0,"NULL","NULL","NULL","NULL");
	Member members[NUMBER] = Member(0,"NULL","NULL",0);
	Transaction transactions[NUMBERS];
	int choice,counter=0,memberCounter =0,transactionCounter=0;
	while(1){
	
	cout<<"\nOPTIONS FOR YOUR CHOICE: "<<endl;
 	cout<<"\t1.add new book"<<endl;
 	cout<<"\t2.Edit a book"<<endl;
 	cout<<"\t3.Delete a book"<<endl;
 	cout<<"\t4.View all books"<<endl;
 	cout<<"\t5.Add new member" <<endl;
 	cout<<"\t6.Edit a member"<<endl;
 	cout<<"\t7.Delete a member"<<endl;
 	cout<<"\t8.View all members"<<endl;
 	cout<<"\t9.Borrow a  book"<<endl;
 	cout<<"\t10.Return a book"<<endl;
 	cout<<"\t11.Search a book by ID and Title"<<endl;
 	cout<<"\t12.Search a member by Name"<<endl;
 	cout<<"\t13.View all memberTransactions"<<endl;
 	cout<<"\t14.exit"<<endl;
 	cout<<"ENTER YOUR CHOICE:  ";
 	cin >> choice;
		
	switch (choice){
		case 1:	
		  addNewBook(books,counter);
		  break;
		case 2:
			editBookDetails(books);
			break;
		case 3:
			deleteAnyBook(books,counter);
			break;
		case 4:
			viewAllBooks(books);
			break;	
		case 5:	
		  addNewMember(members,memberCounter);
		  break;
		case 6:
			editMemberDetails(members);
			break;
		case 7:
			deleteAnyMember(members,memberCounter);
			break;
		case 8:
			viewAllMembers(members);
			break;		
		case 9:
		  borrowBook(books,members,transactions,transactionCounter);
		  break;
		case 10:
		  returnBook(books,members,transactions,transactionCounter);
			break; 
		case 11:
		  searchBook(books);
			break;
		case 12:
		  searchMember(members);
			break;
		case 13:
		  viewAllTransactions(transactions);
			break;		 
		case 14:
			exit(1);
			break;
		default:
			printf("\nentered wrong choice.\n");
			break;
			}
		}
}
