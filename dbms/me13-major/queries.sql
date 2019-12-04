-- 1Q
select name as Faculty_Name, facID as Faculty_number
from Faculty
order by name;

-- 2Q
select s.stuID, concat(s.firstName, " ", s.lastName) as Name
from Student as s, Enroll as e
where s.stuID = e.stuID and e.classNumber = 'ART103A';

-- 3Q
select e.stuID, e.grade
from Enroll as e, Class as c
where c.facID = 'F110' and c.classNumber = e.classNumber;

-- 4Q
select c.classNumber
from Class as c, Faculty as f
where c.facID = f.facID and f.name = 'Raman' and f.department = 'Math';

-- 5Q
select f.facID, f.name
from Faculty as f, Class as c
where f.facID = c.facID and c.room = 'H221';

-- 1qview
create view Q1 as
select name as Faculty_Name, facID as Faculty_number
from Faculty
order by name;
select * from Q1;

-- 2qview
create view Q2 as
select s.stuID, concat(s.firstName, " ", s.lastName) as Name
from Student as s, Enroll as e
where s.stuID = e.stuID and e.classNumber = 'ART103A';
select * from Q2;

-- 3qview
create view Q3 as
select e.stuID, e.grade
from Enroll as e, Class as c
where c.facID = 'F110' and c.classNumber = e.classNumber;
select * from Q3;

-- 4qview
create view Q4 as
select c.classNumber
from Class as c, Faculty as f
where c.facID = f.facID and f.name = 'Raman' and f.department = 'Math';
select * from Q4;

-- 5qview
create view Q5 as
select f.facID, f.name
from Faculty as f, Class as c
where f.facID = c.facID and c.room = 'H221';
select * from Q5;