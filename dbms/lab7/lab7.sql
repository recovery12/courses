create database if not exists lab7;
use lab7;

create table if not exists employees
(
    eid int primary key,
    fname varchar(50),
    lname varchar(50),
    email varchar(50),
    phno int(10),
    hire_date date,
    jid int,
    salary real,
    manager_id int,
    dept_id int
);

create table if not exists departments
(
    dept_id int primary key,
    dept_name varchar(50),
    loc_id int
);

alter table employees add foreign key(dept_id) references departments(dept_id);

set foreign_key_checks = 0;

insert into employees values (1, "Anurag", "Sharma", "anurag.sharma@gmail.com", 1234567890, "1998-11-12", 101, 98, 501, 2);
insert into employees values (2, "Anurag", "Gupta", "anurag.gupta@gmail.com", 1237567890, "1998-10-15", 103, 88, 505, 4);
insert into employees values (3, "Anurag", "Varma", "anurag.varma@gmail.com", 1232567890, "1998-01-11", 102, 99, 502, 3);
insert into employees values (4, "Anurag", "Shetty", "anurag.shetty@gmail.com", 1238567890, "1968-08-10", 105, 91, 506, 1);
insert into employees values (5, "Anurag", "Polishetty", "anurag.polishttey@gmail.com", 1234517890, "1995-05-22", 104, 92, 508, 6);
insert into employees values (6, "Anurag", "Kumar", "anurag.kumar@gmail.com", 1234507890, "1985-03-12", 107, 88, 507, 7);
insert into employees values (7, "Anurag", "Dubey", "anurag.dubey@gmail.com", 1232567890, "1965-06-02", 106, 90, 503, 3);
insert into employees values (8, "Anurag", "Smith", "anurag.smith@gmail.com", 1234567890, "1955-02-12", 104, 95, 509, 8);
insert into employees values (9, "Anurag", "Hood", "anurag.hood@gmail.com", 1934567890, "1925-03-23", 102, 93, 502, 9);
insert into employees values (10, "Anurag", "Daniel", "anurag.daniel@gmail.com", 1239567890, "1915-08-22", 101, 92, 500, 4);

insert into departments values (1, "SCIS", 3);
insert into departments values (2, "CHEM", 2);
insert into departments values (3, "CIS", 5);
insert into departments values (4, "SOCIAL", 4);
insert into departments values (6, "SCIS", 8);
insert into departments values (7, "PHY", 6);
insert into departments values (8, "CHEM", 3);
insert into departments values (9, "SLS", 1);

set foreign_key_checks = 1;

/* Q2 */
create view employee_contact as
select e.fname, e.lname, e.email, e.phno, d.dept_name
from employees as e, departments as d
where e.dept_id = d.dept_id;

select * from employee_contact;

/* Q3 */
create view payroll as 
select fname, lname, jid, salary 
from employees;

select * from payroll;

/* Q4 */
update payroll
set salary = 2 * salary;

select * from payroll;

/* Q5 */
delete from employee_contact
where dept_name = "SCIS";

select * from employee_contact;

/* Q6 */
select *
from payroll
limit 7, 3;

/* Q7 */
drop view payroll;
drop view employee_contact;
