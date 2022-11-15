#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
 using namespace std;
  int ID;
  class student
  {  public:
     int  id;
     int age;
     string name;
     string stream;
/////////////////////////////////////////////////////////////////////////////////////////////   
      void addstudent()
      { 
        cout<<" Enter the name of the student"<<endl;
       fflush(stdin);// or cin.get(); or for gettting one charrecter from the internet
        getline(cin,name);
         cout<<" Enter the age of the  student"<<endl;
          cin>>age;
         cout<<" Enter the  student course"<<endl;
         cin>>stream;
          id=ID;
           ID++;
            ofstream fout; // for writting into the file
             fout.open("C:/project/student.txt", ios::app);// creating file for  student details
             fout<<"\n"<<id;
             fout<<"\n"<<name;
              fout<<"\n"<<age;
               fout<<"\n"<<stream;
               fout.close();
                fout.open("c:/project/id.txt",ios::app);// creating file for storing id 
                fout<<"\n"<<ID;
                fout.close();
                 cout<<"record added succesfully"<<endl;
            }
 //////////////////////////////////////////////////////////////////////////////////////////           
       void print()
       { 
          cout<<id<<endl;
          cout<<name<<endl;
          cout<<age<<endl;
          cout<<stream<<endl;
          cout<<"##################################"<<endl;
       }
 ///////////////////////////////////////////////////////////////////////////////////////////////      
       void printall()
       { 
        ifstream fin;
         fin.open("C:/project/student.txt");
           student s ;// creating a temporary object
            while(!fin.eof())// loop run  until end of file
            {
              fin>>s.id; // fin extract the data from file 1st line and  assign into the id of temp oject
               fin.ignore();// for cleaning the buffer so that fin put the name into buffer and getline use it 
                getline( fin,s.name);//"""  2nd line of file and do same comment of upper id"""
                 fin>>s.age;//"""" 3rd line 
                  fin>>s.stream;//"" 4th line
                   s.print(); /// when all the 4 lines of data is accumulated into object S then the all details of the s is printed
                    // now the pointer is at the last of  that record  in that file and again when loop start agin it will print the next student details
            }
            fin.close();
              }
/////////////////////////////////////////////////////////////////////////////// ////
   void  search( int  id)
               { 
                   ifstream fin;
                   student s;
                  fin.open("C:/project/student.txt");
                   while (!fin.eof())
                   {
                     fin>> s.id; /// from here 
                     fin.ignore();
                      getline(fin,s.name);
                       fin>>s.age;
                        fin>>s.stream;// to here we collect the data from the file and store int the temporary object s
                         // when  all the data is accumlated into the S object 
                          if(s.id==id)// if the id in the file is matched wih the  id that user wants to search
                          { 
                            s.print();// the detail of that perticular student is printed
                            break;
                             // it simple print the next four line of the file where he  get the s.id==id
                          }
                         }
                       fin.close();
              
              }
  ////////////////////////////////////////////////////////////////////////////////////
   void delet( int id)
   { ifstream fin;
    ofstream fout;
     student s;
     fout.open("C:/project/temp.txt"); // creating a temp file;
      fin.open("C:/project/student.txt");
      while (!fin.eof())
      { 
        fin>>s.id;
      fin.ignore();
       getline(fin,s.name);
       fin>>s.age;
        fin>>s.stream;
         if(s.id!=id)
         { 
           fout<<"\n"<<s.id; // writting into  a new temp file
            fout<<"\n"<<s.name;
            fout<<"\n"<<s.age;
             fout<<"\n"<<s.stream;
         }
       }
      fout.close();
      fin.close();
        remove("C:/project/student.txt");// delet the student file
        rename("C:/project/temp.txt","C:/project/student.txt");// rename the  temp file int student file
         cout<<" record deleted succesfully"<<endl;
    } 
    //////////////////////////////////////////////////////////////////////////////// 
     void update( int id)// update= delet+ add with same id
     {
        student s;
         s.delet(id);// 1st delet that student
          cout<<" Enter the name of the student"<<endl;
       fflush(stdin);// or cin.get(); or for gettting one charrecter from the internet
        getline(cin,name);
         cout<<" Enter the age of the  student"<<endl;
          cin>>age;
         cout<<" Enter the  student course"<<endl;
         cin>>stream;
           ID++;
            ofstream fout; // for writting into the file
             fout.open("C:/project/student.txt", ios::app);// creating file for  student details
             fout<<"\n"<<id;
             fout<<"\n"<<name;
              fout<<"\n"<<age;
               fout<<"\n"<<stream;
               fout.close();
                
     }
       
  };
   
   int main()
  {   
     ifstream  fin;
      fin.open("C:/project/id.txt");
       while(!fin.eof())
       {
         fin>>ID; // extract the data from the id file  and put into the ID variable 
         // until last of the file;
       }
      cout<<" currently ID="<<ID<<endl;
    while(1)
    { 
     cout<<"Enter your choice"<<endl;
     cout<<"1. Add new student int the list"<<endl;
     cout<<"2.Search a student int the list"<<endl;
     cout<<"3.Delet a student from the list"<<endl;
     cout<<"4.Update a student from the list"<<endl;
     cout<<"5.Print all student"<<endl;
     int choice, id;
      student s;
      cin>>choice;
      switch (choice)
      {
      case 1:
         s.addstudent();
          break;
      case 2:
            cout<<" enter the id of the student";
             cin>>id;
            s.search( id);
             break;
      case 3:
       cout<<" enter the id of the student whom you want to delet"<<endl;
        cin>>id;
        s.delet(id);
         break;
      case 4:
       cout<<" enter the id of the student whom you want to update"<<endl;
         cin>>id;
        s.update(id);
         break;
      case 5:
         s.printall();
          break;
      
      default:
        break;
      }
    }
    
    return 0;
  }
 