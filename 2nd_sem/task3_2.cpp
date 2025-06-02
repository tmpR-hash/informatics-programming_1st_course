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

void merge(vector<staff>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<staff> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        int yearL = get_year(L[i].date);
        int yearR = get_year(R[j].date);

        if (L[i].salary < R[j].salary || (L[i].salary == R[j].salary && yearL < yearR)) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<staff>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main() {
    vector<staff> a;
    a = get_data();
    mergeSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++) release_data(a[i]);
    input_file.close();
    output_file.close();

    return 0;
}