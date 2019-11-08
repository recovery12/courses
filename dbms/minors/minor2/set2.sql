-- Q6
select sname 
from student 
where snum in (select snum from enrolled group by snum having count(*) in (select max(counts) from (select count(*) as counts from enrolled group by snum) as der)); 

-- Q8
select sname
from student
where snum not in (select snum from enrolled);

-- Q9
select ((select avg(age) from faculty) - (select avg(age) from student)) as diff;