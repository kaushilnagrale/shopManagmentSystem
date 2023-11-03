
declare bill_identi int;
CALL SP_initiateCustomerBill(7777777777);
set bill_identi (select max(bill_id) as use_this_id from shop_management_system.bill);
call SP_addBillItems(8,1,20);
call SP_addBillItems(8,2,1);
call SP_customerPayment(8,'CASH');

select sum(price*quantity) from shop_management_system.bill_item where bill_id = 8;


Insert into shop_management_system.customer (first_name,last_name,email_id,address,phone_number,city,state,post_code,start_date)
values ("Vedant","Parker","VP@hotmail.com","Wadinge",7777777777,"Pune","Maharashtra",416007,"2023-11-03 17:45:57.420")


Insert into shop_management_system.item (item_name,cost_price,selling_price,discount)
values ("Laptop",20000,30000,10)