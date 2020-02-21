drop view cust_avg_with_car;
create view cust_avg_with_car as
select
 	customers.customerName as cust_name, avg(payments.amount) as avg_transaction
from
	customers join payments
	on customers.customerNumber = payments.customerNumber
where customers.customerNumber in 
(select
	distinct customers.customerNumber
from
	products
	join orderdetails on orderdetails.productCode = products.productCode
	join orders on orders.orderNumber = orderdetails.orderNumber
	join customers on customers.customerNumber = orders.customerNumber
where
	productLine = "Classic Cars"
)
group by customers.customerNumber
;
select * from cust_avg_with_car;

/*(select
	distinct customers.customerNumber
from
	products
	join orderdetails on orderdetails.productCode = products.productCode
	join orders on orders.orderNumber = orderdetails.orderNumber
	join customers on customers.customerNumber = orders.customerNumber
where
	productLine = "Classic Cars"
) as customer_classic; */