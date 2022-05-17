#include<iostream>
#include<list>
#include<fstream>
#include<string>
using namespace std;
class Student{
private:
    string id;
    string name;
public:
    void change();
    void display();
    void output();
    Student();
    Student(const string &id, const string &name) : id(id), name(name) {}
    list<Student>list;

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);
};

Student::Student() {
}

const string &Student::getId() const {
    return id;
}

void Student::setId(const string &id) {
    Student::id = id;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

void Student::output() {
    cout<<id<<","<<name<<endl;
}

class ReadandwriteStudent{
public:
    list<Student>readAll(string path);
    void writeAll(string path,list<Student>s);
};
list<Student>ReadandwriteStudent::readAll(string path) {
    list<Student>list;
    ifstream fi(path,ios_base::in);
    if(fi.is_open()){
        cout<<"Mo file thanh cong"<<endl;
        while (1){
            string id;
            string name;
            getline(fi,id,',');
            getline(fi,name);
            if(fi.eof()){
                break;
            }
            Student s(id,name);
            list.push_back(s);
        }
        fi.close();
    } else{
        cout<<"Mo file khong thanh cong"<<endl;
    }
    return list;
}
void ReadandwriteStudent::writeAll(string path, list<Student> s) {
    ofstream fo(path,ios_base::out);
    if(fo.is_open()){
        cout<<"Ghi file thanh cong"<<endl;
        for( Student s:s){
            fo<<s.getId()<<","<<s.getName()<<endl;
        }
        fo.close();
    }else{
        cout<<"Ghi file khong thanh cong"<<endl;
    }
}
class Studentservice{
public:
    void addStudent();
private:
    list<Student>list;
};

void Studentservice::addStudent() {
    list=ReadandwriteStudent().readAll("E:\\DTU\\C++\\All_File\\File_student\\input");
    int j;
    cout<<"Enter Student:";
    cin>>j;
    cin.ignore();
    for(int i=0;i<j;i++){
        int n=list.size();
        string id="STD-000"+ to_string(n);
        string name;
        cout<<"Enter name:";
        getline(cin,name);
        Student s(id,name);
        list.push_back(s);
    }
    ReadandwriteStudent().writeAll("E:\\DTU\\C++\\All_File\\File_student\\input",list);
}
void Student :: display()
{
    list = ReadandwriteStudent().readAll("E:\\DTU\\C++\\All_File\\File_student\\input");
    for(Student e : list)
    {
        e.output();
    }
}
void Student::change() {
    Student s;
    s.display();
    string id_fake;
    string name_fake;
    cout<<"Nhap id can doi :";
    getline(cin,id_fake);
    if(id_fake==id){
        
    }

}
int main(){
    Studentservice s;
    s.addStudent();
    return 0;
}