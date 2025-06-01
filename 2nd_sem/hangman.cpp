#include<iostream>
#include<set>
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<ctime>
using namespace std;

string THEME() {
	cout << "Choose one of those themes:" << endl;
	cout << "1) Music" << endl << "2) Transport" << endl << "3) Capitals" << endl << "4) CS players" << endl << "5) Star Wars charachters" << endl;
	int n;
	cin >> n;
	switch (n) {
	case 1:
		return "music";
		break;
	case 2:
		return "transport";
		break;
	case 3:
		return "capitals";
		break;
	case 4:
		return "csplayers";
		break;
	case 5:
		return "starwars";
		break;
	}
}

void CLEAR() {
	for (int i = 0; i < 100; i++) cout << endl;
}


void PICTURE(int misses) {
	vector<vector<string>> GG = {
		{"  ____  ",
		 "   |  | ",
		 "      | ",
		 "      | ",
		 "      | ",
		 "      | ",
		 "--------"},
		{"  ____  ",
		 "   |  | ",
		 "   0  | ",
		 "      | ",
		 "      | ",
		 "      | ",
		 "--------"},
		{"  ____  ",
		 "   |  | ",
		 "   0  | ",
		 "   |  | ",
		 "      | ",
		 "      | ",
		 "--------"},
		{"  ____  ",
		 "   |  | ",
		 "   0  | ",
		 "  /|  | ",
		 "      | ",
		 "      | ",
		 "--------"},
		{"  ____  ",
		 "   |  | ",
		 "   0  | ",
		 "  /|| | ",
		 "      | ",
		 "      | ",
		 "--------"},
		{"  ____  ",
		 "   |  | ",
		 "   0  | ",
		 "  /|| | ",
		 "  /   | ",
		 "      | ",
		 "--------"},
		{"  ____  ",
		 "   |  | ",
		 "   0  | ",
		 "  /|| | ",
		 "  //  | ",
		 "      | ",
		 "--------"}
	};
	for (const auto a : GG[misses])
		cout << a << endl;
}

int main() {
	map<string, string> Wthemes;
	vector<string> words;
	set<string> themes;
	string str;
	int misses = 0;
	int max_tries = 6;
	string letters = "a b c d e f g h i j k l m n o p q r s t u v w x y z =";

	ifstream input("C:/Users/user/Desktop/words_hm.txt");    //4tenie fayla
	if (!input.is_open()) {
		cout << "Something went wrong with the file" << endl;
		return 0;
	}

	while (getline(input, str)) {                            //raspredelenie 
		themes.insert(str.substr(str.find_first_of("-") + 1, str.length()));
		words.push_back(str.substr(0, str.find_first_of("-")));
		Wthemes[str.substr(0, str.find_first_of("-"))] = str.substr(str.find_first_of("-") + 1, str.length());
	}

	string theme;
	string word;
	srand(time(NULL));
	theme = THEME();
	vector<string> WORDS;
	for (const auto pair : Wthemes)
		if (pair.second == theme)
			WORDS.push_back(pair.first);
	word = WORDS[rand() % WORDS.size()];

	string user_word(word.size(), '_');
	while (misses < max_tries && user_word != word) {
		CLEAR();
		PICTURE(misses);
		cout << endl << "Your condition: " << user_word << endl;
		cout << "Available letters: " << letters << endl;
		cout << "Guess the letter / the whole word: " << endl;

		string user_try;
		cin >> user_try;
		if (user_try.length() == 1) {
			char user_letter = user_try[0];
			size_t pos = word.find(user_letter);
			if (letters.find(user_letter) >= 0 && letters.find(user_letter) <= 52) letters.erase(letters.find(user_letter), 2);
			else {
				cout << "You've already tried this letter. Try another one" << endl;

			}

			if (pos >= 0 && pos <= 52) {
				for (size_t i = 0; i < word.size(); i++) if (word[i] == user_letter) user_word[i] = user_letter;
			}
			else {
				cout << "No such letter" << endl;
				misses++;
			}
		}
		else {
			if (user_try == word) {
				CLEAR();
				cout << "HURRAAAAAH: " << word << endl;
				return 0;
			}
			else {
				CLEAR();
				cout << "You'd got him killed... You had to guess " << word << endl;
				PICTURE(6);
				return 0;
			}
		}
	}
	CLEAR();
	if (user_word == word) cout << "HURRAAAAAH: " << word << endl;
	else {
		cout << "You'd got him killed... You had to guess " << word << endl;
		PICTURE(6);
}
	return 0;
}