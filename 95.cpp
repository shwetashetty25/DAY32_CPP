// write a program that prompts the user to enter a number. If the number is negative, throw an exception. Catch and handle the exception to display an appropriate message.
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    try
    {
        double num;
        cout << "Enter a number: ";
        cin >> num;
        if (num < 0)
        {
            throw invalid_argument("Negative number is not allowed");
        }
        cout << "You entered: " << num << endl;
    }
    catch (const invalid_argument &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}