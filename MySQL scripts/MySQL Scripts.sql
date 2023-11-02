--Creating Schema
CREATE SCHEMA `shop_management_system` ;

--creating TABLE

CREATE TABLE `item` (
  `item_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `item_name` varchar(100) NOT NULL,
  `cost_price` decimal(10,2) DEFAULT NULL,
  `selling_price` decimal(10,2) DEFAULT NULL,
  `discount` decimal(4,2) DEFAULT NULL,
  PRIMARY KEY (`item_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `supplier` (
  `supplier_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `phone` varchar(15) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `city` varchar(20) DEFAULT NULL,
  `state` varchar(20) DEFAULT NULL,
  `post_code` bigint(10) DEFAULT NULL,
  `initial_purchase_date` datetime DEFAULT NULL,
  PRIMARY KEY (`supplier_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `customer` (
  `customer_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `first_name` varchar(45) NOT NULL,
  `last_name` varchar(45) DEFAULT NULL,
  `email_id` varchar(45) DEFAULT NULL,
  `address` varchar(45) DEFAULT NULL,
  `phone_number` varchar(45) DEFAULT NULL,
  `city` varchar(45) DEFAULT NULL,
  `state` varchar(45) DEFAULT NULL,
  `post_code` varchar(45) DEFAULT NULL,
  `start_date` datetime NOT NULL,
  `end_date` datetime DEFAULT NULL,
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `bill` (
  `bill_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `customer_id` bigint(10) DEFAULT NULL,
  `total_price` decimal(10,2) DEFAULT NULL,
  `billing_date` datetime DEFAULT NULL,
  PRIMARY KEY (`bill_id`),
  KEY `custFK_idx` (`customer_id`),
  CONSTRAINT `custFK` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `bill_item` (
  `bill_item_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `bill_id` bigint(10) DEFAULT NULL,
  `item_id` bigint(10) DEFAULT NULL,
  `quantity` varchar(45) DEFAULT NULL,
  `price` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`bill_item_id`),
  KEY `billFK_idx` (`bill_id`),
  KEY `itemFK_idx` (`item_id`),
  CONSTRAINT `billFK` FOREIGN KEY (`bill_id`) REFERENCES `bill` (`bill_id`),
  CONSTRAINT `itemFK` FOREIGN KEY (`item_id`) REFERENCES `item` (`item_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `customer_payment` (
  `customer_payment_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `bill_id` bigint(10) DEFAULT NULL,
  `payment_mode` varchar(10) DEFAULT NULL,
  `payment_amount` decimal(10,2) DEFAULT NULL,
  `payment_date` datetime DEFAULT NULL,
  PRIMARY KEY (`customer_payment_id`),
  KEY `billFK_idx` (`bill_id`),
  CONSTRAINT `BILLSFK` FOREIGN KEY (`bill_id`) REFERENCES `bill` (`bill_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `purchase` (
  `purchase_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `suppliers_id` bigint(10) DEFAULT NULL,
  `total_cost` decimal(10,2) DEFAULT NULL,
  `purchase_date` datetime DEFAULT NULL,
  PRIMARY KEY (`purchase_id`),
  KEY `supFK_idx` (`suppliers_id`),
  CONSTRAINT `supplierFK` FOREIGN KEY (`suppliers_id`) REFERENCES `supplier` (`supplier_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `purchase_item` (
  `purchase_item_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `item_id` bigint(10) DEFAULT NULL,
  `purchase_id` bigint(10) DEFAULT NULL,
  `cost` decimal(10,2) DEFAULT NULL,
  `quantity` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`purchase_item_id`),
  KEY `itempFK_idx` (`item_id`),
  KEY `ppurchaseFK_idx` (`purchase_id`),
  CONSTRAINT `itempFK` FOREIGN KEY (`item_id`) REFERENCES `item` (`item_id`),
  CONSTRAINT `ppurchaseFK` FOREIGN KEY (`purchase_id`) REFERENCES `purchase` (`purchase_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;


CREATE TABLE `purchase_payment` (
  `purchase_payment_id` bigint(10) NOT NULL AUTO_INCREMENT,
  `purchase_id` bigint(10) DEFAULT NULL,
  `payment_mode` varchar(45) DEFAULT NULL,
  `payment_amount` decimal(10,2) DEFAULT NULL,
  `payment_date` datetime DEFAULT NULL,
  PRIMARY KEY (`purchase_payment_id`),
  KEY `pppurchaseFK_idx` (`purchase_id`),
  CONSTRAINT `pppurchaseFK` FOREIGN KEY (`purchase_id`) REFERENCES `purchase` (`purchase_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

