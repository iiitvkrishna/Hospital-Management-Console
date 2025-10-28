#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 20
#define MAX_APPOINTMENTS 200
#define MAX_INVENTORY 50

// Structure definitions
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char phone[15];
    char email[50];
    char address[100];
    char password[30];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char phone[15];
    char email[50];
    char password[30];
} Doctor;

typedef struct {
    int id;
    int patient_id;
    int doctor_id;
    char date[20];
    char time[10];
    char status[20]; // scheduled, completed, cancelled
    char notes[200];
} Appointment;

typedef struct {
    int id;
    char item_name[50];
    int quantity;
    float price;
    char category[30];
} Inventory;

typedef struct {
    int id;
    int patient_id;
    char date[20];
    char diagnosis[200];
    char prescription[200];
    char test_results[300];
    char doctor_notes[200];
} MedicalRecord;

// Global variables
Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];
Inventory inventory_items[MAX_INVENTORY];
MedicalRecord medical_records[MAX_PATIENTS * 10];
int patient_count = 0;
int doctor_count = 0;
int appointment_count = 0;
int inventory_count = 0;
int record_count = 0;

// Function prototypes
void initialize_data();
void save_data();
void load_data();
void patient_registration();
int patient_login();
void doctor_registration();
int doctor_login();
void book_appointment(int patient_id);
void view_patient_history(int patient_id);
void view_doctor_schedule(int doctor_id);
void add_medical_record();
void manage_inventory();
void generate_reports();

// Initialize sample data
void initialize_data() {
    // Sample patients
    strcpy(patients[0].name, "John Doe");
    patients[0].id = 1;
    patients[0].age = 30;
    strcpy(patients[0].gender, "Male");
    strcpy(patients[0].phone, "1234567890");
    strcpy(patients[0].email, "john@email.com");
    strcpy(patients[0].address, "123 Main St");
    strcpy(patients[0].password, "patient123");
    
    strcpy(patients[1].name, "Jane Smith");
    patients[1].id = 2;
    patients[1].age = 25;
    strcpy(patients[1].gender, "Female");
    strcpy(patients[1].phone, "0987654321");
    strcpy(patients[1].email, "jane@email.com");
    strcpy(patients[1].address, "456 Oak St");
    strcpy(patients[1].password, "patient456");
    
    patient_count = 2;
    
    // Sample doctors
    strcpy(doctors[0].name, "Dr. Robert Johnson");
    doctors[0].id = 1;
    strcpy(doctors[0].specialization, "Cardiology");
    strcpy(doctors[0].phone, "1112223333");
    strcpy(doctors[0].email, "robert@hospital.com");
    strcpy(doctors[0].password, "doctor123");
    
    strcpy(doctors[1].name, "Dr. Emily Davis");
    doctors[1].id = 2;
    strcpy(doctors[1].specialization, "Neurology");
    strcpy(doctors[1].phone, "4445556666");
    strcpy(doctors[1].email, "emily@hospital.com");
    strcpy(doctors[1].password, "doctor456");
    
    doctor_count = 2;
    
    // Sample inventory
    strcpy(inventory_items[0].item_name, "Paracetamol");
    inventory_items[0].id = 1;
    inventory_items[0].quantity = 100;
    inventory_items[0].price = 5.99;
    strcpy(inventory_items[0].category, "Medicine");
    
    strcpy(inventory_items[1].item_name, "Bandages");
    inventory_items[1].id = 2;
    inventory_items[1].quantity = 50;
    inventory_items[1].price = 3.99;
    strcpy(inventory_items[1].category, "Supplies");
    
    inventory_count = 2;
}

// Patient registration
void patient_registration() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Maximum patients reached!\n");
        return;
    }
    
    Patient new_patient;
    new_patient.id = patient_count + 1;
    
    printf("Enter patient name: ");
    scanf(" %[^\n]", new_patient.name);
    printf("Enter age: ");
    scanf("%d", &new_patient.age);
    printf("Enter gender: ");
    scanf("%s", new_patient.gender);
    printf("Enter phone: ");
    scanf("%s", new_patient.phone);
    printf("Enter email: ");
    scanf("%s", new_patient.email);
    printf("Enter address: ");
    scanf(" %[^\n]", new_patient.address);
    printf("Enter password: ");
    scanf("%s", new_patient.password);
    
    patients[patient_count] = new_patient;
    patient_count++;
    
    printf("Registration successful! Your ID is: %d\n", new_patient.id);
    save_data();
}

// Patient login
int patient_login() {
    int id;
    char password[30];
    
    printf("Enter patient ID: ");
    scanf("%d", &id);
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id && strcmp(patients[i].password, password) == 0) {
            printf("Login successful! Welcome %s\n", patients[i].name);
            return id;
        }
    }
    
    printf("Invalid credentials!\n");
    return -1;
}

// Doctor registration
void doctor_registration() {
    if (doctor_count >= MAX_DOCTORS) {
        printf("Maximum doctors reached!\n");
        return;
    }
    
    Doctor new_doctor;
    new_doctor.id = doctor_count + 1;
    
    printf("Enter doctor name: ");
    scanf(" %[^\n]", new_doctor.name);
    printf("Enter specialization: ");
    scanf("%s", new_doctor.specialization);
    printf("Enter phone: ");
    scanf("%s", new_doctor.phone);
    printf("Enter email: ");
    scanf("%s", new_doctor.email);
    printf("Enter password: ");
    scanf("%s", new_doctor.password);
    
    doctors[doctor_count] = new_doctor;
    doctor_count++;
    
    printf("Doctor registration successful! Your ID is: %d\n", new_doctor.id);
    save_data();
}

// Doctor login
int doctor_login() {
    int id;
    char password[30];
    
    printf("Enter doctor ID: ");
    scanf("%d", &id);
    printf("Enter password: ");
    scanf("%s", password);
    
    for (int i = 0; i < doctor_count; i++) {
        if (doctors[i].id == id && strcmp(doctors[i].password, password) == 0) {
            printf("Login successful! Welcome Dr. %s\n", doctors[i].name);
            return id;
        }
    }
    
    printf("Invalid credentials!\n");
    return -1;
}

// Book appointment
void book_appointment(int patient_id) {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Maximum appointments reached!\n");
        return;
    }
    
    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;
    new_appointment.patient_id = patient_id;
    
    printf("Available doctors:\n");
    for (int i = 0; i < doctor_count; i++) {
        printf("%d. %s - %s\n", doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
    
    printf("Enter doctor ID: ");
    scanf("%d", &new_appointment.doctor_id);
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter time (HH:MM): ");
    scanf("%s", new_appointment.time);
    
    strcpy(new_appointment.status, "scheduled");
    printf("Enter reason for visit: ");
    scanf(" %[^\n]", new_appointment.notes);
    
    appointments[appointment_count] = new_appointment;
    appointment_count++;
    
    printf("Appointment booked successfully!\n");
    save_data();
}

// View patient history
void view_patient_history(int patient_id) {
    printf("\n=== MEDICAL HISTORY ===\n");
    
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (medical_records[i].patient_id == patient_id) {
            printf("Date: %s\n", medical_records[i].date);
            printf("Diagnosis: %s\n", medical_records[i].diagnosis);
            printf("Prescription: %s\n", medical_records[i].prescription);
            printf("Test Results: %s\n", medical_records[i].test_results);
            printf("Doctor Notes: %s\n", medical_records[i].doctor_notes);
            printf("------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No medical records found.\n");
    }
}

// View doctor schedule
void view_doctor_schedule(int doctor_id) {
    printf("\n=== TODAY'S SCHEDULE ===\n");
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char today[20];
    strftime(today, sizeof(today), "%Y-%m-%d", tm);
    
    int found = 0;
    for (int i = 0; i < appointment_count; i++) {
        if (appointments[i].doctor_id == doctor_id && 
            strcmp(appointments[i].date, today) == 0 &&
            strcmp(appointments[i].status, "scheduled") == 0) {
            
            // Find patient name
            char patient_name[50] = "Unknown";
            for (int j = 0; j < patient_count; j++) {
                if (patients[j].id == appointments[i].patient_id) {
                    strcpy(patient_name, patients[j].name);
                    break;
                }
            }
            
            printf("Time: %s\n", appointments[i].time);
            printf("Patient: %s\n", patient_name);
            printf("Reason: %s\n", appointments[i].notes);
            printf("------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No appointments scheduled for today.\n");
    }
}

// Add medical record
void add_medical_record() {
    if (record_count >= MAX_PATIENTS * 10) {
        printf("Maximum medical records reached!\n");
        return;
    }
    
    MedicalRecord new_record;
    new_record.id = record_count + 1;
    
    printf("Enter patient ID: ");
    scanf("%d", &new_record.patient_id);
    
    // Check if patient exists
    int patient_found = 0;
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == new_record.patient_id) {
            patient_found = 1;
            break;
        }
    }
    
    if (!patient_found) {
        printf("Patient not found!\n");
        return;
    }
    
    // Get current date
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(new_record.date, sizeof(new_record.date), "%Y-%m-%d", tm);
    
    printf("Enter diagnosis: ");
    scanf(" %[^\n]", new_record.diagnosis);
    printf("Enter prescription: ");
    scanf(" %[^\n]", new_record.prescription);
    printf("Enter test results: ");
    scanf(" %[^\n]", new_record.test_results);
    printf("Enter doctor notes: ");
    scanf(" %[^\n]", new_record.doctor_notes);
    
    medical_records[record_count] = new_record;
    record_count++;
    
    printf("Medical record added successfully!\n");
    save_data();
}

// Manage inventory
void manage_inventory() {
    int choice;
    
    do {
        printf("\n=== INVENTORY MANAGEMENT ===\n");
        printf("1. View Inventory\n");
        printf("2. Add Item\n");
        printf("3. Update Item\n");
        printf("4. Delete Item\n");
        printf("5. Back to Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\n=== CURRENT INVENTORY ===\n");
                for (int i = 0; i < inventory_count; i++) {
                    printf("ID: %d\n", inventory_items[i].id);
                    printf("Name: %s\n", inventory_items[i].item_name);
                    printf("Category: %s\n", inventory_items[i].category);
                    printf("Quantity: %d\n", inventory_items[i].quantity);
                    printf("Price: $%.2f\n", inventory_items[i].price);
                    printf("------------------------\n");
                }
                break;
                
            case 2:
                if (inventory_count >= MAX_INVENTORY) {
                    printf("Maximum inventory items reached!\n");
                    break;
                }
                
                Inventory new_item;
                new_item.id = inventory_count + 1;
                
                printf("Enter item name: ");
                scanf(" %[^\n]", new_item.item_name);
                printf("Enter category: ");
                scanf("%s", new_item.category);
                printf("Enter quantity: ");
                scanf("%d", &new_item.quantity);
                printf("Enter price: ");
                scanf("%f", &new_item.price);
                
                inventory_items[inventory_count] = new_item;
                inventory_count++;
                
                printf("Item added successfully!\n");
                save_data();
                break;
                
            case 3:
                printf("Enter item ID to update: ");
                int update_id;
                scanf("%d", &update_id);
                
                for (int i = 0; i < inventory_count; i++) {
                    if (inventory_items[i].id == update_id) {
                        printf("Enter new quantity: ");
                        scanf("%d", &inventory_items[i].quantity);
                        printf("Enter new price: ");
                        scanf("%f", &inventory_items[i].price);
                        printf("Item updated successfully!\n");
                        save_data();
                        break;
                    }
                }
                break;
                
            case 4:
                printf("Enter item ID to delete: ");
                int delete_id;
                scanf("%d", &delete_id);
                
                for (int i = 0; i < inventory_count; i++) {
                    if (inventory_items[i].id == delete_id) {
                        // Shift all items after this one
                        for (int j = i; j < inventory_count - 1; j++) {
                            inventory_items[j] = inventory_items[j + 1];
                        }
                        inventory_count--;
                        printf("Item deleted successfully!\n");
                        save_data();
                        break;
                    }
                }
                break;
                
            case 5:
                printf("Returning to main menu...\n");
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
}

// Generate reports
void generate_reports() {
    printf("\n=== HOSPITAL REPORTS ===\n");
    
    // Patient count
    printf("Total Patients: %d\n", patient_count);
    
    // Doctor count
    printf("Total Doctors: %d\n", doctor_count);
    
    // Appointment statistics
    int total_appointments = 0;
    int completed_appointments = 0;
    int scheduled_appointments = 0;
    
    for (int i = 0; i < appointment_count; i++) {
        total_appointments++;
        if (strcmp(appointments[i].status, "completed") == 0) {
            completed_appointments++;
        } else if (strcmp(appointments[i].status, "scheduled") == 0) {
            scheduled_appointments++;
        }
    }
    
    printf("Total Appointments: %d\n", total_appointments);
    printf("Completed Appointments: %d\n", completed_appointments);
    printf("Scheduled Appointments: %d\n", scheduled_appointments);
    
    // Inventory statistics
    printf("Total Inventory Items: %d\n", inventory_count);
    
    int low_stock_items = 0;
    for (int i = 0; i < inventory_count; i++) {
        if (inventory_items[i].quantity < 10) {
            low_stock_items++;
        }
    }
    printf("Low Stock Items: %d\n", low_stock_items);
}

// Save data to files
void save_data() {
    FILE *file;
    
    // Save patients
    file = fopen("patients.dat", "w");
    if (file) {
        fwrite(&patient_count, sizeof(int), 1, file);
        fwrite(patients, sizeof(Patient), patient_count, file);
        fclose(file);
    }
    
    // Save doctors
    file = fopen("doctors.dat", "w");
    if (file) {
        fwrite(&doctor_count, sizeof(int), 1, file);
        fwrite(doctors, sizeof(Doctor), doctor_count, file);
        fclose(file);
    }
    
    // Save appointments
    file = fopen("appointments.dat", "w");
    if (file) {
        fwrite(&appointment_count, sizeof(int), 1, file);
        fwrite(appointments, sizeof(Appointment), appointment_count, file);
        fclose(file);
    }
    
    // Save inventory
    file = fopen("inventory.dat", "w");
    if (file) {
        fwrite(&inventory_count, sizeof(int), 1, file);
        fwrite(inventory_items, sizeof(Inventory), inventory_count, file);
        fclose(file);
    }
}

// Load data from files
void load_data() {
    FILE *file;
    
    // Load patients
    file = fopen("patients.dat", "r");
    if (file) {
        fread(&patient_count, sizeof(int), 1, file);
        fread(patients, sizeof(Patient), patient_count, file);
        fclose(file);
    }
    
    // Load doctors
    file = fopen("doctors.dat", "r");
    if (file) {
        fread(&doctor_count, sizeof(int), 1, file);
        fread(doctors, sizeof(Doctor), doctor_count, file);
        fclose(file);
    }
    
    // Load appointments
    file = fopen("appointments.dat", "r");
    if (file) {
        fread(&appointment_count, sizeof(int), 1, file);
        fread(appointments, sizeof(Appointment), appointment_count, file);
        fclose(file);
    }
    
    // Load inventory
    file = fopen("inventory.dat", "r");
    if (file) {
        fread(&inventory_count, sizeof(int), 1, file);
        fread(inventory_items, sizeof(Inventory), inventory_count, file);
        fclose(file);
    }
}

// Main function
int main() {
    int choice, user_type, logged_in_id;
    
    initialize_data();
    load_data();
    
    while (1) {
        printf("\n=== HOSPITAL MANAGEMENT SYSTEM ===\n");
        printf("1. Patient Login\n");
        printf("2. Doctor Login\n");
        printf("3. Patient Registration\n");
        printf("4. Doctor Registration\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                logged_in_id = patient_login();
                if (logged_in_id != -1) {
                    // Patient menu
                    int patient_choice;
                    do {
                        printf("\n=== PATIENT MENU ===\n");
                        printf("1. Book Appointment\n");
                        printf("2. View Medical History\n");
                        printf("3. Logout\n");
                        printf("Enter choice: ");
                        scanf("%d", &patient_choice);
                        
                        switch (patient_choice) {
                            case 1:
                                book_appointment(logged_in_id);
                                break;
                            case 2:
                                view_patient_history(logged_in_id);
                                break;
                            case 3:
                                printf("Logged out successfully.\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }
                    } while (patient_choice != 3);
                }
                break;
                
            case 2:
                logged_in_id = doctor_login();
                if (logged_in_id != -1) {
                    // Doctor menu
                    int doctor_choice;
                    do {
                        printf("\n=== DOCTOR MENU ===\n");
                        printf("1. View Today's Schedule\n");
                        printf("2. View Patient History\n");
                        printf("3. Add Medical Record\n");
                        printf("4. Manage Inventory\n");
                        printf("5. Generate Reports\n");
                        printf("6. Logout\n");
                        printf("Enter choice: ");
                        scanf("%d", &doctor_choice);
                        
                        switch (doctor_choice) {
                            case 1:
                                view_doctor_schedule(logged_in_id);
                                break;
                            case 2:
                                printf("Enter patient ID: ");
                                int patient_id;
                                scanf("%d", &patient_id);
                                view_patient_history(patient_id);
                                break;
                            case 3:
                                add_medical_record();
                                break;
                            case 4:
                                manage_inventory();
                                break;
                            case 5:
                                generate_reports();
                                break;
                            case 6:
                                printf("Logged out successfully.\n");
                                break;
                            default:
                                printf("Invalid choice!\n");
                        }
                    } while (doctor_choice != 6);
                }
                break;
                
            case 3:
                patient_registration();
                break;
                
            case 4:
                doctor_registration();
                break;
                
            case 5:
                save_data();
                printf("Thank you for using Hospital Management System!\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}