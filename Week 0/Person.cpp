#include "Person.h"
Person::Person(){
age = 0;
name = nullptr;
}
Person::~Person(){
delete[] name;
}
Person& Person::operator=(const Person& other){
  if (this != other){
    name = setName(other.name);
    age = other.age;
  }
  return *this;
}
void Person::setName(char* newName){
  delete[] name;
  name = new char[strlen(newName) + 1]
  strcpy(name, newName);
}
void Person::setAge(int newAge){
  age = newAge;
}
char* Person::getName(){
  return name;
}
char* Person::getAge(){
  return age;
}
