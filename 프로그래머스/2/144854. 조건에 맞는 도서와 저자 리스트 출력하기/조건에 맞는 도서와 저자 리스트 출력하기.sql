-- 코드를 입력하세요
SELECT B.book_id, author_name, DATE_FORMAT(b.PUBLISHED_DATE, '%Y-%m-%d')  from Book B Join Author A on B.Author_Id=A.author_id where B.category = '경제' order by published_date