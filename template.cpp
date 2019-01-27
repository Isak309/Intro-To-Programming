/** 

 * @description Assignment 02, practice using C++ classes.  In this assignment
 *   we encapsulate a retirement planning object, that can set the amount of periodic
 *   deposits, the interest rate, and time in years we have to save.  The
 *   retirement account planner object can calculate retirement savings and can
 *   do planning to determine how much we need to save in order to reach a
 *   retirement goal.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


/** main 
 * The main entry point for this program.  Execution of this program
 * will begin with this main function.
 *
 * @param argc The command line argument count which is the number of
 *     command line arguments provided by user when they started
 *     the program.
 * @param argv The command line arguments, an array of character
 *     arrays.
 *
 * @returns An it value indicating program exit status.  Usually 0
 *     is returned to indicate normal exit and a non-zero value
 *     is returned to indicate an error condition.
 */
int main(int argc, char** argv)
{
  // test constructor
  cout << "=== Testing class creation using constructor..................." << endl << endl;
  //RetirementAccount account(100.00, 10.0, 0.035, 22.0);

  // test getter methods
  cout << "=== Testing getter methods..................." << endl;
  //cout << "Account: " << endl;
  //cout << "    D (deposit amount)   = $" << fixed << setprecision(2) << account.get_D() << endl;
  //cout << "    m (periods per year) =  " << fixed << setprecision(2) << account.get_m() << endl;
  //cout << "    r (interest rate)    =  " << fixed << setprecision(4) << account.get_r() << endl;
  //cout << "    t (time in years)    =  " << fixed << setprecision(2) << account.get_t() << endl;
  //cout << endl;
  
  // test tostring()
  cout << "=== Testing tostring() method..................." << endl;
  //cout << "Account: " << endl << account.tostring() << endl;
  //cout << endl;
  
  // test setter methods
  cout << "=== Testing setter methods..................." << endl;
  //account.set_D(500.00);
  //account.set_m(12.0);
  //account.set_r(0.048);
  //account.set_t(25.00);
  //cout << "Account: " << endl << account.tostring() << endl;

  // test retirement savings calculation
  cout << "=== Testing retirement savings calculations..................." << endl;
  //cout << "My retirement savings: $"
  //     << fixed << setprecision(2)
  //     << account.calculateRetirementSavings() << endl;
  //cout << endl;
  
  // test retirement planning calculations
  cout << "=== Testing retirement planning calculations..................." << endl;
  //double newD = account.planRetirementDeposits(1000000.00);
  //cout << "In order to save 1 million dollars, we need to make monthly deposits of $"
  //     << fixed << setprecision(2)
  //     << newD;
  //cout << endl;

  //account.set_D(newD);
  //cout << "If we set our deposit to this new amount..." << endl;
  //cout << "Account: " << endl << account.tostring() << endl;
  //cout << "My retirement savings: $"
  //     << fixed << setprecision(2)
  //     << account.calculateRetirementSavings() << endl;
  //cout << endl;

  // an additional test of savings and planning calculations
  cout << "=== Second test on account2 of savings and planning..................." << endl;
  //RetirementAccount account2(650.00, 9.0, 0.035, 30.0);
  //cout << "Account 2:" << endl << account2.tostring() << endl;
  //cout << "My retirement savings: $"
  //     << fixed << setprecision(2)
  //     << account2.calculateRetirementSavings() << endl;
  //cout << endl;

  //newD = account2.planRetirementDeposits(2000000.00);
  //cout << "In order to save 2 million dollars, we need to make deposits of $"
  //     << fixed << setprecision(2)
  //     << newD;
  //cout << endl;

  //account2.set_D(newD);
  //cout << "If we set our deposit to this new amount..." << endl;
  //cout << "Account: " << endl << account2.tostring() << endl;
  //cout << "My retirement savings: $"
  //     << fixed << setprecision(2)
  //     << account2.calculateRetirementSavings() << endl;
  //cout << endl;


  // more tests, demonstrate using arrays of classes and looping over classes
  // create 10 RetirementAccount's to perform some comparison calculations
  cout << "=== Larger number of tests, compare effect of increasing monthly deposit amount..................."
       << endl;
  //const int NUM_PLANS = 10;
  //RetirementAccount plan[NUM_PLANS];

  // set all accounts with same interest rate, periods and time, but different
  // deposit amounts
  //double D = 500.00; // base amount to deposit.
  //double m = 12.0;   // make monthly deposits
  //double r = 0.04;   // compound interest rate.
  //double t = 30.0;   // save for retirement for 30 years
  //for (int i = 0; i < NUM_PLANS; i++)
  //{
  //  plan[i].set_D(D + (i * 100.0));
  //  plan[i].set_m(m);
  //  plan[i].set_r(r);
  //  plan[i].set_t(t);

  //  cout << "Plan " << i << ":" << endl;
  //  cout << plan[i].tostring();
  //  cout << "    Total Savings: "
  //       << fixed << setprecision(2)
  //       << plan[i].calculateRetirementSavings() << endl;
  //}
  
  // return 0 to indicate successful completion
  return 0;
}
