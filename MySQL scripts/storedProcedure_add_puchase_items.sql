USE `shop_management_system`;
DROP procedure IF EXISTS `SP_addPurchaseItems`;

USE `shop_management_system`;
DROP procedure IF EXISTS `shop_management_system`.`SP_addPurchaseItems`;
;

DELIMITER $$
USE `shop_management_system`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_addPurchaseItems`(IN `created_purchase_id` bigint(10),IN `item_id_purchased` bigint(10),IN `quant_item` decimal(10,2))
BEGIN
declare item_price decimal(10,2);
set item_price = (select cost_price from shop_management_system.item where item_id = `item_id_purchased`);
#fetching the created bill id stored in C++ while the program runs
insert into shop_management_system.purchase_item (purchase_id,item_id,quantity,cost)
values (created_purchase_id,item_id_purchased,quant_item,item_price);
END$$

DELIMITER ;
;

call SP_addPurchaseItems(1,1,5);