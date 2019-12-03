
-- Q2
select e.ename
from employees as e, (select min(price) as p from flights where from_1 = "hyderabad" and to_1 = "chennai") as der, (select distinct eid from certified) as der1
where e.eid = der1.eid and e.salary < der.p;

-- Q3
select a.aname 
from employees as e, aircraft as a, (select eid, aid from certified) as der 
where e.salary > 25000 and der.eid = e.eid and der.aid = a.aid;

-- Q4
select a.aid, a.aname 
from aircraft as a, flights as f 
where a.cruisingrange <= f.distance and from_1 = "hyderabad" and to_1 = "delhi";

-- Q5
select ename, salary 
from employees 
where eid not in (select distinct eid from certified);

-- Q6
select (select avg(salary) as ae from employees where eid in (select eid from certified)) - (select avg(salary) as ae from employees);

-- Q7
select ename 
from employees 
where eid in (select eid from certified);

-- Q8
-- select eid
-- from employee
-- order by salary desc
-- limit 1,1;
select eid from employees where salary in (select max(salary) from employees where salary not in (select max(salary) from employees));

-- Q9
select from_1, to_1
from flights 
where distance < (select cruisingrange from aircraft where aid in (select min(aid) as aid from (select max(aid) as aid from certified group by eid) as der));

-- or

select from_1, to_1 
from flights 
where distance <= (select min(der.dist) from (select max(cruisingrange) as dist from aircraft as a, certified as c where a.aid = c.aid group by eid) as der);
