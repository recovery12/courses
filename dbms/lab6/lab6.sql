create database if not exists ucms;
use ucms;

create table if not exists faculty
(
    fid int primary key,
    name char(50),
    desg char(50),
    address varchar(50),
    dno int
);

create table if not exists contact
(
    fid int,
    contact int(10),
    primary key(fid, contact)
);

create table if not exists course
(
    cid int primary key,
    name char(50),
    rno int,
    dno int,
    title char(50),
    author char(50),
    price real,
    text_book varchar(100) AS (concat(title, ' ', author, ' ', price))
);

create table if not exists teaches
(
    teachid int primary key,
    fid int,
    cid int
);

create table if not exists department
(
    dno int primary key,
    name char(50),
    hod int
);

create table if not exists classrooms
(
    rno int primary key,
    lcd tinyint,
    capacity int,
    xxx varchar(50)
);

alter table faculty add foreign key(dno) references department(dno);
alter table department add foreign key(hod) references faculty(fid);
alter table contact add foreign key(fid) references faculty(fid);
alter table teaches add foreign key(fid) references faculty(fid);
alter table teaches add foreign key(cid) references course(cid);
alter table course add foreign key(rno) references classrooms(rno);
alter table course add foreign key(dno) references department(dno);
-- drop database ucms;