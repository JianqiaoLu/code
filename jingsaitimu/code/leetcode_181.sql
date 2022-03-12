SELECT l1.name as Employee
from employee l1, employee l2 
where l1.ManagerId = l2.Id and l1.Salary > l2.Salary


-- v2
SELECT l1.name as Employee
FROM employee l1 join employee l2
on     l1.ManagerId = l2.Id
   and a.Salary > l2.Salary