
# Datediff

Not too long ago we learned how to take teh difference between two dates using a conversion from the [Gregorian Calendar](https://en.wikipedia.org/wiki/Gregorian_calendar) to a day in the [Julian Calendar](https://en.wikipedia.org/wiki/Julian_calendar). Using two dates expressed as dates on a Gregorian calendar, such as January 1, 1970 [CE](https://en.wikipedia.org/wiki/Common_Era) our program calculated (very accurately) how many days between the two dates.

Recall that we used the formula discovered by [Fliegel & Van Flandern](https://dl.acm.org/doi/pdf/10.1145/364096.364097). The formula is very compact and only requires integers to calculate a date that goes as far back as November 24, 4713 [BCE](https://en.wikipedia.org/wiki/Common_Era).

The problem with the Fliegel & Van Flandern's algorithm is that it looks simple but typing it in was very difficult to do.

Let's review the formula one more time. Fliegel & Van Flandern's algorithm [restated on the Wikipedia page](https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation) with some slight modifications. Below is a modestly modified line of code from the [US Naval Obervatory's NOVAS](https://github.com/indigo-astronomy/novas) source code which calculates a Julian Day (`int`)from a Gregorian Date, for example 1/23/2021 where 1 is the month January, 23 is the 23rd day of the month and 2021 is the year.

```C++
int month = 1;
int day = 23;
int year = 2021;
int julian_day = day - 32075 + 1461
      * (year + 4800 + (month - 14) / 12) / 4
      + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3
      * ((year + 4900 + (month - 14) / 12) / 100) / 4;
```

Wouldn't it be nice to write this forumula down once and be able to use it whenever we want? This presents itself as a great opportunity to learn about functions.

We have already learned about the [`main()`](https://en.cppreference.com/w/cpp/language/main_function) function which serves as the entry point to our program. (It's a special, magical function that we'll learn more about later.)

One way to think about function is a way to give a series of steps a name. For example, we may have routines in our daily life like fixing up a morning coffee, taking care of a pet, making a sandwich, or tidying up your room. These routines are not just a single step. The routines have many steps which we may have loops and conditions within them.

By creating these routines and giving them names, we can communicate complex ideas to one another and teach people really sophisticated process. For example, tying shoelaces is a really complicated process with a simple sounding name. Someone had to show you all the steps to do it and even then it took a bit of practice to learn it.

With computers, we can instruct them to do anything we can imagine. At the same time, the programmer ought not to have to repeat the same instructions over and over again. Right now, every time we want our programs to do something we have to write out all the instructions in our `main()` function. This can become quite repetitive and it means it will be hard for us to reuse (think cut-n-paste) our code to make new programs.

Long, long ago, there was a computer called the [EDSAC](https://en.wikipedia.org/wiki/EDSAC) built by the University of Cambridge and became operational in 1949. This was the second computer to become operational which uses an architecture that is very similar to the computers we use today. (It was an electronic digital [stored program](https://en.wikipedia.org/wiki/Stored-program_computer) architecture - similar to a [Von Neumann architecture](https://en.wikipedia.org/wiki/Von_Neumann_architecture) but not quite the same thing.) People were struggling to build computers and they started to realize that programming them was very difficult. The leaders of the team behind the EDSAC were [Maurice Wilkes](https://en.wikipedia.org/wiki/Maurice_Wilkes), [David Wheeler](https://en.wikipedia.org/wiki/David_Wheeler_(computer_scientist)), and [Stanley Gill](https://en.wikipedia.org/wiki/Stanley_Gill). They spent a great deal of time figuring out how to program this machine they had just built and the result of that effort was the book [Programs For An Electronic Digital Computer](https://ia803205.us.archive.org/14/items/programsforelect00wilk/programsforelect00wilk.pdf).

The book Programs For An Electronic Digital Computer was published in 1951. Chapter 2 is titled Subroutines which details a great invention that they had come up with. They would write small programs and give them pithy names. They called these small programs subroutines and today we call them functions. Then when they wanted to use those subroutines (functions) in their EDSAC programs, they could write the name of the subroutine (function) in their program. The compiler would find the code and copy-n-paste it into the program.

The idea may appear obvious to you today however a study of exactly all this is done in a computer is pretty fantastic. (Check out [Compilers: Principles, Techniques, and Tools](https://csuf-primo.hosted.exlibrisgroup.com/permalink/f/t150k2/01CALS_ALMA71378748190002901)!)

The beauty of all this is that we can write functions for our own programs. In this exercise, we shall pick something really easy for us to calculate - the area of a [rectangle](https://en.wikipedia.org/wiki/Rectangle).

To write a [C++ function](https://en.cppreference.com/w/cpp/language/functions) you have to remember a few rules.

1. Functions must have a name that starts with a letter. A functions name is like the name of a variable.
1. A function has a return type. This is the type (`int`, `float`, `bool`, `string`, `void`) of the value that is returned from the function.
1. A function always returns something. Returning nothing (`void`) is still something.
1. A function has a list of typed parameters. Even when there is nothing there, it's still something.
1. A function only can return one thing.
1. A function can have many, many parameters.
1. The types must match!

```
int circle_area(float radius) {
  const float kPi = 3.14;
  float area = radius * radius * kPi;
  return radius;
}
```

In the example above, a function named `circle_area` has a return type of `int`. It has a parameter list with one parameter. The parameter is named `radius` and it's of type `float`. The prototype of the function is `int circle_area(float radius);` and the signature of the function is `circle_area(float radius)`. The body of the function is what is between the open brace `{` and  close brace `}`.

```
float my_radius = 12.3;
float area = NAN;
area = circle_area(my_radius);
float another_area = NAN;
another_area = circle_area(6.9);
```

In the example above, the function `circle_area` is used to calculate the area of a circle with radius `my_radius` and the returned valued (of type `float`) is stored in the variable `area`. The second example shows that you can pass values directly to a function (`6.9`) so long as the types match between what is being passed and the parameters type.


Remember to always test your work. We know that January 1, 2021 is the Julian day 2,459,216 and January 1, 1990 is the Julian day 2,447,893. The number of days between these two dates is 11,323. Use these figures to devise a strong testing strategy.

You can also test your work by checking how many days there are in a [year](https://en.wikipedia.org/wiki/Calendar_year). (Recall that there are 365 days in a typical year.) This means that between January 1, 2021 and January 1, 2022, there are 365 days. However, between January 1, 2020 and January 1, 2021 there are 366 days because the year 2020 is a [leap year](https://en.wikipedia.org/wiki/Leap_year.)

In our case, we need to define a function which will handle a Gregorian date and convert it to a Julian day. A Gregorian date is expressed as three integers and a Julian day is a single integer. Therefore, our function shall look like:

```c++
int GregorianToJulian(int day, int month, int year) {
  // This is the body of the function.
}

```

The name of the function is `GregorianToJulian`. It has three `int` parameters named `day`, `month`, and `year`. The function calculates the Julian day using Fliegel & Van Flandern's formula. This function is defined at the top of the file, after the `using namespace std;` but before the `main()` function.

To use the function, it is called like this:
```c++
int date_month = 1;
int date_day = 10;
int date_year = 1990;
int juian_day = 0;
julian_day = GregorianToJulian(date_day, date_month, date_year);
```

But wait…there's more.

We learned about command line arguments in a previous lab exercise and now we are going to put that knowledge to use.

Our program requires two dates. Each date is represented by three integers. For instance the date 1/5/2022 has an integer for the month (1), an integer for the day (5), and an integer for the year (2020).

It would be ideal if we could pass the two dates to the program from the command line rather than being prompted for the information. To do this, we will extract the two dates from `argv`.

The first step is to convert `argv` into a vector (a list) of strings. The pattern than was introduced is:

```c++
  vector<string> args = vector<string>(argv, argv + argc);
```

We can access arbitrary items using the [at()](https://en.cppreference.com/w/cpp/container/vector/at) [member function](https://en.cppreference.com/w/cpp/language/member_functions). Should we wish to access the 4th element in `args` it would look like the following:

```c++
    try {
      cout << "The 4th element in args is " << args.at(3) << "\n";
    } catch (out_of_range const& problem) {
      cout << "Uh-oh, you went out of bounds.\n";
      cout << problem.what() << "\n";
      return 1;
    }
```

It is quite possible that there is something at the 4th location and it is also very possible that there's nothing there. In the C++ universe, if nothing is there it can cause our program to crash, seg fault, etc. We wrap the call to `at()` with a `try` and `catch` for safety. In case we made a mistake, we can `catch` the mistake and handle is gracefully.

Another important element is that everythign in `args` is a string. We need our date as integers. This little problem is solved by converting strings that look like integers such as "123" to integers using the [`stoi()`](https://en.cppreference.com/w/cpp/string/basic_string/stol) function. A feature of `stoi()` is that if you give it garbage it will throw an [exception](https://en.wikipedia.org/wiki/Exception_handling). This means if you have a command line argument that is not convertible to a numeric value, the function `stoi()` will scream and yell so you can handle the error gracefully rather than continuing to use the garbage entered by the computer user.

```c++
int value_of_argument = 0;
try {
  value_of_argument = std::stoi(args.at(1));
} catch (exception const& problem) {
    cout << "Uh-oh, something went wrong converting a string to an int.\n";
    cout << problem.what() << "\n";
    return 1;
}
```

It is important that we learn to use `try` and `catch` because it will help us avoid mistakes that are hard to detect and cause our programs to crash.

## Requirements

Use the Fliegel & Van Flandern's algorithm to convert two dates into Julian Days and then take the difference.

Write Fliegel & Van Flandern's algorithm as a function with the following prototype:
```c++
int GregorianToJulian(int day, int month, int year);
```

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

_Do not use_ [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard. This program is not interactive and an interactive program will be marked with a zero score.

The program reads in six values from the command line (`argv`), stores them in a vector named `args`. Use the example provided to process command line arguments.

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

As stated earlier, to help you test your work, we know that January 1, 2021 is the Julian day 2,459,216 and January 1, 1990 is the Julian day 2,447,893. The number of days between these two dates is 11,323.

You can also test your work by checking how many days there are in a [year](https://en.wikipedia.org/wiki/Calendar_year). (Recall that there are 365 days in a typical year.) This means that between January 1, 2021 and January 1, 2022, there are 365 days. However, between January 1, 2020 and January 1, 2021 there are 366 days because the year 2020 is a [leap year](https://en.wikipedia.org/wiki/Leap_year.)

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 datediff.cc \
| sed 's/\(datediff\)\.o[ :]*/\1.o datediff.d : /g' > datediff.d; \
[ -s datediff.d ] || rm -f datediff.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c datediff.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o datediff datediff.o 
$ ./datediff
Please provide a starting date and an ending date.
For example:
./datediff 12 25 2019 1 1 2020
$ ./datediff 1 1 2020 1 1 2021
366 days
$ ./datediff 12 25 1990 2 14 2022
11374 days
```

