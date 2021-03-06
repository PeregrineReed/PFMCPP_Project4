/*
 Project 4 - Part 2
 Video: Chapter 3 Part 6

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */











 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type WITHOUT using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write some add/subtract/divide/multiply member functions for each type that take your 3 UDTs
         for example, IntType::divide(const DoubleType& dt);
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Wait for my code review.
 */




#include  <stdlib.h>
#include <iostream>

using namespace std;

struct FloatType
{
    float add( float, float );
    float subtract( float, float );
    float multiply( float, float );
    float divide( float, float );
};

float FloatType::add( float lhs, float rhs )
{
    return lhs + rhs;
}

float FloatType::subtract( float lhs, float rhs )
{
    return lhs - rhs;
}

float FloatType::multiply( float lhs, float rhs )
{
    return lhs * rhs;
}

float FloatType::divide( float lhs, float rhs )
{
    if (rhs == 0.f)
    {
        std::cout << "warning: Can't divide by 0." << std::endl;
        return rhs; FIXME its perfectly fine to divide floating point numbers by 0.  Just warn, dont return rhs.
    }
    else
    {
      return lhs / rhs;
    }
}

struct DoubleType
{
    double add( double, double );
    double subtract( double, double );
    double multiply( double, double );
    double divide( double, double );
};

double DoubleType::add( double lhs, double rhs )
{
    return lhs + rhs;
}

double DoubleType::subtract( double lhs, double rhs )
{
    return lhs - rhs;
}

double DoubleType::multiply( double lhs, double rhs )
{
    return lhs * rhs;
}

double DoubleType::divide( double lhs, double rhs )
{
  if (rhs == 0.0)
  {
      std::cout << "warning: Can't divide by 0." << std::endl;
      return rhs; FIXME its perfectly fine to divide floating point numbers by 0.  Just warn, dont return rhs.
  }
  else
  {
    return lhs / rhs;
  }
}

struct IntType
{
    int add( int, int );
    int subtract( int, int );
    int multiply( int, int );
    int divide( int, int );
};

int IntType::add( int lhs, int rhs )
{
    return lhs + rhs;
}

int IntType::subtract( int lhs, int rhs )
{
   return lhs - rhs;
}

int IntType::multiply( int lhs, int rhs )
{
    return lhs * rhs;
}

int IntType::divide( int lhs, int rhs )
{
    if (rhs == 0)
    {
        std::cout << "error: Can't divide by 0." << std::endl;
        return rhs;
    }
    else
    {
      return lhs / rhs;
    }
}


int main()
{
    FloatType ft;
    DoubleType dt;
    IntType it;

	//uncomment to see abort be called
	//it.divide(1, 0);

    auto result = ft.add( 3.2f, 23.f );
    std::cout << "result of ft.add(): " << result << std::endl;
    result = ft.subtract( 3.2f, 23.f );
    std::cout << "result of ft.subtract(): " << result << std::endl;
    result = ft.multiply( 3.2f, 23.f );
    std::cout << "result of ft.multiply(): " << result << std::endl;
    result = ft.divide( 3.2f, 0.f );
    std::cout << "result of ft.divide(): " << result << std::endl;

    result = dt.add( 3.2, 23.1 ); FIXME result is a float, but dt returns a double.  make another local variable to clear this warning
    std::cout << "result of dt.add(): " << result << std::endl;
    result = dt.subtract( 3.2, 23.1 );
    std::cout << "result of dt.subtract(): " << result << std::endl;
    result = dt.multiply( 3.2, 23.1 );
    std::cout << "result of dt.multiply(): " << result << std::endl;
    result = dt.divide( 3.2, 0 );
    std::cout << "result of dt.divide(): " << result << std::endl;

    result = it.add( 3, 23 ); 
    std::cout << "result of it.add(): " << result << std::endl;
    result = it.subtract( 3, 23 );
    std::cout << "result of it.subtract(): " << result << std::endl;
    result = it.multiply( 3, 23 );
    std::cout << "result of it.multiply(): " << result << std::endl;
    result = it.divide( 3, 23 );
    std::cout << "result of it.divide(): " << result << std::endl;

    std::cout << "good to go!" << std::endl;
}
