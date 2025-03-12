#pragma once
#include <map>
#include "StudentEntity.h"
#include<vector>
using namespace std;
class StudentManager

{
private: 
	map<int, StudentEntity> m_studentList;

public: 
	StudentManager() {}
	void saveStudent(StudentEntity student) {
		m_studentList[student.getId()]=student;
		
	}
	map<int, StudentEntity>& getStudentList() { return m_studentList; }
    bool getStudentById(int id, StudentEntity& outStudent)
    {
        auto it = m_studentList.find(id);
        if (it != m_studentList.end())
        {
            outStudent = it->second;
            return true;
        }
        return false;
    }


    void updateStudent(const int& id, const StudentEntity& student)
    {
        if (m_studentList.find(id) != m_studentList.end())
        {
            m_studentList[id] = student; // Update student record
        }
    }
    std::vector<StudentEntity> getAllStudents()
    {
        std::vector<StudentEntity> students;
        for (const auto& pair : m_studentList)
        {
            students.push_back(pair.second);
        }
        return students;
    }



};

