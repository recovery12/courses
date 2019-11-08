create database if not exists lab4;
use lab4;

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
insert into employee values ("Suresh", "C", "Boddu", 6, '1950-10-04', "bombay", 'M', 5000, 1, 4);
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

/* Lab 4 Answers */
/*Q1*/
select fname, lname
from employee
where salary in (select max(salary) from employee);

/*Q2*/
select e.fname, e.minit, e.lname
from employee as e, dept as d
where d.dnum in (select dnum from dept_location where dlocation = 'hyd') and d.dnum = e.dno;

/*Q3*/
select fname, address
from employee
where dno in (select dnum from dept);

/*Q4*/
select fname
from employee
where eno in (select eno from dependent group by eno having count(*) >= 2);

/*Q5*/
select e.*
from employee as e, (select dno, avg(salary) as avg_sal from employee group by dno) as der
where salary > der.avg_sal and der.dno = e.dno;

/*Q6*/
select fname
from employee
where fname in (select dependent_name from dependent);

/*Q7*/
select fname
from employee
where eno not in (select eno from dependent group by eno having count(*) <> 0);

/*Q8*/
select fname
from employee as e, dept as d
where eno in (select eno from dependent group by eno having count(*) > 0) and e.eno = d.mgr_eno;

/*Q9*/
select p.pname, p.pno, der.emp_count
from project as p, (select count(eno) as emp_count, pno from works_on group by pno having count(pno) > 2) as der
where p.pno = der.pno;

/*Q10*/
select e.lname, w.pno
from works_on as w, employee as e
where w.eno = e.eno
order by e.dno, e.lname;

set foreign_key_checks = 0;
drop table dependent;
drop table dept;
drop table employee;
drop database lab4;