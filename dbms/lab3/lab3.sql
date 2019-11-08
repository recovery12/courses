/* Creating table and inserting data*/

create database lab3;
use lab3;

create table employee
(
    fname varchar(50) not null,
    inital varchar(50),
    lname varchar(50),
    dob date,
    addr varchar(150),
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

/* insert data into dept */
insert into dept values ("ml", 2, '1998-12-02', 1);
insert into dept values ("mlai", 1, '1998-12-02', 3);
insert into dept values ("ai", 3, '1998-12-02', 2);
insert into dept values ("code", 5, '1998-12-02', 5);
insert into dept values ("ai", 1, '1998-12-02', 6);
insert into dept values ("nlp", 4, '1998-12-02', 7);
insert into dept values ("opencv", 2, '1998-12-02', 10);
insert into dept values ("ml", 5, '1998-12-02', 9);
insert into dept values ("code", 1, '1998-12-02', 8);
insert into dept values ("codechef", 4, '1998-12-02', 4);

/* insert data into emp */
insert into employee values ("dum1", "m", "fum1", '1956-03-05', "hyd", 'm', 3, 2, 1, 20000);
insert into employee values ("dum6", "c", "fum1", '1956-03-25', "pune", 'f', 1, 6, 2, 10000);
insert into employee values ("dum1", "c", "fum4", '1957-05-15', "bihar", 'm', 4, 9, 8, 15000);
insert into employee values ("dum1", "m", "fum1", '1952-02-05', "hyd", 'm', 3, 10, 6, 50000);
insert into employee values ("dum1", "s", "fum1", '1959-12-25', "goa", 'f', 6, 7, 9, 25000);
insert into employee values ("dum1", "z", "fum1", '1956-03-05', "hyd", 'm', 3, 3, 1, 35000);
insert into employee values ("dum2", "r", "fum4", '1954-12-12', "bombay", 'f', 1, 8, 2, 30000);
insert into employee values ("dum5", "g", "fum3", '1956-02-22', "hyd", 'f', 4, 5, 5, 40000);
insert into employee values ("dum4", "f", "fum2", '1953-11-02', "banglore", 'm', 5, 4, 4, 20000);
insert into employee values ("dum3", "c", "fum5", '1950-10-04', "bombay", 'm', 2, 1, 3, 15000);

alter table employee add foreign key employee_ibfk_1 (super_eno) references employee(eno);

/* Assignment Answers */
/* Q1 */
update employee
set salary = 1.1*salary
where dno = cast(10*rand() as signed);

select *
from employee;

/* Q2 */
delete
from employee
where dno = cast(10*rand() as signed);

select *
from employee;

/* Q3 */
-- i)
select count(*)
from employee as e, dept as d
where d.dnumber = e.dno and d.dname = "code";
-- ii)
select count(*)
from dept
where dname = "ml";

/* Q4 */
select sum(salary), min(salary), max(salary), avg(salary)
from employee;

/* Q5 */
select d.dnumber, count(*), avg(e.salary)
from employee as e, dept as d
where e.dno = d.dnumber
group by d.dnumber;

/* Q6 */
select distinct e.dno
from employee as e, (select dno, count(*) from employee group by dno having count(*) > 1) as der
where e.dno = der.dno and e.salary > 15000;

drop table employee;
drop table dept;
drop database lab3;