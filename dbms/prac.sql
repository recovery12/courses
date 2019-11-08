create database person;
use person;

create table bodystat
(
age int not null primary key,
rec_date date,
wgs int,
hgs int
);

desc bodystat;
select * from bodystat;
drop table bodystat;
drop database person;
