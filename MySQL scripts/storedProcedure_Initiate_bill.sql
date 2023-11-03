USE `shop_management_system`;
DROP procedure IF EXISTS `SP_initiateCustomerBill`;

USE `shop_management_system`;
DROP procedure IF EXISTS `shop_management_system`.`SP_initiateCustomerBill`;
;

DELIMITER $$
USE `shop_management_system`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_initiateCustomerBill`(IN `phone_no` varchar(15))
BEGIN
declare custID int;
#select customer_id from shop_management_system.customer where phone_number = phone_no;
IF phone_no = Null THEN Set custID = null;
ELSE Set custID =  (select customer_id from shop_management_system.customer where phone_number = `phone_no`);
END IF;

Insert into shop_management_system.bill (total_price,customer_id,billing_date)  values (0,custID,current_timestamp());
END$$

DELIMITER ;
;




CALL SP_initiateCustomerBill(null);



