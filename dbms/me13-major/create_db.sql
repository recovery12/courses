create database if not exists University;
use University;

create table if not exists Student
(
	stuID varchar(10) primary key,
	lastName varchar(50),
	firstName varchar(50),
	course varchar(50),
	credits int
);

create table if not exists Faculty
(
	facID varchar(5) primary key,
	name varchar(50),
	department varchar(50),
	designation varchar(10)
);

create table if not exists Class
(
	classNumber varchar(10) primary key,
	facID varchar(5),
	schedule varchar(10),
	room varchar(5)
);

create table if not exists Enroll
(
	stuID varchar(10),
	classNumber varchar(10),
	grade varchar(1),
	primary key(stuID, classNumber)
);

desc Student;
desc Faculty;
desc Class;
desc Enroll;

alter table Enroll add foreign key(stuID) references Student(stuID);
alter table Enroll add foreign key(classNumber) references Class(classNumber);
alter table Class add foreign key(facID) references Faculty(facID);
