create database if not exists itlab;
use itlab;

create table if not exists ITLABexerciseusers
(
    userid int not null primary key auto_increment,
    username varchar(50) not null unique key,
    passwd varchar(50) not null,
    conpasswd varchar(50) not null,
    phno varchar(10)
)