#include <iostream>

using namespace std;

int main() {
    
    // Variables declarations
    double balance, annualInterestRate;
    short minimumPayment;
    double dailyInterestRate;
    int month;
    double totalInterest;
    double totalPayments;
    double remaining;

    // Input and validate balance
    do 
    {
        cout << "Please enter the current balance on the credit card"<< endl;
        cin >> balance;
    } while (balance <= 0);

    // Input and validate annual interest rate
    do 
    {
        cout << "Please enter the annual interest rate " << endl;
        cin >> annualInterestRate;
    } while (annualInterestRate <= 0 || annualInterestRate >= 100);

    // Input and validate minimum payment
    do 
    {
        cout << "Enter the minimum payment due" << endl;
        cin >> minimumPayment;
    } while ( !( minimumPayment > 0 && minimumPayment % 10 == 0 ) );

    // Convert annual interest rate to daily interest rate
    dailyInterestRate = (annualInterestRate / 365) / 100;
    
    // Accumulator variables
    month = 0;
    totalInterest = 0;
    totalPayments = 0;
    
    cout.setf(ios::fixed);
    cout.precision( 2 );
    // Calculate balance and interest payment 
    while (balance > 0) 
    {
        month++;
        double monthlyInterest = 0;
        
        
        // Calculate monthly interest based on basis of daily interest
        for (int day = 0; day < 30; day++)
        {
            double dailyInterest = balance * dailyInterestRate;
            balance += dailyInterest;
            monthlyInterest += dailyInterest;
        }
        
        
        // Print the balance with interest at the end of the month 
        cout << "Balance with interest at the end of month " << month << " is $ " << balance << endl;
        
        // Adjust the final payment if it's less than the minimum payment
        if (balance < minimumPayment) 
        {
            totalPayments +=  balance;
            balance = 0;
            /*remaining = balance;
            balance = minimumPayment;
            */
        }
        else
        {
            totalPayments += minimumPayment;
            balance -= minimumPayment;
        }
        
        
        cout << "Balance after the minimum payment is $ " << balance << endl;
        
     /*   if ( balance > minimumPayment )
        {
            totalPayments += minimumPayment;
        }
        else
        {
            totalPayments += remaining;
        }
        */
        totalInterest += monthlyInterest;
        
       
        
        
    }
    

    // Output results
    cout << "Total months taken to pay off the balance is " << month << endl;
    cout << "Your total payments were $ " << totalPayments << endl;
    cout << "The total interest you paid was $ " << totalInterest << endl;

    return 0;
}




