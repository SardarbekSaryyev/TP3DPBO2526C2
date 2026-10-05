#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    virtual ~Person() {}
    virtual string role() const = 0;
    virtual string detail() const = 0;

    void display() const {
        cout << "  - [" << role() << "] " << name << ", " << age << " tahun, " << detail() << endl;
    }
};

class Doctor : public Person {
private:
    string specialty;

public:
    Doctor(string name, int age, string specialty) : Person(name, age), specialty(specialty) {}
    string role() const override { return "Dokter"; }
    string detail() const override { return "spesialis " + specialty; }
};

class Nurse : public Person {
private:
    string shift;

public:
    Nurse(string name, int age, string shift) : Person(name, age), shift(shift) {}
    string role() const override { return "Perawat"; }
    string detail() const override { return "shift " + shift; }
};

class Patient : public Person {
private:
    string diagnosis;
    int room;

public:
    Patient(string name, int age, string diagnosis, int room) : Person(name, age), diagnosis(diagnosis), room(room) {}
    string role() const override { return "Pasien"; }
    string detail() const override { return "diagnosis " + diagnosis + ", kamar " + to_string(room); }
};

class Department {
private:
    string name;
    vector<Doctor> doctors;
    vector<Nurse> nurses;
    vector<Patient> patients;

public:
    Department(string name) : name(name) {}

    string getName() const { return name; }
    void addDoctor(const Doctor &d) { doctors.push_back(d); }
    void addNurse(const Nurse &n) { nurses.push_back(n); }
    void addPatient(const Patient &p) { patients.push_back(p); }

    void display() const {
        cout << "Departemen " << name << endl;
        vector<const Person *> all;
        for (const Doctor &d : doctors) all.push_back(&d);
        for (const Nurse &n : nurses) all.push_back(&n);
        for (const Patient &p : patients) all.push_back(&p);
        for (const Person *p : all) p->display();
        cout << "  Total: " << doctors.size() << " dokter, " << nurses.size() << " perawat, " << patients.size() << " pasien" << endl;
    }
};

class Hospital {
private:
    string name;
    vector<Department> departments;

public:
    Hospital(string name) : name(name) {}

    void addDepartment(string deptName) {
        departments.push_back(Department(deptName));
    }

    Department *findDepartment(string deptName) {
        for (Department &d : departments) {
            if (d.getName() == deptName) return &d;
        }
        return nullptr;
    }

    void display() const {
        cout << "=== Rumah Sakit " << name << " ===" << endl;
        for (const Department &d : departments) {
            d.display();
            cout << endl;
        }
    }
};

int main() {
    Hospital hospital("Harapan Sehat");

    hospital.addDepartment("Kardiologi");
    hospital.addDepartment("Anak");

    hospital.findDepartment("Kardiologi")->addDoctor(Doctor("dr. Rina Wijaya", 42, "jantung"));
    hospital.findDepartment("Kardiologi")->addNurse(Nurse("Sari Lestari", 29, "pagi"));
    hospital.findDepartment("Kardiologi")->addPatient(Patient("Budi Santoso", 55, "hipertensi", 101));

    hospital.findDepartment("Anak")->addDoctor(Doctor("dr. Andi Pratama", 38, "anak"));
    hospital.findDepartment("Anak")->addNurse(Nurse("Dewi Anggraini", 27, "malam"));
    hospital.findDepartment("Anak")->addPatient(Patient("Kevin Aditya", 7, "demam berdarah", 205));

    cout << "##### DATA SEBELUM DITAMBAHKAN #####" << endl << endl;
    hospital.display();

    hospital.addDepartment("Saraf");

    hospital.findDepartment("Kardiologi")->addPatient(Patient("Siti Aminah", 61, "gagal jantung", 102));
    hospital.findDepartment("Anak")->addDoctor(Doctor("dr. Maya Putri", 35, "neonatologi"));
    hospital.findDepartment("Saraf")->addDoctor(Doctor("dr. Hendra Gunawan", 47, "saraf"));
    hospital.findDepartment("Saraf")->addNurse(Nurse("Lina Marlina", 31, "siang"));
    hospital.findDepartment("Saraf")->addPatient(Patient("Agus Setiawan", 49, "migrain kronis", 303));

    cout << "##### DATA SESUDAH DITAMBAHKAN #####" << endl << endl;
    hospital.display();

    return 0;
}