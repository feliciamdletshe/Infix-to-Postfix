/*
				 
	ALGORITHM
	1.Scan the infix expression from left to right
	2.If the scanned character is an operand, output it.
	3.Else, if the precedence of the operator in the stack is empty or contains('(' ),push it. Else, pop all the oprerators from the stack which are greater than or equals to in precedence than that of scanned operator thenPush the scanned operator to the stack
	4.If the scanned character is an '(', push it to the stack
	5.If the scanned character is an ')'. pop the stack and output it until a '(' is encountered, and discard both the parenthesis
	6.Reapeat 2-6 steps until infix expression is scanned.
	7.Print the output.
	8.Pop and output from the stack until it is not empty

*/

#include<iostream> //Preprocesser directive that allows input and output streams
#include<cstring> //To allow the use of String libraries
#include<stack> //To use the stack in the standard template library
using namespace std; //defines the cin and cout

// get weight of operators as per precedence
// higher weight given to operators with higher precedence
// for non operators, return 0 
int getWeight(char ch) //function getWeight of characters
{  
   switch (ch) //switch statement  
   {
   	 //cases for the switch statement
      case '/': 
      case '*': return 2;
      case '+':
      case '-': return 1;
      default : return 0;
   }
}

// convert infix expression to postfix using a stack
void convertToPostfix(char infix[], char postfix[], int size) 
{
    //declaring variables in the stack
   stack<char> s;
   int weight;
   int i = 0;
   int k = 0;
   char ch;
   // iterate over the infix expression   
   while (i < size) {
      ch = infix[i];
      if (ch == '(') {
         // simply push the opening parenthesis into a stack
         s.push(ch);
         i++;
         continue;
      }
      if (ch == ')') {
         // if we see a closing parenthesis,
         // pop of all the elements and append it to
         // the postfix expression till we encounter
         // a opening parenthesis
         while (!s.empty() && s.top() != '(') {
            postfix[k++] = s.top();
            s.pop();

         }
         // pop off the opening parenthesis also from the stack
         if (!s.empty()) {
            s.pop();
         }
         i++;
         continue;
      }
      weight = getWeight(ch);
      if (weight == 0) {
         // an operand is encountered
         // simply append it to postfix expression
         postfix[k++] = ch;

      }
      else {
         //  an operator
         if (s.empty()) {
            // simply push the operator onto stack if
            // stack is empty
            s.push(ch);
         }
         else {
            // pop of all the operators from the stack and
            // add it to the postfix expression till we
            // see an operator with a lower precedence that
            // the current operator
            while (!s.empty() && s.top() != '(' &&
                  weight <= getWeight(s.top())) {
               postfix[k++] = s.top();
               s.pop();

            }
            // push the current operator onto stack
            s.push(ch);
         }
      }
      i++;
   }
   // pop of the remaining operators present in the stack
   // and add it to postfix expression 
   while (!s.empty()) {
      postfix[k++] = s.top();
      s.pop();
   }
   postfix[k] = 0; // null terminate the postfix expression 
}

// main
int main() {
   char infix[] = "(6+2)*5-8/4"; //initializing an array infix[]
   int size = strlen(infix); 
   char postfix[size]; //declaring postfix as array of size
   convertToPostfix(infix,postfix,size); //a function to convert the infix to postfix expression
   cout<<"\nInfix Expression :: "<<infix; //displays the cout statement
   cout<<"\nPostfix Expression :: "<<postfix; //displays the postfix expression
   cout<<endl; 
   return 0;
}
