NOTES - 2017/02/01

##Strings

The printf statement is smart enough to check for the null character at
the end of the char array. If we loop through a char array ourselves, we
have to find a way to find the end of the actual info in the array, minus
the junk data.

The strlen() function accepts a char array and returns the position of the
null character signifying the end of the string.
