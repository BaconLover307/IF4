select
	year(to_date),
	avg(salary) as average_salary
from
	salaries
where
	from_date < date("2001-01-01")
group by
	year(to_date);