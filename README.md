# **Student Management System with MFC Dialog Boxes**

## **Project Overview**

This **Student Management System** is developed in **C++** using **MFC (Microsoft Foundation Classes)** to create a **graphical user interface (GUI)** with dialog boxes. The system allows users to **add**, **update**, and **view student data**. It uses **three MFC dialog boxes** to manage students and display results, including calculating **total marks**, ranking students, and displaying the **topper for each subject**.

---

## **Features**

### **Student Data Management:**
- **Add**, **Update**, and **Delete** student records.
- Each student record contains **ID**, **Name**, and marks for various subjects.

### **Add Student Dialog Box:**
- A dialog box to **add new students** to the system.
- The user can input the **ID**, **Name**, and **marks** for each subject.
- The system **validates the inputs** and ensures all fields are filled before adding a student to the list.

### **Update Student Dialog Box:**
- A dialog box to **update existing student records**.
- Users can update the student’s **Name** and **marks** (except for the **ID**).
- If any required fields are left blank during the update, the system will prompt the user to **complete all fields** before proceeding.

### **Display Results Dialog Box:**
- A dialog box to **display the results** of all students.
- Students are shown in **descending order** based on their **total marks**.
- The dialog box also displays the **topper for each subject**, showing the highest marks and the student's name.

### **Graphical User Interface (GUI):**
- Three dialog boxes in **MFC**:
  1. **Add Student**: Collects student details and adds them to the system.
  2. **Update Student**: Allows users to update existing student records.
  3. **Display Results**: Displays sorted student results and subject-wise toppers.

---

## **Technologies Used**

### **Programming Language:**
- **C++** (with **Object-Oriented Programming** principles)

### **Libraries and Frameworks:**

#### **MFC (Microsoft Foundation Classes):**
- **MFC** is used for building the **GUI** and managing the **dialog boxes**.
- The **Add Student**, **Update Student**, and **Display Results** dialogs are created using **MFC dialog boxes**.
- The system makes use of MFC controls like:
  - **CEdit** (for text input)
  - **CButton** (for buttons)
  - **CListBox** (for displaying results)

#### **STL (Standard Template Library):**
- Containers like **vector**, **map**, and **unordered_map** are used to store student data and perform operations like sorting and searching.
  - **vector** is used for dynamic storage of students.
  - **map** is used to associate **student ID** with **student records**.

#### **Error Handling:**
- **MFC Message Boxes** are used to alert users about errors such as missing or incomplete fields during the **add** or **update** process.

---

## **How It Works**

1. **Add Student Dialog Box**:
   - The user enters the **ID**, **Name**, and **marks** for each subject. Once all fields are filled and validated, the student is added to the system.
   - A **message box** appears if any required field is left empty.

2. **Update Student Dialog Box**:
   - Users can update a student's **Name** and **marks** (but not the **ID**).
   - After selecting a student to update, the user can modify the necessary fields.
   - If any required fields are left blank during the update, the system prompts the user with a **message box** to fill in the missing data.

3. **Display Results Dialog Box**:
   - The system calculates the **total marks** for each student and displays the students in **descending order** based on their performance.
   - The dialog box also displays the **topper for each subject** along with their name and marks.

---

## **How to Run the Project**

### **Prerequisites:**
- **C++ Compiler** (e.g., **MSVC - Microsoft Visual C++**)
- **Visual Studio** (or any IDE that supports **MFC** development)

### **Steps to Run**:

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/your-username/student-management-system.git
