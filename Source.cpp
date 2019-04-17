// C++ program to remove comments from a C/C++ program 
#include <iostream> 
#include <fstream>
#include <vector>
using namespace std;

// ===============================================================================
string removeComments(vector<char> prgm)
{
	int n = prgm.size();
	string res;

	// Flags to indicate that single line and multpile line comments 
	// have started or not. 
	bool single_comment = false;
	bool multi_comment = false;
	bool isQuote = false;


	// Traverse the given program 
	for (int i = 0; i < n; i++)
	{
		// If single line comment flag is on, then check for end of it 
		if (single_comment == true && prgm[i] == '\n') {
			single_comment = false;
		}

		// If multiple line comment is on, then check for end of it 
		else if (multi_comment == true && prgm[i] == '!' && prgm[i + 1] == '!') {
			multi_comment = false, i++;
		}

		// If this character is in a comment, ignore it 
		else if (single_comment || multi_comment) {
			continue;
		}

		// Check for beginning of comments and set the approproate flags 
		else if (prgm[i] == '!' && prgm[i + 1] == '-') {
			single_comment = true, i++;

		}
		else if (prgm[i] == '!' && prgm[i + 1] == '!') {
			multi_comment = true, i++;
		}



		// If current character is a non-comment character, append it to res 
		else  res += prgm[i];
	}
	return res;
}
//==========================================================================================

// Driver program to test above functions 
//======================================================
int main()
{
	// input file
	// ----------------------------------
	fstream infile;
	infile.open("Input.txt", ios::in);
	// ----------------------------------

	vector<char> text;
	while (!infile.eof()) {
		text.push_back(infile.get());
	}

	for (int i = 0; i < text.size() - 1; i++) {
		std::cout << text[i];
	}
	cout << endl;
	cout << " Modified Program \n";
	cout << removeComments(text);

	return 0;
}
//=======================================================