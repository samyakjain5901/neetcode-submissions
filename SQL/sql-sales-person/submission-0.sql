-- Write your query below
with base as (
    select o.sales_id from orders o inner join company c on o.com_id = c.com_id
    where c.name = 'CRIMSON'
)
select name from sales_person where sales_id not in (
    select b.sales_id from base b
)