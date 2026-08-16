-- Write your query below
with base as (
    select customer_id,
    sum(case
        when product_name = 'A' then 1 else 0
    end) as cnt_prod_a,
    sum(case
        when product_name = 'B' then 1 else 0
    end) as cnt_prod_b,
    sum(case
        when product_name = 'C' then 1 else 0
    end) as cnt_prod_c
    from orders
    group by customer_id
)
select c.customer_id, c.customer_name from customers c inner join base b 
on c.customer_id = b.customer_id
where b.cnt_prod_a > 0 and b.cnt_prod_b > 0 and b.cnt_prod_c = 0
order by c.customer_name