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
    void change();
    void display();
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
    ReadandwriteStudent().writeAll("E:\\DTU\\C++\\All_File\\File_student\\File_Student\\input",list);
}
void Studentservice :: display()
{
    list = ReadandwriteStudent().readAll("E:\\DTU\\C++\\All_File\\File_student\\File_Student\\input");
    for(Student e : list)
    {
        e.output();
    }
}

void Studentservice::change() {
    Studentservice stu;
    list = ReadandwriteStudent().readAll("E:\\DTU\\C++\\All_File\\File_student\\File_Student\\input");
    stu.display();
    int n;
    string name_fake;
    cout<<"Nhap id can thay doi:";
    cin>>n;
    string id_fake ="STD-000"+ to_string(n);
    Student *tmp;
    bool check = true;
    for(Student &s:list){
        if(id_fake==s.getId()){
            check= false;
            tmp = &s;
        }
    }
    if(check){
        cout<<"Khong co id trung"<<endl;
    }else{
        tmp->output();
        cout<<"Nhap ten can thay doi:";
        cin.ignore();
        getline(cin,name_fake);
        tmp->setName(name_fake);
        cout<<id_fake<<","<<tmp->getName()<<endl;
        ReadandwriteStudent().writeAll("E:\\DTU\\C++\\All_File\\File_student\\File_Student\\input",list);
    }
}

int main(){
    Studentservice s;
    cout<<"1.Them 1 student"<<endl;
    cout<<"2.Thay doi name"<<endl;
    int n;
    cout<<"Chon :";
    cin>>n;
    switch (n) {
        case 1:{
            s.addStudent();
            break;
        }
        case 2:{
            s.change();
            break;
        }
    }
    return 0;
}