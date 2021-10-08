
# Checking If a Number is Prime

Given the number 3,137, how can we check to see if it is a [prime number](https://en.wikipedia.org/wiki/Prime_number)?

Remember a prime number is only divisible by 1 and itself. An example of a prime number is the number 2. It can only be divided by 1 and by itself, 2. Another prime number is 13. There are no numbers less than 13 which divide it evenly. On the other hand, a number like 10 is composite. Composite means that you can express the number as the product of two other, smaller, numbers. For instance, 10 can be expressed as 2 * 5.

If we have the number 3,137, we can check every number from 2 until (3,137 - 1) to see if 3,137 can be divided by all those candidate numbers. If we find a number that divides evenly into 3,137 then we know that 3,137 is composite. Otherwise, 3,137 is prime.

The algorithm [Trial Division](https://en.wikipedia.org/wiki/Trial_division), first described by Fibonacci in 1202 CE, is not the best way to discover if a number is prime yet it is easy to program.

All we would have to do is write a `for` loop that starts at 2 and counts up to the number we are interested in. Let's say we want to verify that 23 is prime. Our for loop starts at 2 and counts up to 23, stopping at 22. Every steps of the way, we use the modulo `%` operator to see if 23 modulo the current count has any remainder. If 23 modulo the counter has no remainder then the number is not prime. Otherwise, if we reach the end of the loop without finding any number that evenly divides into 23 then we know 23 is prime.

Can you think of a way to speed this up? Do you really need to check all the numbers for 23?

Let's look at all the number we have to use: 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22.

Do we really need to check to see if 23 is divisible by 20? Or by 16? or by 15? Note that 20 is a composite number made up of 4 * 5 or 2 * 10. The number 16 is made up of 2 * 8 or 4 * 4. The number 15 is made up of 3 * 5. Do you see a pattern or relationship?

Originally, we thought our look would like something like this:

```c++
int input_number = 23;
for(int counter; counter < input_number; counter++){
  // check if prime
}
```

We don't need to count up to `input_number`. In fact we only need to count up to the [square root of `input_number`](https://en.wikipedia.org/wiki/Trial_division#Method). The loop can be rewritten as:

```c++
int input_number = 23;
for(int counter; counter < IntegerSquareRoot(input_number); counter++){
  // check if prime
}
```

Since we already have an integer square root algorithm from a previous exercise, we can reuse the code by writing a function called `int IntegerSquareRoot(int input_number)`.

The input to the program shall be from the command line. Using `argv`, convert it so a vector of strings named `args` and convert the input using `stoi()`.

## Requirements

Write a program that takes one integer as a command line argument and then calculates whether or not the number is prime. Print a message to the screen stating if the number is or is not a prime number. See the Example Output Section for more details.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

_Do not use_ [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard. This program is not interactive and an interactive program will be marked with a zero score.

The program reads in one value from the command line (`argv`), stores them in a vector named `args`. Use the example provided to process command line arguments.

Use the trial division algorithm along with your `IntegerSquareRoot()` function. Use of the function is mandatory.

Use `stoi()` only. Do not use `atoi()`.

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
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 is_it_prime.cc \
| sed 's/\(is_it_prime\)\.o[ :]*/\1.o is_it_prime.d : /g' > is_it_prime.d; \
[ -s is_it_prime.d ] || rm -f is_it_prime.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c is_it_prime.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o is_it_prime is_it_prime.o 
$ 
$ ./is_it_prime 2
2 is prime.
$ ./is_it_prime 5
5 is prime.
$ ./is_it_prime 2147483647
2147483647 is prime.
$ ./is_it_prime 10
10 is not prime.
$ ./is_it_prime 145
145 is not prime.
```

