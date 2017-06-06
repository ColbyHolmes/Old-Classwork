#include <stdio.h>

// *********  3:30pm (cdt)   9/8/15   **** Important Addition(s)   *****
//
//   NOTE:  I'm adding "submission" instructions below the code.
//          Make sure your (team's?) submission fits these requirements!
//
// *******************************************************************


// ******************************************************************
//   Here's a "quick and dirty" assignment for you.  Write a program 
//   that will take a command line and "parse" the arguments.  So, 
//   we'll assume that your command line
//   looks something like:
//
//      pgmName  options
//
//   for example,  it might be
//
//   ls -ltga  -abc -xyz
//   
//   What your program should do is 1) list the pgm name (ls in this 
//   example) and each of the options (l, t, g, a) on separate lines, 
//   and then execute the command.
//
//   We'll assume that each command has one set of options that start 
//   the '-' character and includes each option as a single letter.
//
//   So, we could have sort -n, but not sort --key=1 since that wouldn't 
//   fit our model at this point.
//
// ***********************************************************************

// Here's a copy command

//    cp -r ~phs0004/public/3600/argv .  will copy all of argv to 
//    the directory in which the command is invoked.                  


// *********  Below here are instructions added at 3:30 pm on 9/8/15  ****
//
//         MAKE SURE YOU FOLLOW THEM !  (yes, this is me SHOUTING!)
//
// ***********************************************************************

// Make sure that your program reads data from standard input (stdin).
// THAT way, we'll be able to use redirection to read OUR data file(s) 
// into the program built from your code.  DO NOT use File open and close
// statements, fscanf or any other fxxx, where xxx are read commands (gets,
// getline, ...)

// Make sure that your program prints output to standard output (stdout)
// THAT way, we'll be able to use redirection to write YOUR output
// into output file(s) that we can test using grading scripts. 
// DO NOT use File open and close statements, fprint or any other 
// fxxx, where xxx are output commands such as putc, ...

// Make sure that all members of your "group" (of up to four students)
// who work together on this program have their names included in 
// block comments at the start of the program you submit.

// Submit your program, which should be single C file, to Blackboard under
// Minor Assignment 2.  (Remember that Minor 1 is your intro paragraph and
// photo that you've emailed (or soon will) to sweany@unt.edu 
// (or sweany@cs.unt.edu).
//
// IF you're not familiar with redirected input and output in Linux, DON'T
// hesitate to ask in class.  If you're confused, many others will be as well.
// Using redirected input and output make grading much easier and faster for
// us and thus I will INSIST on it.

// and now, in a softer tone, let me answer a question that came up in class
// and also in email.  the question is, should each execution of your program
// read just one command and the appropriate flags, or should your program 
// keep reading "pairs" of (command, flags) until the input is exhausted.
// and the answer is, each execution (./a.out) of your program should read
// just one (command, flags) pair.  yes, its not difficult to read all the
// pairs until you run out of input and I assume most of you know how to
// do that.  we'll practice (or give you the opportunity to show you know it
// already) in a later assignment.


// and yes, I SHOULD have thought of these things before introducing the
// assignment in class today.  Mea Culpa.
