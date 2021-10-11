#include <iostream>
#include <string>
#include <cstring>

using namespace std;

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

int main(int argc, char const *argv[]){

  int recursion_stops_at = 0;
  int current_ = 2;


  do{
    cout << "Enter a positve integer to calculate the Fibonnaci numbers up to that number: ";
    cin >> recursion_stops_at;
  } while(recursion_stops_at < 1);
    cout << "It will calculate all the Fibonnaci numbers up this term: " << recursion_stops_at << "\n";

    fibonnaci_recursion(recursion_stops_at, current_);

    cout << "\nAll digits up to the " << recursion_stops_at <<"th term has been printed out\n";
}
