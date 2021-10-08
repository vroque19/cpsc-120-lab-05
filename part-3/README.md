
# Blackjack Calc

Ever play the game [blackjack](https://en.wikipedia.org/wiki/Blackjack)? It is a card game where you attempt to get as close as possible to 21 points without surpassing it.

We will write a little program that can add two cards toegether given the rules of blackjack. 

# Background
Let's first review some basic terminology. A deck of cards has four suits: clubs ♣️, diamonds ♦️, hearts ♥️, and spades ♠️. Each suit has 13 cards: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King. Let's abbreviate Ace as _A_, Jack as _J_, Queen as _Q_, and King as _K_. Court cards or face cards are the Jack, Queen, and King. In blackjack, the Ace can have the lowest value (1) and the highest value (11). All the court cards, have the same value as 10.

Let's abbreviate the suits as _C_ for clubs, _D_ for diamonds, _H_ for hearts, and _S_ for spades.

Here are some examples of abbreviations using the given schema:

* The 5 of diamonds is _5D_
* The Jack of hearts is _JH_
* The 2 of clubs is _2C_

Our program is not a blackjack game. It merely adds two cards together according to how blackjack is played.

For example if the program is given `AS` `KC`, then it will sum 11 and 10 and print to the termial 21.

Our program cannot be completed without some functions to help us perform our calculations.

```c++
string FaceValue(const string &card) {
  return string(1, card.at(0));
}
int NumericValue(const string &face_value){
  // To be implemented
}
```

`FaceValue()` extracts a string from the card representing the value of the card. The possible values are A, 2, 3, 4, 5, 6, 7, 8, 9, 1, J, Q, and K. Notice that it is a 1 and not a 10.

The function you have to write is `NumericValue()`. The function `NumericValue()` takes the string value (A, 2, 3, 4, 5, 6, 7, 8, 9, 1, J, Q, and K) and converts it to a number between 1 and 11. For example, the card _JD_ can have it's `FaceValue()` extracted with `FaceValue("JD")`.  In order to find the numerc value, the return value of `FaceValue()` ought t be sent to `NumericValue()` which will convert the _J_ in _JD_ to 10.

`NumericValue` always returns 11 for aces. When there are two aces, one ace must be 1 and the other ace must be 11. Handle this case by checking to see if the numeric values of both cards are 11. If so, subtract 10 from the sum.


## Requirements

Write a program that reads in 2 cards using the two letter abbreviation codes from the command line using `argv`. Use the pattern demonstrated previously of converting `argv` to a vector of strings named `args`.

Use the [`exit()`](https://en.cppreference.com/w/cpp/utility/program/exit) function to exit from your program if an error occurs in a function. Remember to `#include <cstdlib>` to take advantage of the `exit()` function.

If you need to, use  [`std::stoi()`](https://en.cppreference.com/w/cpp/string/basic_string/stol) to convert a string to an integer. Use the try/catch pattern learned from the previous lab to catch errors.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 blackjack_calc.cc \
| sed 's/\(blackjack_calc\)\.o[ :]*/\1.o blackjack_calc.d : /g' > blackjack_calc.d; \
[ -s blackjack_calc.d ] || rm -f blackjack_calc.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c blackjack_calc.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o blackjack_calc blackjack_calc.o 
$ ./blackjack_calc 
Please provide two cards.
For example:
./blackjack_calc AS KH
./blackjack_calc 3C 4D
$ ./blackjack_calc 7H KD
7H + KD = 17
$ ./blackjack_calc 4D 8H
4D + 8H = 12
$ ./blackjack_calc 3C AS
3C + AS = 14
$ ./blackjack_calc AC AD
AC + AD = 12
```

