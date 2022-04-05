Questions (please see Section 10 of the course):

"1) Which C++ loop(s) did you use and why?

2) How did you handle displaying the leading spaces in each row of the pyramid?

3) Now that you completed the assignment, how might approach the problem differently if you had to solve it again?"

Answers:

1) For loops, to iterate through the original message of the user and get the characters that are required for each row, making sure to follow a 
   certain numerical pattern for every row to display the correct characters (see code). The numerical pattern is based on the index of the currently 
   displayed row. These indeces start from 0, and the total amount of indeces (or rows) is related to the length of the input string. I also included an if 
   statement for the first row of the pyramid, where no string reversion is required.

2) I followed a numerical pattern since I noticed the number of blank spaces before the first character was equal to the (length of the input message) - (the
   index of the current row +1), if indeces start at 0.

3) I might try to solve the assignment using a range based for loop, instead of using patterns based on the indeces.