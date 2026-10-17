#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void vNumberValidation(int& Number)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Must be a \"NUMBER\" : ";
		cin >> Number;
	}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void vNumberZone(int& Number, int From, int To)
{
	while (Number > To || Number < From)
	{
		cout << "The Number must be (" << From << "-" << To << ") : ";
		cin >> Number;
		vNumberValidation(Number);
	}
}

int iGetRandomNumber(int From, int To) 
{
    return rand() % (To - From + 1) + From;
}
 
bool bContinueProject(string Text)
{
    char Continue = ' ';
    do{
        cout << Text;
        cin >> Continue;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (!(Continue == 'y' || Continue == 'Y' || Continue == 'n' || Continue == 'N'));

    if (Continue == 'y' || Continue == 'Y')
        return 1;
    else
        return 0;
}

int iReadUserNumber(int From, int To)
{
    int UserNumber = 0;

    cout << "(( Guess the number ))\n";
    cout << "Enter a number (" << From << "-" << To << "): ";
    cin >> UserNumber;
    vNumberValidation(UserNumber);  
    vNumberZone(UserNumber, From, To);

    return UserNumber;
}

void vWinOrLose(int Number, int NumToCompare)
{
    if (Number == NumToCompare)
    cout << "\nCongratulations, You won :)\n";
    else
    cout << "\nYou lost :(\n\a" << "The Number is (" << NumToCompare << ")!\n";
}

int main()
{
    srand((unsigned)time(NULL));
    int From = 1, To = 10;
    do{
        int RandNum = iGetRandomNumber(From, To);
        int UserNumber = iReadUserNumber(From, To);
        vWinOrLose(UserNumber, RandNum);
        cout << "\n-------------------------------\n";
    }while(bContinueProject("\nDo you want to continue ? (Y/N): "));

    return 0;
}