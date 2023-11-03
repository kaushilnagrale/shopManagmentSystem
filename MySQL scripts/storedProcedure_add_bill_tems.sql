USE `shop_management_system`;
DROP procedure IF EXISTS `SP_addBillItems`;

USE `shop_management_system`;
DROP procedure IF EXISTS `shop_management_system`.`SP_addBillItems`;
;

DELIMITER $$
USE `shop_management_system`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_addBillItems`(IN `created_bill_id` bigint(10),IN `item_id_cust` bigint(10),IN `quant_item` decimal(10,2))
BEGIN
declare item_price decimal(10,2);
set item_price = (select selling_price from shop_management_system.item where item_id = `item_id_cust`);
#fetching the created bill id stored in C++ while the program runs
insert into shop_management_system.bill_item (bill_id,item_id,quantity,price)
values (created_bill_id,item_id_cust,quant_item,item_price);
END$$

DELIMITER ;
;

call SP_addBillItems();