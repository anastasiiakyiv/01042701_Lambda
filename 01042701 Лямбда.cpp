/*
Створіть клас Студенти, який зберігатиме ім’я, прізвище і середній бал студента. Створіть масив (вектор) студентів і функцію для
пошуку студента з найбільшим балом. В головній функції виведіть на екран ім’я знайденого студента. Функція std::max_element()
приймає ітератори початку і кінця контейнера для пошуку, і вказівник на функцію або лямбду з двома параметрами, яка повертає
істину, якщо перший аргумент менший за другий.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Student {
private:
	std::string firstName;
	std::string lastName;
	double gradePointAverage;
public:
	Student(std::string FN, std::string LN, double GPA) :
		firstName(FN), lastName(LN), gradePointAverage(GPA) {}

	std::string getFirstName() const {
		return firstName;
	}

	std::string getLastName() const {
		return lastName;
	}

	double getGPA() const {
		return gradePointAverage;
	}
};

class Students {
private:
	std::vector<Student> students;
public:
	void addStudent(const Student& newStudent) {
		students.push_back(newStudent);
	}

	std::string findBestStudent() const {
		auto bestStudent = std::max_element(students.begin(), students.end(),
			[](const Student& a, const Student& b) {
				return a.getGPA() < b.getGPA();
			});

		if (bestStudent != students.end()) {
			return bestStudent->getFirstName() + " " + bestStudent->getLastName();
		}
		else {
			return "No students in the list";
		}
	}
};

int main() {
	Students studentList;

	Student student1("Mariana", "Tkachenko", 10.7);
	Student student2("Sergii", "Mykolaenko", 11.2);
	Student student3("Yevgen", "Guducshan", 9.5);
	Student student4("Viktor", "Sergijchuk", 9.7);

	studentList.addStudent(student1);
	studentList.addStudent(student2);
	studentList.addStudent(student3);
	studentList.addStudent(student4);

	std::string bestStudent = studentList.findBestStudent();

	std::cout << "The student with the highest GPA: " << bestStudent << std::endl;
	
	return 0;
}