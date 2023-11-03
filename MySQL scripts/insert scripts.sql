#Item Table
Insert into shop_management_system.item (item_name,cost_price,selling_price,discount)
values ("vicco tumeric",20,30,10)

#Adding customer
Insert into shop_management_system.customer (first_name,last_name,email_id,address,phone_number,city,state,post_code,start_date)
values ("John","Deer","jd@hotmail.com","Oxford street 10 Block 2",94573848239,"Nashik","Maharashtra",534112,"2023-11-02 17:45:57.420")

#Adding a bill for John Deer (Probably need an Stored Procedure for finding the customer.)

# Adding a Bill for Anonymous User Need an stored procedure for finding the total amount inncurred for the Bill
Insert into shop_management_system.bill (total_price,billing_date)
values (0,"2023-11-02 17:47:57.420")
#continous after the entry
#Adding items in Bill item table for anonymous user
select max(bill_id) from shop_management_system.bill
#in C++ program need to get item_id from the user after he chooses the item_name and then quantity along with price from item table (else drop price)
#if inv quantity < demanded quanitity then prompt only x items available do u want to proceed Y or N?
# if yes make the specific item quantity in item table = 0
# if no then ignore that item and do not insert
# while yes and inserting choose the specific Bill_id and quantity along with other functionality
# and after success send the user msg that item added in cart
Insert into shop_management_system.bill_item (bill_id,item_id,quantity,price)
values (select max(bill_id) from shop_management_system.bill,1,3,30)

Insert into shop_management_system.bill_item (bill_id,item_id,quantity,price)
values (1,1,3,30)

# once all cart/bill_item is filled then update the cart value
select sum(quantity),sum(price), sum(quantity * price ) as total
from shop_management_system.bill_item
where bill_id = 1

#now update the bill table amount with this value

#Can do enter your phone number for points and discount, so we can identity if the customer is new or OLD


