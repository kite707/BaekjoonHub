-- 코드를 입력하세요
Select f.flavor from First_half F Join July J on F.flavor = J.flavor group by J.flavor order by sum(j.total_order) + sum(f.total_order) desc limit 3;