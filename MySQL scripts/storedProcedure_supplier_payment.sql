USE `shop_management_system`;
DROP procedure IF EXISTS `SP_supplierPayment`;

USE `shop_management_system`;
DROP procedure IF EXISTS `shop_management_system`.`SP_supplierPayment`;
;

DELIMITER $$
USE `shop_management_system`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_supplierPayment`(IN `created_purchase_id` bigint(10),IN `pay_mode` varchar(10))
BEGIN
declare total_amount decimal(10,2);
set total_amount = (select sum(cost*quantity) from shop_management_system.purchase_item where purchase_id = `created_purchase_id`);
insert into shop_management_system.purchase_payment (purchase_id,payment_mode,payment_amount,payment_date)
values(created_purchase_id,pay_mode,total_amount,current_timestamp());
END$$

DELIMITER ;
;
