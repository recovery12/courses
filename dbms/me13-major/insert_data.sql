set foreign_key_checks = 0;

insert into Student values ("S1001", "Smith", "Tom", "History", 40);
insert into Student values ("S1002", "Jones", "Mary", "Art", 30);
insert into Student values ("S1003", "Ravi", "Kumar", "Math", 35);
insert into Student values ("S1004", "Smitha", "agarwal", "Biology", 20);
insert into Student values ("S1005", "Anurag", "Peddi", "Physics", 37);
insert into Student values ("S1006", "Buncy", "karra", "Hindi", 25);
insert into Student values ("S1007", "Buncy", "shaddai", "Biology", 15);
insert into Student values ("S1008", "Subhah", "sarangi", "Physics", 45);
insert into Student values ("S1009", "Akhil", "sharma", "Math", 25);
insert into Student values ("S1010", "Indu", "Rodda", "Hindi", 31);
insert into Student values ("S1011", "Radha", "Raktar", "Biology", 45);
insert into Student values ("S1012", "Pranav", "Kikkera", "Physics", 25);
insert into Student values ("S1013", "Mahesh", "Kumar", "Biology", 15);
insert into Student values ("S1014", "Rohan", "Kumar", "Math", 15);
insert into Student values ("S1015", "Subhash", "Kumar", "Physics", 31);
insert into Student values ("S1016", "Hanu", "bhagavathi", "Biology", 35);
insert into Student values ("S1017", "Majnu", "alugu", "Hindi", 32);
insert into Student values ("S1018", "Majnu", "laxmi", "Physics", 15);
insert into Student values ("S1019", "Hanu", "pippera", "Math", 32);
insert into Student values ("S1020", "Lucky", "kokkula", "Biology", 25);
insert into Student values ("S1021", "vicky", "kompally", "Math", 32);
insert into Student values ("S1022", "Mayank", "padigela", "Physics", 15);
insert into Student values ("S1023", "mohana", "suresh", "Hindi", 31);
insert into Student values ("S1024", "Lucy", "vicky", "Biology", 32);
insert into Student values ("S1025", "Stecy", "varma", "Math", 32);
insert into Student values ("S1026", "Lica", "Duddu", "Hindi", 12);
insert into Student values ("S1027", "Ravi", "Shaddai", "Biology", 55);
insert into Student values ("S1028", "Nancy", "Karra", "Physics", 25);
insert into Student values ("S1029", "Ankit", "Sarangi", "Hindi", 3);
insert into Student values ("S1030", "Raju", "Peddi", "Biology", 25);
insert into Student values ("S1031", "Ravi", "Dubry", "Math", 31);

select * from Student;
-- truncate Student;

insert into Faculty values ("F101", "Anand", "History", "Professor");
insert into Faculty values ("F105", "Joseph", "Art", "Instructor");
insert into Faculty values ("F110", "Raman", "Math", "Associate");
insert into Faculty values ("F120", "Raman", "Hindi", "Associate");
insert into Faculty values ("F111", "Suresh", "Biology", "Associate");
insert into Faculty values ("F112", "Nagaraj", "Physics", "Instructor");
insert into Faculty values ("F113", "Mayank", "Hindi", "Instructor");
insert into Faculty values ("F114", "Durga", "Biology", "Associate");
insert into Faculty values ("F115", "Anupama", "Hindi", "Professor");
insert into Faculty values ("F125", "Anupama", "Math", "Professor");
insert into Faculty values ("F121", "Suresh", "Math", "Associate");

select * from Faculty;
-- truncate Faculty;

insert into Class values ("ART103A", "F101", "MWF9", "H221");
insert into Class values ("CSC201A", "F105", "TuTh10", "M110");
insert into Class values ("MTH101B", "F110", "MWF9", "H225");
insert into Class values ("MTH101B", "F121", "MWF1", "M205");
insert into Class values ("HIN104A", "F120", "HWF4", "F125");
insert into Class values ("BIO110A", "F111", "BMF5", "G115");
insert into Class values ("PHY106B", "F112", "PWF4", "M335");
-- insert into Class values ("HIN104A", "F113", "HMF7", "M226");
-- insert into Class values ("BIO110A", "F114", "BSaF6", "F215");
insert into Class values ("HIN124A", "F115", "HWF8", "G116");
insert into Class values ("MTH121B", "F125", "MSuF6", "F127");

select * from Class;
-- truncate Class;

insert into Enroll values ("S1001", "ART103A", "A");
insert into Enroll values ("S1002", "ART103A", "B");
insert into Enroll values ("S1002", "CSC201A", "A");
insert into Enroll values ("S1002", "MTH121B", "C");
insert into Enroll values ("S1003", "ART103A", "B");
insert into Enroll values ("S1003", "HIN104A", "A");
insert into Enroll values ("S1003", "CSC201A", "B");
insert into Enroll values ("S1003", "PHY106B", "B");
insert into Enroll values ("S1013", "HIN124A", "B");
insert into Enroll values ("S1013", "ART103A", "C");
insert into Enroll values ("S1015", "HIN104A", "C");
insert into Enroll values ("S1014", "BIO110A", "C");
insert into Enroll values ("S1013", "PHY106B", "B");
insert into Enroll values ("S1015", "ART103A", "C");
insert into Enroll values ("S1026", "HIN124A", "B");
insert into Enroll values ("S1020", "CSC201A", "C");
insert into Enroll values ("S1026", "BIO110A", "A");
insert into Enroll values ("S1019", "HIN104A", "C");
insert into Enroll values ("S1019", "ART103A", "C");
insert into Enroll values ("S1010", "PHY106B", "A");
insert into Enroll values ("S1005", "CSC201A", "B");

select * from Enroll;
-- truncate Enroll;

set foreign_key_checks = 1;