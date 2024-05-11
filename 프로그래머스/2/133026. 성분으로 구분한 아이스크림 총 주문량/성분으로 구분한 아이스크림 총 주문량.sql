-- 코드를 입력하세요
SELECT I.INGREDIENT_TYPE,sum(TOTAL_ORDER) as TOTAL_ORDER from FIRST_HALF as J join ICECREAM_INFO as I on J.flavor=I.flavor
group by INGREDIENT_TYPE
order by TOTAL_ORDER;