/*

Description - The following code is done for Lab 04 (take home lab) 

Completed by - Amit Sarvate 
Student ID - 100794129
Date Completed - October 2020

Course - CSCI 1060


References -

-  https://www.hackerearth.com/blog/developers/how-to-find-the-day-of-a-week/

*/ 


#include <iostream> 

using namespace std;


// declaration of the functions 
void printMonth(int month, int year);
int dayOfWeek(int day, int month, int year);
int numDaysInMonth(int month, int year);
void printYear(int year);
string monthName(int month);


int main(){
  
  int monthOrYear;
  int month;
  int year;
  

  // Determining whether the user wants a month or year calender and getting the specific year [and month if needed] - prompting user input 
  cout << "Enter 1 if you want a month calender or 2 if you want a year calendar: ";
  cin >> monthOrYear;

  // month long calendar option 
  if (monthOrYear == 1){
    cout << "Please enter a month (1 to 12): ";
    cin >> month;

    cout << "Please enter a year: ";
    cin >> year;

    printMonth(month, year);

  // year long calendar option 
  } else if (monthOrYear == 2){
    cout << "Please enter a year: ";
    cin >> year;
    
    printYear(year);
  }

  cout << endl;

  return 0;
}

// function retreives the actual name of the month 
string monthName(int month){

  // i put the first index " " because i wanted the user to pick an integer representing the months from 1 to 12 hence why janurary is index 1 and not 0
  string months[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  return months[month];
}

  

// function determines the day of the week for the first day of the inputted month 
int dayOfWeek(int day, int month, int year){


  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  year -= month < 3;

  return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;

}

// function determines the number of days the month has (considers leap years too)
int numDaysInMonth(int month, int year){
  
  // determining whether or not the year is a leap year or not and returning the specific num of days in feb
  if (month == 2){
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
      return 29;
    } else {
      return 28;
    }

  // num of days for jan, mar, may, july, aug, october and december 
  } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
    return 31;
    
  // num of days for apr, jun, sept, nov
  } else if (month == 4 || month == 6 || month == 9 || month == 11){
    return 30;
  }

  
  return 0;

}

// function prints the month 
void printMonth(int month, int year){

  int currentDay;
  int numDays; 
  
  // calling the functions that determine the first day and month name 
  currentDay = dayOfWeek(1, month, year);
  numDays = numDaysInMonth(month, year);
  
  cout << endl;

  // generating the heading days of week for calendar 
  cout << monthName(month) << " " << year << endl;
  cout << endl;
  cout << "    S    M    T    W    T    F    S  \n";
  
  // outputting the number of spaces before a number day is outputted 
  int i;
  for (i = 0; i < currentDay; i++)
    printf("     ");

  // outputting the days 5 spaces in between 
  for(int day = 1; day <= numDays; day++){
    printf("%5d", day);

    // lining the days on a new week if past saturday on calendar 
    if (++i > 6){
      printf("\n");
      i = 0;
    }

    currentDay = i;
  }
 
}

// function prints the year calendar 
void printYear(int year){

  // calls the month calendar function 12 times for each month of the year 
  for (int i = 1; i <= 12; i++){
    printMonth(i, year);
    cout << endl;
  }
}