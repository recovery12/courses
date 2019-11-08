-- Creating procedures
create or replace procedure greet
as
begin
    dbms_output.put_line('Hello World!');
end;

-- Run Procedure
begin
    greet
end;

-- Drop procedure
drop procedure greet;

-- creating math procedures
declare
    a number;

procedure sqr(a IN OUT number)
is
begin
    a := a * a;
end;
begin
    a := 5;
    sqr(a);
    dbms_output.put_line('Square is ' || a);
end;

-- prime or not
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
    for num in 2 .. 1000
    loop
        status := true;
        isprime(num, status);
        if status
        then
            dbms_output.put_line(num || ' is a prime');
        end if;
    end loop;
end;

-- Trigger
create or replace trigger sal_mod
before delete or insert or update on employee
for each row
when (NEW.eno > 0)
declare
    sal_diff number;
begin
    sal_diff := :NEW.salary - :OLD.salary;
    dbms_output.put_line('Salary raise ' || sal_diff);
end;

-- Drop Trigger
drop trigger greet;

-- Commits
begin
    commit;
end;

begin
    set autocommit off;
    set autocommit on;
end;

-- rollback and savepoint
begin
    update employee
    set salary = 3
    where eno = 4;
    savepoint s1;
    
    update employee
    set salary = 5;
    rollback to s1;
end;