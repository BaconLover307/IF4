delete cascade from orders
where exists (
	select 1
	from
		orderdetails
		join products on products.productCode = orderdetails.productCode
	where
		orders.orderNumber = orderdetails.orderNumber
		and orderdetails.quantityOrdered > products.quantityInStock
);

select
	count(orders.orderNumber)
from
	orders
;
