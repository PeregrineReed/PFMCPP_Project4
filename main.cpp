/*
 Chapter 2 Part 7
 Returning Values tasks
 
 1) write 3 UDTs named FloatType, DoubleType, IntType.
 
 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );
 
 3) make them return the correct primitive type. e.g. if you're implementing the FloatType::add function, your implementation would start like this:
        float FloatType::add( float lhs, float rhs )
 
 4) declare a few instances of each class in main() and call the member functions with the appropriate arguments.
        FloatType ft;
        auto result = ft.add(3.2f, 23.f );
 
 5) print out those results using std::cout:
        std::cout << "result of ft.add(): " << result << std::endl;
 
 6) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
        return rhs;
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
      return rhs;
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

    result = dt.add( 3.2, 23.1 );
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
