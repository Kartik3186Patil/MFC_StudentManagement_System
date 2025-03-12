#pragma once
#include <string>
using namespace std;
class StudentEntity
{
private:
	int m_id;
	string m_name;
	int m_subMark1;
	int m_subMark2;
	int m_subMark3;
public:
    // Constructor
    StudentEntity(int id, string& name, int subMark1, int subMark2, int subMark3)
        : m_id(id), m_name(name), m_subMark1(subMark1), m_subMark2(subMark2), m_subMark3(subMark3) {
    }
    StudentEntity() {};

    // Getter for m_id
    int getId() const {
        return m_id;
    }

    // Setter for m_id
    void setId(int id) {
        m_id = id;
    }

    // Getter for m_name
    std::string getName() const {
        return m_name;
    }

    // Setter for m_name
    void setName(string name) {
        m_name = name;
    }

    // Getter for m_subMark1
    int getSubMark1() const {
        return m_subMark1;
    }

    // Setter for m_subMark1
    void setSubMark1(int subMark1) {
        m_subMark1 = subMark1;
    }

    // Getter for m_subMark2
    int getSubMark2() const {
        return m_subMark2;
    }

    // Setter for m_subMark2
    void setSubMark2(int subMark2) {
        m_subMark2 = subMark2;
    }

    // Getter for m_subMark3
    int getSubMark3() const {
        return m_subMark3;
    }

    // Setter for m_subMark3
    void setSubMark3(int subMark3) {
        m_subMark3 = subMark3;
    }

};

