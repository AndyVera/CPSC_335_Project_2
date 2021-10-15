#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <array>
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
  cout << "\n***Equation 2:***\nPrints out the first 20 Fibonacci numbers\n";
  for (int i = 1; i <= 20; i++){
    first_component = pow((1 + sqrt(5)),i);
    second_component = pow((1 - sqrt(5)),i);
    third_component = pow(2.0, i) * sqrt(5);
    product = (first_component - second_component) / third_component;
    cout << product << ", ";
  }

  //Prints out the Fibonacci term from the first number inputed
  cout << "\n\nThe " << first << "th (the first number inputed) fibonnaci number is: ";
  first_component = pow((1 + sqrt(5)),first);
  second_component = pow((1 - sqrt(5)),first);
  third_component = pow(2.0, first) * sqrt(5);
  product = (first_component - second_component) / third_component;
  cout << product << "\n";

  //Prints out the nth Fibonacci number using any of the previous Fibonacci numbers
  cout << "The " << second << "th fibonnaci number is: ";
  double equation_2 = product * pow((1 + sqrt(5)) / 2, second - first );
  cout << equation_2 << "\n";

  //Prints out Fibonacci numbers usign Equation 3
  cout << "\n***Equation 3:***\nPrinting out the Fibonacci numbers\n";
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
  cout << "\n\nThe " << second <<"th term is: " << equation_3 << '\n';

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

//=========================This Function is for Problem 2=================================

int calc_sum (int arr2 [], int start, int end){
  int total = 0;
  for(int i = start; i < end; i++){ total = total + arr2[i]; }
  return total;
}

void largest_sum (int arr [] , int len_of_arr){
  int b = 0;
  int e = 1;
  int sum_new = 0;
  int sum_old = 0;

  for(int i = 0; i <= len_of_arr - 1; i++ ){
    for(int j = i + 1; j <= len_of_arr; j++){
      //cout << "i = " << i << '\n';
     //cout << "j = " << j << '\n';

      sum_new = calc_sum(arr, i, j);
      //cout << "Sum of the new is: " << sum_new << '\n';
      sum_old = calc_sum(arr, b, e);
      //cout << "Sum of the old is: " << sum_old << '\n';

      if (sum_new > sum_old){
        b = i;
        e = j;
      }
      }
    }

    for (int l = b; l < e; l++){
      cout << arr[l] << ", ";
    }
  }

int main(int argc, char const *argv[]){

//==============This lines of code are meant for Part A of the Problem 1=====================
  int recursion_stops_at = 0;
  int current_ = 2;
  cout << "\n+++We are first doing Part A of Problem 1+++\n";
  do{
    cout << "Enter a positve integer to calculate the Fibonnaci numbers up to that number: ";
    cin >> recursion_stops_at;
  } while(recursion_stops_at < 1);
    cout << "It will calculate all the Fibonnaci numbers up this term: " << recursion_stops_at << "\n";
    fibonnaci_recursion(recursion_stops_at, current_);
    cout << "\nAll digits up to the " << recursion_stops_at <<"th term has been printed out\n\n=======================================================================\n";

//============================================================================================

//==============This lines of code are meant for Part B of the Problem 1=====================
int previous = 0;
int calculating_up_to = 0;
cout << "\n+++We are first doing Part B of Problem 1+++\n";
do{
  cout << "Enter a positve integer to calculate the Fibonnaci numbers up to that number: ";
  cin >> previous;
} while(previous < 1);

do{
  cout << "Enter another postive integer greater than the first input which will calculate the nth Fibonnaci number after the first number: ";
  cin >> calculating_up_to;
} while(calculating_up_to < 1 || calculating_up_to <= previous );
golden_number_equation_2_and_3(previous, calculating_up_to);
cout << "====================================================================================\n";
//===============================================================================================

//=============These lines of code are meant for Problem 2======================================
cout << "\n\n+++Now Doing Problem 2 of Project 2+++\n";
int length_of_test_array = 8;
signed test_array [length_of_test_array] = {-3, -5, 5, -1, -3, 1, 5, -6};

int length_of_sample_array_1 = 9;
signed sample_array_1 [length_of_sample_array_1] = { 10, 2,-5, 1, 9, 0,-4, 2,-2 };

int length_of_sample_array_2 = 6;
signed sample_array_2 [length_of_sample_array_2] = {-7, 1, 8, 2, -3, 1};

int length_of_sample_array_3 = 6;
signed sample_array_3 [length_of_sample_array_3] = {9, 7, 2, 16,-22, 11};

int length_of_sample_array_4 = 14;
signed sample_array_4 [length_of_sample_array_4] = {6, 1, 9, -33, 7, 2, 9, 1, -3, 8, -2, 9, 12, -4};

cout << "Largest Sum for Test Array is: (";
largest_sum(test_array, length_of_test_array);
cout << ")\n";

cout << "Largest Sum for Sample Array 1 is: (";
largest_sum(sample_array_1, length_of_sample_array_1);
cout << ")\n";

cout << "Largest Sum for Sample Array 2 is: (";
largest_sum(sample_array_2, length_of_sample_array_2);
cout << ")\n";

cout << "Largest Sum for Sample Array 3 is: (";
largest_sum(sample_array_3, length_of_sample_array_3);
cout << ")\n";

cout << "Largest Sum for Sample Array 4 is:";
largest_sum(sample_array_4, length_of_sample_array_4);
cout << ")\n";
}
