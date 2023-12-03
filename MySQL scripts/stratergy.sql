
declare bill_identi int(2);
# initiate a order
CALL SP_initiateCustomerBill(7777777777);
#get the order number quickly
set bill_identi = (select max(bill_id) as use_this_id from shop_management_system.bill);
#add items
call SP_addBillItems(32,1,5);
call SP_addBillItems(9,2,1);
#when finished give ask payment details
call SP_customerPayment(32,'CASH');



declare purch_identi int;
#initiate a purchase order
CALL SP_supplierPayment(94543848239);
#get the order number quickly
set purch_identi = (select max(purchase_id) as use_this_id from shop_management_system.purchase);
#add items
call SP_addPurchaseItems(1,1,20);
call SP_addPurchaseItems(1,2,1);
#when finished give ask payment details
call SP_supplierPayment(1,'CASH');



select sum(price*quantity) from shop_management_system.bill_item where bill_id = 8;


Insert into shop_management_system.customer (first_name,last_name,email_id,address,phone_number,city,state,post_code,start_date)
values ("Vedant","Parker","VP@hotmail.com","Wadinge",7777777777,"Pune","Maharashtra",416007,"2023-11-03 17:45:57.420")


Insert into shop_management_system.item (item_name,cost_price,selling_price,discount)
values ("Laptop",20000,30000,10)