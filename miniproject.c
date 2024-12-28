#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

// Define a structure for patient details
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

// Declare an array to hold patient records
struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

// Function to add a new patient
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Cannot add more patients, memory full.\n");
        return;
    }
    
    struct Patient newPatient;
    
    printf("Enter Patient ID: ");
    scanf("%d", &newPatient.id);
    getchar(); // To consume newline character
    printf("Enter Patient Name: ");
    fgets(newPatient.name, 50, stdin);
    newPatient.name[strcspn(newPatient.name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter Patient Age: ");
    scanf("%d", &newPatient.age);
    getchar(); // To consume newline character
    printf("Enter Disease: ");
    fgets(newPatient.disease, 50, stdin);
    newPatient.disease[strcspn(newPatient.disease, "\n")] = '\0'; // Remove trailing newline
    
    patients[patientCount++] = newPatient;
    printf("Patient added successfully.\n");
}

// Function to display all patients
void displayPatients() {
    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }
    
    printf("List of Patients:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("\nPatient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
    }
}

// Function to update a patient's details
void updatePatient() {
    int id, found = 0;
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            getchar(); // To consume newline character
            printf("Enter new Patient Name: ");
            fgets(patients[i].name, 50, stdin);
            patients[i].name[strcspn(patients[i].name, "\n")] = '\0';
            printf("Enter new Patient Age: ");
            scanf("%d", &patients[i].age);
            getchar(); // To consume newline character
            printf("Enter new Disease: ");
            fgets(patients[i].disease, 50, stdin);
            patients[i].disease[strcspn(patients[i].disease, "\n")] = '\0';
            printf("Patient record updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Patient not found.\n");
    }
}

// Function to delete a patient's record
void deletePatient() {
    int id, found = 0;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient record deleted successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Patient not found.\n");
    }
}

// Function to search for a patient by ID
void searchPatient() {
    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            printf("\nPatient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            break;
        }
    }
    
    if (!found) {
        printf("Patient not found.\n");
    }
}

// Main program
int main() {
    int choice;
    
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Update Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Search Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                updatePatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                searchPatient();
                break;
            case 6:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}


