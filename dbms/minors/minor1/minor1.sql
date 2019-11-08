create database if not exists Shipping;
use Shipping;

create table if not exists table1
(
   sid int primary key,
   sname varchar(50),
   rating int,
   age real
);

create table if not exists table2
(
   sid int,
   bid int,
   day date
);

create table if not exists table3
(
   bid int primary key,
   bname varchar(50),
   color char(20)
);

insert into table1 values (22, "Dustbin", 7, 45.0);
insert into table1 values (29, "Brutus", 1, 33.0);
insert into table1 values (31, "Lubber", 8, 55.5);
insert into table1 values (32, "Andy", 8, 25.5);
insert into table1 values (58, "Rusty", 10, 35.0);
insert into table1 values (64, "Horatio", 7, 35.0);
insert into table1 values (71, "Zorba", 10, 16.0);
insert into table1 values (74, "Horatio", 9, 35.0);
insert into table1 values (85, "Art", 3, 25.5);
insert into table1 values (95, "Bob", 3, 63.5);

insert into table2 values (22, 101, "1998-10-10");
insert into table2 values (22, 102, "1998-10-10");
insert into table2 values (22, 103, "1998-08-10");
insert into table2 values (22, 104, "1998-07-10");
insert into table2 values (31, 102, "1998-10-11");
insert into table2 values (31, 103, "1998-06-11");
insert into table2 values (31, 104, "1998-12-11");
insert into table2 values (64, 101, "1998-05-09");
insert into table2 values (64, 102, "1998-08-09");
insert into table2 values (74, 103, "1998-08-09");

insert into table3 values (101, "Interlake", "blue");
insert into table3 values (102, "Interlake", "red");
insert into table3 values (103, "Clipper", "green");
insert into table3 values (104, "Marine", "red");

select *
from table1;

select *
from table2;

select *
from table3;

show columns in table1;
show columns in table2;
show columns in table3;

/*Q2*/
alter table table2 add foreign key(sid) references table1(sid);
alter table table2 add foreign key(bid) references table3(bid);
show columns in table2;

/*Q3*/
-- i
select sname
from table1
where sname like '__r%';

-- ii
select distinct t1.sname
from table1 as t1, table2 as t2
where t1.sid = t2.sid and t2.day like '1998-08%';

-- iii
select distinct sname
from table1
where rating between 5 and 10;

-- iv
select distinct t3.bname
from table3 as t3, table2 as t2
where t3.bid = t2.bid and day between '1998-08-01%' and '1998-11-31%';

/*Q4*/
select distinct age
from table1;

/*Q5*/
select t2.day
from table2 as t2, table3 as t3
where t3.bname = 'Interlake' and t3.color = 'blue'
union
select t2.day
from table2 as t2, table3 as t3
where t3.bname = 'Interlake' and t3.color = 'red';

/*Q6*/
update table1
set rating = if (rating + 1 <= 10, rating+1, 10);
select * from table1;

/*Q7*/
-- i
select avg(rating)
from table1
where age >= 35;

-- ii
select max(age), min(age), avg(age)
from table1;

/*Q8*/
select distinct t1.sname, der.*
from table1 as t1, (select t2.sid, count(t2.sid) from table2 as t2 group by t2.sid) as der
where t1.sid = der.sid;

/*Q9*/
-- i
select avg(table1.rating), table2.bid, count(table2.sid)
from table1, table2
where table1.sid = table2.sid
group by table2.bid;

-- ii
select distinct min(der.age) as age
from (select * from table1 where age > 18) as der
group by der.rating
having count(der.rating) >= 2;

/*Q10*/
-- i
delete
from table1
where sid = 29;
select * from table1;

-- ii
rename table table1 to ReadyToDrop;

-- iii
alter table ReadyToDrop change sname sailor_name varchar(50);

-- iv
alter table ReadyToDrop drop column age;
select * from ReadyToDrop;

-- v
alter table table2 drop foreign key table2_ibfk_1;
truncate ReadyToDrop;

-- drop table table3;
-- drop table table2;
-- drop table table1;
drop database Shipping;