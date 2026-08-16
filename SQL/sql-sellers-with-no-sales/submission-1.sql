-- Write your query below
with base as (
    select seller_id, 
    sum(case
        when date_trunc('year', sale_date) = '2020-01-01' then 1
        else 0
    end) as cnt_2020
    from orders
    group by seller_id
)
select s.seller_name from seller s left join base b on s.seller_id = b.seller_id
where b.cnt_2020 is null or b.cnt_2020 = 0
order by s.seller_name