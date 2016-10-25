public class p2Date
{
	private int month;
	private int day;
	private int year;

	public p2Date()
   	{
		// Default constructor: Creates a date object
		// and initializes it to the default date.
		// Precondition: None.
		// Postcondition: A date of 01/01/2000 exists.
		setMonth(1);
		setDay(1);
		setYear(2000);
	} // end default constructor

	public p2Date(int month, int day, int year)
	{
		// Constructor: Creates date with supplied value
		// Precondition: month, day, and year are the desired values
		// Postcondition: A date of month/day/year exists
		setMonth(month);
		setDay(day);
		setYear(year);
	} // end constructor
	
	public void setMonth(int month)
	{
		// Sets the month of a date.
		// Precondition: month is an int greater than 0 and 
		// less than or equal to 12.
		// Postcondition: Month is changed to month.
		if (month > 0 || month <= 12) {
			this.month = month;
		}  // end if
	} // end setMonth

	public void setDay(int day)
	{
		// Sets the Day of a date.
		// Precondition: day is an int greater than 0 and less
		// than or equal to the number of days in the month.
		// Postcondition: Day is changed to day.
		int[] daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (this.year % 4 == 0)  //if it's a leap year
		{
			daysInMonth[2] = 29; //Feb has 29 days
		} // end if
		if (day > 0 || day <= daysInMonth[this.month])
		{
			this.day = day;
		}  // end if
	} // end setDay

	public void setYear(int year)
	{
		// Sets the Year of a date.
		// Precondition: year is the desired Year.
		// Postcondition: Year is changed to year.
		this.year = year;
	} // end setYear

	public void setDate(String date)
   	{
		// Sets the Date.
		// Precondition: date is the desired Date in
		// MM/DD/YYYY format.
		// Postcondition: The Date is changed to date.
		setMonth(Integer.parseInt(date.substring(0,2)));
		setDay(Integer.parseInt(date.substring(3,5)));
		setYear(Integer.parseInt(date.substring(6)));
	} // end setDate

	public void incrementDay()
	{
		// Increments the day by 1.
		// Precondition: None.
		// Postcondition: The day is incremented by 1. Rolls over to
		// the next month and year if needed.
		int[] daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int tempDay = this.day + 1; // increment current day and store in temp
		if (this.year % 4 == 0)  //if it's a leap year
		{
			daysInMonth[2] = 29; //Feb has 29 days
		} //end if
		if (tempDay > daysInMonth[this.month])
		{
			if ((this.month + 1) < 12)
			{
				setMonth(this.month + 1);
			}
			else
			{
				setMonth(1);
				setYear(this.year + 1);
			} // end if
			setDay(1);
		}
		else
		{
			setDay(tempDay);
		} // end if
		

	} // end incrementDay

	public void displayDateRegular() 
	{  
		// Displays the date in MM/DD/YYYY format.
		// Precondition: Assumes System.out is available.
		// Postcondition: None.
		String date = String.format("%02d", this.month);
		date += String.format("/%02d", this.day);
		date += String.format("/%04d", this.year);
		System.out.print(date);
	}  // end displayDateRegular

	public void displayDateWords()
	{
		// Displays the date in Day, Month dd, yyyy format.
		// Precondition Assumes System.out is available.
		// Postcondition: None.
		int dayOfWeek = 0;
		int firstDayOfMonth = ((int)((this.year - 1901) * 365.25 + 2)) % 7;
		int[] daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		String[] monthArray = {"", "January", "February", "March", "April",
								"May", "June", "July", "August", "September",
								"October", "November", "December"};
		String[] daysArray = {"Sunday", "Monday", "Tuesday", "Wednesday",
							"Thursday", "Friday", "Saturday"};
		if (this.year % 4 == 0)  //if it's a leap year
		{
			daysInMonth[2] = 29; //Feb has 29 days
		} //end if
		for (int i = 0; i < this.month; i++)
		{
			firstDayOfMonth = (firstDayOfMonth + daysInMonth[i]) % 7;
		}

		dayOfWeek = (firstDayOfMonth + this.day - 1) % 7;

		System.out.print(daysArray[dayOfWeek] + ", " + monthArray[this.month] +
				" " + this.day + ", " + this.year);

	}
} // end p2Date
