 --Question 1
 --a
 create view role1_view as select * from role3;
 --b
 insert into role1_view values('AB101','207131','HERMIONE GRANGER');
 --b
 delete from role1_view where actorno='A4343';
--c
update role1_view set character='IRONMAN' where actorno='A7525';

--Question 2
 create view manager_staff_view1 as select * from staff3 where position='Manager';
--Question 3
 create index branch_index1 on branch3(branchno);
--Question 4 
 create index composite_index_role1 on role3(actorno,catalogno);
 --Question 5
 create unique index staff_name_index1 on staff3(name);
 --Question 6
 drop index branch_index1 ;
 