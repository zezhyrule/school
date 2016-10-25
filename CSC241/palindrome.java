// Name: Charles Davis
// Palindrome Tester

import java.util.Stack;
import java.util.Scanner;

public class palindrome
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String word;
		p4StackA s = new p4StackA();
		p4StackA u = new p4StackA();
		p4StackA r = new p4StackA();

		System.out.print("Enter a word: ");

		word = input.next();

		for (int i = 0; i < word.length(); i++)
		{
			s.push(word.charAt(i));
			u.push(word.charAt(i));
		}

		while (!u.isEmpty())
		{
			r.push(u.pop());
		}

		boolean isPalindrome = true;

		while (!s.isEmpty())
		{
			if (s.pop() != r.pop())
				isPalindrome = false;
		}

		if (isPalindrome)
			System.out.println(word + " is a palindrome!");
		else
			System.out.println(word + " is not a palindrome.");
	}
}
