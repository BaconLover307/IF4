select distinct
	employees.emp_no,
	employees.first_name,
	employees.last_name
from
	employees
	join titles on employees.emp_no = titles.emp_no
	join salaries on employees.emp_no = salaries.emp_no
where
	salaries.salary >= 75367
	and employees.first_name like 'S%';