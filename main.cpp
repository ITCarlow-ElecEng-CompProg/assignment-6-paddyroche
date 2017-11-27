/**<
Patrick Roche
Exercise 6
Decimal/Binary conversion */

/**< Preprocessor Directives */
#include <iostream>
#include <cmath>

using namespace std;

/**< 3 functions being used */
void bin_2_dec(long int x);
void dec_2_bin(long int y);
int main();

/**< Main Function */
int main()
{
   /**< naming the character 'input for the switch case */
   char input;

   /**< As its binary, the num inputed as binary/dec has to be stored as a long int since banary numbers
   are too long for the "int" datatype  */
   long int num;

   /**< Heading */
   cout << "Decimal/Binary Numbering Systems Conversion\n" << endl;


   do
   {
       /**< Telling user what to press */
       cout << "enter required program\n" <<
               "press 'b' for binary to decimal\n" <<
               "press 'd' for decimal to binary\n" <<
               "press q to quit program" << endl;
       /**< inputting the character b/d or q */
       cin >> input;

       /**< a switch case in the main function to decide what function to use  */
       switch (input)
       {
           case 'b':   cout << "Binary to Decimal..." << endl;
                       cin >> num;
                       /**< calls the function binary to decimal */
                       bin_2_dec(num);
                       break;
           case 'd':   cout << "Decimal to Binary..." << endl;
                       cin >> num;
                       /**< calls the function Decimal to Binary */
                       dec_2_bin(num);
           break;
                       case 'q': cout << "Quit program..." << endl;
                       break;
           default:    cout << "Please try again..." << endl;
                       break;
       }
   }
   /**< while the input in not 'q' */
   while (input != 'q');

    return 0;
}

/**< function for binary to decimal conversion */
void bin_2_dec(long int num)
{
    /**< Variable Declarition */
    long int i = 0,  output = 0;

    /**< Asking & Getting the user to input the binary number they want to convert */
    //cout << "Please enter the Binary number you want to convert!" << endl;
    //cin >> num;

    /**< For loop to calcualte  */
    while (num > 0)
    {
        if( num % 10 == 1)
        {
            output = output + pow(2,i);
        }
        i++;
        num = num / 10;
    }

    /**< Displaying the result to the user  */
    cout << output << "\n" << endl;

    return;
}

/**< Function for converting dec-binary */
void dec_2_bin(long int y)
{
    int i;

    /**< An array of 10 and called binarray-e.g.0-9 */
    int binarray[10] = {0};

    /**< for loop starting at 0, ending at 9 and adding each time */
    for(i=0;i<10;i++)
    {
        /**< if remainder of 'y' divided by 2 is even (0) */
        if(y%2 == 0)
        {
            /**< since its even, this element must be 0 */
            binarray[i] = 0;
            /**< reduces 'y' by half. this is how you calculate from decimal to binary*/
            y = y/2;
        }
        else
        {
            /**< since its odd, this element must be 1 */
            binarray[i] = 1;
            /**< y-1 turns it from odd to even and reduces it by half */
            y = (y-1)/2;
        }
    }

    /**< this for loop reverses the output to match the binary number. e.g- decimal 10 is showing as 0101 where it is suppossed
    to be 1010 */
    for(i=9;i>=0;i--)
    {
        /**< the correct output */
        cout << binarray[i];
    }


    return;
}
