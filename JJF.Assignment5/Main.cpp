
// Assignment 5 - Math Quiz
// Jordan Fredericks

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string filepath = "Quiz.txt";
	string filepath2 = "QuizResults.txt";

	ifstream ifs(filepath);
	string line;
	string problem[10]; // array to store the problems

	int count = 0; //Counter for the while loop

	//Gets each problem and adds it to an array
	while (getline(ifs, line))
	{
		problem[count] = line;
		count++;
	}

	cout << "Welcome to the Math Quiz!\n";

	ofstream ofs(filepath2); // Open the results file
	
	srand(time(NULL));// seed the rand
	
	for (int i = 0; i < 3; i++)
	{
		int answer = 0;
		int randomNumber = rand() % 10 + 1;
		cout << "\nQuestion " << i + 1 << ": " << problem[randomNumber - 1] << " =\n" << "Enter your answer: ";
		cin >> answer;
		ofs << problem[randomNumber - 1] << " = " << answer << "\n";
	}
	ofs.close();

	cout << "\nResults saved to QuizResults.txt";
	

	(void)_getch();
	return 0;
}
