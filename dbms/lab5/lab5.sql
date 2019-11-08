create database lab5;
use lab5;

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
    dno int
);

create table if not exists dept
(
    dname varchar(50),
    dnum int primary key,
    mgr_eno int,
    mgr_start_date date
);

create table if not exists dependent
(
    eno int,
    dependent_name varchar(50),
    sex char,
    bdate date,
    relation varchar(20),
    primary key(eno, dependent_name)
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
    pno int,
    plocation varchar(150),
    dnum  int,
    primary key(pno)
);

create table if not exists works_on
(
    eno int,
    pno int,
    hours int,
    primary key(eno, pno)
);

insert into employee values ("Abdul", "D", "Razak", 3, '1956-03-05', "hyderbad", 'M', 20000, 2, 1);
insert into employee values ("Rakesh", "R", "Padigela", 1, '1954-12-12', "bombay", 'F', 30000, 3, 2);
insert into employee values ("Rajesh", "G", "Peddi", 4, '1956-02-22', "hyderbad", 'F', 40000, 5, 5);
insert into employee values ("Rahman", "F", "Shaik", 5, '1953-11-02', "banglore", 'M', 20000, 4, 4);
insert into employee values ("Suresh", "C", "Boddu", 2, '1950-10-04', "bombay", 'M', 15000, 1, 3);
insert into employee values ("Suresh", "C", "Boddu", 6, '1950-10-04', "bombay", 'M', 5000, 2, 4);
insert into employee values ("Suresh", "C", "Boddu", 7, '1950-10-04', "bombay", 'M', 25000, 1, 3);

insert into dept values ("SCIS", 2, 1, '1998-12-02');
insert into dept values ("SLS", 1, 3, '1998-12-02');
insert into dept values ("PHY", 3, 2, '1998-12-02');
insert into dept values ("CHEM", 5, 5, '1998-12-02');
insert into dept values ("CHEM", 6, 2, '1998-12-02');
insert into dept values ("CIS", 7, 5, '1998-02-02');
insert into dept values ("CIS", 4, 4, '1998-12-02');

insert into dependent values (1, "Kushal", "M", '1998-02-12', 'son');
insert into dependent values (1, "Meera", "F", '1998-12-12', 'daughter');
insert into dependent values (3, "Meera Kumari", "F", '1988-10-02', 'daughter');
insert into dependent values (3, "Mehren", "F", '1978-04-22', 'daughter');
insert into dependent values (4, "Rajesh", "M", '1992-05-16', 'son');

insert into dept_location values (2, "hyd");
insert into dept_location values (3, "bihar");
insert into dept_location values (4, "hyd");
insert into dept_location values (5, "pune");
insert into dept_location values (1, "hyd");
insert into dept_location values (2, "chennai");
insert into dept_location values (5, "hyd");
insert into dept_location values (4, "banglore");
insert into dept_location values (2, "bombay");

insert into project values ("Word", 1, "hyd", 1);
insert into project values ("Excel", 3, "bombay", 3);
insert into project values ("Ppt", 2, "hyd", 5);
insert into project values ("Word", 5, "hyd", 4);
insert into project values ("Excel", 4, "hyd", 3);
insert into project values ("Excel", 7, "hyd", 2);
insert into project values ("Ppt", 6, "hyd", 3);

insert into works_on values (2, 4, 32);
insert into works_on values (3, 4, 32);
insert into works_on values (4, 6, 32);
insert into works_on values (5, 4, 32);
insert into works_on values (1, 8, 32);
insert into works_on values (4, 4, 32);
insert into works_on values (2, 6, 32);
insert into works_on values (2, 5, 32);
insert into works_on values (1, 2, 32);
insert into works_on values (2, 1, 32);

alter table employee add foreign key(super_eno) references employee(eno);
alter table employee add foreign key(dno) references dept(dnum);
alter table dept add foreign key(mgr_eno) references employee(eno);
alter table works_on add foreign key(eno) references employee(eno);
alter table dependent add foreign key(eno) references employee(eno);
alter table dept_location add foreign key(dnum) references dept(dnum);
alter table project add foreign key(dnum) references dept(dnum);
alter table works_on add foreign key(pno) references project(pno);

/* Lab 5 Answers */
/*Q1*/
select fname, lname
from employee
where year(curdate())-year(dob) in (select min(year(curdate())-year(dob)) from employee);

/*Q2*/
select e1.fname, e1.lname
from employee as e1, employee as e2
where e1.lname = e2.lname and e1.eno = e2.super_eno;

/*Q3*/
select fname, address
from employee
where address = "hyderbad";

/*Q4*/
select fname, lname
from employee
where eno in (select eno from dependent group by eno having count(*) > 1);

/*Q5*/
update employee
set salary = 1.1*salary
where eno in (select mgr_eno from dept where dname = "CHEM");
select * from employee;

/*Q6*/
set foreign_key_checks = 0;
delete
from employee
where year(curdate())-year(dob) >= 68;
set foreign_key_checks = 1;
select * from employee;

/*Q7*/
select *
from employee
where eno not in (select eno from dependent group by eno having count(*) > 0);

/*Q8*/
select * 
from employee as e, (select dno, avg(salary) as sal from employee group by dno) as der 
where e.salary > der.sal and e.dno = der.dno;

/*Q9*/
select *
from employee
where dno in (select dno from employee where fname = "Suresh" and dno = 4 and eno = 6);

/*Q10*/
select salary
from employee
where eno not in (select mgr_eno from dept where dname = "CHEM");

/*Q11*/
select dname, dnum
from dept
where dnum in (select dno from employee where salary > (select max(salary) from employee where dno = 4));

/*Q12*/
select * 
from employee
where salary > (select min(salary) as sal from employee where dno = 4);

set foreign_key_checks = 0;
drop table dependent;
drop table dept;
drop table employee;
drop database lab5;