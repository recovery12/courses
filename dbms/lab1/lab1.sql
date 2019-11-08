
create database lab;
use lab;

create table if not exists employee
(
fname varchar(50),
minit char,
lname varchar(50),
eno int primary key,
dob date,
address varchar(150),
sex char,
salary real,
super_eno int,
dno int,
foreign key(super_eno) references employee(eno)
);

create table if not exists dept
(
dname varchar(50),
dnum int primary key,
mgr_eno int,
mgr_start_date date
);

create table if not exists dept_location
(
dnum int,
dlocation varchar(150),
primary key(dnum, dlocation)
);

create table if not exists project
(
pname varchar(50),
pno int primary key,
plocation varchar(150),
dnum  int
);

create table if not exists works_on
(
eno int,
pno int,
hours int,
primary key(eno, pno)
);

create table if not exists dependent
(
eno int,
dependent_name varchar(50),
sex char,
bdate date,
relation varchar(20)
);

alter table employee add foreign key(super_eno) references employee(eno) on update cascade;
alter table employee add foreign key(dno) references dept(dnum);
alter table dept add foreign key(mgr_eno) references employee(eno);
alter table works_on add foreign key(eno) references employee(eno);
alter table dependent add foreign key(eno) references employee(eno);
alter table dept_location add foreign key(dnum) references dept(dnum);
alter table project add foreign key(dnum) references dept(dnum);
alter table works_on add foreign key(pno) references project(pno);

-- drop table dependent;
-- drop table works_on;
-- drop table project;
-- drop table dept_location;
-- drop table dept;
-- drop table employee;
-- drop database lab;
