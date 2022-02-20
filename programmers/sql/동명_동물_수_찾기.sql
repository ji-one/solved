-- 코드를 입력하세요
SELECT NAME, COUNT(NAME) AS 'COUNT'
FROM ANIMAL_INS
GROUP BY NAME
HAVING COUNT(NAME) >= 2
ORDER BY NAME

-- ** 쿼리문 실행 순서
-- SELECT - 5순위 (필수)
-- FROM - 1순위 (필수)
-- WHERE - 2순위
-- GROUP BY - 3순위
-- HAVING - 4순위
-- ORDER BY - 6순위