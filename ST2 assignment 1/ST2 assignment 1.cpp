#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void openInputFile(ifstream& inFile);
void openInputFile1(ifstream& inFile);
void readIntoVector(ifstream& inFile, vector<string>& vec, int& recordCount);
bool compareAccounts(string l1, string l2);
void swap(string& i, string& j);
void readIntoVector1(ifstream& inFile, vector<string>& vec, int& recordCount);


#define dir "D:\\BB\\University2022\\ST2_2022\\Assignment1\\"

string FNAME_BASE = "NamesdataA1.csv";
string FNAME_TARGET = "NamesdataA2Txt.txt";
string FNAME1 = "NamesdataA1Txttst.txt";
string FNAME2 = "NamesdataA1Txt.txt";
string FNAME3 = "NamesdataA2Txt.txt";
string FNAME4 = "NamesdataA1txtbaddata.txt";
string FNAME5 = "NamesdataA1Txtdupid.txt";
string FNAME6 = "NamesdataA1TxtFraud.txt";
string ffname = "";

void doFilenames()
{
	FNAME1 = string(dir) + FNAME1;
	FNAME2 = string(dir) + FNAME2;
	FNAME3 = string(dir) + FNAME3;
	FNAME4 = string(dir) + FNAME4;
	FNAME5 = string(dir) + FNAME5;
	FNAME6 = string(dir) + FNAME6;
}
std::string trim(const std::string& str,
	const std::string& whitespace = " \t")
{
	
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content
	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;
	return str.substr(strBegin, strRange);
}











int main()
{
	cout << "Assignment1 2022" << endl;
	cout << "" << endl;
	string salesStaff[] = { "Brad", "Janet", "Dr Scott", "Rifraf", "Nell", "Eddie" };
	string userinput;
	int userinput2;
	userinput2 = 1, 2, 3, 4, 5, 6;
	char again = 'Y';
	userinput == "SHOW", "C", "R", "F", "A", "D", "S";
	while (userinput == "SHOW", "C", "R", "F", "A", "D", "S" || again == 'Y') {
		cout << "Assignment1 2022" << endl;
		cout << "" << endl;
		cout << "Assignment1 2002 Menu" << endl;
		cout << "---------------------" << endl;
		cout << "E(xit)   -   Exit" << endl;
		
		cout << "C(heck)  -   Check File details" << endl;
		cout << "R(ead)   -   Read File" << endl;
		
		cout << "F(raud)  -   Search for sales fraud" << endl;
		
		cout << "S(ort)   -   Sort on accout number" << endl;
		cin >> userinput;
		if (userinput == "R") {
			cout << "Which file do you want to read?" << endl;
			cout << "" << endl;
			cout << "1. " << FNAME1 << endl;
			cout << "2. " << FNAME2 << endl;
			cout << "3. " << FNAME3 << endl;
			cout << "4. " << FNAME4 << endl;
			cout << "5. " << FNAME5 << endl;
			cout << "6. " << FNAME6 << endl;
			cin >> userinput2;
			if (userinput2 == 1) {
				fstream myFile;
				myFile.open(FNAME1, ios::in);
				string line;
				while (getline(myFile, line)) {
					cout << line << endl;
				}


			}
			else if (userinput2 == 2) {
				fstream myFile;
				myFile.open(FNAME2, ios::in);
				string line;
				while (getline(myFile, line)) {
					cout << line << endl;
				}


			}
			else if (userinput2 == 3) {
				fstream myFile;
				myFile.open(FNAME3, ios::in);
				string line;
				while (getline(myFile, line)) {
					cout << line << endl;
				}


			}
			else if (userinput2 == 4) {
				fstream myFile;
				myFile.open(FNAME4, ios::in);
				string line;
				while (getline(myFile, line)) {
					cout << line << endl;
				}


			}
			else if (userinput2 == 5) {
				fstream myFile;
				myFile.open(FNAME5, ios::in);
				string line;
				while (getline(myFile, line)) {
					cout << line << endl;
				}


			}
			else if (userinput2 == 6) {
				fstream myFile;
				myFile.open(FNAME6, ios::in);
				string line;
				while (getline(myFile, line)) {
					cout << line << endl;
				}


			}






		}
		
		else if (userinput == "E") {
			cout << "" << endl;
			cout << "thnk you!" << endl;
			exit(0);

		}
		else if (userinput == "F") {
			
			ifstream inFile;
			openInputFile(inFile);
			vector<string> vec;
			int recordCount = 0;
			readIntoVector(inFile, vec, recordCount);

			int fraudCount = 0;
			cout << "Count of records: " << recordCount << endl;
			for (auto it = vec.begin(); it != vec.end(); it++) {
				string line = *it;
				int comma5thPosition = 5;
				int indexOf5thComma = -1;
				while (comma5thPosition-- > 0) {
					indexOf5thComma = line.find(",", indexOf5thComma + 1);
				}
				int indexOf6thComma = line.find(",", indexOf5thComma + 1);
				int indexOf7thComma = line.find(",", indexOf6thComma + 1);
				int lengthOf7thdata = indexOf7thComma - indexOf6thComma + 1;
				string strData7th = line.substr(indexOf6thComma + 1, lengthOf7thdata);
				double sales = stod(strData7th);
				int indexOf8thComma = line.find(",", indexOf7thComma + 1);
				int indexOf9thComma = line.find(",", indexOf8thComma + 1);
				int lengthOf9thdata = indexOf9thComma - indexOf8thComma + 1;
				string strData9th = line.substr(indexOf8thComma + 1, lengthOf9thdata);
				double commission = stod(strData9th);
				if (commission > 0.11 * sales) {
					fraudCount++;
					string accountDetails = line.substr(0, indexOf5thComma);
					cout << "Fraud account ";
					for (int i = 0; i < accountDetails.length(); i++)
						(accountDetails[i] != ',') ? cout << accountDetails[i] : cout << " ";
					cout << endl;
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << "Sales value is: " << sales << endl;
					cout << "Commission is: " << commission << endl;
					cout << "Reasonable value is: " << (0.11 * sales) << endl;
				}
			}
			cout << "Total count of fraud is: " << fraudCount << endl;

		}
		else if (userinput == "S") {
		ifstream inFile;
		openInputFile1(inFile);
		vector<string> vec;
		int recordCount = 0;
		readIntoVector1(inFile, vec, recordCount);
		int swapCount = 0;
		int comparisonCount = 0;

		
		for (int i = 0; i < recordCount - 1; i++) {
			for (int j = 0; j < recordCount - 1 - i; j++) {
				comparisonCount++;
				if (compareAccounts(vec[j], vec[j + 1])) {
					swapCount++;
					swap(vec[j], vec[j + 1]);
				}
			}
		}
		
		cout << "Number of comparisons: " << comparisonCount << endl;
		cout << "Number of swaps: " << swapCount << endl;
		cout << "Sort testing First[0] " << vec[0] << endl;
		cout << "Sort testing First[9] " << vec[9] << endl;
		cout << "Sort testing Last " << vec[recordCount - 1] << endl;
		cout << endl;

		for (int i = 0; i < recordCount; i++)
			cout << "[" << i << "] = " << vec[i] << endl;

}
		else if (userinput == "C") {
		ifstream fin;
		int userinput3;
		string filename, line;
		int lines, tags, comments, links, totalChars, charsInTags;
		bool tagOpen = false;


		lines = tags = comments = links = totalChars = charsInTags = 0;
		cout << "Which file do you want to check?" << endl;
		cout << "" << endl;
		cout << "1. " << FNAME1 << endl;
		cout << "2. " << FNAME2 << endl;
		cout << "3. " << FNAME3 << endl;
		cout << "4. " << FNAME4 << endl;
		cout << "5. " << FNAME5 << endl;
		cout << "6. " << FNAME6 << endl;
		cout << "" << endl;
		cout << "" << endl;
		cin >> userinput3;
		if (userinput3 == 1) {
			filename = FNAME1;
		}
		if (userinput3 == 2) {
			filename = FNAME2;
		}
		if (userinput3 == 3) {
			filename = FNAME3;
		}
		if (userinput3 == 4) {
			filename = FNAME4;
		}
		if (userinput3 == 5) {
			filename = FNAME5;
		}
		if (userinput3 == 6) {
			filename = FNAME6;
		}

		fin.open(filename.c_str());




		cout << "\nAll lines of the file\n\n";


		while (!fin.fail()) {


			getline(fin, line);


			cout << line << "\n";


			lines++;
			totalChars += line.size() + 1;


			int i = 0;


		}

		fin.close();
		lines--;
		totalChars--;




		cout << "Processing:  " << filename << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "Checking report" << endl;
		cout << "---------------" << endl;
		cout << "Number of lines: " << lines << endl;
		cout << "Number of chars in file : " << totalChars << endl;
		cout << "" << endl;
		cout << "" << endl;

}
		
		







	}



	







	return 0;

}
void openInputFile(ifstream& inFile) {
	
	string inFileName;
	inFileName = "NamesdataA1TxtFraud.txt";
	inFile.open(inFileName);
	
}
void openInputFile1(ifstream& inFile) {

	string inFileName;
	inFileName = "NamesdataA1Txttst.txt";
	inFile.open(inFileName);

}
void readIntoVector(ifstream& inFile, vector<string>& vec, int& recordCount) {
	string line;
	while (getline(inFile, line)) {
		if (line != "") {
			vec.push_back(line);
			recordCount++;
		}
	}
	inFile.close();
}
bool compareAccounts(string l1, string l2) {
	string strAccount1 = l1.substr(0, l1.find(" ", 0));
	int accountNumber1 = stoi(strAccount1);
	string strAccount2 = l2.substr(0, l2.find(" ", 0));
	int accountNumber2 = stoi(strAccount2);
	return accountNumber1 > accountNumber2;
}

void swap(string& i, string& j) {
	string temp = i;
	i = j;
	j = temp;
}

void readIntoVector1(ifstream& inFile, vector<string>& vec, int& recordCount) {
	string line;
	while (getline(inFile, line)) {
		if (line != "") {
			recordCount++;
			int comma5thPosition = 5;
			int indexOf5thComma = -1;
			while (comma5thPosition-- > 0) {
				indexOf5thComma = line.find(",", indexOf5thComma + 1);
			}
			string accountDetails = line.substr(0, indexOf5thComma);
			string x = ",", y = " ";
			size_t pos;
			while ((pos = accountDetails.find(x)) != string::npos) {
				accountDetails.replace(pos, 1, y);
			}
			vec.push_back(accountDetails);
		}
	}
	inFile.close();
}




