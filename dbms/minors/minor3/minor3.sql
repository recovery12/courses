create database if not exists minor3;
use minor3;

create table if not exists personal_data
(
   emp_id int primary key,
   emp_name varchar(20),
   dob date,
   addr varchar(50),
   age int
);

create table if not exists official_data
(
   emp_id int,
   exper int,
   salary real,
   rating int
);

create table if not exists dept_data
(
   dept_id int primary key,
   dept_name varchar(20),
   dept_location varchar(20),
   dept_hod int
);

alter table official_data add foreign key(emp_id) references personal_data(emp_id);

set foreign_key_checks = 0;

insert into personal_data values (12, "Vikash", "1996-11-09", "New Delhi", 23);
insert into personal_data values (13, "Prabash", "1993-11-11", "Bhopal", 26);
insert into personal_data values (14, "Gopal", "1992-11-11", "Vizag", 27);
insert into personal_data values (15, "Kisan", "1991-11-11", "Jaipur", 28);
insert into personal_data values (16, "Imran", "1990-11-11", "Mumbai", 29);
insert into personal_data values (17, "Akash", "1997-11-11", "Pune", 22);

insert into official_data values (12, 5, 35000, 9);
insert into official_data values (13, 6, 35000, 9);
insert into official_data values (14, 0, 15000, 5);
insert into official_data values (15, 3, 25000, 7);
insert into official_data values (16, 8, 45000, 10);
insert into official_data values (17, 4, 35000, 9);

insert into dept_data values (1, "HR", "Delhi", 13);
insert into dept_data values (2, "finance", "Mumbai", 13);
insert into dept_data values (3, "marketing", "Hyd", 12);
insert into dept_data values (4, "marketing", "Hyd", 14);
insert into dept_data values (5, "product", "Bhopal", 12);

-- 3
select e.emp_name, d.dept_name from personal_data as e join dept_data as d on d.dept_hod = e.emp_id and d.dept_hod in (select dept_hod from dept_data group by dept_hod having count(*) > 1);

-- 4
select e.emp_id, e.emp_name, if (isnull(d.dept_name), "not a HOD", d.dept_name) from personal_data as e left outer join dept_data as d on d.dept_hod = e.emp_id;

-- 5
create view demo_view as select emp_name, addr, age from personal_data;
insert into demo_view values ("Alok", "Indore", 28);
delete from demo_view where emp_name = "Alok";
drop view demo_view;

-- 6 
create view combo_view as select p.emp_name, p.dob, o.exper, o.salary from personal_data as p, official_data as o;

-- 7
start transaction;
savepoint s1;
delete from official_data where rating < 7;
savepoint s2;
delete from official_data where salary < 25000;
rollback to s2;
release savepoint s1;

-- 8
create procedure display()
select p.emp_name, p.emp_id, p.age, o.rating from personal_data as p, official_data as o where p.age < 25 and rating > 8;

call display();

-- 9
create procedure update_data()
update official_data set salary = 1.1 * salary, rating = rating + 1 where exper > 5 and exper < 8;

call update_data();

-- 10
declare
    num number;
    status boolean;

procedure isprime(num IN number, status IN OUT boolean)
is
begin
    if (mod(num, 2) = 0 and num != 2)
    then
        status := false;
    end if;
        
    for i in 3 .. num-1
    loop
        if mod(num, i) = 0
        then
            status := false;
        end if;
    end loop;
end;
begin
    num := 53;
    status := true;
    isprime(num, status);
    if status
    then
        dbms_output.put_line(num || ' is a prime');
    end if;
end;