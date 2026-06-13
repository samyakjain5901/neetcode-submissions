-- Write your query below
select employee_id, 
case 
    when employee_id % 2 != 0 and e.name not like 'M%' then salary 
    else 0 
end as bonus
from employees e
order by employee_id
        