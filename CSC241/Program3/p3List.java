public class p3List
{
	private studentNode head;

	public p3List()
	{
		// Default constructor: Creates an empty list object.
		// Precondition: None.
		// Postcondition: An empty list exists.
		head = null;
	} // end default constructor

	public void addNode(String name, String studentID)
	{
		// Creates a new student node and adds to list based on
		// alphabetical order of the student's last name
		// Precondition: name is a String of form "Last, First" and
		// studentID is a String.
		// Postcondition: A studentNode is inserted into the
		// appropriate location on the list.
		studentNode newNode = new studentNode(name, studentID);

		if (this.head == null)   // if the list is empty
		{
			this.head = newNode; // newNode is head of the list
		}
		else // list is not empty
		{
			if (newNode.comesBefore(this.head)) // if newNode preceeds head
			{
				newNode.next = this.head;
				this.head = newNode;
			}
			else // newNode should be placed after first node
			{
				boolean done = false;
				studentNode curr = this.head;
				studentNode prev = curr;

				while (curr != null && done == false)
				{
					if (newNode.comesBefore(curr))
					{
						prev.next = newNode; // node is inserted in between
						newNode.next = curr; // two existing nodes
						done = true;
					}
					else
					{
						prev = curr;
						curr = curr.next;
					}
				}

				if (done == false) // newNode goes at end of list
				{
					prev.next = newNode;    // prev was last item of list
				}						    // but now newNode is last
			}
		}
	} // end addNode()
	
	public void processStudent(String name, String studentID, String courseID,
								int credits, char grade)
	{
		// Adds the student and their course to the list.
		// Precondition: A list exists.
		// Postcondition: Student is added if they were not
		// previously on the list. Student's course is added.
		if (this.getStudentByID(studentID) == null)
		{
			this.addNode(name, studentID); // if not on the list, add them
		}
		this.getStudentByID(studentID).addCourse(courseID, credits, grade);
	} // end processStudent()

	public studentNode getStudentByID(String studentID)
	{
		// Checks if studentID matches one already on the list.
		// Precondition: List exists, studentID is a string.
		// Postcondition: Returns the studentNode with the matching
		// studentID. If no match is found, returns null.
		studentNode curr = this.head;
		while (curr != null) // check if student is already on list
		{
			if (curr.studentID.equals(studentID))
			{
				return curr;
			}

			curr = curr.next;
		}
		return curr; // this return statement will always return null
	} // end getStudentByID()

	public void displayList()
	{
		// Prints the contents of the list to the console.
		// Precondition: A list exists.
		// Postcondition: The data items of each element of the list
		// are printed to the console formatted nicely.
		studentNode curr = this.head;
		do
		{
			System.out.printf("%1$-20s", curr.name);
			System.out.println(curr.studentID);

			courseNode currCourse = curr.courseHead;
			while (currCourse != null)
			{
				System.out.print("       " + currCourse.courseID + "       ");
				System.out.print(currCourse.credits + "    ");
			    System.out.println(currCourse.grade);
				currCourse = currCourse.next;
			}
			System.out.printf("%1$26s", "Total Credits: " + curr.getTotalCredits());
		    System.out.printf("   %1$-18s", "Quality Points: " + curr.getTotalQualityPoints());
		    System.out.printf("   GPA: %1$.3f", curr.getGPA());
			System.out.println();
			System.out.println();

			curr = curr.next;
		} while (curr != null);
	} // end displayList()

	private class studentNode
	{
		String name;
		String studentID;
		courseNode courseHead;
		studentNode next;

		public studentNode(String name, String studentID)
		{
			// Constructor: Creates a studentNode object.
			// Precondition: None.
			// Postcondition: A studentNode object
			// with populated data items is created.
			this.name = name;
			this.studentID = studentID;
			this.courseHead = null;
			this.next = null;
		} // end constructor

		public void addCourse(String courseID, int credits, char grade)
		{
			// Creates a new course node and appends to course list.
			// Precondition: studentNode exists, courseID is a String,
			// credits is an integer, and grade is a character.
			// Postcondition: A courseNode is appended to the list.
			courseNode newNode = new courseNode(courseID, credits, grade);

			if (this.courseHead == null)    // if the course list is empty
			{
				this.courseHead = newNode;
			}
			else		    			   // the list is not empty
			{
				courseNode curr = this.courseHead;

				while (curr.next != null)
				{
					curr = curr.next;
				}
				curr.next = newNode;
			}
		} // end addCourse()


		public int getTotalCredits()
		{
			// Accumulates credit hours for each course taken
			// by this student and returns the total.
			// Precondition: A studentNode object exists.
			// Postcondition: Returns an integer representing
			// the total number of credit hours taken by the student.
			int totalCredits = 0;
			courseNode curr = this.courseHead;

			while (curr != null)
			{
				totalCredits += curr.getCredits();
				curr = curr.next;
			}

			return totalCredits;
		} // end getTotalCredits()

		public int getTotalQualityPoints()
		{
			// Accumulates quality points for each course
			// taken by this student and gets the total.
			// Precondition: A studentNode object exists.
			// Postcondition: Returns an integer representing
			// the total quality points of this student.
			int totalQualityPoints = 0;
			courseNode curr = this.courseHead;

			while (curr != null)
			{
				totalQualityPoints += curr.getQualityPoints();
				curr = curr.next;
			}

			return totalQualityPoints;
		} // end getTotalQualityPoints()

		public double getGPA()
		{
			// Calculates the GPA of this student.
			// Precondition: studentNode exists
			// Postcondition: Returns calculated GPA.
			return (double)this.getTotalQualityPoints() / this.getTotalCredits();
		} // end getGPA()

		public boolean comesBefore(studentNode sNode)
		{
			// Determines alphabetical relationship between
			// the names of two studentNode objects.
			// Precondition: Two studentNode objects with
			// populated data items exist.
			// Postcondition: Returns true if this studentNode's name
			// alphabetically preceeds sNode's name; otherwise returns false.
			if (this.name.compareTo(sNode.name) <= 0)
				return true;
			else
				return false;
		} // end comesBefore()

	} // end studentNode class

	private class courseNode
	{
		String courseID;
		int credits;
		char grade;
		courseNode next;

		public courseNode(String courseID, int credits, char grade)
		{
			// Constructor: Creates a courseNode object.
			// Precondition: None.
			// Postcondition: A courseNode object
			// with populated data items is created.
			this.courseID = courseID;
			this.credits = credits;
			this.grade = grade;
			this.next = null;
		} // end constructor

		public int getCredits()
		{
			// Gets the credits of this course.
			// Precondition: A courseNode exists.
			// Postcondition: Returns credits.
			return this.credits;
		} // end getCredits()

		public int getQualityPoints()
		{
			// Calculates weighted quality points for this course.
			// Precondition: A course exists with a letter grade
			// A, B, C, D, or F and credits as an integer.
			// Postcondition: Returns quality points of this course.
			int pointValue;

			if (this.grade == 'A')     // determine point value for letter grade
				pointValue = 4;
			else if (this.grade == 'B')
				pointValue = 3;
			else if (this.grade == 'C')
				pointValue = 2;
			else if (this.grade == 'D')
				pointValue = 1;
			else
				pointValue = 0;

			return pointValue * this.credits;
		} // end getQualityPoints()

	} // end courseNode class

} // end p3List class
