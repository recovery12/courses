create database if not exists airport;
use airport;

create table if not exists flights
(
   flno int primary key,
   from_1 char(20),
   to_1 char(20),
   distance int,
   price real
);

create table if not exists aircraft
(
   aid int primary key,
   aname char(20),
   cruisingrange int
);

create table if not exists certified
(
   eid int,
   aid int,
   primary key(eid, aid)
);

create table if not exists employees
(
   eid int primary key,
   ename char(20),
   salary int
);

alter table certified add foreign key(eid) references employees(eid);
alter table certified add foreign key(aid) references aircraft(aid);

show columns in flights;
show columns in aircraft;
show columns in certified;
show columns in employees;

set foreign_key_checks = 0;

insert into flights values (101, "hyderabad", "chennai", 500, 25000);
insert into flights values (102, "hyderabad", "chennai", 650, 35000);
insert into flights values (103, "hyderabad", "delhi", 800, 55000);
insert into flights values (104, "delhi", "pune", 400, 40000);
insert into flights values (105, "chennai", "goa", 1000, 75000);

insert into aircraft values (1, "indigo", 500);
insert into aircraft values (2, "boeing", 800);
insert into aircraft values (3, "vistara", 900);
insert into aircraft values (4, "airindia", 1000);
insert into aircraft values (5, "emirates", 1500);

insert into employees values (1001, "joseph", 20000);
insert into employees values (1002, "raj", 6000);
insert into employees values (1003, "tarun", 80000);
insert into employees values (1004, "henry", 9000);
insert into employees values (1005, "daniel", 60000);
insert into employees values (1006, "michael", 8000);

insert into certified values (1001, 1);
insert into certified values (1003, 3);
insert into certified values (1005, 5);
insert into certified values (1001, 2);
insert into certified values (1003, 4);
insert into certified values (1001, 3);
insert into certified values (1005, 4);

select * from flights;
select * from aircraft;
select * from employees;
select * from certified;

set foreign_key_checks = 1;
