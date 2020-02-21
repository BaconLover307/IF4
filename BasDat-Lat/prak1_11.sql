select
	departments.dept_name
from
	departments left join dept_manager
on
	departments.dept_no = dept_manager.dept_no
where
	dept_manager.dept_no is null
;