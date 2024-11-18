#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Base Class: Student
class Student {
protected:
    std::string first_name;
    std::string last_name;
    double gpa;
    int graduation_year;
    std::string graduation_semester;
    int enrolled_year;
    std::string enrolled_semester;
    std::string level; // Undergraduate or Graduate
public:
    Student();
    virtual ~Student();

    // Setters
    void setFirstName(const std::string& first);
    void setLastName(const std::string& last);
    void setGPA(double gpa_val);
    void setGraduationYear(int year);
    void setGraduationSemester(const std::string& semester);
    void setEnrolledYear(int year);
    void setEnrolledSemester(const std::string& semester);
    void setLevel(const std::string& lvl);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    double getGPA() const;
    int getGraduationYear() const;
    std::string getGraduationSemester() const;
    int getEnrolledYear() const;
    std::string getEnrolledSemester() const;
    std::string getLevel() const;

    virtual void displayInfo(std::ofstream& out) const; // Virtual function for polymorphism
};

// Implementation of Base Class
Student::Student()
    : first_name("Unknown"), last_name("Unknown"), gpa(0.0), graduation_year(0),
      graduation_semester("Unknown"), enrolled_year(0), enrolled_semester("Unknown"),
      level("Unknown") {}

Student::~Student() {}

void Student::setFirstName(const std::string& first) { first_name = first; }
void Student::setLastName(const std::string& last) { last_name = last; }
void Student::setGPA(double gpa_val) { gpa = gpa_val; }
void Student::setGraduationYear(int year) { graduation_year = year; }
void Student::setGraduationSemester(const std::string& semester) { graduation_semester = semester; }
void Student::setEnrolledYear(int year) { enrolled_year = year; }
void Student::setEnrolledSemester(const std::string& semester) { enrolled_semester = semester; }
void Student::setLevel(const std::string& lvl) { level = lvl; }

std::string Student::getFirstName() const { return first_name; }
std::string Student::getLastName() const { return last_name; }
double Student::getGPA() const { return gpa; }
int Student::getGraduationYear() const { return graduation_year; }
std::string Student::getGraduationSemester() const { return graduation_semester; }
int Student::getEnrolledYear() const { return enrolled_year; }
std::string Student::getEnrolledSemester() const { return enrolled_semester; }
std::string Student::getLevel() const { return level; }

void Student::displayInfo(std::ofstream& out) const {
    out << "Name: " << first_name << " " << last_name << "\n";
    out << "GPA: " << gpa << "\n";
    out << "Graduation: " << graduation_semester << " " << graduation_year << "\n";
    out << "Enrolled: " << enrolled_semester << " " << enrolled_year << "\n";
    out << "Level: " << level << "\n";
}

// Derived Class: Art_Student
class Art_Student : public Student {
    std::string art_emphasis;
public:
    Art_Student();
    ~Art_Student();

    void setArtEmphasis(const std::string& emphasis);
    std::string getArtEmphasis() const;

    void displayInfo(std::ofstream& out) const override;
};

// Implementation of Art_Student
Art_Student::Art_Student() : art_emphasis("Unknown") {}
Art_Student::~Art_Student() {}

void Art_Student::setArtEmphasis(const std::string& emphasis) { art_emphasis = emphasis; }
std::string Art_Student::getArtEmphasis() const { return art_emphasis; }

void Art_Student::displayInfo(std::ofstream& out) const {
    Student::displayInfo(out);
    out << "Art Emphasis: " << art_emphasis << "\n";
}

// Derived Class: Physics_Student
class Physics_Student : public Student {
    std::string concentration;
public:
    Physics_Student();
    ~Physics_Student();

    void setConcentration(const std::string& conc);
    std::string getConcentration() const;

    void displayInfo(std::ofstream& out) const override;
};

// Implementation of Physics_Student
Physics_Student::Physics_Student() : concentration("Unknown") {}
Physics_Student::~Physics_Student() {}

void Physics_Student::setConcentration(const std::string& conc) { concentration = conc; }
std::string Physics_Student::getConcentration() const { return concentration; }

void Physics_Student::displayInfo(std::ofstream& out) const {
    Student::displayInfo(out);
    out << "Concentration: " << concentration << "\n";
}

// Main function
int main() {
    std::vector<Art_Student*> art_students;
    std::vector<Physics_Student*> physics_students;

    // Create Art_Student objects
    Art_Student* art1 = new Art_Student;
    art1->setFirstName("Alice");
    art1->setLastName("Michael");
    art1->setGPA(3.8);
    art1->setArtEmphasis("Art History");
    art1->setGraduationYear(2025);
    art1->setGraduationSemester("Spring");
    art1->setEnrolledYear(2021);
    art1->setEnrolledSemester("Fall");
    art1->setLevel("Undergraduate");
    art_students.push_back(art1);

    Art_Student* art2 = new Art_Student;
    art2->setFirstName("Bob");
    art2->setLastName("Frank");
    art2->setGPA(3.6);
    art2->setArtEmphasis("Art Studio");
    art2->setGraduationYear(2024);
    art2->setGraduationSemester("Fall");
    art2->setEnrolledYear(2020);
    art2->setEnrolledSemester("Spring");
    art2->setLevel("Undergraduate");
    art_students.push_back(art2);

    Art_Student* art3 = new Art_Student;
    art3->setFirstName("Cathy");
    art3->setLastName("Miller");
    art3->setGPA(3.7);
    art3->setArtEmphasis("Art Education");
    art3->setGraduationYear(2026);
    art3->setGraduationSemester("Winter");
    art3->setEnrolledYear(2022);
    art3->setEnrolledSemester("Summer");
    art3->setLevel("Undergraduate");
    art_students.push_back(art3);

    Art_Student* art4 = new Art_Student;
    art4->setFirstName("David");
    art4->setLastName("Jones");
    art4->setGPA(3.9);
    art4->setArtEmphasis("Art Studio");
    art4->setGraduationYear(2023);
    art4->setGraduationSemester("Summer");
    art4->setEnrolledYear(2019);
    art4->setEnrolledSemester("Fall");
    art4->setLevel("Graduate");
    art_students.push_back(art4);

    Art_Student* art5 = new Art_Student;
    art5->setFirstName("Emma");
    art5->setLastName("Chris");
    art5->setGPA(4.0);
    art5->setArtEmphasis("Art History");
    art5->setGraduationYear(2025);
    art5->setGraduationSemester("Spring");
    art5->setEnrolledYear(2021);
    art5->setEnrolledSemester("Spring");
    art5->setLevel("Undergraduate");
    art_students.push_back(art5);

    // Create Physics_Student objects
    Physics_Student* phys1 = new Physics_Student;
    phys1->setFirstName("Frank");
    phys1->setLastName("Newton");
    phys1->setGPA(3.9);
    phys1->setConcentration("Biophysics");
    phys1->setGraduationYear(2024);
    phys1->setGraduationSemester("Fall");
    phys1->setEnrolledYear(2020);
    phys1->setEnrolledSemester("Spring");
    phys1->setLevel("Undergraduate");
    physics_students.push_back(phys1);

    Physics_Student* phys2 = new Physics_Student;
    phys2->setFirstName("Grace");
    phys2->setLastName("Einstein");
    phys2->setGPA(3.85);
    phys2->setConcentration("Earth and Planetary Sciences");
    phys2->setGraduationYear(2025);
    phys2->setGraduationSemester("Spring");
    phys2->setEnrolledYear(2021);
    phys2->setEnrolledSemester("Fall");
    phys2->setLevel("Undergraduate");
    physics_students.push_back(phys2);

    Physics_Student* phys3 = new Physics_Student;
    phys3->setFirstName("Henry");
    phys3->setLastName("Hawking");
    phys3->setGPA(3.75);
    phys3->setConcentration("Biophysics");
    phys3->setGraduationYear(2023);
    phys3->setGraduationSemester("Summer");
    phys3->setEnrolledYear(2019);
    phys3->setEnrolledSemester("Fall");
    phys3->setLevel("Graduate");
    physics_students.push_back(phys3);

    Physics_Student* phys4 = new Physics_Student;
    phys4->setFirstName("Ivy");
    phys4->setLastName("Curie");
    phys4->setGPA(4.0);
    phys4->setConcentration("Earth and Planetary Sciences");
    phys4->setGraduationYear(2026);
    phys4->setGraduationSemester("Winter");
    phys4->setEnrolledYear(2022);
    phys4->setEnrolledSemester("Spring");
    phys4->setLevel("Undergraduate");
    physics_students.push_back(phys4);

    Physics_Student* phys5 = new Physics_Student;
    phys5->setFirstName("Jack");
    phys5->setLastName("Galileo");
    phys5->setGPA(3.8);
    phys5->setConcentration("Biophysics");
    phys5->setGraduationYear(2025);
    phys5->setGraduationSemester("Spring");
    phys5->setEnrolledYear(2021);
    phys5->setEnrolledSemester("Fall");
    phys5->setLevel("Undergraduate");
    physics_students.push_back(phys5);

    // Write data to file
    std::ofstream outfile("student_info.dat");
    for (const auto& student : art_students) {
        student->displayInfo(outfile);
        outfile << "\n";
    }
    for (const auto& student : physics_students) {
        student->displayInfo(outfile);
        outfile << "\n";
    }
    outfile.close();

    // Cleanup dynamically allocated memory
    for (auto& student : art_students) {
        delete student;
    }
    for (auto& student : physics_students) {
        delete student;
    }

    return 0;
}
