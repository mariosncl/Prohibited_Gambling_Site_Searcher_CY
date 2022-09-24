/*Simple program created by Marios Nicolaou to aid cypriot citizens to check whether 
a gambling site is included in the forbidden-prohibited gambling sites list of the National Betting Authority of Cyprus*/

// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void checkfun(string inputsite)
{

	fstream file;
	string readfile;
	bool flag = false;
	int line = 0;

	// Safeguard, to verify the existance of the file that includes the sites.
	file.open("List.txt", ios::in | ios::out);
	
	if (file.fail())
	{
		cout << "File does not exist" << endl;
		cout << "Exit program" << endl;
	}
	else
	{

		while (!file.eof())// will search the hole file line by line to find the site inputed
		{
			getline(file, readfile);
			line++;// Variable need for finding what line the site was found from the file

			if (readfile == inputsite)
			{
				flag = true;

				cout << "The site is included in the forbidden sites list of the National Betting Authority\n";
				cout << "The prohibited site was found on line: " << line << " Of the list"<<endl;
				break;
			}

		}
	}
	if (flag == false)// if it doesnt find a site with that name, flag will stay false, so site not found
	{
		cout << "The site you entered is NOT included in the list of forbidden sites\n";
	}
	file.close();


}

// Driver code
int main()
{
	string inputsite;
	string yesorno;

	cout << "Enter the site to check if it is included in the black list: \n";
	cin >> inputsite;
	checkfun(inputsite);
	cout << endl;
	cout << "Do you want to search a new site? (yes or no)\n";
	cin >> yesorno;
	if (yesorno == "no")
	{
		cout << "Goodbye (:";
		return 0;

	}
	while (yesorno == "yes")
	{
		cout << "Enter the site to check if it is included in the black list: \n";
		cin >> inputsite;
		checkfun(inputsite);
		cout << endl;
		cout << "Do you want to search a new site? (yes or no)\n";
		cin >> yesorno;
		if (yesorno == "no")
		{
			cout << "Goodbye (:";
			return 0;

		}
	}
	return 0;
}