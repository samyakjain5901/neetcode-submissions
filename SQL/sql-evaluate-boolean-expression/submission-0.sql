-- Write your query below
with left_base as (
    select e.left_operand, e.operator, e.right_operand, v.value as left_val
    from variables v inner join expressions e
    on v.name = e.left_operand
),
right_base as (
    select l.left_operand, l.operator, l.right_operand,
    l.left_val, v.value as right_val
    from variables v inner join left_base l
    on v.name = l.right_operand
)
select left_operand, operator, right_operand, 
case 
    when operator = '>' then
        case when left_val > right_val then true
        else false end
    when operator = '<' then
        case when left_val < right_val then true
        else false end
    else
        case when left_val = right_val then true
        else false end
end as value
from right_base