select
	emp_no, birth_date
from
	employees
where
	hire_date >= date("1994-01-24") and hire_date <= date("1994-06-24") order by birth_date desc
;