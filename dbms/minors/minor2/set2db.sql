create database if not exists university;
use university;

create table if not exists student
(
    snum int primary key,
    sname char(50),
    major char(20),
    level char(3),
    age int
);

create table if not exists class
(
    cname char(10) primary key,
    meets_at char(20),
    room char(10),
    fid int
);

create table if not exists faculty
(
    fid int primary key,
    fname char(20),
    deptid int,
    age int
);

create table if not exists enrolled
(
    snum int,
    cname char(10),
    primary key(snum, cname)
);

alter table class add foreign key(fid) references faculty(fid);
alter table enrolled add foreign key(snum) references student(snum);
alter table enrolled add foreign key(cname) references class(cname);

set foreign_key_checks = 0;

insert into student values (1, "John", "CS", "Sr", 19);
insert into student values (2, "Smith", "CS", "Jr", 20);
insert into student values (3, "Jacob", "CV", "Sr", 20);
insert into student values (4, "Tom", "CV", "Jr", 20);
insert into student values (5, "Sid", "CS", "Jr", 19);

insert into class values ("class1", "noon", "room1", 14);
insert into class values ("class2", "morning", "room2", 14);
insert into class values ("class3", "morning", "room3", 12);
insert into class values ("class4", "morning", "room4", 11);
insert into class values ("class5", "evening", "room5", 14);

insert into faculty values (11, "Harshith", 1000, 30);
insert into faculty values (12, "Mohan", 1001, 35);
insert into faculty values (13, "Kumar", 1002, 33);
insert into faculty values (14, "Sohan", 1003, 40);
insert into faculty values (15, "Shan", 1004, 32);

insert into enrolled values (1, "class1");
insert into enrolled values (2, "class1");
insert into enrolled values (3, "class2");
insert into enrolled values (3, "class3");
insert into enrolled values (4, "class3");
insert into enrolled values (1, "class2");
insert into enrolled values (2, "class2");

set foreign_key_checks = 1;