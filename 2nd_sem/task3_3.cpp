#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std; 
ifstream input_file("C:/Users/user/Desktop/data.txt");
ofstream output_file("C:/Users/user/Desktop/out.txt");

struct staff {
	string surname;
	string position;
	string date;
	int experience;
	int salary;
};

vector<staff> get_data() {
	vector<staff> str;
	staff a;
	while (input_file.peek() != EOF) {
		input_file >> a.surname;
		input_file >> a.position;
		input_file >> a.date;
		input_file >> a.experience;
		input_file >> a.salary;
		str.push_back(a);
	}
	return str;
}

void release_data(staff a) {
    output_file << left << a.surname << " ";
    output_file << left << a.position << " ";
    output_file << left << a.date << " ";
    output_file << left << a.experience << " ";
    output_file << left << a.salary << endl;
}


int get_year(const string& date) {
    return stoi(date.substr(6, 10));
}

bool date_check(const string& date1, const string& date2) {
    int day1 = stoi(date1.substr(0, 2));
    int month1 = stoi(date1.substr(3, 2));
    int year1 = stoi(date1.substr(6, 4));

    int day2 = stoi(date2.substr(0, 2));
    int month2 = stoi(date2.substr(3, 2));
    int year2 = stoi(date2.substr(6, 4));

    if (year1 != year2) return year1 < year2;
    if (month1 != month2) return month1 < month2;
    return day1 < day2;
}
    
void shakerSort(vector<staff>& arr) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;

    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (date_check(arr[i + 1].date, arr[i].date)) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break; 

        swapped = false;
        end--; 

        for (int i = end - 1; i >= start; i--) {
            if (date_check(arr[i + 1].date, arr[i].date)) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        start++;
    }
}




int main() {
    vector<staff> a;
    a = get_data();
    shakerSort(a);
    for (int i = 0; i < a.size(); i++) release_data(a[i]);
    input_file.close();
    output_file.close();

    return 0;
}