USE `shop_management_system`;
DROP procedure IF EXISTS `SP_customerPayment`;

USE `shop_management_system`;
DROP procedure IF EXISTS `shop_management_system`.`SP_customerPayment`;
;

DELIMITER $$
USE `shop_management_system`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_customerPayment`(IN `created_bill_id` bigint(10),IN `pay_mode` varchar(10))
BEGIN
declare total_amount decimal(10,2);
set total_amount = (select sum(price*quantity) from shop_management_system.bill_item where bill_id = `created_bill_id`);
insert into shop_management_system.customer_payment (bill_id,upper(payment_mode),payment_amount,payment_date)
values(created_bill_id,pay_mode,total_amount,current_timestamp());
END$$

DELIMITER ;
;
