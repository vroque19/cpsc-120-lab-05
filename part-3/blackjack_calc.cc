// Vanessa Roque
// CPSC 120-19
// 2021-10-07
// vroque19@csu.fullerton.edu
// @vroque19
//
// Lab 05-03
//
// Converts face values to numeric value
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;


/// NumericValue takes the \p face_value of a card as a string
/// and returns the numeric_value of the card as an int
///
/// \param face_value A string representing the value of a card
/// (A, 2, ..., Q, K)
///
/// \returns The numeric_value of the card as an int (0, 1, ..., 11, 12)
///
/// \remark This is in the inverse of NumericValueToFaceValue()
int NumericValue(const string &face_value) {
  int numeric_value = 0;

  try {
    numeric_value = stoi(face_value);
  } catch (exception const& problem) {
    cout << "Problem converting the face value to a number. \n";
    cout << problem.what() << " \n";
    exit(1);
  }

  if (face_value == "A") {
    numeric_value = 11;
  } else if (face_value == "J") {
    numeric_value = 10;
  } else if (face_value == "Q") {
    numeric_value = 10;
  } else if (face_value == "K") {
    numeric_value = 10;
  } 

  return numeric_value;
}

/// Given a two to three letter string that represents a \p card, return
/// a single letter string that represents the card's face_value
///
/// \param card A two to three letter string representing a card,
/// ex. AS, 4D, 10H, QS
///
/// \returns A single letter string that which has the face_value of the
/// card (A, 2, 3, 4, 5, 6, 7, 8, 9, 1, J, Q, K)
///
/// \remark Although a 10 has two letters, only the first letter is needed
/// since it is the only card that has a value that starts with 1.
string FaceValue(const string &card) {
  try {
    return string(1, card.at(0));
  } catch (out_of_range const &problem) {
    cout << "The string doesn't have a 0th letter.\n";
    cout << problem.what() << "\n";
    exit(1);
  }
}

/// Entry point to the blackjack_calc program
/// \remark Must have at least 2 arguments. Each argument represents a card.
int main(int argc, char const *argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 3) {
    cout << "Please provide two cards.\n";
    cout << "For example:\n";
    try {
      cout << args.at(0) << " AS KH\n";
      cout << args.at(0) << " 3C 4D\n";
    } catch (out_of_range const &problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }
  string card_one;
  string card_two;
  try {
    card_one = args.at(1);
    card_two = args.at(2);
  } catch (out_of_range const &problem) {
    cout << "Uh-oh, you went out of bounds.\n";
    cout << problem.what() << "\n";
    return 1;
  }

  int card_one_value = 0;
  int card_two_value = 0;
  int sum = 0;

  string card_one_face_value = FaceValue(card_one);
  cout << "The face value of card one is " << card_one_face_value << " \n";
  string card_two_face_value = FaceValue(card_two);
  cout << "The face value of card two is " << card_two_face_value << " \n";

  card_one_value = NumericValue(card_one_face_value);
  card_two_value = NumericValue(card_two_face_value);
  sum = card_one_value + card_two_value;

  sum = NumericValue(FaceValue(card_one)) + NumericValue(FaceValue(card_two));

  if (sum == 22) {
   sum = sum - 10;
  } 
  cout << card_one << " + " << card_two << " = " << sum << "\n";
  return sum;
}
