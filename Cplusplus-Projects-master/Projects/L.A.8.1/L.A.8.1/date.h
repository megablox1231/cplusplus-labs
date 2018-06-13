
#include <iostream.h>
#include <bool.h>


#ifndef _DATE_H
#define _DATE_H


class date
{
	public:
		date ();	// default constructor, date is set to valid values of your choice
		date (int month, int day, int year);	// constructor with initial values of month, day, and year
		date (const date &temp);	// copy constructor, self is constructed as a copy of temp
		void setDate (int month, int day, int year);  // set values for date
		void getDate ();  // get date from keyboard
		void print () const;   // public print function
		
		void print(ostream &outfile) const;	// to support use of << operator
		void getTime(istream &infile);  		// to support use of >> operator
        istream& operator>> (istream &infile, date &temp);
		ostream& operator<< (ostream &outfile, const date &temp);
		
		date operator++();
		date operator++(int);
		date operator--();
		date operator--(int);
		bool operator==(const date &) const;
		bool operator<(const date &) const;
		bool operator>(const date &) const;
		
	private:
		int myMonth, myDay, myYear;
		int daysInMonth (int month, int year);	// suggested private member function
};

  date::date()
      :myMonth(0), myDay(0), myYear(0);
  {
              
  }

  date::date(int month, int day, int year)
  {
      setDate(month,day,year);                         
  }
  
  date::date(const date &temp)
      :myMonth(temp.myMonth), myDay(temp.myDay), myYear(temp.myYear);
  {
                   
  } 
  
  void date::setDate(int month, int day, int year)
  {
       if(month > 0 && month <=12)
       {
           myMonth = month;     
       } 
       if(year >=20 && year <=99)
       {
               myYear = year + 1900;
       }
       else if(year >=0 && year <= 19)
       {
            myYear = year + 2000;
       }
       if(day > 0 && day <= daysInMonth(month,year))
            myDay = day;
  }
  
  void date::getDate(int month, int day, int year)
  {
       setDate(month,day,year);
  }
  
  void date::print();
  {
       int tempYear;
       if(myYear >=20 && myYear <=99)
       {
               tempYear = year % 1900;
       }
       else if(myYear >=0 && myYear <= 19)
       {
            tempYear = year % 2000;
       }
       cout << month << "/" << day << "/" << tempYear;
  }
  
  int date::daysInMonth (int month, int year)
  {
      if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
      if(month == 2)
      {
          if(((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0))
          {
              return 29;
          }
          else return 28;    
      }
      return 30;      
  }

  void date::print(ostream &outfile) const	// to support use of << operator
  {
       int tempYear;
       if(myYear >=20 && myYear <=99)
       {
               tempYear = year % 1900;
       }
       else if(myYear >=0 && myYear <= 19)
       {
            tempYear = year % 2000;
       }
        outfile << month << "/" << day << "/" << tempYear;       
  }
  
  void date::getTime(istream &infile)  		// to support use of >> operator
  {
       int year,day,month;
       cout << "input(month/day/year)"<<endl;
       infile >> month >> day >> year;    
  }
 
  ostream& operator<< (ostream &outfile, const date &temp)  // overloaded << operator
  {
      date.print (outfile);
      return outfile;
  }

 istream& operator>> (istream &infile, date &temp)  // overloaded >> operator
 {
	date.getTime(infile);
	return infile;
 }
 
 date date::operator++()
 {
      if(myDay == daysInMonth(myMonth))
      {
           myDay = 1;
           if(myMonth == 12)
               myMonth = 1;
           else
               myMonth++;
      }
      else
          myDay++;
      return *this;    
 }
 
 date date::operator++(int)
 {
      date temp = *this;
      ++(*this);
      return temp;
 }
 
 date date::operator--()
 {
      if(myDay == 1)
      {
           if(myMonth == 1)
               myMonth = 12;       
           else
               myMonth--;
           myDay = daysInMonth(myMonth);    
      }
      else
           myDay--;         
      return *this;    
 }
 
 date date::operator--(int)
 {
      date temp = *this;
      --(*this);
      return temp;
 }
 
 bool date::operator==(const date &temp2)const
 {
      return((myDay == temp2.myDay) && (myMonth == temp2.myMonth) && (myYear == temp3.myYear))      
 }
 
 bool date::operator<(const date &temp2)const
 {
      if(myYear < temp2.myYear)
      {
           return true;
      }
      else
      {
           if(myYear > temp2.myYear)
           {
                 return false;
           }
           else //year == year
           {
                if(myMonth < temp2.myMonth)
                {
                     return true;
                }
                else
                {
                     if(myMonth > temp2.myMonth)
                     {
                          return false;
                     }
                     else 
                     {
                          return (myDay < temp2.myDay);
                     }
                }
           }                   
      }
 }
 
 bool date::operator>(const date &temp2)const
 {
      return !((*this < temp2) || (*this == temp2));
 }
 
#endif
