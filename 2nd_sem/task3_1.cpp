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


void bucketSort(vector<staff>& arr) {
    if (arr.empty()) return;
    int min_exp = arr[0].experience;
    int max_exp = arr[0].experience;
    for (const auto& emp : arr) {
        if (emp.experience < min_exp) min_exp = emp.experience;
        if (emp.experience > max_exp) max_exp = emp.experience;
    }

    size_t bucketCount = arr.size();
    vector<vector<staff>> buckets(bucketCount);

    for (const auto& emp : arr) {
        int bucketIndex = static_cast<int>((emp.experience - min_exp) * (bucketCount - 1) / (max_exp - min_exp));
        buckets[bucketIndex].push_back(emp);
    }
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end(), [](const staff& a, const staff& b) {
            return a.experience < b.experience;
            });
    }
    int index = 0;
    for (const auto& bucket : buckets) {
        for (const auto& emp : bucket) {
            arr[index++] = emp;
        }
    }
}



int main() {
    vector<staff> a;
    a = get_data();
    bucketSort(a);
    for (int i = 0; i < a.size(); i++) release_data(a[i]);
    input_file.close();
    output_file.close();

    return 0;
}