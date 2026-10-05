from abc import ABC, abstractmethod


class Person(ABC):
    def __init__(self, name, age):
        self._name = name
        self._age = age

    @abstractmethod
    def role(self):
        pass

    @abstractmethod
    def detail(self):
        pass

    def display(self):
        print(f"  - [{self.role()}] {self._name}, {self._age} tahun, {self.detail()}")


class Doctor(Person):
    def __init__(self, name, age, specialty):
        super().__init__(name, age)
        self.__specialty = specialty

    def role(self):
        return "Dokter"

    def detail(self):
        return f"spesialis {self.__specialty}"


class Nurse(Person):
    def __init__(self, name, age, shift):
        super().__init__(name, age)
        self.__shift = shift

    def role(self):
        return "Perawat"

    def detail(self):
        return f"shift {self.__shift}"


class Patient(Person):
    def __init__(self, name, age, diagnosis, room):
        super().__init__(name, age)
        self.__diagnosis = diagnosis
        self.__room = room

    def role(self):
        return "Pasien"

    def detail(self):
        return f"diagnosis {self.__diagnosis}, kamar {self.__room}"


class Department:
    def __init__(self, name):
        self.__name = name
        self.__doctors = []
        self.__nurses = []
        self.__patients = []

    def get_name(self):
        return self.__name

    def add_doctor(self, doctor):
        self.__doctors.append(doctor)

    def add_nurse(self, nurse):
        self.__nurses.append(nurse)

    def add_patient(self, patient):
        self.__patients.append(patient)

    def display(self):
        print(f"Departemen {self.__name}")
        for person in self.__doctors + self.__nurses + self.__patients:
            person.display()
        print(f"  Total: {len(self.__doctors)} dokter, {len(self.__nurses)} perawat, {len(self.__patients)} pasien")


class Hospital:
    def __init__(self, name):
        self.__name = name
        self.__departments = []

    def add_department(self, dept_name):
        department = Department(dept_name)
        self.__departments.append(department)
        return department

    def find_department(self, dept_name):
        for department in self.__departments:
            if department.get_name() == dept_name:
                return department
        return None

    def display(self):
        print(f"=== Rumah Sakit {self.__name} ===")
        for department in self.__departments:
            department.display()
            print()


def main():
    hospital = Hospital("Harapan Sehat")

    cardio = hospital.add_department("Kardiologi")
    cardio.add_doctor(Doctor("dr. Rina Wijaya", 42, "jantung"))
    cardio.add_nurse(Nurse("Sari Lestari", 29, "pagi"))
    cardio.add_patient(Patient("Budi Santoso", 55, "hipertensi", 101))

    pediatric = hospital.add_department("Anak")
    pediatric.add_doctor(Doctor("dr. Andi Pratama", 38, "anak"))
    pediatric.add_nurse(Nurse("Dewi Anggraini", 27, "malam"))
    pediatric.add_patient(Patient("Kevin Aditya", 7, "demam berdarah", 205))

    print("##### DATA SEBELUM DITAMBAHKAN #####\n")
    hospital.display()

    cardio.add_patient(Patient("Siti Aminah", 61, "gagal jantung", 102))
    pediatric.add_doctor(Doctor("dr. Maya Putri", 35, "neonatologi"))
    neuro = hospital.add_department("Saraf")
    neuro.add_doctor(Doctor("dr. Hendra Gunawan", 47, "saraf"))
    neuro.add_nurse(Nurse("Lina Marlina", 31, "siang"))
    neuro.add_patient(Patient("Agus Setiawan", 49, "migrain kronis", 303))

    print("##### DATA SESUDAH DITAMBAHKAN #####\n")
    hospital.display()


if __name__ == "__main__":
    main()