/*
PROGRAM NAME: Program 6, Trees
PROGRAMMER:   Charles Davis
CLASS:        CSC 241.001, Fall 2016
INSTRUCTOR:   Dr. D. Dunn
DATE STARTED: November 20, 2016
DUE DATE:     November 22, 2016
REFERENCES:   Data Abstraction & Problem Solving with Java Textbook (tree implementation)

PROGRAM PURPOSE:


VARIABLE DICTIONARY:
	stack, p6StackP - Reference-based stack with generic type
	variableArray, char[] - array used for holding operands
	valueArray, int[] - array with values corresponding to operands at same index
	temp, char - the current character in the string
	postfix, String - a valid postfix expression
	infix, String - a valid infix expression
	result, double - the evaluated expression

ADTs:
	Stack
	Binary Tree

FILES USED:
	p6.java
	p6StackP.java
	p6BinaryTree.java
	p6.sh

SAMPLE INPUTS:

P*B
(((P*4)/(A-S))/((2+6)-(3*2)))
(W)

SAMPLE OUTPUTS:

Infix: P*B
Postfix: PB*
Prefix: *PB
Result: 160

Infix: (((P*4)/(A-S))/((2+6)-(3*2)))
Postfix: P4*AS-/26+32*-/
Prefix: //*P4-AS-+26*32
Result: -21.333

Infix: (W)
Postfix: W
Prefix: W
Result: 10


---------------------------------------------------------------------
*/
import java.io.*;
import java.util.*;

public class p6
{
	public static void main(String[] args)
	{
		try // try block to catch if file isn't found
		{
			File fileA = new File("../instr/p6a.dat"); // file containing infixes
			Scanner fileStreamA = new Scanner(fileA);

			File fileB = new File("../instr/p6b.dat"); // file defining operands
			Scanner fileStreamB = new Scanner(fileB);

			// Load arrays with operand values
			char[] variableArray = new char[20];
			int[] valueArray = new int[20];
			int i = 0;

			while (fileStreamB.hasNext())
			{
				variableArray[i] = fileStreamB.next().charAt(0);
				valueArray[i] = fileStreamB.nextInt();
				i++;
			} // end while

			fileStreamB.close(); // done with fileB

			p6BinaryTree<Character> arithmeticTree;
			String infixExpression, postfixExpression;
			double result = 0;

			// main loop
			while (fileStreamA.hasNextLine())
			{
				// each line of data file is infix expression
				infixExpression = fileStreamA.nextLine();

				postfixExpression = infixToPostfix(infixExpression);

				result = evaluatePostfix(postfixExpression, variableArray, valueArray);

				arithmeticTree = makeBinaryTree(postfixExpression);

				System.out.println("Infix: " + infixExpression);
				System.out.println("Postfix: " + postfixExpression);
				System.out.print("Prefix: ");
			  	printPrefix(arithmeticTree); // recursive printing method
				System.out.println();
				// make result prettier
				if (result == (long)result) 
					System.out.printf("Result: %d", (long)result);
				else
					System.out.printf("Result: %.3f", result);
				System.out.println("\n");
			} // end while

			fileStreamA.close();
		} // end try
		catch (FileNotFoundException e)
		{
			System.out.println(e);
		} // end catch
	} // end main

	public static String infixToPostfix(String infix)
	{
	// -----------------------------------------------
	// Converts the infix string into a postfix string.
	// Precondition: infix is an infix expression.
	// Postcondition: A valid postfix string is returned.
	// -----------------------------------------------
		p6StackP<Character> stack = new p6StackP<>();
		StringBuilder postfix = new StringBuilder();
		char temp;

		for (int i = 0; i < infix.length(); i++)
		{
			temp = infix.charAt(i);

			if (Character.isLetter(temp) || Character.isDigit(temp))
			{
				postfix.append(temp); // append operand to postfix string
			}
			else if (temp == '+' || temp == '-')
			{
				while (!stack.isEmpty() && stack.peek() != '(')
				{
					postfix.append(stack.pop());
				}
				stack.push(temp);
			}
			else if (temp == '*' || temp == '/')
			{
				while (!stack.isEmpty() && stack.peek() != '(' &&
					   	stack.peek() != '+' && stack.peek() != '-')
				{
					postfix.append(stack.pop());
				}
				stack.push(temp);
			}
			else if (temp == '^')
			{
				stack.push(temp);
			}
			else if (temp == '(')
			{
				stack.push(temp);
			}
			else if (temp == ')')
			{
				while (stack.peek() != '(')
				{
					postfix.append(stack.pop()); // pop and append everything up to left paren
				}
				stack.pop(); // remove matching left paren from stack
			} // end if
		} // end for

		while (!stack.isEmpty())
		{
			if (stack.peek() != '(')
				postfix.append(stack.pop());
		} // end while

		return postfix.toString();
	} // end infixToPostfix

	public static double evaluatePostfix(String postfix, char[] variableArray, int[] valueArray)
	{
	// -----------------------------------------------
	// Evaluates the postfix expression.
	// Precondition: postfix is a valid postfix expression.
	// The arrays contain operand values at correponding indexes.
	// Postcondition: The evaluated total is returned.
	// -----------------------------------------------
		p6StackP<Double> stack = new p6StackP<>();
		char temp;
		double leftOperand, rightOperand;

		for (int i = 0; i < postfix.length(); i++)
		{
			temp = postfix.charAt(i);

			if (Character.isDigit(temp)) // push numbers onto stack
			{
				stack.push((double)Character.getNumericValue(temp));
			}
			else if (Character.isLetter(temp)) // convert letters to number and push to stack
			{
				int count = 0;
				while (temp != variableArray[count] || count >= variableArray.length)
				{
					count++; //find the corresponding index to the operand value
				}
				stack.push((double)valueArray[count]);
			}
			else
			{
				rightOperand = stack.pop();
				leftOperand = stack.pop();

				if (temp == '+')
				{
					stack.push(leftOperand + rightOperand);
				}
				else if (temp == '-')
				{
					stack.push(leftOperand - rightOperand);
				}
				else if (temp == '/')
				{
					stack.push(leftOperand / rightOperand);
				}
				else if (temp == '*')
				{
					stack.push(leftOperand * rightOperand);
				}
				else if (temp == '^')
				{
					stack.push(Math.pow(leftOperand, rightOperand));
				} // end if
			} // end if
		} // end for

		return stack.pop();

	} // end evaluatePostfix

	public static p6BinaryTree<Character> makeBinaryTree(String postfix)
	{
	// -----------------------------------------------
	// Turns a postfix expression into an arithmetic tree.
	// Precondition: postfix is a valid postfix expression.
	// Postcondition: An expression tree is returned.
	// -----------------------------------------------
		p6StackP<p6BinaryTree<Character>> stack = new p6StackP<>();
		char temp;
		p6BinaryTree<Character> leftTree;
		p6BinaryTree<Character> rightTree;

		for (int i = 0; i < postfix.length(); i++)
		{
			temp = postfix.charAt(i);

			if (Character.isDigit(temp) || Character.isLetter(temp)) // temp is operand
			{
				// create tree and push onto stack
				stack.push(new p6BinaryTree<Character>(temp));
			}
			else // temp is operator
			{
				rightTree = stack.pop();
				leftTree = stack.pop();
				stack.push(new p6BinaryTree<Character>(temp, leftTree, rightTree));
			}
		} // end for

		return stack.pop();

	} // end makeBinaryTree

	public static void printPrefix(p6BinaryTree<Character> binTree)
	{
	// -----------------------------------------------
	// Takes an expression tree and prints a prefix.
	// Precondition: binTree is a valid expression tree.
	// Postcondition: A prefix expression is printed.
	// -----------------------------------------------
		p6BinaryTree<Character> leftTree;
		p6BinaryTree<Character> rightTree;

		if (!binTree.isEmpty())
		{
			try 
			{
				System.out.print(binTree.getRootItem());
				leftTree = binTree.detachLeftSubtree();
				if (!leftTree.isEmpty())
					printPrefix(leftTree);
				rightTree = binTree.detachRightSubtree();
				if (!rightTree.isEmpty())
					printPrefix(rightTree);
			}
			catch (Exception e)
			{
				System.out.println(e);
			}
		} // end if
	} // end printPrefix

} // end p6
