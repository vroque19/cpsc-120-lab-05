
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// https://en.wikipedia.org/wiki/Integer_square_root
// Heron's method 1 CE
//
/// Calculate the integer square root using Heron's method
///
/// Given an input_number, calculate the integer square root by calculating the
/// series x_{k+1} = \frac{1}{2}\left(x_k + \frac{n}{x_k}\right), k \geq 0, x_0
/// > 0.
///
/// \param input_number The number to be square rooted
/// returns the integer square root of input_number
int IntegerSquareRoot(int input_number) {
  // TODO: Implement the integer square root algorithm
}

/// Main function - the entry point to our program
int main(int argc, char const* argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 2) {
    cout << "Please provide a number to check.\n";
    cout << "For example:\n";
    try {
      cout << args.at(0) << " 2147483647\n";
    } catch (out_of_range const& problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }
  int input_number = 0;
  try {
    input_number = stoi(args.at(1));
  } catch (const exception& problem) {
    cout << "There was a problem reading the input number.\n";
    cout << problem.what() << "\n";
    return (1);
  }

  bool is_prime_flag = true;

  // TODO: Write the trial division algorithm using your own integer suqare root
  // function to control the loop.

  cout << input_number;
  if (is_prime_flag) {
    cout << " is prime.\n";
  } else {
    cout << " is not prime.\n";
  }
  return 0;
}