USE `shop_management_system`;
DROP procedure IF EXISTS `SP_initiateSupplierPurchase`;

USE `shop_management_system`;
DROP procedure IF EXISTS `shop_management_system`.`SP_initiateSupplierPurchase`;
;

DELIMITER $$
USE `shop_management_system`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `SP_initiateSupplierPurchase`(IN `phone_no` varchar(15))
BEGIN
declare supID int;
#select customer_id from shop_management_system.customer where phone_number = phone_no;
IF phone_no = Null THEN Set supID = null;
ELSE Set supID =  (select supplier_id from shop_management_system.supplier where phone = `phone_no`);
END IF;

Insert into shop_management_system.purchase (total_cost,suppliers_id,purchase_date)  values (0,supID,current_timestamp());
END$$

DELIMITER ;
;




CALL SP_initiateSupplierPurchase(null);

# to improve ,, getting the cost from the manager via C++ and then putting it into the item table

