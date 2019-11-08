
create database lab2;
use lab2;

create table employee
(
fname varchar(50) not null,
inital varchar(50),
lname varchar(50),
dob date,
address varchar(150),
sex char,
super_eno int not null,
eno int not null,
dno int not null,
salary real,
primary key(eno),
foreign key(super_eno) references employee(eno)
);

create table dept
(
dname varchar(50),
mgr_eno int not null,
mgr_start_date date,
dnumber int not null,
primary key(dnumber)
);

alter table employee add foreign key(dno) references dept(dnumber);
alter table employee drop foreign key employee_ibfk_1;

desc employee;
desc dept;


/* insert data into dept */
insert into dept values ("ml", 2, '1998-12-02', 1);
insert into dept values ("mlai", 1, '1998-12-02', 3);
insert into dept values ("ai", 3, '1998-12-02', 2);
insert into dept values ("code", 5, '1998-12-02', 5);
insert into dept values ("codechef", 4, '1998-12-02', 4);

/* insert data into emp */
insert into employee values ("dum1", "m", "fum1", '1956-03-05', "hyd", 'm', 3, 2, 1, 20000);
insert into employee values ("dum2", "r", "fum4", '1954-12-12', "bombay", 'f', 1, 3, 2, 30000);
insert into employee values ("dum5", "g", "fum3", '1956-02-22', "hyd", 'f', 4, 5, 5, 40000);
insert into employee values ("dum4", "f", "fum2", '1953-11-02', "banglore", 'm', 5, 4, 4, 20000);
insert into employee values ("dum3", "c", "fum5", '1950-10-04', "bombay", 'm', 2, 1, 3, 15000);

/*1-a*/
select dob, address
from employee
where fname='dum2' and inital='r' and lname='fum4';

/*1-b*/
select fname,inital,lname, address
from employee, dept
where employee.dno = dept.dnumber and dept.dname = "ai";

/*2-a*/
select eno
from employee;

/*2-b*/
select e.eno, d.dname
from employee as e, dept as d;

/*3*/
select distinct salary
from employee;

/*4-a*/
select *
from employee
where address like 'b%';

/*4-b*/
select *
from employee
where dob like '195_%';

/*5-a*/
select *
from employee
where dno = 5 and (salary between 20000 and 50000);

/*5-b*/
select *
from employee
where dob >= '1953%' and dob <= '1955%';

/*6-a*/
select salary from employee where dno = 1
intersect
select salary from employee where dno = 4;

/*6-b*/
select * from employee where dno = 1
minus
select * from employee where dno = 2;

/*6-c*/
select fname,eno,salary from employee where dno = 1
union
select fname,eno,salary from employee where dno = 2;

/*7*/
select e.eno, e.salary, e.super_eno, d.dname, d.mgr_start_date 
from employee as e, dept as d
where e.dno = d.dnumber;

-- drop table employee;
-- drop table dept;

-- drop database lab2;
