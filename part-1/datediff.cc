// Vanessa Roque
// CPSC 120-19
// 2021-10-07
// vroque19@csu.fullerton.edu
// @vroque19
//
// Lab 05-01
//
// Date difference with command line arguments
//

/// Program to calculate the date between two Gregorian dates.

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/// Convert a Gregorian calendar date to a Julian day number
///
/// Given a date of the form YYYY/MM/DD such as 12/25/2021, convert the
/// Gregorian date to a Julian day number. The Julian day is the continuous
/// count of days since the beginning of the Julian period, January 1, 4713 BCE.
/// See https://en.wikipedia.org/wiki/Julian_day for more information.
///
/// \param day The day of the month, valid values are 1-31
/// \param month The month of the year, valid values are 1-12
/// \param year The year, valid values are -4713 through 2436204
/// returns the Julian day number
int GregorianToJulian(int day, int month, int year) {
  int julian_day_number = 0;

  julian_day_number = day - 32075 + 1461
    * (year + 4800 + (month - 14) / 12) / 4
    + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3
    * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  // TODO: write the implementation

  return julian_day_number;
}

/// Main function - the entry point to our program
int main(int argc, char* argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 7) {
    cout << "Please provide a starting date and an ending date.\n";
    cout << "For example:\n";
    try {
      cout << args.at(0) << " 12 25 2019 1 1 2020\n";
    } catch (out_of_range const& problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }

  int start_month = 0;
  int start_day = 0;
  int start_year = 0;

  try {
    start_month = stoi(args.at(1));
    start_day = stoi(args.at(2));
    start_year = stoi(args.at(3));
  } catch (const exception& problem) {
    cout << "There was a problem reading the start date.\n";
    cout << problem.what() << "\n";
    return (1);
  }

  int end_month = 0;
  int end_day = 0;
  int end_year = 0;

  try {
    end_month = stoi(args.at(4));
    end_day = stoi(args.at(5));
    end_year = stoi(args.at(6));
  } catch (const exception& problem) {
    cout << "There was a problem reading the end date.\n";
    cout << problem.what() << "\n";
    return (1);
  }

  int start_number_of_days_since_epoch =
      GregorianToJulian(start_day, start_month, start_year);

  int end_number_of_days_since_epoch =
      GregorianToJulian(end_day, end_month, end_year);

  int number_days =
      end_number_of_days_since_epoch - start_number_of_days_since_epoch;

  cout << number_days << " days\n";

  return 0;
}
