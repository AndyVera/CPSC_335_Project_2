#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

//===============Function is for Part A of Problem 1 ======================
int fibonnaci_recursion(int stop_term, int at, int first = 0, int second = 1)
{
  int next_num = 0;

  if (stop_term == 1) { cout << 0 << "\n"; return 0; }
  if (stop_term == 2) { cout << 0 << ", " << 1 << "\n"; return 0; }

  else {
      if (at <= stop_term) {
        if (at == 2){
          cout << first << ", " << second;
          next_num = first + second;
          first = second;
          second = next_num;
          cout << ", " << next_num;
        }
        else {
          next_num = first + second;
          first = second;
          second = next_num;
          cout << ", " << next_num;
        }
        at++;
        fibonnaci_recursion(stop_term, at, first, second);
      }
  }
  return 0;
}
//=========================================================================

//===============Function is for Part B of Problem 1 ======================

int golden_number_equation_2_and_3 (int first, int second){

  double first_component = 0;
  double second_component = 0;
  double third_component = 0;
  double product = 0;

  //Prints out the first 20 Fibonnaci numbers
  cout << "\nEquation 1: \nPrints out the first 20 Fibonacci numbers\n";
  for (int i = 1; i <= 20; i++){
    first_component = pow((1 + sqrt(5)),i);
    second_component = pow((1 - sqrt(5)),i);
    third_component = pow(2.0, i) * sqrt(5);
    product = (first_component - second_component) / third_component;
    cout << product << ", ";
  }

  //Prints out the Fibonacci term from the first number inputed
  cout << "\n\nEquation 2: \nThe " << first << "th (the first number inputed) fibonnaci number is: ";
  first_component = pow((1 + sqrt(5)),first);
  second_component = pow((1 - sqrt(5)),first);
  third_component = pow(2.0, first) * sqrt(5);
  product = (first_component - second_component) / third_component;
  cout << product << "\n";

  //Prints out the nth Fibonacci number using any of the previous Fibonacci numbers
  cout << "The " << second - first << "th term after the " << first << "th term is: ";
  double equation_2 = product * pow((1 + sqrt(5)) / 2, second - first );
  cout << equation_2 << "\n";

  //Prints out Fibonacci numbers usign Equation 3
  cout << "\nEquation 3:\nPrinting out the Fibonacci numbers\n";
  double equation_3 = 0;
  cout << 0;
  for (int i  = 1; i < second; i++){
    cout << ", ";
    first_component = pow((1 + sqrt(5)),i);
    second_component = pow((1 - sqrt(5)),i);
    third_component = pow(2.0, i) * sqrt(5);
    product = (first_component - second_component) / third_component;

    equation_3 = product * ((1 + sqrt(5)) / 2);
    cout << equation_3;
  }
  cout << '\n';

  double maxium_equation_2 = 0.0;
  double maxium_equation_3 = 0.0;
  double equation_2_part1, equation_2_part2, equation_3_part1, equation_3_part2;

  //using the equation to prove that the Golden Ratio gets close to 1.61803 for when n = 7

  //Using Equation 2
  equation_2_part1 =  pow((1 + sqrt(5)),6.0);
  second_component = pow((1 - sqrt(5)),6.0);
  third_component = pow(2.0, 6.0) * sqrt(5);
  product = (first_component - second_component) / third_component;
  equation_2_part2 = equation_2_part1 * pow((1 + sqrt(5)) / 2, 7.0 - 6.0 );
  maxium_equation_2 = equation_2_part2 / equation_2_part1;

  //Using Equation 3
   equation_3_part1 = equation_2_part1;
   equation_3_part2 = equation_3_part1 * ((1 + sqrt(5)) / 2.0);
   maxium_equation_3 = equation_3_part2 / equation_3_part1;

  cout << "\nFor when n = 7, \nthe maxium when using equation 2 is: " << maxium_equation_2;
  cout << "\nthe maxium when using equation 3 is: " << maxium_equation_3 << "\n";

  //using the equation to prove that the Golden Ratio gets close to 1.61803 for when n = 30

  //Using Equation 2
  equation_2_part1 =  pow((1 + sqrt(5)),29.0);
  second_component = pow((1 - sqrt(5)),29.0);
  third_component = pow(2.0, 29.0) * sqrt(5);
  product = (first_component - second_component) / third_component;
  equation_2_part2 = equation_2_part1 * pow((1 + sqrt(5)) / 2, 30.0 - 29.0 );
  maxium_equation_2 = equation_2_part2 / equation_2_part1;

  //Using Equation 3
   equation_3_part1 = equation_2_part1;
   equation_3_part2 = equation_3_part1 * ((1 + sqrt(5)) / 2.0);
   maxium_equation_3 = equation_3_part2 / equation_3_part1;

  cout << "\nFor when n = 30, \nthe maxium when using equation 2 is: " << maxium_equation_2;
  cout << "\nthe maxium when using equation 3 is: " << maxium_equation_3 << "\n";

  return 0;
}

//=========================================================================================

int main(int argc, char const *argv[]){

//==============This lines of code are meant for Part A of the Problem 1=====================
  int recursion_stops_at = 0;
  int current_ = 2;
  cout << "\nWe are first doing Part A of Problem 1\n";
  do{
    cout << "Enter a positve integer to calculate the Fibonnaci numbers up to that number: ";
    cin >> recursion_stops_at;
  } while(recursion_stops_at < 1);
    cout << "It will calculate all the Fibonnaci numbers up this term: " << recursion_stops_at << "\n";
    fibonnaci_recursion(recursion_stops_at, current_);
    cout << "\nAll digits up to the " << recursion_stops_at <<"th term has been printed out\n\n";

//============================================================================================

//==============This lines of code are meant for Part B of the Problem 1=====================
int previous = 0;
int calculating_up_to = 0;
cout << "\nWe are first doing Part B of Problem 1\n";
do{
  cout << "Enter a positve integer to calculate the Fibonnaci numbers up to that number: ";
  cin >> previous;
} while(previous < 1);

do{
  cout << "Enter another postive integer greater than the first input which will calculate the nth Fibonnaci number after the first number: ";
  cin >> calculating_up_to;
} while(calculating_up_to < 1 || calculating_up_to <= previous );
golden_number_equation_2_and_3(previous, calculating_up_to);

//===============================================================================================

//=============These lines of code are meant for Problem 2======================================


}
