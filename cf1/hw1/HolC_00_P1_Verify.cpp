//****************************************************************************
//       CLASS:  CSCE-2100.021
//  ASSIGNMENT:  Program 1
//     STUDENT:  Patrick W. Burke
// DESCRIPTION:  This program simply writes a student name with a timestamp
//               into a single class-shared log file (logfile) and then 
//               creates abseparate output (myfile) in the directory in
//               which the student is executing the program.
//
//               Student simply have to replace "xxxLNAMExxx" and 
//               "xxxFNAMExxx" with his/her name and execute the file.
//
// REQUIRED SOURCE FILES:       ************************************
//	BurP_00_P1_Verify.cpp   **** MODIFY WITH YOUR FILENAME  ****
//                              **** IN ACCORDANCE WITH THE     ****
//                              **** FILENAMING CONVENTIONS IN  ****
//                              **** THE INSTRUCTIONS.          ****
//                              ************************************
//               
// SPECIAL INSTRUCTIONS:  Programs are expected to compile and execute on
//	the UNT CSE Unix machines (e.g. cse01.cse.unt.edu) with a "make run"
//     command with all of the submitted files in ONE DIRECTORY.
//
//	If you have any special instructions (and you had better 
//	have a VERY good reason for doing so), put them here AND include
//     a README.txt file with your submitted files explaining HOW to 
//     compile your code and WHY you could not meet the standard "make"
//     expectations!
//
//****************************************************************************
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

int main () 
{ //***main
  time_t currentTime;
  time (&currentTime);       //retrieve the current date & time

  int log_complete = 0;
  char f_name[30] = "Colby";  //** change xxxFNAMExxx to your first name
  char l_name[30] = "Holmes";  //** change xxxLNAMExxx to your last name
  ofstream logfile, myfile;

     //********************************************************************
     //*********** Enter Student Data in Class Shared Log File ************
     //********************************************************************
  logfile.open ("/home/pwb0013/csce2100/program1/2100_class_log.txt", ios::out | ios::app);

  if (logfile.is_open())
    {    // normal file opening ... ready for data

         // create a student-specific entry in the class-section shared log file
     logfile << l_name << "," << f_name << "," << ctime(&currentTime) << endl; 
     logfile.close();

     cout << "***** logfile processing complete *****" << endl  << endl;

     log_complete = 1;  // log-file processing completed normally
    }
  else
    {    // could not open shared file ... report and exit
     cout << "***** ERROR:  Unable to open 2100_class_log.txt *****" << endl;
     return 0;
    }

     //********************************************************************
     //***** If student-data was successfully processed in the Class  *****
     //***** Shared Log File, create Output File in the Student       *****
     //***** Directory.                                               *****
     //********************************************************************
  if (log_complete == 1)
    {
     myfile.open ("CSCE2100_Program1_Verification.txt", ios::trunc);

     if (myfile.is_open())
       {    // normal file opening ... ready for data

            // populate the student's processing-verification file
        myfile << "CONGRATULATIONS:  I have the singular privilege of" << endl;
        myfile << "   proclaiming that the following student has " << endl;
        myfile << "   demonstrated an outstanding mastery of the" << endl;
        myfile << "   C++ Programming Language by successfully copying" << endl;
        myfile << "   some text, compiling and executing the code, and" << endl;
        myfile << "   submitting the results to the CSCE2100 BlackBoard.";
        myfile << endl << endl << endl;
        myfile << "               " <<f_name << " " << l_name << endl << endl;
        myfile << "               " << ctime(&currentTime) << endl; 
        myfile.close();

        cout <<"***Verification File processing complete***" << endl << endl;

       }
     else
       {    // could not open Student Verification File ... report and exit
        cout << "***** ERROR:  Unable to open Verification File *****" << endl;
        return 0;
       }
    }
cout << endl << "Bye ... Have a Great Day and a Pleasant Tomorrow"  << endl  << endl;
return 0;

}